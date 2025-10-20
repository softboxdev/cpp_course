# Руководство по сборке программы с помощью Makefile

## 1. Создание проекта

### Структура проекта
```
myproject/
├── src/
│   ├── main.c
│   ├── calculator.c
│   └── utils.c
├── include/
│   ├── calculator.h
│   └── utils.h
├── obj/
└── Makefile
```

### Исходные файлы

**include/calculator.h:**
```c
#ifndef CALCULATOR_H
#define CALCULATOR_H

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

#endif
```

**include/utils.h:**
```c
#ifndef UTILS_H
#define UTILS_H

void print_result(const char* operation, double result);
int get_user_input(int* a, int* b);

#endif
```

**src/calculator.c:**
```c
#include "calculator.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) {
        return 0.0;
    }
    return (double)a / b;
}
```

**src/utils.c:**
```c
#include <stdio.h>
#include "utils.h"

void print_result(const char* operation, double result) {
    printf("%s: %.2f\n", operation, result);
}

int get_user_input(int* a, int* b) {
    printf("Введите два числа: ");
    return scanf("%d %d", a, b);
}
```

**src/main.c:**
```c
#include <stdio.h>
#include "calculator.h"
#include "utils.h"

int main() {
    int a, b;
    
    printf("=== Калькулятор ===\n");
    
    if (get_user_input(&a, &b) != 2) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    
    print_result("Сложение", add(a, b));
    print_result("Вычитание", subtract(a, b));
    print_result("Умножение", multiply(a, b));
    print_result("Деление", divide(a, b));
    
    return 0;
}
```

## 2. Создание Makefile

### Базовый Makefile

**Makefile:**
```makefile
# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
LDFLAGS = -lm

# Директории
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Цели
TARGET = calculator

# Поиск исходных файлов
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Основное правило
$(TARGET): $(OBJECTS)
    $(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)
    @echo "✅ Программа $(TARGET) успешно собрана!"

# Правило для объектных файлов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

# Создание директории для объектных файлов
$(OBJ_DIR):
    mkdir -p $@

# Очистка
clean:
    rm -rf $(OBJ_DIR) $(TARGET)
    @echo "🧹 Очистка завершена"

# Пересборка
rebuild: clean $(TARGET)

# Запуск программы
run: $(TARGET)
    @echo "🚀 Запуск программы..."
    ./$(TARGET)

# Отладка
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Показать переменные
vars:
    @echo "CC: $(CC)"
    @echo "CFLAGS: $(CFLAGS)"
    @echo "SOURCES: $(SOURCES)"
    @echo "OBJECTS: $(OBJECTS)"
    @echo "TARGET: $(TARGET)"

# Справка
help:
    @echo "Доступные команды:"
    @echo "  make           - сборка программы"
    @echo "  make run       - сборка и запуск"
    @echo "  make debug     - сборка с отладкой"
    @echo "  make clean     - очистка проекта"
    @echo "  make rebuild   - полная пересборка"
    @echo "  make vars      - показать переменные"
    @echo "  make help      - эта справка"

.PHONY: clean rebuild run debug vars help
```

## 3. Пошаговая инструкция по сборке

### Шаг 1: Подготовка окружения

```bash
# Создаем структуру проекта
mkdir -p myproject/{src,include,obj}
cd myproject

# Создаем файлы как показано выше
# ... создаем все исходные файлы и Makefile
```

### Шаг 2: Базовая сборка

```bash
# Простая сборка
make

# Или явно указать цель
make all
```

**Вывод:**
```
gcc -Wall -Wextra -std=c99 -Iinclude -c src/main.c -o obj/main.o
gcc -Wall -Wextra -std=c99 -Iinclude -c src/calculator.c -o obj/calculator.o
gcc -Wall -Wextra -std=c99 -Iinclude -c src/utils.c -o obj/utils.o
gcc -Wall -Wextra -std=c99 -Iinclude -o calculator obj/main.o obj/calculator.o obj/utils.o -lm
✅ Программа calculator успешно собрана!
```

### Шаг 3: Проверка сборки

```bash
# Проверяем что создались файлы
ls -la

# Должны увидеть:
# calculator  obj/  src/  include/  Makefile

# Проверяем объектные файлы
ls obj/
# main.o  calculator.o  utils.o
```

### Шаг 4: Запуск программы

```bash
# Запуск собранной программы
./calculator

# Или используем цель run
make run
```

**Пример вывода программы:**
```
=== Калькулятор ===
Введите два числа: 10 3
Сложение: 13.00
Вычитание: 7.00
Умножение: 30.00
Деление: 3.33
```

## 4. Расширенный Makefile с дополнительными функциями

### Улучшенная версия Makefile

```makefile
# Конфигурация проекта
PROJECT_NAME = calculator
VERSION = 1.0

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
LDFLAGS = -lm

# Директории
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
BIN_DIR = bin

# Цели
TARGET = $(BIN_DIR)/$(PROJECT_NAME)

# Автоматический поиск исходников
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADERS = $(wildcard $(INC_DIR)/*.h)

# Конфигурация сборки
DEBUG ?= 0
ifeq ($(DEBUG),1)
CFLAGS += -g -O0 -DDEBUG
else
CFLAGS += -O2 -DNDEBUG
endif

# Основная цель
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJECTS) | $(BIN_DIR)
    $(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)
    @echo "✅ $(PROJECT_NAME) v$(VERSION) успешно собран!"

# Компиляция объектных файлов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@
    @echo "🔨 Скомпилирован: $<"

# Создание необходимых директорий
$(BIN_DIR) $(OBJ_DIR):
    mkdir -p $@

# Зависимости между файлами
$(OBJ_DIR)/main.o: $(INC_DIR)/calculator.h $(INC_DIR)/utils.h
$(OBJ_DIR)/calculator.o: $(INC_DIR)/calculator.h
$(OBJ_DIR)/utils.o: $(INC_DIR)/utils.h

# Очистка
clean:
    rm -rf $(OBJ_DIR) $(BIN_DIR)
    @echo "🧹 Очистка завершена"

# Полная пересборка
rebuild: clean all

# Запуск
run: $(TARGET)
    @echo "🚀 Запуск $(PROJECT_NAME)..."
    @echo "========================================"
    ./$(TARGET)

# Отладочная сборка
debug:
    @$(MAKE) DEBUG=1

# Статический анализ
analyze: CFLAGS += -fanalyzer
analyze: clean all

# Проверка стиля кода
style:
    @echo "📝 Проверка стиля кода..."
    @if command -v clang-format >/dev/null 2>&1; then \
        clang-format -n $(SOURCES) $(HEADERS); \
    else \
        echo "clang-format не установлен"; \
    fi

# Сборка с разными оптимизациями
release: CFLAGS += -O3 -march=native
release: clean all

size-optimized: CFLAGS += -Os
size-optimized: clean all

# Информация о проекте
info:
    @echo "📊 Информация о проекте:"
    @echo "   Проект: $(PROJECT_NAME) v$(VERSION)"
    @echo "   Компилятор: $(CC)"
    @echo "   Флаги: $(CFLAGS)"
    @echo "   Исходники: $(words $(SOURCES)) файлов"
    @echo "   Заголовки: $(words $(HEADERS)) файлов"
    @echo "   Цель: $(TARGET)"

# Установка (пример)
install: $(TARGET)
    @echo "📥 Установка $(PROJECT_NAME)..."
    cp $(TARGET) /usr/local/bin/
    chmod +x /usr/local/bin/$(PROJECT_NAME)
    @echo "✅ Установка завершена"

# Создание архива с исходниками
dist: clean
    @echo "📦 Создание дистрибутива..."
    tar -czf $(PROJECT_NAME)-$(VERSION).tar.gz \
        --transform 's,^,$(PROJECT_NAME)-$(VERSION)/,' \
        $(SRC_DIR) $(INC_DIR) Makefile README.md
    @echo "✅ Создан архив: $(PROJECT_NAME)-$(VERSION).tar.gz"

# Справка
help:
    @echo "📖 Доступные команды для $(PROJECT_NAME):"
    @echo ""
    @echo "  Сборка:"
    @echo "    make all           - стандартная сборка"
    @echo "    make debug         - сборка с отладкой"
    @echo "    make release       - оптимизированная сборка"
    @echo "    make size-optimized- оптимизация по размеру"
    @echo ""
    @echo "  Запуск:"
    @echo "    make run           - сборка и запуск"
    @echo ""
    @echo "  Анализ:"
    @echo "    make analyze       - статический анализ"
    @echo "    make style         - проверка стиля кода"
    @echo "    make info          - информация о проекте"
    @echo ""
    @echo "  Утилиты:"
    @echo "    make clean         - очистка"
    @echo "    make rebuild       - полная пересборка"
    @echo "    make dist          - создание архива"
    @echo "    make install       - установка в систему"
    @echo "    make help          - эта справка"
    @echo ""
    @echo "  Примеры:"
    @echo "    make DEBUG=1       - сборка с отладкой"
    @echo "    make -j4           - параллельная сборка"

.PHONY: all clean rebuild run debug analyze style info install dist help release size-optimized
```

## 5. Практические примеры использования

### Сборка с отладкой
```bash
make debug
```

### Параллельная сборка (ускорение)
```bash
make -j4
```

### Сборка с конкретными настройками
```bash
# Сборка с отладкой и параллельно
make debug -j4

# Сборка с кастомными флагами
make CFLAGS="-Wall -O2 -Iinclude" -j4
```

### Очистка и пересборка
```bash
# Просто очистка
make clean

# Полная пересборка
make rebuild

# Пересборка с отладкой
make DEBUG=1 rebuild
```

## 6. Отладка проблем сборки

### Просмотр команд которые выполнит make
```bash
make -n
```

### Подробный вывод
```bash
make --debug
```

### Проверка переменных
```bash
make vars
```

### Пример вывода при проблемах
```bash
# Если есть ошибки компиляции
make
# Вывод ошибок компилятора...
# Исправляем ошибки в коде и запускаем снова
make
```

## 7. Дополнительные возможности

### Сборка под другие системы
```bash
# Кросс-компиляция (пример)
make CC=x86_64-w64-mingw32-gcc
```

### Инкрементальная сборка
```bash
# Первая сборка - компилируются все файлы
make

# Изменяем только один файл
# touch src/utils.c

# Вторая сборка - компилируется только измененный файл
make
```

## 8. Проверка работоспособности

После сборки проверяем:

```bash
# Проверяем что файл создан
file bin/calculator

# Проверяем зависимости
ldd bin/calculator

# Запускаем тест
make run

# Вводим тестовые данные
# Введите два числа: 15 4
# Должны получить корректные результаты
```
