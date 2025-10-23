# Практическое руководство: Создание демона (фонового приложения) на C++ в Ubuntu 24.04

## 1. Установка необходимых инструментов

```bash
sudo apt update
sudo apt install g++ build-essential systemd
```

## 2. Создание простого демона для мониторинга системы

Создадим файл `system_monitor_daemon.cpp`:

```cpp
// Подключаем необходимые системные заголовочные файлы
#include <iostream>     // Для ввода-вывода
#include <fstream>      // Для работы с файлами
#include <string>       // Для работы со строками
#include <cstdlib>      // Для стандартных функций
#include <cstring>      // Для строковых функций
#include <csignal>      // Для обработки сигналов
#include <sys/stat.h>   // Для работы с правами файлов
#include <sys/types.h>  // Для системных типов
#include <unistd.h>     // Для POSIX API
#include <fcntl.h>      // Для управления файлами
#include <syslog.h>     // Для системного журнала
#include <chrono>       // Для работы со временем
#include <thread>       // Для работы с потоками
#include <atomic>       // Для атомарных операций

// Объявляем атомарную переменную для контроля работы демона
std::atomic<bool> daemon_running(true);

// Функция обработки сигналов
void signal_handler(int signal_number) {
    // Проверяем какой сигнал был получен
    switch(signal_number) {
        case SIGTERM:  // Сигнал завершения
        case SIGINT:   // Сигнал прерывания (Ctrl+C)
            // Записываем в системный журнал информацию о завершении
            syslog(LOG_INFO, "Получен сигнал завершения, демон останавливается");
            // Устанавливаем флаг работы в false
            daemon_running = false;
            break;
        case SIGHUP:   // Сигнал перезагрузки конфигурации
            // Записываем в журнал информацию о перезагрузке конфигурации
            syslog(LOG_INFO, "Получен сигнал перезагрузки конфигурации");
            break;
        default:
            // Для неизвестных сигналов записываем предупреждение
            syslog(LOG_WARNING, "Получен неизвестный сигнал: %d", signal_number);
            break;
    }
}

// Функция инициализации обработчиков сигналов
void setup_signal_handlers() {
    // Регистрируем обработчик для сигнала завершения
    signal(SIGTERM, signal_handler);
    // Регистрируем обработчик для сигнала прерывания
    signal(SIGINT, signal_handler);
    // Регистрируем обработчик для сигнала перезагрузки
    signal(SIGHUP, signal_handler);
}

// Функция для превращения процесса в демона
void become_daemon() {
    // Создаем дочерний процесс
    pid_t process_id = fork();
    
    // Проверяем успешность создания процесса
    if (process_id < 0) {
        // В случае ошибки выходим с кодом ошибки
        std::cerr << "Ошибка при создании дочернего процесса" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // Если это родительский процесс - завершаем его
    if (process_id > 0) {
        exit(EXIT_SUCCESS);
    }
    
    // Устанавливаем новый leader для сессии
    pid_t session_id = setsid();
    // Проверяем успешность создания сессии
    if (session_id < 0) {
        std::cerr << "Ошибка при создании сессии" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // Второй fork для предотвращения получения управляющего терминала
    process_id = fork();
    if (process_id < 0) {
        std::cerr << "Ошибка при втором fork" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (process_id > 0) {
        exit(EXIT_SUCCESS);
    }
    
    // Сбрасываем маску прав создания файлов
    umask(0);
    
    // Меняем текущую рабочую директорию на корневую
    chdir("/");
    
    // Закрываем стандартные файловые дескрипторы
    close(STDIN_FILENO);   // Закрываем стандартный ввод
    close(STDOUT_FILENO);  // Закрываем стандартный вывод
    close(STDERR_FILENO);  // Закрываем стандартный вывод ошибок
    
    // Перенаправляем стандартные дескрипторы в /dev/null
    open("/dev/null", O_RDONLY);   // stdin
    open("/dev/null", O_WRONLY);   // stdout
    open("/dev/null", O_WRONLY);   // stderr
}

// Функция для получения информации о загрузке системы
std::string get_system_load() {
    // Создаем объект для чтения файла
    std::ifstream load_file("/proc/loadavg");
    std::string load_info;
    
    // Проверяем успешность открытия файла
    if (load_file.is_open()) {
        // Читаем первую строку с информацией о загрузке
        std::getline(load_file, load_info);
        load_file.close();  // Закрываем файл
    } else {
        load_info = "Не удалось прочитать загрузку системы";
    }
    
    return load_info;  // Возвращаем строку с информацией
}

// Функция для получения информации о свободной памяти
std::string get_memory_info() {
    // Создаем объект для чтения файла информации о памяти
    std::ifstream mem_file("/proc/meminfo");
    std::string line;
    std::string memory_info;
    
    // Проверяем успешность открытия файла
    if (mem_file.is_open()) {
        // Читаем файл построчно
        while (std::getline(mem_file, line)) {
            // Ищем строки с информацией о свободной и общей памяти
            if (line.find("MemFree:") != std::string::npos || 
                line.find("MemTotal:") != std::string::npos) {
                memory_info += line + "\n";  // Добавляем строку к результату
            }
        }
        mem_file.close();  // Закрываем файл
    } else {
        memory_info = "Не удалось прочитать информацию о памяти";
    }
    
    return memory_info;  // Возвращаем строку с информацией
}

// Функция для записи информации в лог-файл
void write_to_log_file(const std::string& message) {
    // Создаем объект для записи в файл в режиме добавления
    std::ofstream log_file("/var/log/system_monitor.log", std::ios::app);
    
    // Получаем текущее время
    auto current_time = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(current_time);
    
    // Проверяем успешность открытия файла
    if (log_file.is_open()) {
        // Записываем время и сообщение в файл
        log_file << "[" << std::ctime(&time_t) << "] " << message << std::endl;
        log_file.close();  // Закрываем файл
    }
}

// Главная функция демона
void run_daemon() {
    // Счетчик циклов для демонстрации работы
    int cycle_count = 0;
    
    // Основной цикл работы демона
    while (daemon_running) {
        // Увеличиваем счетчик циклов
        cycle_count++;
        
        // Получаем информацию о системе
        std::string load_info = get_system_load();
        std::string memory_info = get_memory_info();
        
        // Формируем сообщение для лога
        std::string log_message = "Цикл " + std::to_string(cycle_count) + 
                                 " - Загрузка: " + load_info + 
                                 " Память:\n" + memory_info;
        
        // Записываем информацию в системный журнал
        syslog(LOG_INFO, "Мониторинг системы - цикл %d", cycle_count);
        
        // Записываем подробную информацию в файл лога
        write_to_log_file(log_message);
        
        // Ждем 10 секунд перед следующей итерацией
        for (int i = 0; i < 10 && daemon_running; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

// Точка входа в программу
int main(int argc, char* argv[]) {
    // Открываем соединение с системным журналом
    openlog("system_monitor_daemon", LOG_PID | LOG_NDELAY, LOG_DAEMON);
    
    // Записываем в журнал информацию о запуске демона
    syslog(LOG_INFO, "Демон мониторинга системы запускается");
    
    // Превращаем процесс в демона
    become_daemon();
    
    // Настраиваем обработчики сигналов
    setup_signal_handlers();
    
    // Запускаем основную функцию демона
    run_daemon();
    
    // Записываем в журнал информацию об остановке демона
    syslog(LOG_INFO, "Демон мониторинга системы останавливается");
    
    // Закрываем соединение с системным журналом
    closelog();
    
    // Возвращаем код успешного завершения
    return EXIT_SUCCESS;
}
```

## 3. Создание Makefile для компиляции

Создаем файл `Makefile`:

```makefile
# Компилятор C++
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -pthread

# Имя исполняемого файла
TARGET = system_monitor_daemon

# Исходные файлы
SOURCES = system_monitor_daemon.cpp

# Правило по умолчанию
all: $(TARGET)

# Правило компиляции
$(TARGET): $(SOURCES)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Установка демона (требует прав root)
install:
    sudo cp $(TARGET) /usr/local/bin/
    sudo chmod +x /usr/local/bin/$(TARGET)
    sudo cp system-monitor.service /etc/systemd/system/
    sudo systemctl daemon-reload

# Запуск демона
start:
    sudo systemctl start system-monitor

# Остановка демона
stop:
    sudo systemctl stop system-monitor

# Просмотр статуса
status:
    sudo systemctl status system-monitor

# Просмотр логов
logs:
    sudo journalctl -u system-monitor -f

# Очистка
clean:
    rm -f $(TARGET)

.PHONY: all install start stop status logs clean
```

## 4. Создание systemd service файла

Создаем файл `system-monitor.service`:

```ini
[Unit]
Description=System Monitor Daemon
Documentation=https://example.com
After=network.target

[Service]
Type=simple
User=root
ExecStart=/usr/local/bin/system_monitor_daemon
ExecReload=/bin/kill -HUP $MAINPID
Restart=on-failure
RestartSec=5s

[Install]
WantedBy=multi-user.target
```

## 5. Создание скрипта управления демоном

Создаем файл `daemon_manager.sh`:

```bash
#!/bin/bash

# Скрипт управления демоном мониторинга системы

DAEMON_NAME="system_monitor_daemon"
SERVICE_NAME="system-monitor"

# Функция показа справки
show_help() {
    echo "Использование: $0 {start|stop|restart|status|install|uninstall}"
    echo "  start    - запустить демона"
    echo "  stop     - остановить демона"
    echo "  restart  - перезапустить демона"
    echo "  status   - показать статус демона"
    echo "  install  - установить демона как системную службу"
    echo "  uninstall - удалить демона"
}

# Функция компиляции демона
compile_daemon() {
    echo "Компиляция демона..."
    make clean
    make
    if [ $? -eq 0 ]; then
        echo "Демон успешно скомпилирован"
    else
        echo "Ошибка компиляции демона"
        exit 1
    fi
}

# Функция установки
install_daemon() {
    echo "Установка демона..."
    
    # Компилируем демона
    compile_daemon
    
    # Копируем исполняемый файл
    sudo cp $DAEMON_NAME /usr/local/bin/
    sudo chmod +x /usr/local/bin/$DAEMON_NAME
    
    # Копируем service файл
    sudo cp system-monitor.service /etc/systemd/system/
    
    # Перезагружаем systemd
    sudo systemctl daemon-reload
    
    # Включаем автозагрузку
    sudo systemctl enable $SERVICE_NAME
    
    echo "Демон установлен и настроен для автозагрузки"
}

# Функция удаления
uninstall_daemon() {
    echo "Удаление демона..."
    
    # Останавливаем службу
    sudo systemctl stop $SERVICE_NAME 2>/dev/null
    
    # Отключаем автозагрузку
    sudo systemctl disable $SERVICE_NAME 2>/dev/null
    
    # Удаляем файлы
    sudo rm -f /usr/local/bin/$DAEMON_NAME
    sudo rm -f /etc/systemd/system/$SERVICE_NAME.service
    
    # Перезагружаем systemd
    sudo systemctl daemon-reload
    
    echo "Демон удален"
}

# Проверка прав доступа
check_root() {
    if [ "$EUID" -ne 0 ]; then
        echo "Это действие требует прав root. Используйте sudo."
        exit 1
    fi
}

# Основная логика скрипта
case "$1" in
    start)
        check_root
        echo "Запуск демона..."
        sudo systemctl start $SERVICE_NAME
        ;;
    stop)
        check_root
        echo "Остановка демона..."
        sudo systemctl stop $SERVICE_NAME
        ;;
    restart)
        check_root
        echo "Перезапуск демона..."
        sudo systemctl restart $SERVICE_NAME
        ;;
    status)
        sudo systemctl status $SERVICE_NAME
        ;;
    install)
        check_root
        install_daemon
        ;;
    uninstall)
        check_root
        uninstall_daemon
        ;;
    compile)
        compile_daemon
        ;;
    *)
        show_help
        exit 1
        ;;
esac

exit 0
```

## 6. Инструкция по использованию

### Компиляция и установка:

```bash
# Даем права на выполнение скрипта
chmod +x daemon_manager.sh
chmod +x Makefile

# Компилируем демона
make

# Или используем скрипт для компиляции
./daemon_manager.sh compile

# Устанавливаем демона (требует sudo)
sudo ./daemon_manager.sh install

# Запускаем демона
sudo ./daemon_manager.sh start

# Проверяем статус
sudo ./daemon_manager.sh status

# Просматриваем логи
sudo journalctl -u system-monitor -f
```

### Ручной запуск (для тестирования):

```bash
# Компилируем
make

# Запускаем в foreground для отладки
./system_monitor_daemon

# В другом терминале проверяем процесс
ps aux | grep system_monitor

# Просматриваем логи
tail -f /var/log/system_monitor.log
```

## 7. Ключевые особенности демона

1. **Двойной fork** - для полного отсоединения от терминала
2. **Обработка сигналов** - корректное завершение по SIGTERM/SIGINT
3. **Системный журнал** - использование syslog для логирования
4. **Файловая система** - работа с /proc для получения системной информации
5. **Systemd integration** - интеграция с современной системой инициализации

Этот демон будет работать в фоне, мониторить систему и писать логи каждые 10 секунд.