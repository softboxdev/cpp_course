# Сборка программ в GNU/Linux: Подробное руководство

## 1. Как работает сборка программ в GNU/Linux

### Основные этапы сборки

**1. Препроцессирование**
- Обработка директив препроцессора (#include, #define, #ifdef)
- Подстановка макросов и включение заголовочных файлов
- Генерация чистого C/C++ кода

**2. Компиляция**
- Перевод исходного кода на C/C++ в ассемблерный код
- Проверка синтаксиса и семантики
- Оптимизация кода

**3. Ассемблирование**
- Преобразование ассемблерного кода в объектные файлы (.o)
- Создание машинного кода, специфичного для архитектуры процессора

**4. Линковка**
- Объединение объектных файлов в исполняемый файл
- Разрешение внешних ссылок на библиотеки
- Создание финального бинарного файла

### Ключевые инструменты

- **GCC** (GNU Compiler Collection) - основной компилятор
- **G++** - компилятор для C++
- **make** - утилита для автоматизации сборки
- **autoconf/automake** - генерация скриптов конфигурации
- **pkg-config** - управление флагами компиляции для библиотек
- **ld** - компоновщик

## 2. Учебное руководство по сборке программ в Ubuntu 22.04

### Установка необходимых инструментов

```bash
# Обновление системы
sudo apt update && sudo apt upgrade -y

# Установка базовых инструментов разработки
sudo apt install build-essential -y

# Дополнительные утилиты
sudo apt install cmake autoconf automake libtool pkg-config -y

# Отладочные инструменты
sudo apt install gdb valgrind -y

# Система контроля версий
sudo apt install git -y
```

### Проверка установки

```bash
# Проверка версий
gcc --version
g++ --version
make --version
cmake --version
```

## 3. Практические примеры сборки

### Пример 1: Простая программа на C

**1. Создаем исходный файл**
```c
// hello.c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

**2. Прямая компиляция с GCC**
```bash
# Базовая компиляция
gcc hello.c -o hello

# Компиляция с отладочной информацией
gcc -g hello.c -o hello_debug

# Компиляция с оптимизацией
gcc -O2 hello.c -o hello_optimized

# Запуск программы
./hello
```

**3. Подробный разбор флагов компиляции**
```bash
# Препроцессирование
gcc -E hello.c > hello.i

# Компиляция в ассемблер
gcc -S hello.c

# Компиляция в объектный файл
gcc -c hello.c

# Линковка
gcc hello.o -o hello
```

### Пример 2: Программа с несколькими файлами

**1. Создаем файлы проекта**
```c
// main.c
#include <stdio.h>
#include "math_utils.h"

int main() {
    int a = 5, b = 3;
    printf("Sum: %d\n", add(a, b));
    printf("Product: %d\n", multiply(a, b));
    return 0;
}
```

```c
// math_utils.c
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}
```

```c
// math_utils.h
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int add(int a, int b);
int multiply(int a, int b);

#endif
```

**2. Ручная сборка**
```bash
# Компиляция каждого исходного файла
gcc -c main.c
gcc -c math_utils.c

# Линковка объектных файлов
gcc main.o math_utils.o -o calculator

# Запуск
./calculator
```

### Пример 3: Использование Makefile

**1. Создаем Makefile**
```makefile
# Переменные
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = calculator
SOURCES = main.c math_utils.c
OBJECTS = $(SOURCES:.c=.o)

# Основная цель
$(TARGET): $(OBJECTS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Правило для объектных файлов
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
    rm -f $(OBJECTS) $(TARGET)

# Установка (пример)
install: $(TARGET)
    cp $(TARGET) /usr/local/bin/

.PHONY: clean install
```

**2. Использование make**
```bash
# Сборка проекта
make

# Очистка
make clean

# Сборка с другими флагами
make CFLAGS="-Wall -O2"
```

### Пример 4: Сборка с внешними библиотеками

**1. Установка библиотеки development packages**
```bash
# Пример для библиотеки SDL2
sudo apt install libsdl2-dev libsdl2-image-dev
```

**2. Программа с использованием библиотеки**
```c
// sdl_example.c
#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }
    
    printf("SDL initialized successfully!\n");
    SDL_Quit();
    return 0;
}
```

**3. Компиляция с библиотеками**
```bash
# Ручное указание флагов
gcc sdl_example.c -o sdl_example `pkg-config --cflags --libs sdl2`

# Или по отдельности
gcc sdl_example.c -o sdl_example -lSDL2
```

## 4. Сборка реальных проектов

### Пример: Сборка проекта из исходников

**1. Получение исходного кода**
```bash
# Клонирование репозитория (пример)
git clone https://github.com/example/project.git
cd project
```

**2. Типичные сценарии сборки**

**Автоматическая сборка (autotools):**
```bash
./configure
make
sudo make install
```

**CMake сборка:**
```bash
mkdir build && cd build
cmake ..
make
sudo make install
```

**Сборка с кастомными параметрами:**
```bash
./configure --prefix=/usr/local --enable-feature
make -j4  # Использование 4 ядер
sudo make install
```

## 5. Отладка и оптимизация

### Отладочные флаги
```bash
# Компиляция с отладочной информацией
gcc -g -O0 program.c -o program_debug

# Использование gdb
gdb ./program_debug
```

### Оптимизация
```bash
# Разные уровни оптимизации GCC
gcc -O0 # Без оптимизации (отладка)
gcc -O1 # Базовая оптимизация
gcc -O2 # Стандартная оптимизация
gcc -O3 # Агрессивная оптимизация
gcc -Os # Оптимизация по размеру
```

## 6. Полезные команды и инструменты

### Анализ бинарных файлов
```bash
# Просмотр секций
objdump -h program

# Символы
nm program

# Зависимости
ldd program

# Размеры секций
size program
```

### Создание deb-пакетов
```bash
# Установка инструментов для создания пакетов
sudo apt install devscripts debhelper dh-make

# Создание структуры пакета
dh_make --createorig
```

## 7. Решение распространенных проблем

### Проблемы с зависимостями
```bash
# Поиск пакетов
apt search library-name
apt show package-name

# Установка dev-пакетов
sudo apt install libsomething-dev
```

### Проблемы с путями
```bash
# Добавление путей к библиотекам
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

# Указание кастомных путей при компиляции
gcc -I/path/to/include -L/path/to/lib program.c -lsomelib
```
