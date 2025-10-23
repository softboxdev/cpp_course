# Практическое руководство: Создание и использование библиотек и модулей в C++ под Ubuntu 24.04

Это руководство демонстрирует полный цикл создания и использования статических и динамических библиотек в C++ под Ubuntu 24.04, включая обработку ошибок, документацию и систему сборки.

## 1. Установка необходимых инструментов

```bash
sudo apt update
sudo apt install g++ build-essential cmake make doxygen graphviz
```

## 2. Создание статической библиотеки

### Заголовочный файл `math_operations.h`:

```cpp
// Защита от множественного включения файла
#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

// Объявления функций математических операций

// Функция сложения двух целых чисел
int add(int a, int b);

// Функция вычитания двух целых чисел
int subtract(int a, int b);

// Функция умножения двух целых чисел
int multiply(int a, int b);

// Функция деления двух чисел с плавающей точкой
double divide(double a, double b);

// Функция вычисления факториала числа
unsigned long long factorial(int n);

// Функция проверки числа на простоту
bool is_prime(int number);

// Класс для работы с комплексными числами
class ComplexNumber {
private:
    double real_part;  // Действительная часть комплексного числа
    double imag_part;  // Мнимая часть комплексного числа

public:
    // Конструктор класса с параметрами по умолчанию
    ComplexNumber(double real = 0.0, double imag = 0.0);
    
    // Метод получения действительной части
    double get_real() const;
    
    // Метод получения мнимой части
    double get_imag() const;
    
    // Метод сложения двух комплексных чисел
    ComplexNumber add(const ComplexNumber& other) const;
    
    // Метод умножения двух комплексных чисел
    ComplexNumber multiply(const ComplexNumber& other) const;
    
    // Метод вывода комплексного числа в строку
    std::string to_string() const;
};

#endif // MATH_OPERATIONS_H
```

### Реализация библиотеки `math_operations.cpp`:

```cpp
// Подключаем собственный заголовочный файл
#include "math_operations.h"

// Подключаем стандартные библиотеки
#include <stdexcept>  // Для исключений
#include <sstream>    // Для работы со строками
#include <cmath>      // Для математических функций

// Реализация функции сложения
int add(int a, int b) {
    return a + b;  // Возвращаем сумму параметров
}

// Реализация функции вычитания
int subtract(int a, int b) {
    return a - b;  // Возвращаем разность параметров
}

// Реализация функции умножения
int multiply(int a, int b) {
    return a * b;  // Возвращаем произведение параметров
}

// Реализация функции деления
double divide(double a, double b) {
    // Проверяем деление на ноль
    if (b == 0.0) {
        // Генерируем исключение при делении на ноль
        throw std::runtime_error("Division by zero!");
    }
    return a / b;  // Возвращаем частное параметров
}

// Реализация функции вычисления факториала
unsigned long long factorial(int n) {
    // Проверяем корректность входного параметра
    if (n < 0) {
        throw std::invalid_argument("Factorial is not defined for negative numbers");
    }
    
    // Инициализируем результат
    unsigned long long result = 1;
    
    // Вычисляем факториал в цикле
    for (int i = 2; i <= n; ++i) {
        result *= i;  // Умножаем результат на текущее число
    }
    
    return result;  // Возвращаем вычисленный факториал
}

// Реализация функции проверки числа на простоту
bool is_prime(int number) {
    // Обрабатываем специальные случаи
    if (number <= 1) return false;    // Числа меньше 2 не простые
    if (number == 2) return true;     // 2 - простое число
    if (number % 2 == 0) return false; // Четные числа больше 2 не простые
    
    // Проверяем нечетные делители до квадратного корня
    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) {
            return false;  // Найден делитель - число не простое
        }
    }
    
    return true;  // Делителей не найдено - число простое
}

// Реализация методов класса ComplexNumber

// Конструктор класса
ComplexNumber::ComplexNumber(double real, double imag) 
    : real_part(real), imag_part(imag) {}  // Инициализация членов класса

// Метод получения действительной части
double ComplexNumber::get_real() const {
    return real_part;  // Возвращаем действительную часть
}

// Метод получения мнимой части
double ComplexNumber::get_imag() const {
    return imag_part;  // Возвращаем мнимую часть
}

// Метод сложения комплексных чисел
ComplexNumber ComplexNumber::add(const ComplexNumber& other) const {
    // Создаем новый объект с суммой соответствующих частей
    return ComplexNumber(real_part + other.real_part, 
                        imag_part + other.imag_part);
}

// Метод умножения комплексных чисел
ComplexNumber ComplexNumber::multiply(const ComplexNumber& other) const {
    // Вычисляем новую действительную часть
    double new_real = real_part * other.real_part - imag_part * other.imag_part;
    // Вычисляем новую мнимую часть
    double new_imag = real_part * other.imag_part + imag_part * other.real_part;
    // Возвращаем новый объект комплексного числа
    return ComplexNumber(new_real, new_imag);
}

// Метод преобразования в строку
std::string ComplexNumber::to_string() const {
    std::ostringstream oss;  // Создаем строковый поток
    oss << real_part;        // Добавляем действительную часть
    
    // Добавляем мнимую часть с соответствующим знаком
    if (imag_part >= 0) {
        oss << " + " << imag_part << "i";  // Положительная мнимая часть
    } else {
        oss << " - " << -imag_part << "i"; // Отрицательная мнимая часть
    }
    
    return oss.str();  // Возвращаем результирующую строку
}
```

## 3. Создание динамической библиотеки

### Заголовочный файл `string_operations.h`:

```cpp
#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <string>   // Для работы со строками
#include <vector>   // Для работы с векторами

// Макрос для экспорта символов библиотеки
#ifdef _WIN32
    #ifdef BUILDING_DLL
        #define DLL_EXPORT __declspec(dllexport)
    #else
        #define DLL_EXPORT __declspec(dllimport)
    #endif
#else
    #define DLL_EXPORT  // Для Linux ничего не делаем
#endif

// extern "C" для совместимости с C
extern "C" {
    // Функция переворачивания строки
    DLL_EXPORT void reverse_string(char* str);
    
    // Функция проверки палиндрома
    DLL_EXPORT bool is_palindrome(const char* str);
}

// Класс для работы со строками
class DLL_EXPORT StringProcessor {
private:
    std::string data;  // Внутреннее хранилище строки

public:
    // Конструктор из C-строки
    StringProcessor(const char* str = "");
    
    // Метод преобразования к верхнему регистру
    void to_uppercase();
    
    // Метод преобразования к нижнему регистру
    void to_lowercase();
    
    // Метод получения текущей строки
    std::string get_string() const;
    
    // Метод разбиения строки по разделителю
    std::vector<std::string> split(char delimiter) const;
    
    // Статический метод объединения строк
    static std::string join(const std::vector<std::string>& strings, 
                           const std::string& delimiter);
};

#endif // STRING_OPERATIONS_H
```

### Реализация динамической библиотеки `string_operations.cpp`:

```cpp
// Определяем макрос для экспорта
#define BUILDING_DLL

// Подключаем заголовочный файл
#include "string_operations.h"

// Подключаем необходимые библиотеки
#include <algorithm>  // Для алгоритмов STL
#include <cctype>     // Для функций работы с символами
#include <cstring>    // Для C-строковых функций

// Реализация C-функции переворота строки
void reverse_string(char* str) {
    // Проверяем валидность указателя
    if (str == nullptr) return;
    
    // Находим длину строки
    int length = std::strlen(str);
    
    // Переворачиваем строку с двух концов
    for (int i = 0; i < length / 2; ++i) {
        // Меняем симметричные символы местами
        std::swap(str[i], str[length - i - 1]);
    }
}

// Реализация C-функции проверки палиндрома
bool is_palindrome(const char* str) {
    // Проверяем валидность указателя
    if (str == nullptr) return false;
    
    // Находим длину строки
    int length = std::strlen(str);
    
    // Сравниваем симметричные символы
    for (int i = 0; i < length / 2; ++i) {
        if (str[i] != str[length - i - 1]) {
            return false;  // Найдено несоответствие - не палиндром
        }
    }
    
    return true;  // Все символы совпали - палиндром
}

// Реализация методов класса StringProcessor

// Конструктор класса
StringProcessor::StringProcessor(const char* str) : data(str ? str : "") {}

// Метод преобразования к верхнему регистру
void StringProcessor::to_uppercase() {
    // Применяем преобразование к каждому символу
    std::transform(data.begin(), data.end(), data.begin(),
                  [](unsigned char c) { return std::toupper(c); });
}

// Метод преобразования к нижнему регистру
void StringProcessor::to_lowercase() {
    // Применяем преобразование к каждому символу
    std::transform(data.begin(), data.end(), data.begin(),
                  [](unsigned char c) { return std::tolower(c); });
}

// Метод получения текущей строки
std::string StringProcessor::get_string() const {
    return data;  // Возвращаем копию внутренней строки
}

// Метод разбиения строки по разделителю
std::vector<std::string> StringProcessor::split(char delimiter) const {
    std::vector<std::string> result;  // Вектор для результата
    std::string token;               // Временная строка для токена
    std::istringstream stream(data); // Создаем поток из строки
    
    // Читаем токены до конца строки
    while (std::getline(stream, token, delimiter)) {
        result.push_back(token);  // Добавляем токен в результат
    }
    
    return result;  // Возвращаем вектор токенов
}

// Статический метод объединения строк
std::string StringProcessor::join(const std::vector<std::string>& strings, 
                                 const std::string& delimiter) {
    std::string result;  // Результирующая строка
    
    // Объединяем все строки через разделитель
    for (size_t i = 0; i < strings.size(); ++i) {
        result += strings[i];  // Добавляем текущую строку
        
        // Добавляем разделитель, если не последняя строка
        if (i != strings.size() - 1) {
            result += delimiter;
        }
    }
    
    return result;  // Возвращаем объединенную строку
}
```

## 4. Создание главной программы

### Файл `main.cpp`:

```cpp
// Подключаем стандартные библиотеки
#include <iostream>   // Для ввода-вывода
#include <iomanip>    // Для форматирования вывода

// Подключаем наши библиотеки
#include "math_operations.h"   // Статическая библиотека
#include "string_operations.h" // Динамическая библиотека

// Функция демонстрации математических операций
void demonstrate_math_operations() {
    std::cout << "=== ДЕМОНСТРАЦИЯ МАТЕМАТИЧЕСКИХ ОПЕРАЦИЙ ===" << std::endl;
    
    // Демонстрация базовых операций
    std::cout << "Базовые операции:" << std::endl;
    std::cout << "5 + 3 = " << add(5, 3) << std::endl;
    std::cout << "10 - 4 = " << subtract(10, 4) << std::endl;
    std::cout << "6 * 7 = " << multiply(6, 7) << std::endl;
    
    // Демонстрация деления с обработкой исключения
    try {
        std::cout << "15.0 / 3.0 = " << divide(15.0, 3.0) << std::endl;
        std::cout << "10.0 / 0.0 = " << divide(10.0, 0.0) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    
    // Демонстрация факториала
    std::cout << "\nФакториалы:" << std::endl;
    for (int i = 0; i <= 10; ++i) {
        std::cout << i << "! = " << factorial(i) << std::endl;
    }
    
    // Демонстрация проверки простых чисел
    std::cout << "\nПростые числа до 20:" << std::endl;
    for (int i = 1; i <= 20; ++i) {
        if (is_prime(i)) {
            std::cout << i << " - простое" << std::endl;
        }
    }
    
    // Демонстрация работы с комплексными числами
    std::cout << "\nКомплексные числа:" << std::endl;
    ComplexNumber num1(3.0, 4.0);   // Создаем первое комплексное число
    ComplexNumber num2(1.0, -2.0);  // Создаем второе комплексное число
    
    std::cout << "num1 = " << num1.to_string() << std::endl;
    std::cout << "num2 = " << num2.to_string() << std::endl;
    
    ComplexNumber sum = num1.add(num2);           // Сложение
    ComplexNumber product = num1.multiply(num2);  // Умножение
    
    std::cout << "Сумма: " << sum.to_string() << std::endl;
    std::cout << "Произведение: " << product.to_string() << std::endl;
}

// Функция демонстрации строковых операций
void demonstrate_string_operations() {
    std::cout << "\n=== ДЕМОНСТРАЦИЯ СТРОКОВЫХ ОПЕРАЦИЙ ===" << std::endl;
    
    // Демонстрация C-функций
    char test_str[] = "Hello World";  // Тестовая строка
    std::cout << "Исходная строка: " << test_str << std::endl;
    
    reverse_string(test_str);  // Переворачиваем строку
    std::cout << "Перевернутая строка: " << test_str << std::endl;
    
    // Проверка палиндромов
    const char* palindrome1 = "radar";
    const char* palindrome2 = "hello";
    
    std::cout << "\nПроверка палиндромов:" << std::endl;
    std::cout << palindrome1 << " - " 
              << (is_palindrome(palindrome1) ? "палиндром" : "не палиндром") 
              << std::endl;
    std::cout << palindrome2 << " - " 
              << (is_palindrome(palindrome2) ? "палиндром" : "не палиндром") 
              << std::endl;
    
    // Демонстрация класса StringProcessor
    std::cout << "\nРабота с классом StringProcessor:" << std::endl;
    StringProcessor processor("Hello,World,Test,String");  // Создаем процессор
    
    std::cout << "Исходная строка: " << processor.get_string() << std::endl;
    
    // Преобразование к верхнему регистру
    processor.to_uppercase();
    std::cout << "В верхнем регистре: " << processor.get_string() << std::endl;
    
    // Преобразование к нижнему регистру
    processor.to_lowercase();
    std::cout << "В нижнем регистре: " << processor.get_string() << std::endl;
    
    // Разбиение строки
    auto parts = processor.split(',');  // Разбиваем по запятой
    std::cout << "Разбиение строки:" << std::endl;
    for (size_t i = 0; i < parts.size(); ++i) {
        std::cout << "  Часть " << i << ": " << parts[i] << std::endl;
    }
    
    // Объединение строк
    std::vector<std::string> strings = {"Apple", "Banana", "Orange"};
    std::string joined = StringProcessor::join(strings, " | ");
    std::cout << "Объединенная строка: " << joined << std::endl;
}

// Главная функция программы
int main() {
    std::cout << "ПРИМЕР РАБОТЫ С БИБЛИОТЕКАМИ И МОДУЛЯМИ НА C++" << std::endl;
    std::cout << "=============================================" << std::endl;
    
    try {
        // Демонстрируем математические операции
        demonstrate_math_operations();
        
        // Демонстрируем строковые операции
        demonstrate_string_operations();
        
    } catch (const std::exception& e) {
        // Обрабатываем исключения
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1;  // Возвращаем код ошибки
    }
    
    std::cout << "\nПрограмма завершена успешно!" << std::endl;
    return 0;  // Успешное завершение
}
```

## 5. Создание Makefile для сборки

### Файл `Makefile`:

```makefile
# Компилятор и флаги
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -fPIC
LDFLAGS := -L. -lstring_operations

# Имена файлов
STATIC_LIB := libmath_operations.a
DYNAMIC_LIB := libstring_operations.so
MAIN_APP := library_demo

# Исходные файлы
MATH_SOURCES := math_operations.cpp
STRING_SOURCES := string_operations.cpp
MAIN_SOURCE := main.cpp

# Объектные файлы
MATH_OBJECTS := $(MATH_SOURCES:.cpp=.o)
STRING_OBJECTS := $(STRING_SOURCES:.cpp=.o)
MAIN_OBJECTS := $(MAIN_SOURCE:.cpp=.o)

# Правило по умолчанию
all: $(STATIC_LIB) $(DYNAMIC_LIB) $(MAIN_APP)

# Сборка статической библиотеки
$(STATIC_LIB): $(MATH_OBJECTS)
    ar rcs $@ $^  # Создаем архив статической библиотеки

# Сборка динамической библиотеки
$(DYNAMIC_LIB): $(STRING_OBJECTS)
    $(CXX) -shared -o $@ $^  # Создаем shared library

# Сборка главного приложения
$(MAIN_APP): $(MAIN_OBJECTS) $(STATIC_LIB) $(DYNAMIC_LIB)
    $(CXX) -o $@ $(MAIN_OBJECTS) -L. -lmath_operations -lstring_operations

# Компиляция объектных файлов для математической библиотеки
math_operations.o: math_operations.cpp math_operations.h
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Компиляция объектных файлов для строковой библиотеки
string_operations.o: string_operations.cpp string_operations.h
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Компиляция главного файла
main.o: main.cpp math_operations.h string_operations.h
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Установка библиотек в систему
install:
    sudo cp $(DYNAMIC_LIB) /usr/local/lib/
    sudo cp string_operations.h /usr/local/include/
    sudo cp math_operations.h /usr/local/include/
    sudo ldconfig  # Обновляем кэш библиотек

# Запуск приложения
run: $(MAIN_APP)
    LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH ./$(MAIN_APP)

# Очистка
clean:
    rm -f *.o *.a *.so $(MAIN_APP)

# Создание документации
doc:
    doxygen Doxyfile

# Отладочная сборка
debug: CXXFLAGS += -g -DDEBUG
debug: clean all

.PHONY: all clean run install debug doc
```

## 6. Создание файла конфигурации Doxygen

### Файл `Doxyfile`:

```
# Базовые настройки проекта
PROJECT_NAME           = "Math and String Libraries"
PROJECT_NUMBER         = 1.0
PROJECT_BRIEF          = "Пример создания библиотек на C++"

# Настройки вывода
OUTPUT_DIRECTORY       = docs
CREATE_SUBDIRS         = NO
ALLOW_UNICODE_NAMES    = YES

# Настройки извлечения
EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = YES
EXTRACT_STATIC         = YES

# Настройки исходного кода
INPUT                  = .
FILE_PATTERNS          = *.h *.cpp
RECURSIVE              = NO

# Настройки генерации
GENERATE_HTML          = YES
GENERATE_LATEX         = NO
GENERATE_TREEVIEW      = YES

# Настройки диаграмм
HAVE_DOT               = YES
CALL_GRAPH             = YES
CALLER_GRAPH           = YES
```

## 7. Инструкция по использованию

### Компиляция и запуск:

```bash
# Делаем Makefile исполняемым
chmod +x Makefile

# Собираем все компоненты
make all

# Запускаем приложение
make run

# Или запускаем напрямую
LD_LIBRARY_PATH=. ./library_demo
```

### Отдельные команды:

```bash
# Только статическая библиотека
make libmath_operations.a

# Только динамическая библиотека  
make libstring_operations.so

# Очистка
make clean

# Создание документации
make doc

# Установка в систему (требует sudo)
make install
```

### Проверка библиотек:

```bash
# Просмотр символов в статической библиотеке
nm libmath_operations.a

# Просмотр информации о динамической библиотеке
ldd libstring_operations.so

# Проверка зависимостей исполняемого файла
ldd library_demo
```

