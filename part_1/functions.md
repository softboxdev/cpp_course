# 📚 Урок 1.5: Функции и их параметры. Рекурсия

## 🎯 Цель урока
Научиться создавать, использовать и понимать функции в C++, включая параметры, возвращаемые значения и рекурсивные функции.

---

## 📖 Теоретическая часть

### 1. Что такое функция?
**Функция** - это именованный блок кода, который выполняет определенную задачу и может быть вызван из других частей программы.

**Преимущества функций:**
- Переиспользование кода
- Структурирование программы
- Упрощение отладки
- Разделение ответственности

---

## 🔧 Синтаксис функции

### 1.1 Объявление функции (прототип)
```cpp
// Объявление (прототип) - говорит компилятору о существовании функции
// Тип_возврата Имя_функции(Параметры);
int add(int a, int b);
void printMessage();
double calculateArea(double radius);
```

### 1.2 Определение функции (реализация)
```cpp
// Определение - содержит фактический код функции
int add(int a, int b) {
    int result = a + b;
    return result;
}
```

### 1.3 Вызов функции
```cpp
int main() {
    int sum = add(5, 3);  // Вызов функции
    cout << "Сумма: " << sum << endl;
    return 0;
}
```

---

## 🧩 Структура полной программы с функциями

```cpp
#include <iostream>
using namespace std;

// 1. ОБЪЯВЛЕНИЯ ФУНКЦИЙ (прототипы)
int add(int a, int b);            // Функция сложения
void printHello();                // Функция без параметров
double calculateCircleArea(double radius);  // Функция с возвратом double
void printNumber(int number);     // Функция без возвращаемого значения

// 2. ГЛАВНАЯ ФУНКЦИЯ
int main() {
    printHello();  // Вызов функции без параметров
    
    int x = 10, y = 20;
    int result = add(x, y);  // Вызов функции с параметрами
    printNumber(result);
    
    double radius = 5.5;
    double area = calculateCircleArea(radius);
    cout << "Площадь круга: " << area << endl;
    
    return 0;
}

// 3. ОПРЕДЕЛЕНИЯ ФУНКЦИЙ
void printHello() {
    cout << "Привет из функции!" << endl;
}

int add(int a, int b) {
    return a + b;  // Возврат значения
}

void printNumber(int number) {
    cout << "Число: " << number << endl;
    // Функции с void не возвращают значения
    // return не обязателен
}

double calculateCircleArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}
```

---

## 📊 Типы параметров функций

### 2.1 Параметры по значению (копия)
```cpp
// Параметр 'value' - копия переданного значения
void modifyValue(int value) {
    value = 100;  // Меняем копию, оригинал не изменится
    cout << "Внутри функции: " << value << endl;
}

int main() {
    int x = 10;
    modifyValue(x);  // x передается как копия
    cout << "После функции: " << x << endl;  // x = 10 (не изменился)
    return 0;
}
```

### 2.2 Параметры по ссылке (&)
```cpp
// Параметр 'value' - ссылка на оригинальную переменную
void modifyReference(int &value) {
    value = 100;  // Меняем оригинальную переменную
    cout << "Внутри функции: " << value << endl;
}

int main() {
    int x = 10;
    modifyReference(x);  // Передаем ссылку на x
    cout << "После функции: " << x << endl;  // x = 100 (изменился!)
    return 0;
}
```

### 2.3 Константные параметры
```cpp
// const гарантирует, что функция не изменит параметр
void printVector(const vector<int> &vec) {
    // vec.push_back(10);  // ОШИБКА: vec - константная ссылка
    for(int num : vec) {
        cout << num << " ";
    }
}

int main() {
    vector<int> numbers = {1, 2, 3};
    printVector(numbers);  // Безопасная передача по константной ссылке
    return 0;
}
```

### 2.4 Параметры по умолчанию
```cpp
// Параметры со значениями по умолчанию
void printInfo(string name, int age = 18, string city = "Москва") {
    cout << name << ", " << age << " лет, город " << city << endl;
}

int main() {
    printInfo("Анна", 25, "Санкт-Петербург");  // Все параметры указаны
    printInfo("Иван", 30);                      // city = "Москва" по умолчанию
    printInfo("Мария");                         // age=18, city="Москва" по умолчанию
    return 0;
}
```

### 2.5 Перегрузка функций
```cpp
// Несколько функций с одним именем, но разными параметрами
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << add(5, 3) << endl;      // Вызов первой функции
    cout << add(2.5, 3.7) << endl;  // Вызов второй функции
    cout << add(1, 2, 3) << endl;   // Вызов третьей функции
    return 0;
}
```

---

## 🎯 Возвращаемые значения

### 3.1 Функции с возвращаемым значением
```cpp
// Возврат простого значения
int getMax(int a, int b) {
    if(a > b) return a;
    else return b;
}

// Возврат вычисляемого значения
double calculateTax(double income) {
    if(income < 10000) return income * 0.13;
    else return income * 0.20;
}

// Возврат нескольких значений через структуру/вектор
struct Point {
    int x, y;
};

Point createPoint(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
```

### 3.2 Функции без возвращаемого значения (void)
```cpp
void printMenu() {
    cout << "=== МЕНЮ ===" << endl;
    cout << "1. Сложение" << endl;
    cout << "2. Вычитание" << endl;
    cout << "3. Выход" << endl;
}

void clearScreen() {
    // Эмуляция очистки экрана
    for(int i = 0; i < 50; i++) {
        cout << endl;
    }
}
```

### 3.3 Возврат ссылки (осторожно!)
```cpp
// Опасный пример - возврат ссылки на локальную переменную
int& badFunction() {
    int x = 10;  // Локальная переменная
    return x;    // ОШИБКА: x уничтожится после выхода из функции
}

// Корректный пример - возврат ссылки на существующий объект
int& getElement(int arr[], int index) {
    return arr[index];  // Возвращаем ссылку на элемент массива
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    getElement(array, 2) = 100;  // Меняем третий элемент на 100
    cout << array[2];  // 100
    return 0;
}
```

---

## 🔄 Рекурсия

### 4.1 Что такое рекурсия?
**Рекурсия** - когда функция вызывает саму себя.

### 4.2 Базовый пример: факториал
```cpp
// Факториал: n! = n * (n-1) * ... * 1
// Рекурсивное определение: n! = n * (n-1)!

int factorial(int n) {
    // Базовый случай (остановка рекурсии)
    if(n <= 1) {
        return 1;
    }
    // Рекурсивный случай
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    cout << "5! = " << factorial(5) << endl;  // 120
    return 0;
}
```

**Визуализация factorial(5):**
```
factorial(5)
= 5 * factorial(4)
= 5 * (4 * factorial(3))
= 5 * (4 * (3 * factorial(2)))
= 5 * (4 * (3 * (2 * factorial(1))))
= 5 * (4 * (3 * (2 * 1)))  // factorial(1) = 1 (базовый случай)
= 5 * (4 * (3 * 2))
= 5 * (4 * 6)
= 5 * 24
= 120
```

### 4.3 Числа Фибоначчи
```cpp
// F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
int fibonacci(int n) {
    if(n == 0) return 0;           // Базовый случай 1
    if(n == 1) return 1;           // Базовый случай 2
    return fibonacci(n-1) + fibonacci(n-2);  // Рекурсивный случай
}

int main() {
    for(int i = 0; i < 10; i++) {
        cout << "F(" << i << ") = " << fibonacci(i) << endl;
    }
    return 0;
}
```

### 4.4 Сумма цифр числа
```cpp
// Сумма цифр числа рекурсивно
int sumOfDigits(int n) {
    if(n < 10) {
        return n;  // Базовый случай: одна цифра
    }
    // Последняя цифра + сумма остальных цифр
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    cout << sumOfDigits(12345) << endl;  // 1+2+3+4+5 = 15
    return 0;
}
```

### 4.5 Возведение в степень
```cpp
// a^n = a * a^(n-1)
double power(double a, int n) {
    if(n == 0) return 1;              // Базовый случай: a^0 = 1
    if(n == 1) return a;              // Базовый случай: a^1 = a
    if(n > 0) return a * power(a, n-1);  // Рекурсия для положительных
    else return 1 / power(a, -n);     // Рекурсия для отрицательных
}
```

### 4.6 Быстрое возведение в степень (оптимизированная рекурсия)
```cpp
// Оптимизированный алгоритм: a^n = (a^(n/2))^2
double fastPower(double a, int n) {
    if(n == 0) return 1;
    
    double half = fastPower(a, n / 2);
    
    if(n % 2 == 0) {
        return half * half;  // Четная степень
    } else {
        return a * half * half;  // Нечетная степень
    }
}
```

### 4.7 Хвостовая рекурсия
```cpp
// Хвостовая рекурсия - рекурсивный вызов в конце функции
// (компилятор может оптимизировать в цикл)

// Обычная рекурсия факториала
int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n-1);  // НЕ хвостовая (умножение после вызова)
}

// Хвостовая рекурсия факториала
int factorialTail(int n, int accumulator = 1) {
    if(n <= 1) return accumulator;
    return factorialTail(n-1, n * accumulator);  // Хвостовая
}
```

### 4.8 Преобразование числа в двоичное
```cpp
void decimalToBinary(int n) {
    if(n == 0) return;  // Базовый случай
    
    decimalToBinary(n / 2);  // Рекурсивный вызов
    cout << n % 2;           // Вывод остатка (после рекурсии!)
}

int main() {
    decimalToBinary(10);  // Вывод: 1010
    return 0;
}
```

---

## ⚠️ Важные правила рекурсии

### 1. **Всегда должен быть базовый случай**
```cpp
// ПРАВИЛЬНО:
void countdown(int n) {
    if(n <= 0) {  // Базовый случай
        cout << "Пуск!" << endl;
        return;
    }
    cout << n << "... ";
    countdown(n-1);
}

// НЕПРАВИЛЬНО (бесконечная рекурсия):
void infiniteRecursion(int n) {
    cout << n << endl;
    infiniteRecursion(n+1);  // Нет условия остановки!
}
```

### 2. **Рекурсивный вызов должен приближать к базовому случаю**
```cpp
// ПРАВИЛЬНО - аргумент уменьшается
int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n-1);  // n-1 < n
}

// ОПАСНО - может не сойтись к базовому случаю
int mystery(int n) {
    if(n == 1) return 1;
    if(n % 2 == 0) return mystery(n/2);
    else return mystery(3*n + 1);  // Может расти!
}
```

### 3. **Стек вызовов ограничен**
```cpp
// Слишком глубокая рекурсия вызовет переполнение стека
void deepRecursion(int n) {
    if(n == 0) return;
    deepRecursion(n-1);
}

int main() {
    deepRecursion(1000000);  // Скорее всего переполнение стека
    return 0;
}
```

---

## 🏆 Практические задачи

### Задача 1: Калькулятор с функциями
```cpp
// Создайте программу-калькулятор с функциями для каждой операции
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if(b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return 0;
    }
    return a / b;
}

// Добавьте меню для выбора операции
```

### Задача 2: Проверка палиндрома
```cpp
// Напишите функцию, которая проверяет, является ли строка палиндромом
// (читается одинаково слева направо и справа налево)

bool isPalindrome(string str, int start = 0, int end = -1) {
    if(end == -1) end = str.length() - 1;
    
    // Базовый случай
    if(start >= end) return true;
    
    // Если символы не совпадают
    if(str[start] != str[end]) return false;
    
    // Рекурсивный вызов для следующей пары
    return isPalindrome(str, start + 1, end - 1);
}
```

### Задача 3: Поиск НОД (наибольшего общего делителя)
```cpp
// Алгоритм Евклида (рекурсивная версия)
int gcd(int a, int b) {
    if(b == 0) return a;            // Базовый случай
    return gcd(b, a % b);           // Рекурсивный случай
}

// НОК через НОД
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
```

### Задача 4: Ханойские башни
```cpp
// Классическая задача рекурсии
void hanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        cout << "Переместить диск 1 с " << from << " на " << to << endl;
        return;
    }
    
    hanoi(n-1, from, aux, to);
    cout << "Переместить диск " << n << " с " << from << " на " << to << endl;
    hanoi(n-1, aux, to, from);
}

int main() {
    hanoi(3, 'A', 'C', 'B');  // 3 диска
    return 0;
}
```

### Задача 5: Генератор простых чисел
```cpp
// Проверка простоты числа (рекурсивная)
bool isPrime(int n, int divisor = 2) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(divisor * divisor > n) return true;  // Базовый случай
    
    if(n % divisor == 0) return false;      // Число составное
    
    return isPrime(n, divisor + 1);         // Проверяем следующий делитель
}
```

---

## 📝 Пример полной программы: Игра "Угадай число" с функциями

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Прототипы функций
int generateRandomNumber(int min, int max);
int getUserGuess();
void giveHint(int guess, int secret);
bool playAgain();

int main() {
    srand(time(0));  // Инициализация генератора случайных чисел
    bool playing = true;
    
    while(playing) {
        cout << "=== ИГРА 'УГАДАЙ ЧИСЛО' ===" << endl;
        int secret = generateRandomNumber(1, 100);
        int attempts = 0;
        bool guessed = false;
        
        while(!guessed && attempts < 10) {
            int guess = getUserGuess();
            attempts++;
            
            if(guess == secret) {
                cout << "Поздравляю! Вы угадали число " << secret;
                cout << " за " << attempts << " попыток!" << endl;
                guessed = true;
            } else {
                giveHint(guess, secret);
            }
        }
        
        if(!guessed) {
            cout << "К сожалению, вы не угадали. Число было: " << secret << endl;
        }
        
        playing = playAgain();
    }
    
    cout << "Спасибо за игру!" << endl;
    return 0;
}

// Определения функций
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int getUserGuess() {
    int guess;
    do {
        cout << "Введите число от 1 до 100: ";
        cin >> guess;
        
        if(guess < 1 || guess > 100) {
            cout << "Ошибка! Число должно быть от 1 до 100." << endl;
        }
    } while(guess < 1 || guess > 100);
    
    return guess;
}

void giveHint(int guess, int secret) {
    if(guess < secret) {
        cout << "Загаданное число БОЛЬШЕ." << endl;
    } else {
        cout << "Загаданное число МЕНЬШЕ." << endl;
    }
}

bool playAgain() {
    char choice;
    cout << "\nХотите сыграть еще? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
```

---

## 💡 Советы по работе с функциями

### 1. **Принцип единственной ответственности**
```cpp
// ПЛОХО: функция делает слишком много
void processUser() {
    // Ввод данных, проверка, вычисления, вывод...
}

// ХОРОШО: каждая функция делает одну вещь
string getUserInput();
bool validateInput(string input);
int calculateResult(string input);
void displayResult(int result);
```

### 2. **Именование функций**
```cpp
// Плохие имена:
void f1();           // Что делает?
void doStuff();      // Что именно делает?

// Хорошие имена:
void calculateAverage();   // Вычисляет среднее
bool isValidEmail();       // Проверяет email
int findMaxValue();        // Находит максимальное значение
void printReport();        // Печатает отчет
```

### 3. **Длина функций**
- Идеально: 5-15 строк
- Максимум: 20-30 строк
- Если больше - разбивайте на подфункции

### 4. **Комментарии к функциям**
```cpp
/**
 * Вычисляет факториал числа n
 * @param n - неотрицательное целое число
 * @return n! или 1 если n <= 0
 * @throws нет исключений
 */
int factorial(int n) {
    // реализация
}
```

---

## 🚀 Шаблон для домашней работы

```cpp
#include <iostream>
using namespace std;

// Объявления функций
int task1(int a, int b);
void task2(string text, int count);
int task3(int n);
// ... добавить прототипы для всех задач

int main() {
    // Тестирование всех функций
    cout << "Задача 1: " << task1(5, 3) << endl;
    task2("Hello", 3);
    cout << "Задача 3: " << task3(5) << endl;
    
    return 0;
}

// Определения функций
int task1(int a, int b) {
    // Реализация задачи 1
    return a + b;  // Пример
}

void task2(string text, int count) {
    for(int i = 0; i < count; i++) {
        cout << text << endl;
    }
}

int task3(int n) {
    if(n <= 1) return 1;
    return n * task3(n-1);  // Рекурсивный факториал
}
```

---

## 📊 Итоговая таблица

| Концепция | Синтаксис | Пример | Когда использовать |
|-----------|-----------|--------|-------------------|
| **Функция с возвратом** | `тип имя(параметры)` | `int add(int a, int b)` | Нужно получить результат |
| **void функция** | `void имя(параметры)` | `void print()` | Только выполнить действие |
| **Параметр по значению** | `тип имя` | `void f(int x)` | Простые типы, копия безопасна |
| **Параметр по ссылке** | `тип& имя` | `void f(int& x)` | Изменить исходную переменную |
| **const параметр** | `const тип& имя` | `void f(const vector& v)` | Передача больших объектов |
| **Рекурсия** | Функция вызывает себя | `int f(n) { return n * f(n