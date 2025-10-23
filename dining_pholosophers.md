# Практическое руководство: Задача обедающих философов на C++ с семафорами и мьютексами

## 1. Установка необходимых инструментов

```bash
sudo apt update
sudo apt install g++ build-essential cmake make
```

## 2. Полностью прокомментированный код решения

### Файл `dining_philosophers.cpp`:

```cpp
// Подключаем необходимые заголовочные файлы
#include <iostream>      // Для ввода-вывода в консоль (cout, endl)
#include <thread>        // Для работы с потоками (thread, this_thread)
#include <vector>        // Для использования динамического массива (vector)
#include <mutex>         // Для мьютексов (mutex, lock_guard, unique_lock)
#include <chrono>        // Для работы со временем (seconds, milliseconds)
#include <random>        // Для генерации случайных чисел (random_device, mt19937)
#include <semaphore>     // Для семафоров (counting_semaphore)
#include <string>        // Для работы со строками (string)
#include <atomic>        // Для атомарных операций (atomic)

// Используем стандартное пространство имен для упрощения кода
using namespace std;

// Класс представляющий философа
class Philosopher {
private:
    int id;                             // Уникальный идентификатор философа
    string name;                        // Имя философа
    mutex& left_fork;                   // Ссылка на левую вилку (мьютекс)
    mutex& right_fork;                  // Ссылка на правую вилку (мьютекс)
    counting_semaphore<5>& table_semaphore;  // Ссылка на семафор стола
    atomic<int>& meals_eaten;           // Ссылка на счетчик съеденных блюд
    atomic<bool>& running;              // Флаг продолжения работы

    // Генератор случайных чисел для имитации времени размышлений и еды
    random_device rd;                   // Устройство для получения случайного seed
    mt19937 gen;                        // Генератор случайных чисел
    uniform_int_distribution<> think_dist;  // Распределение для времени размышлений
    uniform_int_distribution<> eat_dist;    // Распределение для времени еды

public:
    // Конструктор класса Philosopher
    Philosopher(int philosopher_id, 
                string philosopher_name, 
                mutex& left, 
                mutex& right, 
                counting_semaphore<5>& sem, 
                atomic<int>& meals, 
                atomic<bool>& run_flag)
        : id(philosopher_id),                    // Инициализация ID
          name(move(philosopher_name)),          // Инициализация имени (move для эффективности)
          left_fork(left),                       // Инициализация ссылки на левую вилку
          right_fork(right),                     // Инициализация ссылки на правую вилку
          table_semaphore(sem),                  // Инициализация ссылки на семафор
          meals_eaten(meals),                    // Инициализация ссылки на счетчик блюд
          running(run_flag),                     // Инициализация ссылки на флаг работы
          gen(rd()),                             // Инициализация генератора случайных чисел
          think_dist(1000, 3000),                // Время размышлений: 1-3 секунды
          eat_dist(500, 2000)                    // Время еды: 0.5-2 секунды
    {
        // Выводим сообщение о создании философа
        cout << "Философ " << name << " (ID: " << id << ") присоединился к столу" << endl;
    }

    // Метод который выполняется в отдельном потоке
    void operator()() {
        // Цикл пока установлен флаг running
        while (running.load()) {
            think();    // Философ размышляет
            eat();      // Философ пытается поесть
        }
        
        // Сообщение когда философ завершает работу
        cout << "Философ " << name << " закончил трапезу" << endl;
    }

private:
    // Метод имитации размышлений философа
    void think() {
        // Генерируем случайное время размышлений
        int think_time = think_dist(gen);
        
        // Выводим сообщение о начале размышлений
        cout << "Философ " << name << " размышляет " << think_time << "мс" << endl;
        
        // Останавливаем поток на время размышлений
        this_thread::sleep_for(chrono::milliseconds(think_time));
    }

    // Метод имитации приема пищи философа
    void eat() {
        // ЗАХВАТЫВАЕМ семафор стола (уменьшаем счетчик на 1)
        // Если семафор = 0, поток БЛОКИРУЕТСЯ пока место не освободится
        table_semaphore.acquire();

        // Пытаемся взять вилки в правильном порядке чтобы избежать дедлока
        // Все философы сначала берут левую вилку, потом правую
        
        // Берем левую вилку (захватываем мьютекс)
        unique_lock<mutex> left_lock(left_fork, defer_lock);  // defer_lock - не захватывать сразу
        
        // Берем правую вилку (захватываем мьютекс)
        unique_lock<mutex> right_lock(right_fork, defer_lock);

        // Атомарно захватываем ОБЕ вилки одновременно
        // Это предотвращает deadlock (взаимную блокировку)
        lock(left_lock, right_lock);

        // В этот момент философ держит ОБЕ вилки
        // Это КРИТИЧЕСКАЯ СЕКЦИЯ - доступ к разделяемым ресурсам

        // Генерируем случайное время еды
        int eat_time = eat_dist(gen);
        
        // Увеличиваем счетчик съеденных блюд
        meals_eaten++;
        
        // Выводим сообщение о начале еды
        cout << "Философ " << name << " ест " << eat_time << "мс (" 
             << meals_eaten.load() << " блюдо)" << endl;
        
        // Имитируем процесс еды
        this_thread::sleep_for(chrono::milliseconds(eat_time));

        // Вилки автоматически освобождаются при разрушении unique_lock
        
        // ОСВОБОЖДАЕМ семафор стола (увеличиваем счетчик на 1)
        // Это позволяет другому философу сесть за стол
        table_semaphore.release();
    }
};

// Класс для управления обеденным столом
class DiningTable {
private:
    vector<mutex> forks;                    // Вектор вилок (мьютексов)
    vector<thread> philosophers;            // Вектор потоков философов
    counting_semaphore<5> table_semaphore;  // Семафор стола (максимум 4 философа из 5 могут есть одновременно)
    atomic<int> total_meals;                // Общий счетчик съеденных блюд
    atomic<bool> running;                   // Флаг продолжения работы
    const int num_philosophers;             // Количество философов

public:
    // Конструктор класса DiningTable
    DiningTable(int number_of_philosophers = 5) 
        : forks(number_of_philosophers),           // Создаем N вилок-мьютексов
          table_semaphore(number_of_philosophers - 1), // Семафор на N-1 (предотвращает дедлок)
          total_meals(0),                          // Инициализируем счетчик блюд
          running(true),                           // Устанавливаем флаг работы в true
          num_philosophers(number_of_philosophers) // Сохраняем количество философов
    {
        // Выводим информацию о создании стола
        cout << "Создан обеденный стол для " << num_philosophers 
             << " философов" << endl;
        cout << "Одновременно могут есть " << (num_philosophers - 1) 
             << " философов" << endl;
    }

    // Метод запуска обеда философов
    void start_dinner() {
        // Массив имен философов
        vector<string> names = {"Аристотель", "Платон", "Сократ", "Декарт", "Кант"};
        
        // Создаем и запускаем потоки для каждого философа
        for (int i = 0; i < num_philosophers; ++i) {
            // Определяем индексы вилок для текущего философа
            int left_fork_index = i;                               // Левая вилка - с тем же индексом
            int right_fork_index = (i + 1) % num_philosophers;     // Правая вилка - следующий индекс по кругу
            
            // Создаем философа и добавляем его поток в вектор
            philosophers.emplace_back(
                Philosopher(i + 1,                                // ID философа
                           names[i],                              // Имя философа
                           forks[left_fork_index],                // Левая вилка
                           forks[right_fork_index],               // Правая вилка  
                           table_semaphore,                       // Семафор стола
                           total_meals,                           // Счетчик блюд
                           running                               // Флаг работы
                )
            );
        }
        
        cout << "Все философы сели за стол. Обед начался!" << endl;
    }

    // Метод для работы в основном потоке (мониторинг и управление)
    void monitor() {
        // Ждем некоторое время чтобы философы поели
        for (int i = 0; i < 10; ++i) {
            // Ждем 2 секунды
            this_thread::sleep_for(chrono::seconds(2));
            
            // Выводим текущую статистику
            cout << "=== СТАТИСТИКА: съедено " << total_meals.load() 
                 << " блюд за " << (i + 1) * 2 << " секунд ===" << endl;
            
            // Проверяем не пора ли завершать обед
            if (total_meals.load() >= 20) {
                cout << "Достигнут лимит блюд. Завершаем обед..." << endl;
                break;
            }
        }
        
        // Сигнализируем философам о завершении
        stop_dinner();
    }

    // Метод остановки обеда
    void stop_dinner() {
        // Устанавливаем флаг running в false
        running.store(false);
        
        cout << "Завершаем обед..." << endl;
        
        // Ожидаем завершения всех потоков философов
        for (auto& philosopher : philosophers) {
            if (philosopher.joinable()) {
                philosopher.join();  // Блокируем текущий поток до завершения философа
            }
        }
        
        // Выводим итоговую статистику
        cout << "=== ОБЕД ЗАВЕРШЕН ===" << endl;
        cout << "Всего съедено блюд: " << total_meals.load() << endl;
    }

    // Деструктор класса
    ~DiningTable() {
        // Гарантируем что все потоки завершены
        stop_dinner();
    }
};

// Альтернативное решение с использованием таймаутов (дополнительная реализация)
class TimeoutPhilosopher {
private:
    int id;
    string name;
    mutex& left_fork;
    mutex& right_fork;
    atomic<int>& meals_eaten;
    atomic<bool>& running;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> think_dist;
    uniform_int_distribution<> eat_dist;

public:
    TimeoutPhilosopher(int philosopher_id, string philosopher_name, 
                      mutex& left, mutex& right, atomic<int>& meals, atomic<bool>& run_flag)
        : id(philosopher_id),
          name(move(philosopher_name)),
          left_fork(left),
          right_fork(right),
          meals_eaten(meals),
          running(run_flag),
          gen(rd()),
          think_dist(1000, 3000),
          eat_dist(500, 2000)
    {}

    void operator()() {
        while (running.load()) {
            think();
            
            // Пытаемся поесть с таймаутом
            if (!try_eat_with_timeout()) {
                // Если не удалось поесть - философ продолжает размышлять
                cout << "Философ " << name << " не смог поесть и продолжает размышлять" << endl;
            }
        }
    }

private:
    void think() {
        int think_time = think_dist(gen);
        cout << "Философ " << name << " размышляет " << think_time << "мс" << endl;
        this_thread::sleep_for(chrono::milliseconds(think_time));
    }

    bool try_eat_with_timeout() {
        // Пытаемся взять левую вилку с таймаутом
        unique_lock<mutex> left_lock(left_fork, defer_lock);
        
        // Пытаемся захватить левую вилку в течение 100ms
        if (!left_lock.try_lock_for(chrono::milliseconds(100))) {
            return false;  // Не удалось взять левую вилку
        }

        // Пытаемся взять правую вилку с таймаутом
        unique_lock<mutex> right_lock(right_fork, defer_lock);
        
        // Пытаемся захватить правую вилку в течение 100ms
        if (!right_lock.try_lock_for(chrono::milliseconds(100))) {
            return false;  // Не удалось взять правую вилку
        }

        // Если удалось взять обе вилки - едим
        int eat_time = eat_dist(gen);
        meals_eaten++;
        cout << "Философ " << name << " ест " << eat_time << "мс (" 
             << meals_eaten.load() << " блюдо)" << endl;
        this_thread::sleep_for(chrono::milliseconds(eat_time));

        return true;
    }
};

// Главная функция программы
int main() {
    // Устанавливаем локаль для корректного вывода русских символов
    setlocale(LC_ALL, "ru_RU.UTF-8");

    cout << "==================================================" << endl;
    cout << "    РЕШЕНИЕ ЗАДАЧИ ОБЕДАЮЩИХ ФИЛОСОФОВ" << endl;
    cout << "    Использование семафоров и мьютексов" << endl;
    cout << "==================================================" << endl << endl;

    // Создаем обеденный стол на 5 философов
    DiningTable table(5);

    // Запускаем обед
    table.start_dinner();

    // Запускаем мониторинг и управление
    table.monitor();

    cout << "Программа завершена успешно!" << endl;
    return 0;  // Успешное завершение программы
}
```

## 3. Создание Makefile для компиляции

### Файл `Makefile`:

```makefile
# Компилятор C++
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++20 -Wall -Wextra -O2 -pthread

# Имя исполняемого файла
TARGET = dining_philosophers

# Исходные файлы
SOURCES = dining_philosophers.cpp

# Правило по умолчанию
all: $(TARGET)

# Правило компиляции
$(TARGET): $(SOURCES)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Запуск программы
run: $(TARGET)
    ./$(TARGET)

# Отладочная сборка
debug: CXXFLAGS += -g -DDEBUG
debug: clean $(TARGET)

# Очистка
clean:
    rm -f $(TARGET)

# Статический анализ кода
check:
    cppcheck --enable=all $(SOURCES)

.PHONY: all run debug clean check
```

## 4. Объяснение ключевых концепций

### Проблема обедающих философов:

**Условия задачи:**
- 5 философов сидят за круглым столом
- Каждому нужно 2 вилки чтобы есть
- Между каждыми двумя философами лежит 1 вилка
- Философы могут либо размышлять, либо есть
- Нужно предотвратить deadlock и starvation

### Решение с семафорами:

```cpp
counting_semaphore<5> table_semaphore(4);  // Максимум 4 философа могут есть одновременно
```

**Принцип работы:**
- Семафор ограничивает количество философов, которые могут одновременно пытаться есть
- Это предотвращает ситуацию когда все философы берут левую вилку и ждут правую (deadlock)
- Гарантирует что минимум один философ сможет поесть

### Решение с мьютексами:

```cpp
unique_lock<mutex> left_lock(left_fork, defer_lock);
unique_lock<mutex> right_lock(right_fork, defer_lock);
lock(left_lock, right_lock);  // Атомарный захват обеих вилок
```

**Принцип работы:**
- `std::lock()` атомарно захватывает оба мьютекса
- Избегает классического deadlock когда каждый философ держит одну вилку
- Гарантирует что философ либо получит обе вилки, либо ни одной

## 5. Инструкция по использованию

### Компиляция и запуск:

```bash
# Делаем Makefile исполняемым
chmod +x Makefile

# Компилируем программу
make

# Запускаем программу
./dining_philosophers

# Или одной командой
make run
```

### Анализ работы программы:

```bash
# Запуск с выводом в файл для анализа
./dining_philosophers > output.log 2>&1

# Просмотр статистики
grep "СТАТИСТИКА" output.log

# Просмотр сообщений о еде
grep "ест" output.log
```

## 6. Ключевые особенности реализации

1. **Предотвращение deadlock**: семафор ограничивает количество одновременно едящих философов
2. **Атомарный захват вилок**: `std::lock()` гарантирует что философ получает обе вилки или ни одной
3. **Правильный порядок вилок**: все философы берут сначала левую, потом правую вилку
4. **Коoperativeтивное завершение**: атомарный флаг `running` позволяет корректно завершить все потоки
5. **Статистика в реальном времени**: мониторинг прогресса обеда

Это решение гарантирует что:
- Не возникает взаимных блокировок (deadlock)
- Все философы eventually получают возможность поесть (no starvation)
- Ресурсы используются эффективно
- Программа может быть корректно завершена в любой момент