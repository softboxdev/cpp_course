# **Полное руководство по сборке программ на C++ в Linux (Ubuntu)**

## **📌 Введение: Особенности Linux**

В Linux сборка программ проще, чем в Windows, потому что:
1. Компилятор уже есть или ставится одной командой
2. Нет необходимости в сложных настройках PATH
3. Все инструменты работают "из коробки"
4. Терминал — ваш лучший друг

---

## **🎯 Установка компилятора (один раз)**

### **Шаг 1: Откройте терминал**
Нажмите **Ctrl + Alt + T** или найдите "Терминал" в меню приложений.

### **Шаг 2: Установите компилятор GCC**
Введите команду:
```bash
sudo apt update
sudo apt install g++
```
Введите пароль (символы не отображаются, это нормально).

### **Шаг 3: Проверьте установку**
```bash
g++ --version
```
Вы должны увидеть что-то вроде:
```
g++ (Ubuntu 11.4.0) 11.4.0
Copyright (C) 2021 Free Software Foundation, Inc.
```

**Готово!** Компилятор установлен.

---

## **🔧 Три способа сборки (от простого к сложному)**

### **Способ 1: Простейшая сборка (один файл)**

#### **Шаг 1: Создайте папку для проекта**
```bash
mkdir ~/cpp_projects
cd ~/cpp_projects
mkdir first_program
cd first_program
```

#### **Шаг 2: Создайте файл с программой**
```bash
nano hello.cpp
```
Или используйте любой текстовый редактор: **gedit**, **vim**, **code** (VS Code).

#### **Шаг 3: Напишите простую программу**
Вставьте этот код:
```cpp
#include <iostream>

int main() {
    std::cout << "Привет, Linux!" << std::endl;
    std::cout << "Моя первая программа в Ubuntu" << std::endl;
    return 0;
}
```

**Сохраните файл:**
- В nano: **Ctrl+X**, затем **Y**, затем **Enter**
- В gedit: **Ctrl+S**
- В vim: **Esc**, затем **:wq**, **Enter**

#### **Шаг 4: Скомпилируйте программу**
```bash
g++ hello.cpp -o myprogram
```
Разберём команду:
- `g++` — компилятор C++
- `hello.cpp` — исходный файл
- `-o` — опция "output" (вывод)
- `myprogram` — имя исполняемого файла (без расширения в Linux)

#### **Шаг 5: Запустите программу**
```bash
./myprogram
```
**Обратите внимание на `./`** — в Linux нужно явно указывать путь к программе в текущей папке.

---

### **Способ 2: Сборка с Makefile (несколько файлов)**

#### **Структура проекта:**
```
calculator/
├── main.cpp
├── math.cpp
├── math.h
└── Makefile
```

#### **Шаг 1: Создайте файлы**
```bash
mkdir calculator
cd calculator

# Создаем файлы
touch main.cpp math.cpp math.h Makefile
```

#### **Шаг 2: Наполните файлы содержимым**

**math.h:**
```cpp
#ifndef MATH_H
#define MATH_H

int add(int a, int b);
int subtract(int a, int b);
double divide(double a, double b);

#endif
```

**math.cpp:**
```cpp
#include "math.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

double divide(double a, double b) {
    if (b == 0) {
        return 0; // упрощённо для примера
    }
    return a / b;
}
```

**main.cpp:**
```cpp
#include <iostream>
#include "math.h"

int main() {
    std::cout << "5 + 3 = " << add(5, 3) << std::endl;
    std::cout << "10 - 4 = " << subtract(10, 4) << std::endl;
    std::cout << "15 / 3 = " << divide(15, 3) << std::endl;
    return 0;
}
```

#### **Шаг 3: Создайте Makefile**
```makefile
# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++11

# Имя исполняемого файла
TARGET = calculator

# Исходные файлы
SRCS = main.cpp math.cpp

# Объектные файлы (автоматически из SRCS)
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Компиляция .cpp в .o
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
    rm -f $(OBJS) $(TARGET)

# Пересборка
rebuild: clean all

# Запуск
run: $(TARGET)
    ./$(TARGET)

.PHONY: all clean rebuild run
```

#### **Шаг 4: Используйте Makefile**
```bash
# Собрать программу
make

# Или явно
make all

# Запустить программу
make run

# Очистить скомпилированные файлы
make clean

# Пересобрать с нуля
make rebuild

# Просто запустить (если уже собрана)
./calculator
```

---

### **Способ 3: Сборка вручную (для понимания процесса)**

#### **Шаг 1: Компиляция каждого .cpp файла в .o**
```bash
g++ -c main.cpp -o main.o
g++ -c math.cpp -o math.o
```
Флаг `-c` означает "только компиляция, без линковки".

#### **Шаг 2: Линковка всех .o файлов**
```bash
g++ main.o math.o -o calculator
```

#### **Шаг 3: Запуск**
```bash
./calculator
```

---

## **⚙️ Полезные флаги компиляции**

```bash
# Базовые флаги (всегда используйте -Wall!)
g++ program.cpp -o program -Wall -Wextra

# Спецификация стандарта C++
g++ program.cpp -o program -std=c++11    # C++11
g++ program.cpp -o program -std=c++14    # C++14
g++ program.cpp -o program -std=c++17    # C++17
g++ program.cpp -o program -std=c++20    # C++20

# Отладочная информация (для gdb)
g++ program.cpp -o program -g

# Оптимизация
g++ program.cpp -o program -O1   # базовая оптимизация
g++ program.cpp -o program -O2   # хорошая оптимизация (рекомендуется)
g++ program.cpp -o program -O3   # агрессивная оптимизация

# Все вместе
g++ program.cpp -o program -Wall -Wextra -std=c++17 -O2 -g
```

---

## **🐛 Отладка программ**

### **Установка отладчика GDB:**
```bash
sudo apt install gdb
```

### **Компиляция с отладочной информацией:**
```bash
g++ program.cpp -o program -g
```

### **Запуск в отладчике:**
```bash
gdb ./program
```
**Основные команды GDB:**
```
run                # Запуск программы
break main         # Точка останова на функции main
break 10           # Точка останова на строке 10
next               # Следующая строка (без захода в функции)
step               # Следующая строка (с заходом в функции)
print variable     # Вывести значение переменной
continue           # Продолжить выполнение
quit               # Выйти из gdb
```

---

## **📁 Организация проектов**

### **Рекомендуемая структура для начинающих:**
```
my_project/
├── src/           # Исходные файлы (.cpp)
│   ├── main.cpp
│   └── utils.cpp
├── include/       # Заголовочные файлы (.h)
│   └── utils.h
├── bin/           # Исполняемые файлы (сюда компилируем)
├── obj/           # Объектные файлы (опционально)
└── Makefile       # Файл сборки
```

### **Makefile для такой структуры:**
```makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include
TARGET = bin/myapp
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
    @mkdir -p $(dir $@)
    $(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
    @mkdir -p $(dir $@)
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -rf $(OBJ_DIR) $(TARGET)

run: $(TARGET)
    ./$(TARGET)

.PHONY: all clean run
```

---

## **🚨 Частые проблемы и решения**

### **Проблема 1: "command not found: g++"**
```bash
# Решение: установить компилятор
sudo apt install g++
```

### **Проблема 2: "Permission denied" при запуске**
```bash
# Решение 1: Добавить флаг выполнения
chmod +x myprogram
./myprogram

# Решение 2: Запустить через bash
bash ./myprogram
```

### **Проблема 3: Ошибка "fatal error: iostream: No such file or directory"**
```bash
# Решение: Установить библиотеки разработки
sudo apt install build-essential
```

### **Проблема 4: Кириллица отображается некорректно**
```cpp
// В программе добавьте:
#include <iostream>
#include <locale>

int main() {
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());
    std::wcout << L"Привет, мир!" << std::endl;
    return 0;
}
```

### **Проблема 5: Программа сразу закрывается**
```cpp
// Добавьте в конец main():
#include <iostream>

int main() {
    std::cout << "Hello!" << std::endl;
    
    // Способ 1: Ожидание Enter
    std::cin.get();
    
    // Способ 2: Запуск из терминала
    // просто запускайте программу из терминала
    
    return 0;
}
```

---

## **🚀 Автоматизация: Полезные алиасы и скрипты**

### **Добавьте в ~/.bashrc:**
```bash
# Быстрая компиляция и запуск
alias cpprun='g++ -Wall -Wextra -std=c++17 -O2 -o /tmp/cpp_temp && /tmp/cpp_temp'

# Компиляция с основными флагами
alias g++='g++ -Wall -Wextra -std=c++17'

# Очистка временных файлов
alias cleanobj='find . -name "*.o" -delete; find . -name "*.out" -delete'
```

### **Скрипт для быстрой компиляции (cppc):**
```bash
#!/bin/bash
# Сохраните как ~/bin/cppc и сделайте исполняемым: chmod +x ~/bin/cppc

if [ $# -eq 0 ]; then
    echo "Использование: cppc файл.cpp [имя_программы]"
    exit 1
fi

INPUT_FILE="$1"
OUTPUT_NAME="${2:-a.out}"

echo "Компиляция $INPUT_FILE..."
g++ -Wall -Wextra -std=c++17 -O2 "$INPUT_FILE" -o "$OUTPUT_NAME"

if [ $? -eq 0 ]; then
    echo "Успешно! Запуск: ./$OUTPUT_NAME"
    ./"$OUTPUT_NAME"
else
    echo "Ошибка компиляции!"
fi
```

---

## **🎯 Пошаговый чеклист для первой программы**

1. **Откройте терминал** (Ctrl + Alt + T)
2. **Создайте папку** для проекта:
   ```bash
   mkdir ~/my_first_cpp
   cd ~/my_first_cpp
   ```
3. **Создайте файл** с программой:
   ```bash
   nano test.cpp
   ```
4. **Введите код**:
   ```cpp
   #include <iostream>
   
   int main() {
       std::cout << "Ура! Моя первая программа в Linux!" << std::endl;
       return 0;
   }
   ```
5. **Скомпилируйте**:
   ```bash
   g++ test.cpp -o test -Wall
   ```
6. **Запустите**:
   ```bash
   ./test
   ```
7. **Если видите вывод** — всё работает!

---

## **📚 Полезные советы**

1. **Всегда используйте `-Wall -Wextra`** — они помогут найти многие ошибки
2. **Сохраняйте Makefile** даже для маленьких проектов
3. **Используйте систему контроля версий Git**:
   ```bash
   sudo apt install git
   git init
   git add .
   git commit -m "First commit"
   ```
4. **Изучите основы командной строки** — это сэкономит массу времени
5. **Для сложных проектов** рассмотрите CMake

## **🆘 Где получить помощь?**

1. **Справка по командам:**
   ```bash
   man g++          # Руководство по g++
   g++ --help       # Краткая справка
   ```

2. **Онлайн ресурсы:**
   - [cppreference.com](https://en.cppreference.com) — документация по C++
   - [Stack Overflow](https://stackoverflow.com) — вопросы и ответы

3. **Локальная помощь в Ubuntu:**
   ```bash
   # Установите документацию
   sudo apt install cpp-doc gcc-doc
   ```

Разберём **оба Makefile** максимально подробно, буквально по каждой строке.

## **📁 Makefile 1: Простой проект (Calculator)**

### **Полный Makefile:**
```makefile
# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++11

# Имя исполняемого файла
TARGET = calculator

# Исходные файлы
SRCS = main.cpp math.cpp

# Объектные файлы (автоматически из SRCS)
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Компиляция .cpp в .o
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
    rm -f $(OBJS) $(TARGET)

# Пересборка
rebuild: clean all

# Запуск
run: $(TARGET)
    ./$(TARGET)

.PHONY: all clean rebuild run
```

---

## **📝 Построчное объяснение:**

### **Секция 1: Переменные (Variables)**

```makefile
# Компилятор
CXX = g++
```
- `#` — комментарий (игнорируется make)
- `CXX` — **стандартное имя переменной** для компилятора C++ (можно назвать как угодно, но это общепринято)
- `=` — оператор присваивания
- `g++` — значение переменной (имя компилятора)
- **Эквивалент в C++:** `std::string CXX = "g++";`

```makefile
# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++11
```
- `CXXFLAGS` — **стандартная переменная** для флагов компилятора C++
- `-Wall` — включить ВСЕ предупреждения (Warning all)
- `-Wextra` — дополнительные предупреждения
- `-std=c++11` — использовать стандарт C++11

```makefile
# Имя исполняемого файла
TARGET = calculator
```
- `TARGET` — имя конечной программы (после компиляции получится файл `calculator`)

```makefile
# Исходные файлы
SRCS = main.cpp math.cpp
```
- `SRCS` — список всех исходных файлов `.cpp` через пробел
- **Важно:** Порядок НЕ имеет значения для сборки

```makefile
# Объектные файлы (автоматически из SRCS)
OBJS = $(SRCS:.cpp=.o)
```
- `OBJS` — список объектных файлов
- `$(SRCS:.cpp=.o)` — **подстановка**: берёт значение `SRCS` и заменяет `.cpp` на `.o`
- **Результат:** `main.o math.o`

---

### **Секция 2: Правила (Rules)**

```makefile
# Правило по умолчанию
all: $(TARGET)
```
- `all:` — имя правила (цель/target)
- `$(TARGET)` — зависимости (prerequisites), раскрывается в `calculator`
- **Как работает:** Когда вы пишете `make all` (или просто `make`), make проверяет:
  1. Существует ли файл `calculator`?
  2. Если нет или он устарел → выполняется команда из правила `$(TARGET):`

```makefile
# Сборка исполняемого файла
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
```
- `$(TARGET): $(OBJS)` — правило для сборки `calculator` из объектных файлов
- **Синтаксис:** `цель: зависимости`
- **Табуляция!** Команды должны начинаться с TAB (не пробелов!)
- Команда: `g++ -Wall -Wextra -std=c++11 -o calculator main.o math.o`
  - `g++` — компилятор
  - `-o calculator` — имя выходного файла
  - `main.o math.o` — что линковать

```makefile
# Компиляция .cpp в .o
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
```
- `%.o: %.cpp` — **шаблонное правило** (pattern rule)
- `%` — подстановочный знак (wildcard)
- **Читается как:** "Любой файл `.o` зависит от соответствующего файла `.cpp`"
- **Примеры:**
  - `main.o: main.cpp`
  - `math.o: math.cpp`

**Автоматические переменные:**
- `$<` — имя **первой** зависимости (в нашем случае `.cpp` файл)
- `$@` — имя **цели** (в нашем случае `.o` файл)

**Разбор команды для `main.o`:**
```
g++ -Wall -Wextra -std=c++11 -c main.cpp -o main.o
```
- `-c` — "compile only" (скомпилировать, но не линковать)
- `main.cpp` — что компилировать (`$<`)
- `-o main.o` — куда сохранить (`$@`)

---

### **Секция 3: Вспомогательные правила**

```makefile
# Очистка
clean:
    rm -f $(OBJS) $(TARGET)
```
- `clean:` — правило без зависимостей
- Команда: `rm -f main.o math.o calculator`
  - `rm` — удалить файлы
  - `-f` — force (не спрашивать подтверждения)
- **Вызов:** `make clean`

```makefile
# Пересборка
rebuild: clean all
```
- `rebuild:` — фиктивная цель
- `clean all` — зависимости (выполнить clean, потом all)
- **Порядок важен:** сначала clean, потом all
- **Вызов:** `make rebuild`

```makefile
# Запуск
run: $(TARGET)
    ./$(TARGET)
```
- `run:` — зависит от `$(TARGET)`
- Если `calculator` не существует или устарел → сначала соберётся
- Команда: `./calculator`
- **Вызов:** `make run`

```makefile
.PHONY: all clean rebuild run
```
- `.PHONY:` — специальная директива
- Список целей, которые **НЕ являются файлами**
- **Зачем:** Предотвращает конфликты, если вдруг в папке есть файлы с именами `clean`, `all` и т.д.
- Без `.PHONY`: если файл `clean` существует, `make clean` ничего не сделает
- С `.PHONY`: `make clean` всегда выполнит команду, даже если файл `clean` существует

---

## **🔄 Как работает Make (пошагово):**

**Пример 1: Первая сборка**
```bash
make
# или
make all
```

1. Ищет правило `all:` → зависит от `calculator`
2. Ищет правило `calculator:` → зависит от `main.o math.o`
3. Ищет правило `main.o:` → файл `main.cpp` существует
   - Выполняет: `g++ -Wall -Wextra -std=c++11 -c main.cpp -o main.o`
4. Ищет правило `math.o:` → файл `math.cpp` существует
   - Выполняет: `g++ -Wall -Wextra -std=c++11 -c math.cpp -o math.o`
5. Все зависимости готовы → выполняет правило `calculator:`
   - Выполняет: `g++ -Wall -Wextra -std=c++11 -o calculator main.o math.o`

**Пример 2: Изменили только `main.cpp`**
```bash
# Редактируем main.cpp
make
```

1. `make` проверяет `all` → `calculator`
2. `calculator` зависит от `main.o math.o`
3. Проверяет `main.o`: `main.cpp` новее чем `main.o` → перекомпилирует
4. Проверяет `math.o`: `math.cpp` не менялся → пропускает
5. Собирает `calculator` с новым `main.o` и старым `math.o`

**Пример 3: Очистка**
```bash
make clean
```
- Просто выполняет команду: `rm -f main.o math.o calculator`

---

## **📁 Makefile 2: Продвинутый проект (со структурой папок)**

### **Полный Makefile:**
```makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include
TARGET = bin/myapp
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
    @mkdir -p $(dir $@)
    $(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
    @mkdir -p $(dir $@)
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -rf $(OBJ_DIR) $(TARGET)

run: $(TARGET)
    ./$(TARGET)

.PHONY: all clean run
```

---

## **📝 Разбор отличий от первого Makefile:**

### **Новые переменные:**

```makefile
CXXFLAGS = -Wall -Wextra -std=c++17 -I./include
```
- `-I./include` — добавить папку `include` в пути поиска заголовочных файлов
- **Зачем:** Чтобы `#include "myheader.h"` искался в `./include/`

```makefile
TARGET = bin/myapp
```
- Выходной файл будет в папке `bin/`

```makefile
SRC_DIR = src
OBJ_DIR = obj
```
- Отдельные папки для исходников и объектных файлов

```makefile
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
```
- `$(wildcard паттерн)` — функция, которая находит все файлы по шаблону
- `$(wildcard src/*.cpp)` → находит все `.cpp` файлы в папке `src/`
- **Пример результата:** `src/main.cpp src/utils.cpp src/parser.cpp`
- **Преимущество:** Не нужно вручную перечислять файлы

```makefile
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
```
- `$(patsubst шаблон,замена,текст)` — функция замены по шаблону
- Берёт `SRCS` (`src/main.cpp src/utils.cpp`)
- Заменяет `src/%.cpp` на `obj/%.o`
- **Результат:** `obj/main.o obj/utils.o`

---

### **Улучшенные правила:**

```makefile
$(TARGET): $(OBJS)
    @mkdir -p $(dir $@)
    $(CXX) $(CXXFLAGS) -o $@ $(OBJS)
```

**Новые элементы:**
- `@` перед командой — не выводить саму команду в терминал (только результат)
- `mkdir -p` — создать папку (если не существует)
  - `-p` — создавать все промежуточные папки
- `$(dir $@)` — функция, возвращающая директорию файла
  - `$@` = `bin/myapp`
  - `$(dir $@)` = `bin/`
- **Итого:** `mkdir -p bin/` → создаёт папку `bin` если её нет

```makefile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
    @mkdir -p $(dir $@)
    $(CXX) $(CXXFLAGS) -c $< -o $@
```

- `$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp` — шаблон с путями
- **Пример:** `obj/main.o: src/main.cpp`
- `@mkdir -p $(dir $@)` — создаёт папку `obj/` если нужно
- `$<` = `src/main.cpp` (исходник)
- `$@` = `obj/main.o` (цель)

```makefile
clean:
    rm -rf $(OBJ_DIR) $(TARGET)
```
- `-r` — рекурсивно (удалить папку со всем содержимым)
- `-f` — без подтверждения
- Удаляет всю папку `obj/` и файл `bin/myapp`

---

## **🎯 Сравнение двух подходов:**

| Аспект | Makefile 1 (Простой) | Makefile 2 (Продвинутый) |
|--------|----------------------|--------------------------|
| **Структура** | Все файлы в одной папке | Разделение `src/`, `include/`, `bin/`, `obj/` |
| **Перечисление файлов** | Вручную в `SRCS` | Автоматически через `wildcard` |
| **Поддержка новых файлов** | Добавлять вручную в `SRCS` | Достаточно создать файл в `src/` |
| **Пути к заголовкам** | В текущей папке | Явно указано `-I./include` |
| **Организация** | Проще для новичков | Профессиональнее, чище |

---

## **🔧 Дополнительные полезности для Makefile:**

### **Отладка Makefile:**
```bash
# Вывести значения переменных
make -p

# Вывести команды, но не выполнять
make -n

# Подробный вывод
make --debug
```

### **Автоматические переменные (полный список):**
- `$@` — имя цели (target)
- `$<` — первая зависимость
- `$^` — все зависимости (без дубликатов)
- `$+` — все зависимости (с дубликатами)
- `$?` — зависимости, которые новее цели
- `$*` — подстановочный знак `%`

### **Пример с `$^`:**
```makefile
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $^  # $^ = все .o файлы
```

---

## **🚨 Частые ошибки:**

### **Ошибка 1: Табуляция вместо пробелов**
```makefile
# НЕПРАВИЛЬНО (пробелы):
clean:
    rm -f *.o  # Make выдаст ошибку!

# ПРАВИЛЬНО (TAB):
clean:
    rm -f *.o   # TAB в начале строки!
```

### **Ошибка 2: Отсутствующие зависимости**
```makefile
# ПЛОХО: не пересоберётся при изменении заголовка
main.o: main.cpp
    $(CXX) -c main.cpp -o main.o

# ХОРОШО: добавить заголовки
main.o: main.cpp utils.h
    $(CXX) -c main.cpp -o main.o
```

### **Автоматическая генерация зависимостей:**
```makefile
# Генерирует .d файлы с зависимостями
DEPFLAGS = -MMD -MP
CXXFLAGS += $(DEPFLAGS)

# Включить .d файлы
-include $(OBJS:.o=.d)
```

---

## **🎯 Итоговый совет для новичков:**

1. **Начните с простого Makefile** (первый вариант)
2. **Поняв основы**, переходите к структурированному (второй вариант)
3. **Используйте `wildcard`** — экономит время
4. **Всегда добавляйте `.PHONY`**
5. **Тестируйте** все цели: `make`, `make clean`, `make run`

**Минимальный рабочий Makefile для начала:**
```makefile
CXX = g++
CXXFLAGS = -Wall -Wextra
TARGET = program
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) -o $@ $^

clean:
    rm -f $(OBJS) $(TARGET)

run: $(TARGET)
    ./$(TARGET)

.PHONY: all clean run
```

