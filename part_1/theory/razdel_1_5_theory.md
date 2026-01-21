
# Функции в C++: подробное объяснение

## 1. Что такое функция и зачем она нужна?

**Функция** - это именованный блок кода, который выполняет определенную задачу и может быть вызван из других частей программы.

**Зачем нужны функции:**
- Повторное использование кода (не копируем один и тот же код)
- Упрощение программы (разбиваем на логические части)
- Улучшение читаемости
- Облегчение отладки и тестирования

## 2. Объявление и определение функции

### Объявление функции (прототип)
```cpp
// Объявление (прототип) функции
// Сообщает компилятору о существовании функции
int sum(int a, int b);  // точка с запятой в конце!
```

### Определение функции
```cpp
// Определение функции
// Содержит фактическую реализацию
int sum(int a, int b) {  // фигурные скобки
    return a + b;
}
```

### Полный пример
```cpp
#include <iostream>
using namespace std;

// 1. Объявление функций (прототипы)
int sum(int a, int b);
void printMessage();

int main() {
    // Вызов функции
    int result = sum(5, 3);
    cout << "Сумма: " << result << endl;
    
    printMessage();
    
    return 0;
}

// 2. Определение функции sum
int sum(int a, int b) {
    return a + b;  // возвращаем результат
}

// 3. Определение функции printMessage
void printMessage() {
    cout << "Привет из функции!" << endl;
    // Функция void ничего не возвращает
}
```

## 3. Параметры по значению (Value Parameters)

**Параметр по значению** создает КОПИЮ передаваемого значения. Изменения параметра внутри функции НЕ влияют на оригинальную переменную.

```cpp
#include <iostream>
using namespace std;

// Параметры по значению
void incrementByValue(int x) {
    x = x + 10;  // изменяем КОПИЮ
    cout << "Внутри функции: x = " << x << endl;
}

int main() {
    int number = 5;
    
    cout << "До вызова функции: number = " << number << endl;
    
    incrementByValue(number);  // передаем КОПИЮ значения
    
    cout << "После вызова функции: number = " << number << endl;
    // number остался равен 5, потому что функция работала с копией
    
    return 0;
}

/*
Вывод:
До вызова функции: number = 5
Внутри функции: x = 15
После вызова функции: number = 5
*/
```

## 4. Параметры по ссылке (Reference Parameters)

**Параметр по ссылке** работает с ОРИГИНАЛЬНОЙ переменной. Изменения параметра внутри функции влияют на оригинальную переменную.

```cpp
#include <iostream>
using namespace std;

// Параметр по ссылке (знак &)
void incrementByReference(int &x) {
    x = x + 10;  // изменяем ОРИГИНАЛ
    cout << "Внутри функции: x = " << x << endl;
}

// Пример с обменом значений
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int number = 5;
    
    cout << "До вызова функции: number = " << number << endl;
    
    incrementByReference(number);  // передаем ССЫЛКУ на переменную
    
    cout << "После вызова функции: number = " << number << endl;
    // number изменился на 15!
    
    // Пример с обменом значений
    int x = 10, y = 20;
    cout << "\nДо swap: x = " << x << ", y = " << y << endl;
    
    swap(x, y);  // передаем ссылки на x и y
    
    cout << "После swap: x = " << x << ", y = " << y << endl;
    
    return 0;
}

/*
Вывод:
До вызова функции: number = 5
Внутри функции: x = 15
После вызова функции: number = 15

До swap: x = 10, y = 20
После swap: x = 20, y = 10
*/
```

## 5. Константные параметры (Const Parameters)

**Константные параметры** гарантируют, что функция не изменит переданное значение.

```cpp
#include <iostream>
using namespace std;

// Константный параметр по ссылке
// Эффективно (не создает копию) и безопасно (не изменяет оригинал)
void printArray(const int arr[], int size) {
    // arr[] - передача массива по ссылке (фактически по указателю)
    // const гарантирует, что массив не будет изменен
    
    cout << "Массив: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        // arr[i] = 0;  // ОШИБКА! Нельзя изменить константный массив
    }
    cout << endl;
}

// Константная ссылка на int
void printValue(const int &value) {
    cout << "Значение: " << value << endl;
    // value = 100;  // ОШИБКА! Нельзя изменить константную ссылку
}

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int x = 42;
    
    printArray(numbers, 5);
    printValue(x);
    
    return 0;
}
```

## 6. Возвращаемые значения

Функции могут возвращать значения или не возвращать ничего (`void`).

```cpp
#include <iostream>
using namespace std;

// Возвращает int
int add(int a, int b) {
    return a + b;
}

// Возвращает double
double average(int a, int b) {
    return (a + b) / 2.0;  // 2.0 для вещественного деления
}

// Возвращает bool
bool isEven(int number) {
    return (number % 2 == 0);
}

// Возвращает указатель на массив (продвинутая тема)
int* createArray(int size) {
    int* arr = new int[size];  // выделяем память
    for(int i = 0; i < size; i++) {
        arr[i] = i * i;  // заполняем квадратами чисел
    }
    return arr;  // возвращаем указатель
}

// Ничего не возвращает
void printStars(int count) {
    for(int i = 0; i < count; i++) {
        cout << "* ";
    }
    cout << endl;
}

int main() {
    int sum = add(10, 20);
    cout << "Сумма: " << sum << endl;
    
    double avg = average(10, 20);
    cout << "Среднее: " << avg << endl;
    
    cout << "Число 5 четное? " << (isEven(5) ? "Да" : "Нет") << endl;
    
    printStars(5);
    
    // Работа с возвращаемым указателем
    int* myArray = createArray(5);
    cout << "Созданный массив: ";
    for(int i = 0; i < 5; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;
    
    delete[] myArray;  // освобождаем память!
    
    return 0;
}
```

## 7. Рекурсия

**Рекурсия** - когда функция вызывает саму себя. Должна иметь условие выхода!

### Пример 1: Факториал
```cpp
#include <iostream>
using namespace std;

// Рекурсивная функция для вычисления факториала
// n! = n * (n-1) * (n-2) * ... * 1
// 0! = 1
int factorial(int n) {
    // Базовый случай (условие выхода из рекурсии)
    if(n <= 1) {
        return 1;
    }
    // Рекурсивный случай
    return n * factorial(n - 1);
}

int main() {
    int n = 5;
    cout << "Факториал " << n << " = " << factorial(n) << endl;
    
    // Как это работает для factorial(5):
    // factorial(5) = 5 * factorial(4)
    // factorial(4) = 4 * factorial(3)
    // factorial(3) = 3 * factorial(2)
    // factorial(2) = 2 * factorial(1)
    // factorial(1) = 1  ← базовый случай!
    // Затем все возвращается назад:
    // factorial(2) = 2 * 1 = 2
    // factorial(3) = 3 * 2 = 6
    // factorial(4) = 4 * 6 = 24
    // factorial(5) = 5 * 24 = 120
    
    return 0;
}
```

### Пример 2: Числа Фибоначчи
```cpp
#include <iostream>
using namespace std;

// Рекурсивная функция для чисел Фибоначчи
// F(0) = 0, F(1) = 1
// F(n) = F(n-1) + F(n-2)
int fibonacci(int n) {
    // Базовые случаи
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    // Рекурсивный случай
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "Числа Фибоначчи: ";
    for(int i = 0; i < 10; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    
    return 0;
}
```

### Пример 3: Рекурсивный поиск в массиве
```cpp
#include <iostream>
using namespace std;

// Рекурсивный поиск максимума в массиве
int findMax(int arr[], int start, int end) {
    // Базовый случай: один элемент
    if(start == end) {
        return arr[start];
    }
    
    // Рекурсивный случай
    int mid = (start + end) / 2;
    int max1 = findMax(arr, start, mid);      // максимум в левой половине
    int max2 = findMax(arr, mid + 1, end);    // максимум в правой половине
    
    // Возвращаем больший из двух максимумов
    return (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {3, 7, 2, 9, 1, 4, 6, 8, 5};
    int size = 9;
    
    int max = findMax(arr, 0, size - 1);
    cout << "Максимальный элемент: " << max << endl;
    
    return 0;
}
```

## 8. Параметры по умолчанию

```cpp
#include <iostream>
using namespace std;

// Функция с параметрами по умолчанию
void printInfo(string name, int age = 18, string city = "Москва") {
    cout << "Имя: " << name << endl;
    cout << "Возраст: " << age << endl;
    cout << "Город: " << city << endl;
    cout << "---" << endl;
}

int main() {
    // Можно вызывать функцию с разным количеством параметров
    printInfo("Анна", 25, "Санкт-Петербург");
    printInfo("Иван", 30);          // city будет "Москва" по умолчанию
    printInfo("Мария");             // age=18, city="Москва" по умолчанию
    
    // Важно: параметры по умолчанию должны идти в конце списка
    // void printInfo(string name = "Гость", int age, string city) - ОШИБКА!
    
    return 0;
}
```

## 9. Перегрузка функций

```cpp
#include <iostream>
using namespace std;

// Перегрузка функций - несколько функций с одним именем,
// но разными параметрами

// 1. Сложение двух целых чисел
int add(int a, int b) {
    return a + b;
}

// 2. Сложение трех целых чисел
int add(int a, int b, int c) {
    return a + b + c;
}

// 3. Сложение двух вещественных чисел
double add(double a, double b) {
    return a + b;
}

// 4. Конкатенация строк
string add(string a, string b) {
    return a + b;
}

int main() {
    cout << "add(5, 3) = " << add(5, 3) << endl;          // вызов 1-й функции
    cout << "add(5, 3, 2) = " << add(5, 3, 2) << endl;    // вызов 2-й функции
    cout << "add(3.14, 2.71) = " << add(3.14, 2.71) << endl; // вызов 3-й функции
    cout << "add(\"Hello, \", \"World!\") = " 
         << add(string("Hello, "), string("World!")) << endl; // вызов 4-й функции
    
    return 0;
}
```

## Практические задания

### Задание 1: Калькулятор
Создайте функции для всех арифметических операций (+, -, *, /).

### Задание 2: Работа с массивами
Создайте функции для:
- Поиска минимума/максимума
- Вычисления среднего значения
- Реверсирования массива

### Задание 3: Рекурсивные задачи
1. Вычисление суммы цифр числа
2. Проверка палиндрома (слово, которое читается одинаково слева направо)
3. Быстрое возведение в степень

### Задание 4: Функции с разными типами параметров
Создайте функцию, которая принимает параметры по значению, по ссылке и по константной ссылке, и продемонстрируйте разницу.

## Важные правила и советы

1. **Одна функция - одна задача**
2. **Именуйте функции глаголами** (calculate, print, find, etc.)
3. **Избегайте глобальных переменных** - передавайте данные через параметры
4. **Рекурсия должна иметь условие выхода!**
5. **Используйте const** для параметров, которые не должны изменяться
6. **Для больших объектов** (структуры, классы, массивы) передавайте по ссылке
7. **Для простых типов** (int, double, char) можно передавать по значению

## Типичные ошибки

```cpp
// 1. Бесконечная рекурсия (нет условия выхода)
void infiniteRecursion(int x) {
    infiniteRecursion(x + 1);  // ОШИБКА! Никогда не закончится
}

// 2. Изменение константного параметра
void print(const int &x) {
    x = 10;  // ОШИБКА! x - константная ссылка
}

// 3. Возврат ссылки на локальную переменную
int& badFunction() {
    int x = 10;
    return x;  // ОШИБКА! x уничтожится после выхода из функции
}
```

Функции - это строительные блоки программ на C++. Освоив их, вы сможете создавать хорошо структурированные, читаемые и поддерживаемые программы!

# Все виды синтаксиса параметров функций в C++

## Полный обзор синтаксиса параметров

### 1. **Параметры по значению (Pass by Value)**

#### **Базовый синтаксис:**
```cpp
// Простой тип
void function(int parameter) { /* ... */ }

// Несколько параметров
void function(int a, double b, char c) { /* ... */ }

// Указатель как значение (копируется указатель, не данные)
void function(int* ptr) { /* ... */ }
```

#### **Полный пример:**
```cpp
#include <iostream>

// 1. Простые типы по значению
void simpleByValue(int num, double price, char grade) {
    // Все параметры - локальные копии
    num = 100;          // Меняется только копия
    price = 99.99;      // Меняется только копия
    grade = 'A';        // Меняется только копия
    
    std::cout << "Внутри функции: " << num << ", " << price << ", " << grade << std::endl;
}

// 2. Указатель по значению
void pointerByValue(int* ptr) {
    // ptr - копия указателя, указывает на те же данные
    *ptr = 100;         // Меняем данные по адресу
    ptr = nullptr;      // Меняем только копию указателя
}

// 3. Массив по значению (на самом деле передается как указатель!)
void arrayByValue(int arr[5]) {  // Размер игнорируется!
    // arr на самом деле int* - указатель на первый элемент
    arr[0] = 100;       // Меняет оригинальный массив!
}

// 4. Структура по значению (полное копирование)
struct Point {
    int x, y;
};

void structByValue(Point p) {
    p.x = 100;          // Меняется только копия
    p.y = 200;
}

int main() {
    int a = 5;
    double b = 10.5;
    char c = 'B';
    
    std::cout << "До вызова: " << a << ", " << b << ", " << c << std::endl;
    simpleByValue(a, b, c);
    std::cout << "После вызова: " << a << ", " << b << ", " << c << std::endl;
    
    // Пример с указателем
    int value = 50;
    int* ptr = &value;
    pointerByValue(ptr);
    std::cout << "value после pointerByValue: " << value << std::endl;
    
    // Пример с массивом
    int arr[5] = {1, 2, 3, 4, 5};
    arrayByValue(arr);
    std::cout << "arr[0] после arrayByValue: " << arr[0] << std::endl;
    
    // Пример со структурой
    Point point = {10, 20};
    structByValue(point);
    std::cout << "point после structByValue: (" << point.x << ", " << point.y << ")" << std::endl;
    
    return 0;
}
```

### 2. **Параметры по ссылке (Pass by Reference)**

#### **Базовый синтаксис:**
```cpp
// Ссылка на простой тип
void function(int& ref) { /* ... */ }

// Ссылка на константу
void function(const int& ref) { /* ... */ }

// Ссылка на указатель
void function(int*& refPtr) { /* ... */ }

// Ссылка на массив с размером
void function(int (&refArr)[5]) { /* ... */ }
```

#### **Полный пример со всеми видами ссылок:**
```cpp
#include <iostream>
#include <array>

// 1. Обычная ссылка (можем изменять)
void modifyByReference(int& ref) {
    ref *= 2;  // Меняем оригинальное значение
}

// 2. Константная ссылка (только для чтения)
void readByConstReference(const int& cref) {
    // cref *= 2;  // ОШИБКА: нельзя изменять константную ссылку
    std::cout << "Значение: " << cref << std::endl;
}

// 3. Ссылка на указатель
void modifyPointer(int*& ptrRef) {
    static int newValue = 100;
    ptrRef = &newValue;  // Меняем сам указатель
}

// 4. Ссылка на константный указатель
void readPointer(const int* const& constPtrRef) {
    // constPtrRef - константная ссылка на константный указатель
    // Нельзя изменить ни указатель, ни данные
    std::cout << "Значение по указателю: " << *constPtrRef << std::endl;
}

// 5. Ссылка на массив фиксированного размера
void processArray(int (&arrRef)[5]) {  // Должен совпадать размер!
    for(int i = 0; i < 5; i++) {
        arrRef[i] *= 2;  // Меняем оригинальный массив
    }
}

// 6. Ссылка на многомерный массив
void processMatrix(int (&matrixRef)[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matrixRef[i][j] += 1;
        }
    }
}

// 7. Ссылка на структуру
struct Data {
    int id;
    std::string name;
};

void modifyStruct(Data& dataRef) {
    dataRef.id = 100;
    dataRef.name = "Modified";
}

// 8. Константная ссылка на структуру
void printStruct(const Data& dataRef) {
    std::cout << "ID: " << dataRef.id << ", Name: " << dataRef.name << std::endl;
}

int main() {
    // 1. Обычная ссылка
    int x = 5;
    modifyByReference(x);
    std::cout << "x после modifyByReference: " << x << std::endl;
    
    // 2. Константная ссылка
    readByConstReference(x);
    
    // 3. Ссылка на указатель
    int* ptr = &x;
    modifyPointer(ptr);
    std::cout << "*ptr после modifyPointer: " << *ptr << std::endl;
    
    // 4. Константная ссылка на константный указатель
    const int* constPtr = &x;
    readPointer(constPtr);
    
    // 5. Ссылка на массив
    int arr[5] = {1, 2, 3, 4, 5};
    processArray(arr);
    std::cout << "arr после processArray: ";
    for(int val : arr) std::cout << val << " ";
    std::cout << std::endl;
    
    // 6. Ссылка на многомерный массив
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    processMatrix(matrix);
    std::cout << "matrix[1][1] после processMatrix: " << matrix[1][1] << std::endl;
    
    // 7-8. Ссылки на структуры
    Data data = {1, "Original"};
    modifyStruct(data);
    printStruct(data);
    
    return 0;
}
```

### 3. **Комбинированные варианты**

#### **Смешанные параметры:**
```cpp
#include <iostream>

// Комбинация разных типов параметров
void mixedParameters(
    int byValue,           // По значению
    int& byRef,            // По ссылке
    const int& byConstRef, // По константной ссылке
    int* byPtrValue,       // Указатель по значению
    int*& byPtrRef,        // Ссылка на указатель
    const int* const& constPtrConstRef  // Константная ссылка на константный указатель
) {
    // Можем изменить: byRef, *byPtrValue, byPtrRef
    // Не можем изменить: byValue, byConstRef, constPtrConstRef
    
    byValue = 0;           // Меняем копию
    byRef = 1;             // Меняем оригинал
    // byConstRef = 2;     // Ошибка
    
    *byPtrValue = 3;       // Меняем данные по указателю
    byPtrValue = nullptr;  // Меняем копию указателя
    
    *byPtrRef = 4;         // Меняем данные по указателю
    byPtrRef = nullptr;    // Меняем сам указатель
    
    // *constPtrConstRef = 5;  // Ошибка
    // constPtrConstRef = nullptr;  // Ошибка
}

int main() {
    int a = 10, b = 20, c = 30;
    int* ptr1 = &b;
    int* ptr2 = &c;
    const int* const constPtr = &a;
    
    mixedParameters(a, b, c, ptr1, ptr2, constPtr);
    
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    std::cout << "*ptr1 = " << (ptr1 ? *ptr1 : 0) << std::endl;
    std::cout << "*ptr2 = " << (ptr2 ? *ptr2 : 0) << std::endl;
    
    return 0;
}
```

### 4. **Специальные синтаксисы C++11 и новее**

#### **Rvalue-ссылки (C++11):**
```cpp
#include <iostream>
#include <utility>

// Rvalue-ссылка (только для временных объектов)
void processRvalue(int&& rref) {
    std::cout << "Обработка rvalue: " << rref << std::endl;
}

// Универсальная ссылка (шаблон)
template<typename T>
void universalReference(T&& uref) {
    std::cout << "Универсальная ссылка: " << uref << std::endl;
}

// Perfect forwarding (идеальная передача)
template<typename T>
void wrapper(T&& arg) {
    // std::forward сохраняет категорию значения (lvalue/rvalue)
    processRvalue(std::forward<T>(arg));
}

int main() {
    int x = 42;
    
    // processRvalue(x);        // Ошибка: x - lvalue
    processRvalue(100);        // OK: 100 - rvalue
    processRvalue(std::move(x)); // OK: x превращен в rvalue
    
    universalReference(x);     // OK: выводится как int&
    universalReference(200);   // OK: выводится как int&&
    
    wrapper(300);              // Perfect forwarding
    
    return 0;
}
```

#### **Параметры по умолчанию:**
```cpp
#include <iostream>

// Параметры по умолчанию
void defaultParameters(
    int required,
    int optional1 = 10,        // Значение по умолчанию
    double optional2 = 3.14,
    const char* optional3 = "default"
) {
    std::cout << required << ", " << optional1 << ", " 
              << optional2 << ", " << optional3 << std::endl;
}

// Параметры по умолчанию только в конце!
// void badExample(int a = 1, int b) {}  // ОШИБКА

int main() {
    defaultParameters(1);                    // 1, 10, 3.14, "default"
    defaultParameters(1, 20);                // 1, 20, 3.14, "default"
    defaultParameters(1, 20, 2.71);          // 1, 20, 2.71, "default"
    defaultParameters(1, 20, 2.71, "custom"); // 1, 20, 2.71, "custom"
    
    return 0;
}
```

#### **Variadic templates (переменное число параметров):**
```cpp
#include <iostream>

// Базовый случай рекурсии
void printAll() {
    std::cout << std::endl;
}

// Шаблон с переменным числом параметров
template<typename T, typename... Args>
void printAll(T first, Args... args) {
    std::cout << first << " ";
    printAll(args...);  // Рекурсивный вызов
}

// Fold expressions (C++17)
template<typename... Args>
void printAllFold(Args... args) {
    (std::cout << ... << args) << std::endl;  // Унарная свертка
}

int main() {
    printAll(1, 2.5, "hello", 'A');          // 1 2.5 hello A
    printAllFold(1, 2.5, "hello", 'A');      // 12.5helloA
    
    return 0;
}
```

### 5. **Указатели vs Ссылки: детальное сравнение**

```cpp
#include <iostream>

// 1. Указатель по значению
void pointerExample(int* ptr) {
    if (ptr) {  // Всегда проверяем на nullptr!
        *ptr = 100;    // Изменяем данные
        ptr = nullptr; // Меняем только локальную копию
    }
}

// 2. Указатель по ссылке
void pointerReference(int*& ptrRef) {
    if (ptrRef) {
        *ptrRef = 200;   // Изменяем данные
        ptrRef = nullptr; // Меняем сам указатель
    }
}

// 3. Ссылка (никогда не может быть nullptr)
void referenceExample(int& ref) {
    ref = 300;  // Всегда валидный объект
    // Не нужно проверять на null!
}

// 4. Константный указатель на константу
void constPointerConst(const int* const constPtr) {
    // Нельзя изменить ни указатель, ни данные
    // if (constPtr) std::cout << *constPtr << std::endl;
}

int main() {
    int value = 50;
    int* ptr = &value;
    
    std::cout << "Исходное значение: " << value << std::endl;
    
    pointerExample(ptr);
    std::cout << "После pointerExample: " << value << std::endl;
    std::cout << "ptr равен nullptr? " << (ptr == nullptr ? "да" : "нет") << std::endl;
    
    pointerReference(ptr);
    std::cout << "После pointerReference: " << value << std::endl;
    std::cout << "ptr равен nullptr? " << (ptr == nullptr ? "да" : "нет") << std::endl;
    
    ptr = &value;  // Восстанавливаем указатель
    referenceExample(*ptr);  // Разыменовываем для получения ссылки
    std::cout << "После referenceExample: " << value << std::endl;
    
    return 0;
}
```

### 6. **Массивы как параметры: все варианты**

```cpp
#include <iostream>
#include <array>
#include <vector>

// 1. Массив как указатель (сишный стиль)
void arrayAsPointer(int* arr, size_t size) {
    for(size_t i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// 2. Массив с указанием размера (размер игнорируется!)
void arrayWithSize(int arr[10]) {  // 10 игнорируется!
    // Фактически это int* arr
}

// 3. Ссылка на массив фиксированного размера
void arrayReference(int (&arr)[5]) {  // Размер важен!
    for(int& elem : arr) {
        elem += 1;
    }
}

// 4. Массив как шаблонный параметр (C++)
template<size_t N>
void templateArray(int (&arr)[N]) {  // Выводит размер автоматически
    std::cout << "Размер массива: " << N << std::endl;
    for(size_t i = 0; i < N; i++) {
        arr[i] = i * 10;
    }
}

// 5. std::array (рекомендуется в C++)
void stdArrayExample(std::array<int, 5>& arr) {
    for(auto& elem : arr) {
        elem += 100;
    }
}

// 6. std::vector (динамический массив)
void vectorExample(std::vector<int>& vec) {
    for(auto& elem : vec) {
        elem += 1000;
    }
}

int main() {
    // 1. Сишный массив
    int cArray[5] = {1, 2, 3, 4, 5};
    arrayAsPointer(cArray, 5);
    
    // 3. Ссылка на массив
    int fixedArray[5] = {10, 20, 30, 40, 50};
    arrayReference(fixedArray);
    
    // 4. Шаблонный массив
    int dynamicSizeArray[] = {1, 2, 3};  // Размер 3
    templateArray(dynamicSizeArray);
    
    // 5. std::array
    std::array<int, 5> stdArr = {100, 200, 300, 400, 500};
    stdArrayExample(stdArr);
    
    // 6. std::vector
    std::vector<int> vec = {1000, 2000, 3000};
    vectorExample(vec);
    
    return 0;
}
```

### 7. **Сравнительная таблица всех видов параметров**

| Тип параметра | Синтаксис | Модификация оригинала | Может быть null | Передача массива | C++ версия |
|--------------|-----------|---------------------|----------------|------------------|------------|
| По значению | `void f(T param)` | ❌ Нет | ❌ Нет | Только указатель | C++98 |
| По ссылке | `void f(T& param)` | ✅ Да | ❌ Нет | `T (&)[N]` | C++98 |
| По константной ссылке | `void f(const T& param)` | ❌ Нет | ❌ Нет | `const T (&)[N]` | C++98 |
| Указатель по значению | `void f(T* param)` | *Да (через *) | ✅ Да | Естественно | C++98 |
| Ссылка на указатель | `void f(T*& param)` | ✅ Да (и указатель, и данные) | ✅ Да | - | C++98 |
| Rvalue-ссылка | `void f(T&& param)` | ✅ Временные объекты | ❌ Нет | - | C++11 |
| Универсальная ссылка | `template f(T&&)` | Зависит от типа | ❌ Нет | - | C++11 |
| `std::array` | `void f(array<T,N>&)` | ✅ Да | ❌ Нет | Идеально для массивов | C++11 |
| `std::vector` | `void f(vector<T>&)` | ✅ Да | ✅ Пустой вектор | Динамические массивы | C++98 |

### 8. **Лучшие практики и рекомендации**

```cpp
#include <iostream>
#include <vector>
#include <string>

// ПРАВИЛЬНО:

// 1. Простые типы - по значению
void processInt(int value) { /* ... */ }

// 2. Большие объекты - по константной ссылке
void printString(const std::string& str) { /* ... */ }

// 3. Если нужно изменить - по ссылке
void modifyVector(std::vector<int>& vec) { /* ... */ }

// 4. Необязательные параметры - указатель с nullptr по умолчанию
void findValue(const std::vector<int>& data, int* foundIndex = nullptr) {
    if (foundIndex) *foundIndex = 42;
}

// 5. Выходные параметры - по ссылке
void getMinMax(const std::vector<int>& data, int& min, int& max) {
    min = data[0];
    max = data[0];
    // ...
}

// 6. Множество выходных параметров - через структуру
struct Result {
    int min, max, sum;
};

Result calculateStats(const std::vector<int>& data) {
    return {data[0], data[0], 0};  // C++17 structured binding
}

// НЕПРАВИЛЬНО:

// 1. Большой объект по значению (неэффективно)
// void badExample1(std::vector<int> data) {}  // КОПИРОВАНИЕ!

// 2. Неинтуитивный интерфейс
// void badExample2(int& inputOutput) {}  // Непонятно, входной или выходной

// 3. Указатель без проверки на nullptr
// void badExample3(int* ptr) { *ptr = 10; }  // ОПАСНО!

int main() {
    // Пример использования
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // Простое чтение
    // printVector(numbers);  // Должно принимать const std::vector<int>&
    
    // Модификация
    modifyVector(numbers);
    
    // Получение нескольких результатов
    int min, max;
    getMinMax(numbers, min, max);
    
    // Использование структуры для возврата
    Result stats = calculateStats(numbers);
    
    return 0;
}
```

### **Итоговые правила выбора:**

1. **Используйте передачу по значению для:**
   - Встроенных типов (int, double, char, bool)
   - Маленьких структур (меньше 2-3 указателей)
   - Перечислений (enum)

2. **Используйте передачу по константной ссылке для:**
   - Больших объектов (строки, векторы, массивы)
   - Классов и структур
   - Когда нужно только читать данные

3. **Используйте передачу по ссылке для:**
   - Выходных параметров
   - Когда нужно изменить оригинальный объект
   - Для экономии памяти при работе с большими объектами

4. **Используйте указатели для:**
   - Необязательных параметров (с nullptr по умолчанию)
   - Низкоуровневого кода
   - Совместимости с C API

5. **Используйте умные указатели для:**
   - Владения ресурсами
   - Динамически выделяемой памяти
   - Полиморфных объектов
 Подробное пошаговое объяснение работы программы

Давайте разберем **каждую строку** этой программы и поймем, **что происходит в памяти**.

## Исходный код с нумерацией строк:
```cpp
#include <iostream>

// 1. Простые типы по значению
void simpleByValue(int num, double price, char grade) {
    // Все параметры - локальные копии
    num = 100;          // Меняется только копия
    price = 99.99;      // Меняется только копия
    grade = 'A';        // Меняется только копия
    
    std::cout << "Внутри функции: " << num << ", " << price << ", " << grade << std::endl;
}

// 2. Указатель по значению
void pointerByValue(int* ptr) {
    // ptr - копия указателя, указывает на те же данные
    *ptr = 100;         // Меняем данные по адресу
    ptr = nullptr;      // Меняем только копию указателя
}

// 3. Массив по значению (на самом деле передается как указатель!)
void arrayByValue(int arr[5]) {  // Размер игнорируется!
    // arr на самом деле int* - указатель на первый элемент
    arr[0] = 100;       // Меняет оригинальный массив!
}

// 4. Структура по значению (полное копирование)
struct Point {
    int x, y;
};

void structByValue(Point p) {
    p.x = 100;          // Меняется только копия
    p.y = 200;
}

int main() {
    int a = 5;
    double b = 10.5;
    char c = 'B';
    
    std::cout << "До вызова: " << a << ", " << b << ", " << c << std::endl;
    simpleByValue(a, b, c);
    std::cout << "После вызова: " << a << ", " << b << ", " << c << std::endl;
    
    // Пример с указателем
    int value = 50;
    int* ptr = &value;
    pointerByValue(ptr);
    std::cout << "value после pointerByValue: " << value << std::endl;
    
    // Пример с массивом
    int arr[5] = {1, 2, 3, 4, 5};
    arrayByValue(arr);
    std::cout << "arr[0] после arrayByValue: " << arr[0] << std::endl;
    
    // Пример со структурой
    Point point = {10, 20};
    structByValue(point);
    std::cout << "point после structByValue: (" << point.x << ", " << point.y << ")" << std::endl;
    
    return 0;
}
```

## Шаг 1: Выполнение main() - начало

### **Строки 31-33:**
```cpp
int main() {
    int a = 5;
    double b = 10.5;
    char c = 'B';
```

**Что происходит в памяти:**

```
СТЕК (stack) main():
┌───────────────────┐
│ a = 5            │ ← int (4 байта)
├───────────────────┤
│ b = 10.5         │ ← double (8 байт)
├───────────────────┤
│ c = 'B'          │ ← char (1 байт)
└───────────────────┘
```

**Визуализация:**
- `a` → ячейка памяти с адресом, например, `0x7ffd1234`
- `b` → ячейка памяти с адресом, например, `0x7ffd1238`
- `c` → ячейка памяти с адресом, например, `0x7ffd1240`

## Шаг 2: Вывод исходных значений

### **Строка 35:**
```cpp
std::cout << "До вызова: " << a << ", " << b << ", " << c << std::endl;
```

**Результат:**
```
До вызова: 5, 10.5, B
```

## Шаг 3: Вызов simpleByValue(a, b, c)

### **Строка 36:**
```cpp
simpleByValue(a, b, c);
```

**Что происходит ПРИ ВЫЗОВЕ функции:**

1. **Создается новый фрейм стека** для функции `simpleByValue`
2. **Значения a, b, c КОПИРУЮТСЯ** в новые переменные внутри функции

```
ДО вызова:
┌───────────────────┐ main() стек
│ a = 5            │
├───────────────────┤
│ b = 10.5         │
├───────────────────┤
│ c = 'B'          │
└───────────────────┘

ВО ВРЕМЯ вызова:
┌───────────────────┐ simpleByValue() стек
│ num = 5          │ ← КОПИЯ значения a
├───────────────────┤
│ price = 10.5     │ ← КОПИЯ значения b
├───────────────────┤
│ grade = 'B'      │ ← КОПИЯ значения c
└───────────────────┘
┌───────────────────┐ main() стек (остается!)
│ a = 5            │ ← ОРИГИНАЛ не меняется!
├───────────────────┤
│ b = 10.5         │ ← ОРИГИНАЛ не меняется!
├───────────────────┤
│ c = 'B'          │ ← ОРИГИНАЛ не меняется!
└───────────────────┘
```

## Шаг 4: Выполнение simpleByValue()

### **Строки 4-7:**
```cpp
void simpleByValue(int num, double price, char grade) {
    // Все параметры - локальные копии
    num = 100;          // Меняется только копия
    price = 99.99;      // Меняется только копия
    grade = 'A';        // Меняется только копия
```

**Что происходит в памяти функции:**

```
ПЕРЕД изменением:
┌───────────────────┐ simpleByValue() стек
│ num = 5          │
├───────────────────┤
│ price = 10.5     │
├───────────────────┤
│ grade = 'B'      │
└───────────────────┘

ПОСЛЕ изменения:
┌───────────────────┐ simpleByValue() стек
│ num = 100        │ ← ИЗМЕНИЛАСЬ КОПИЯ!
├───────────────────┤
│ price = 99.99    │ ← ИЗМЕНИЛАСЬ КОПИЯ!
├───────────────────┤
│ grade = 'A'      │ ← ИЗМЕНИЛАСЬ КОПИЯ!
└───────────────────┘

НО в main() стеке:
┌───────────────────┐ main() стек
│ a = 5            │ ← ОРИГИНАЛ БЕЗ ИЗМЕНЕНИЙ!
├───────────────────┤
│ b = 10.5         │ ← ОРИГИНАЛ БЕЗ ИЗМЕНЕНИЙ!
├───────────────────┤
│ c = 'B'          │ ← ОРИГИНАЛ БЕЗ ИЗМЕНЕНИЙ!
└───────────────────┘
```

### **Строка 8:**
```cpp
std::cout << "Внутри функции: " << num << ", " << price << ", " << grade << std::endl;
```

**Результат:**
```
Внутри функции: 100, 99.99, A
```

## Шаг 5: Возврат из simpleByValue()

**Что происходит при возврате:**
1. Уничтожается стековый фрейм функции `simpleByValue`
2. Все локальные переменные (`num`, `price`, `grade`) уничтожаются
3. Управление возвращается в `main()`

```
ПОСЛЕ возврата:
┌───────────────────┐ main() стек (как и было!)
│ a = 5            │
├───────────────────┤
│ b = 10.5         │
├───────────────────┤
│ c = 'B'          │
└───────────────────┘
```

## Шаг 6: Вывод после возврата

### **Строка 37:**
```cpp
std::cout << "После вызова: " << a << ", " << b << ", " << c << std::endl;
```

**Результат:**
```
После вызова: 5, 10.5, B
```

**Вывод:** Оригинальные значения НЕ изменились!

## Шаг 7: Работа с указателями

### **Строки 40-41:**
```cpp
int value = 50;
int* ptr = &value;
```

**Что происходит в памяти:**

```
main() стек:
┌───────────────────┐
│ value = 50       │ ← переменная типа int
├───────────────────┤
│ ptr = 0x...      │ ← указатель (хранит АДРЕС value)
└───────────────────┘

Адресная арифметика:
- `&value` → возвращает адрес переменной value
- `ptr` хранит этот адрес
- `*ptr` дает доступ к значению по этому адресу
```

**Визуализация:**
```
value: [50] ← значение
        ↑
ptr: [адрес value] ← хранит "ссылку" на value
```

## Шаг 8: Вызов pointerByValue(ptr)

### **Строка 42:**
```cpp
pointerByValue(ptr);
```

**Что происходит при вызове:**
1. Создается копия указателя `ptr`
2. Обе копии указывают на ОДНУ И ТУ ЖЕ память

```
ДО вызова в main():
value: [50]
         ↑
ptr: [адрес value]

ВО ВРЕМЯ вызова:
main() стек:           pointerByValue() стек:
value: [50]            ptr_copy: [адрес value]
         ↑                       ↑
ptr: [адрес value]      (такой же адрес!)
```

## Шаг 9: Выполнение pointerByValue()

### **Строки 11-14:**
```cpp
void pointerByValue(int* ptr) {
    // ptr - копия указателя, указывает на те же данные
    *ptr = 100;         // Меняем данные по адресу
    ptr = nullptr;      // Меняем только копию указателя
}
```

**Пошагово:**

1. **`*ptr = 100;`** - разыменовываем указатель
   ```
   До:   value: [50]
   
   После: value: [100]  ← ИЗМЕНИЛОСЬ оригинальное значение!
   ```
   
   **Почему изменилось?** Потому что обе копии указателя (`ptr` в main и `ptr` в функции) содержат ОДИН И ТОТ ЖЕ АДРЕС

2. **`ptr = nullptr;`** - меняем саму копию указателя
   ```
   В функции: ptr_copy: [nullptr]  ← изменилась копия
   
   В main(): ptr: [адрес value]    ← оригинальный указатель не изменился!
   ```

## Шаг 10: Возврат и вывод

### **Строка 43:**
```cpp
std::cout << "value после pointerByValue: " << value << std::endl;
```

**Результат:**
```
value после pointerByValue: 100
```

**Вывод:** Значение изменилось через указатель!

## Шаг 11: Работа с массивом

### **Строка 46:**
```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

**Что происходит в памяти:**

```
main() стек:
┌───────────────────┐
│ arr[0] = 1       │
├───────────────────┤
│ arr[1] = 2       │
├───────────────────┤
│ arr[2] = 3       │
├───────────────────┤
│ arr[3] = 4       │
├───────────────────┤
│ arr[4] = 5       │
└───────────────────┘

Важно: имя массива `arr` - это указатель на первый элемент!
arr == &arr[0]
```

## Шаг 12: Вызов arrayByValue(arr)

### **Строка 47:**
```cpp
arrayByValue(arr);
```

**Ключевой момент:**
- В C/C++ массивы НЕ передаются по значению (не копируются)
- Передается указатель на первый элемент
- `arrayByValue(int arr[5])` компилятор преобразует в `arrayByValue(int* arr)`

```
Передача массива:
main(): arr → [1][2][3][4][5]
              ↑
функция получает: int* arr = адрес arr[0]
```

## Шаг 13: Выполнение arrayByValue()

### **Строки 17-20:**
```cpp
void arrayByValue(int arr[5]) {  // Размер игнорируется!
    // arr на самом деле int* - указатель на первый элемент
    arr[0] = 100;       // Меняет оригинальный массив!
}
```

**Что происходит:**
```cpp
arr[0] = 100;
// Эквивалентно:
*(arr + 0) = 100;
// И так как arr содержит адрес arr[0] из main():
*(адрес_первого_элемента) = 100;
```

```
До:   main(): [1][2][3][4][5]
После: main(): [100][2][3][4][5]  ← ИЗМЕНИЛСЯ оригинал!
```

## Шаг 14: Вывод после arrayByValue

### **Строка 48:**
```cpp
std::cout << "arr[0] после arrayByValue: " << arr[0] << std::endl;
```

**Результат:**
```
arr[0] после arrayByValue: 100
```

## Шаг 15: Работа со структурой

### **Строки 23-27 и 51:**
```cpp
struct Point {
    int x, y;
};

Point point = {10, 20};
```

**Что происходит:**
```
main() стек:
┌───────────────────┐
│ point.x = 10     │
├───────────────────┤
│ point.y = 20     │
└───────────────────┘
```

## Шаг 16: Вызов structByValue(point)

### **Строка 52:**
```cpp
structByValue(point);
```

**Что происходит:**
1. Создается ПОЛНАЯ КОПИЯ структуры `Point`
2. Копируются ВСЕ поля структуры

```
ДО вызова:
main(): point {x=10, y=20}

ВО ВРЕМЯ вызова:
main(): point {x=10, y=20} ← оригинал
функция: p {x=10, y=20}   ← ПОЛНАЯ КОПИЯ (8 байт)
```

## Шаг 17: Выполнение structByValue()

### **Строки 29-32:**
```cpp
void structByValue(Point p) {
    p.x = 100;          // Меняется только копия
    p.y = 200;
}
```

```
В функции: p {x=100, y=200} ← изменилась КОПИЯ
В main(): point {x=10, y=20} ← оригинал НЕ изменился
```

## Шаг 18: Вывод после structByValue

### **Строка 53:**
```cpp
std::cout << "point после structByValue: (" << point.x << ", " << point.y << ")" << std::endl;
```

**Результат:**
```
point после structByValue: (10, 20)
```

## Полный вывод программы:
```
До вызова: 5, 10.5, B
Внутри функции: 100, 99.99, A
После вызова: 5, 10.5, B
value после pointerByValue: 100
arr[0] после arrayByValue: 100
point после structByValue: (10, 20)
```

## Ключевые выводы:

1. **Простые типы по значению** → создается копия, оригинал не меняется
2. **Указатель по значению** → копируется сам указатель, но обе копии указывают на одни данные
3. **Массив как параметр** → фактически передается указатель, меняется оригинал
4. **Структура по значению** → полное копирование, оригинал не меняется

## Визуальная схема памяти:

```
main() стек ДО всех вызовов:
┌───────────────────────┐
│ a = 5                │ ← int
├───────────────────────┤
│ b = 10.5             │ ← double
├───────────────────────┤
│ c = 'B'              │ ← char
├───────────────────────┤
│ value = 50           │ ← int
├───────────────────────┤
│ ptr → value          │ ← указатель
├───────────────────────┤
│ arr[0..4] = 1,2,3,4,5│ ← массив
├───────────────────────┤
│ point.x = 10, y = 20 │ ← структура
└───────────────────────┘

ПОСЛЕ всех вызовов:
┌───────────────────────┐
│ a = 5                │ ← НЕ изменилось
├───────────────────────┤
│ b = 10.5             │ ← НЕ изменилось
├───────────────────────┤
│ c = 'B'              │ ← НЕ изменилось
├───────────────────────┤
│ value = 100          │ ← ИЗМЕНИЛОСЬ через указатель
├───────────────────────┤
│ ptr → value          │ ← указатель прежний
├───────────────────────┤
│ arr[0] = 100         │ ← ИЗМЕНИЛОСЬ через массив-указатель
│ arr[1..4] = 2,3,4,5  │
├───────────────────────┤
│ point.x = 10, y = 20 │ ← НЕ изменилось
└───────────────────────┘
```
# Полный код программы с комментариями и выводом

```cpp
#include <iostream>

// 1. Функция с параметрами по значению (простые типы)
// Параметры num, price, grade - это КОПИИ переданных значений
void simpleByValue(int num, double price, char grade) {
    // Все изменения происходят только с локальными копиями
    num = 100;          // Изменяем копию переменной a из main()
    price = 99.99;      // Изменяем копию переменной b из main()
    grade = 'A';        // Изменяем копию переменной c из main()
    
    // Выводим измененные значения (только копий)
    std::cout << "Внутри функции simpleByValue: " 
              << num << ", " << price << ", " << grade << std::endl;
}

// 2. Функция с указателем как параметром по значению
// Указатель ptr - это КОПИЯ указателя из main()
void pointerByValue(int* ptr) {
    // ptr - копия указателя, но обе копии указывают на одни данные
    
    // Меняем данные по адресу, на который указывает ptr
    // Так как ptr и оригинальный указатель из main() указывают 
    // на одну и ту же память, меняется оригинальное значение
    *ptr = 100;
    
    // Меняем саму копию указателя (делаем её nullptr)
    // Это НЕ влияет на оригинальный указатель в main()
    ptr = nullptr;
}

// 3. Функция с массивом как параметром
// Важно: в C/C++ массивы передаются как указатели!
// Синтаксис int arr[5] компилятор преобразует в int* arr
void arrayByValue(int arr[5]) {
    // Размер [5] игнорируется компилятором!
    // arr - это указатель на первый элемент массива
    
    // Меняем первый элемент массива через указатель
    // Так как arr указывает на оригинальный массив из main(),
    // изменения будут видны в main()
    arr[0] = 100;
}

// 4. Объявление структуры Point
struct Point {
    int x;  // Координата X
    int y;  // Координата Y
};

// 5. Функция со структурой как параметром по значению
// Структура p - это ПОЛНАЯ КОПИЯ структуры из main()
void structByValue(Point p) {
    // Изменяем поля копии структуры
    p.x = 100;  // Изменяем копию поля x
    p.y = 200;  // Изменяем копию поля y
    
    // Эти изменения НЕ влияют на оригинальную структуру в main()
}

// Главная функция программы
int main() {
    // ==================== ЧАСТЬ 1: Простые типы по значению ====================
    std::cout << "=== Часть 1: Простые типы по значению ===" << std::endl;
    
    int a = 5;           // Объявление и инициализация целочисленной переменной
    double b = 10.5;     // Объявление и инициализация переменной с плавающей точкой
    char c = 'B';        // Объявление и инициализация символьной переменной
    
    // Выводим значения ДО вызова функции
    std::cout << "До вызова simpleByValue:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    
    // Вызываем функцию, передавая параметры ПО ЗНАЧЕНИЮ
    // Значения a, b, c копируются в параметры функции
    simpleByValue(a, b, c);
    
    // Выводим значения ПОСЛЕ вызова функции
    // Оригинальные значения a, b, c НЕ изменились!
    std::cout << "После вызова simpleByValue:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    
    // ==================== ЧАСТЬ 2: Указатели по значению ====================
    std::cout << "\n=== Часть 2: Указатели по значению ===" << std::endl;
    
    int value = 50;      // Создаем переменную value
    int* ptr = &value;   // Создаем указатель ptr и присваиваем ему адрес value
    
    std::cout << "До вызова pointerByValue:" << std::endl;
    std::cout << "value = " << value << std::endl;
    std::cout << "*ptr = " << *ptr << std::endl;
    
    // Вызываем функцию, передавая указатель ПО ЗНАЧЕНИЮ
    // Указатель ptr копируется, но обе копии указывают на value
    pointerByValue(ptr);
    
    std::cout << "После вызова pointerByValue:" << std::endl;
    std::cout << "value = " << value << " (изменилось через указатель!)" << std::endl;
    
    // Проверяем, что указатель ptr НЕ стал nullptr
    // (в функции менялась только копия указателя)
    if (ptr != nullptr) {
        std::cout << "*ptr = " << *ptr << " (указатель не изменился)" << std::endl;
    } else {
        std::cout << "ptr = nullptr (указатель изменился)" << std::endl;
    }
    
    // ==================== ЧАСТЬ 3: Массивы как параметры ====================
    std::cout << "\n=== Часть 3: Массивы как параметры ===" << std::endl;
    
    // Создаем и инициализируем массив из 5 элементов
    int arr[5] = {1, 2, 3, 4, 5};
    
    std::cout << "До вызова arrayByValue:" << std::endl;
    std::cout << "arr[0] = " << arr[0] << std::endl;
    std::cout << "Весь массив: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // Вызываем функцию, передавая массив
    // Массив передается как указатель на первый элемент
    arrayByValue(arr);
    
    std::cout << "После вызова arrayByValue:" << std::endl;
    std::cout << "arr[0] = " << arr[0] << " (изменился!)" << std::endl;
    std::cout << "Весь массив: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // ==================== ЧАСТЬ 4: Структуры по значению ====================
    std::cout << "\n=== Часть 4: Структуры по значению ===" << std::endl;
    
    // Создаем и инициализируем структуру Point
    Point point = {10, 20};  // point.x = 10, point.y = 20
    
    std::cout << "До вызова structByValue:" << std::endl;
    std::cout << "point.x = " << point.x << ", point.y = " << point.y << std::endl;
    
    // Вызываем функцию, передавая структуру ПО ЗНАЧЕНИЮ
    // Создается полная копия структуры
    structByValue(point);
    
    std::cout << "После вызова structByValue:" << std::endl;
    std::cout << "point.x = " << point.x << ", point.y = " << point.y;
    std::cout << " (не изменились!)" << std::endl;
    
    // ==================== ВЫВОДЫ И СРАВНЕНИЕ ====================
    std::cout << "\n=== Итоговые выводы ===" << std::endl;
    std::cout << "1. Простые типы по значению: ОРИГИНАЛЫ НЕ МЕНЯЮТСЯ" << std::endl;
    std::cout << "2. Указатели по значению: ДАННЫЕ ПО УКАЗАТЕЛЮ МЕНЯЮТСЯ, " 
              << "сам указатель - НЕТ" << std::endl;
    std::cout << "3. Массивы как параметры: ОРИГИНАЛЬНЫЙ МАССИВ МЕНЯЕТСЯ "
              << "(передается как указатель)" << std::endl;
    std::cout << "4. Структуры по значению: ОРИГИНАЛ НЕ МЕНЯЕТСЯ "
              << "(создается полная копия)" << std::endl;
    
    return 0;  // Завершение программы с кодом 0 (успех)
}
```

## Ожидаемый вывод программы:

```
=== Часть 1: Простые типы по значению ===
До вызова simpleByValue:
a = 5, b = 10.5, c = B
Внутри функции simpleByValue: 100, 99.99, A
После вызова simpleByValue:
a = 5, b = 10.5, c = B

=== Часть 2: Указатели по значению ===
До вызова pointerByValue:
value = 50
*ptr = 50
После вызова pointerByValue:
value = 100 (изменилось через указатель!)
*ptr = 100 (указатель не изменился)

=== Часть 3: Массивы как параметры ===
До вызова arrayByValue:
arr[0] = 1
Весь массив: 1 2 3 4 5 
После вызова arrayByValue:
arr[0] = 100 (изменился!)
Весь массив: 100 2 3 4 5 

=== Часть 4: Структуры по значению ===
До вызова structByValue:
point.x = 10, point.y = 20
После вызова structByValue:
point.x = 10, point.y = 20 (не изменились!)

=== Итоговые выводы ===
1. Простые типы по значению: ОРИГИНАЛЫ НЕ МЕНЯЮТСЯ
2. Указатели по значению: ДАННЫЕ ПО УКАЗАТЕЛЮ МЕНЯЮТСЯ, сам указатель - НЕТ
3. Массивы как параметры: ОРИГИНАЛЬНЫЙ МАССИВ МЕНЯЕТСЯ (передается как указатель)
4. Структуры по значению: ОРИГИНАЛ НЕ МЕНЯЕТСЯ (создается полная копия)
```

## Ключевые моменты для понимания:

### 1. **Простые типы по значению**
```cpp
void func(int a) { a = 100; }  // Меняется только копия
int main() {
    int x = 5;
    func(x);  // x останется 5
}
```

### 2. **Указатели по значению**
```cpp
void func(int* p) { 
    *p = 100;    // Меняем данные по адресу
    p = nullptr; // Меняем только копию указателя
}
int main() {
    int x = 5;
    int* ptr = &x;
    func(ptr);  // x станет 100, но ptr не станет nullptr
}
```

### 3. **Массивы как параметры**
```cpp
void func(int arr[]) {  // То же что int* arr
    arr[0] = 100;  // Меняет оригинальный массив!
}
int main() {
    int arr[3] = {1, 2, 3};
    func(arr);  // arr[0] станет 100
}
```

### 4. **Структуры по значению**
```cpp
struct Point { int x, y; };
void func(Point p) { p.x = 100; }  // Меняет только копию
int main() {
    Point p = {10, 20};
    func(p);  // p.x останется 10
}
```

## Как скомпилировать и запустить:

1. **Сохраните код** в файл `memory_demo.cpp`

2. **Скомпилируйте** командой:
```bash
g++ -o memory_demo memory_demo.cpp
```
или
```bash
g++ -std=c++11 -o memory_demo memory_demo.cpp
```

3. **Запустите** программу:
```bash
./memory_demo
```

Эта программа наглядно демонстрирует все основные способы передачи параметров в C++ и их влияние на оригинальные данные.

