# Модель памяти и хранение данных в C/C++

## 1. Стек, куча, статическая память, жизненный цикл переменных

### **Стек (Stack)**
```c
void stackExample() {
    int a = 10;          // Локальная переменная в стеке
    double b = 20.5;     // Ещё одна в стеке
    // Автоматическое освобождение при выходе из функции
}
```
**Характеристики:**
- Автоматическое управление памятью (LIFO)
- Быстрый доступ
- Ограниченный размер (~1-8 МБ)
- Хранит локальные переменные и параметры функций

### **Статическая память**
```c
static int globalVar = 100;    // Статическая глобальная переменная

void function() {
    static int counter = 0;    // Статическая локальная переменная
    counter++;
    // Сохраняет значение между вызовами функции
}
```
**Характеристики:**
- Существует всю программу
- Инициализируется при запуске программы
- Нулевыми значениями по умолчанию

### **Куча (Heap/Динамическая память)**
```c
int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));  // Выделение в куче
    // Память существует пока не освобождена явно
    return arr;
}
```
**Характеристики:**
- Ручное управление (malloc/free, new/delete)
- Большой размер (ограничен ОЗУ)
- Медленнее стека
- Гибкое распределение

## 2. Указатели

```c
int main() {
    int value = 42;
    int* ptr = &value;     // Указатель на value
    
    *ptr = 100;            // Изменение через указатель
    int** ptr2 = &ptr;     // Указатель на указатель
    
    // Арифметика указателей
    int arr[5] = {1, 2, 3, 4, 5};
    int* arrPtr = arr;
    *(arrPtr + 2) = 10;    // arr[2] = 10
}
```

## 3. Динамическая память

### **C стиль**
```c
#include <stdlib.h>

void dynamicMemoryC() {
    // Выделение памяти
    int* numbers = (int*)malloc(10 * sizeof(int));
    int* initialized = (int*)calloc(10, sizeof(int)); // Инициализация нулями
    
    // Изменение размера
    numbers = (int*)realloc(numbers, 20 * sizeof(int));
    
    // Освобождение памяти
    free(numbers);
    free(initialized);
}
```

### **C++ стиль**
```cpp
#include <memory>

void dynamicMemoryCPP() {
    // Одиночные объекты
    int* single = new int(42);
    delete single;
    
    // Массивы
    int* array = new int[10];
    delete[] array;
    
    // Умные указатели (рекомендуется)
    std::unique_ptr<int> smartPtr = std::make_unique<int>(100);
    std::shared_ptr<int> shared = std::make_shared<int>(200);
}
```

## 4. Строки

### **C строки**
```c
#include <string.h>

void cStrings() {
    char str1[20] = "Hello";
    char* str2 = (char*)malloc(20);
    
    strcpy(str2, "World");      // Копирование
    strcat(str1, " World");     // Конкатенация
    size_t len = strlen(str1);  // Длина строки
    
    free(str2);
}
```

### **C++ строки**
```cpp
#include <string>

void cppStrings() {
    std::string str = "Hello";
    str += " World";           // Конкатенация
    
    // Методы
    str.size();               // Длина
    str.find("World");        // Поиск
    str.substr(6, 5);         // Подстрока
    
    // C совместимость
    const char* cstr = str.c_str();
}
```

## 5. Работа с файлами

### **C стиль**
```c
#include <stdio.h>

void fileOperationsC() {
    FILE* file = fopen("data.txt", "w");
    if (file) {
        fprintf(file, "Hello File!\n");
        fclose(file);
    }
    
    // Чтение
    file = fopen("data.txt", "r");
    if (file) {
        char buffer[100];
        while (fgets(buffer, 100, file)) {
            printf("%s", buffer);
        }
        fclose(file);
    }
}
```

### **C++ стиль**
```cpp
#include <fstream>
#include <iostream>

void fileOperationsCPP() {
    // Запись
    std::ofstream outFile("data.txt");
    if (outFile.is_open()) {
        outFile << "Hello File!" << std::endl;
        outFile.close();
    }
    
    // Чтение
    std::ifstream inFile("data.txt");
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
}
```

## 6. Анализ использования памяти и Valgrind

### **Установка Valgrind**
```bash
# Ubuntu/Debian
sudo apt-get install valgrind

# Fedora/RHEL
sudo dnf install valgrind

# macOS
brew install valgrind
```

### **Основные команды Valgrind**

```bash
# Проверка утечек памяти
valgrind --leak-check=full ./your_program

# Проверка на ошибки памяти
valgrind --tool=memcheck ./your_program

# Детальный анализ
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./your_program

# Проверка использования неинициализированной памяти
valgrind --tool=memcheck --track-origins=yes ./your_program
```

### **Пример программы с утечками для тестирования**
```c
#include <stdlib.h>
#include <string.h>

void memoryLeaksExample() {
    // Утечка памяти
    int* leak = (int*)malloc(100 * sizeof(int));
    // Не освобождаем!
    
    // Использование после освобождения
    int* useAfterFree = (int*)malloc(sizeof(int));
    free(useAfterFree);
    *useAfterFree = 42;  // Ошибка!
    
    // Выход за границы массива
    int* buffer = (int*)malloc(10 * sizeof(int));
    buffer[10] = 5;      // Выход за границы
    free(buffer);
    
    // Двойное освобождение
    int* doubleFree = (int*)malloc(sizeof(int));
    free(doubleFree);
    free(doubleFree);    // Двойное освобождение
}

int main() {
    memoryLeaksExample();
    return 0;
}
```

### **Анализ с Valgrind**
```bash
# Компилируем с отладочной информацией
gcc -g -o test_program test.c

# Запускаем Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./test_program
```

### **Интерпретация результатов Valgrind**

Типичный вывод:
```
==12345== ERROR SUMMARY: 3 errors from 3 contexts
==12345== 
==12345== 100 bytes in 1 blocks are definitely lost
==12345==    at 0x483B7F3: malloc (vg_replace_malloc.c:307)
==12345==    by 0x109123: memoryLeaksExample (test.c:6)
```

**Ключевые сообщения:**
- **"definitely lost"** - гарантированная утечка
- **"indirectly lost"** - косвенная утечка
- **"possibly lost"** - возможная утечка
- **"Invalid read/write"** - обращение к невалидной памяти
- **"Use after free"** - использование после освобождения

### **Лучшие практики работы с памятью**

1. **Для C++:**
```cpp
// Используйте умные указатели
auto ptr = std::make_unique<MyClass>();
auto shared = std::make_shared<MyClass>();

// Используйте контейнеры STL
std::vector<int> vec;
std::string str;
```

2. **Для C:**
```c
// Всегда проверяйте результат malloc
int* ptr = malloc(size);
if (ptr == NULL) {
    // Обработка ошибки
}

// Освобождайте в обратном порядке выделению
void cleanup() {
    free(ptr3);
    free(ptr2);
    free(ptr1);
}

// Используйте инструменты статического анализа
// cppcheck, clang-tidy, PVS-Studio
```

3. **Общие рекомендации:**
```cpp
// 1. RAII (Resource Acquisition Is Initialization)
class FileHandler {
    FILE* file;
public:
    FileHandler(const char* name) : file(fopen(name, "r")) {}
    ~FileHandler() { if(file) fclose(file); }
};

// 2. Правило нуля/трех/пяти
class RuleOfFive {
    int* data;
public:
    // Конструктор, деструктор, копирование, перемещение
    RuleOfFive() : data(new int[100]) {}
    ~RuleOfFive() { delete[] data; }
    RuleOfFive(const RuleOfFive& other); // Копирующий
    RuleOfFive& operator=(const RuleOfFive& other);
    RuleOfFive(RuleOfFive&& other) noexcept; // Перемещающий
    RuleOfFive& operator=(RuleOfFive&& other) noexcept;
};

// 3. Используйте автоматический анализ
// Включайте sanitizers при компиляции
// gcc/clang: -fsanitize=address,undefined
```

### **Практическое задание для закрепления**

1. Напишите программу с утечками памяти разных типов
2. Проанализируйте её с Valgrind
3. Исправьте все найденные ошибки
4. Напишите аналогичную программу на C++ с умными указателями
5. Сравните производительность и безопасность подходов

### **Дополнительные инструменты**

```bash
# Massif для анализа использования памяти во времени
valgrind --tool=massif ./your_program
ms_print massif.out.12345

# Cachegrind для анализа кэша
valgrind --tool=cachegrind ./your_program
cg_annotate cachegrind.out.12345

# Helgrind для анализа многопоточности
valgrind --tool=helgrind ./your_program
```

Эта структура охватывает все указанные темы и предоставляет практические примеры для понимания модели памяти и инструментов отладки.