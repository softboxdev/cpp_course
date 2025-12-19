# Рекурсия: Полное объяснение с примерами

## Что такое рекурсия?

**Рекурсия** - это когда функция вызывает сама себя. Это мощная техника программирования, которая позволяет решать сложные задачи, разбивая их на более простые подзадачи того же типа.

## Основные компоненты рекурсивной функции

Любая рекурсивная функция должна иметь:

1. **Базовый случай (base case)** - условие выхода из рекурсии
2. **Рекурсивный случай (recursive case)** - вызов функции самой себя
3. **Прогрессия к базовому случаю** - каждый шаг должен приближать к базовому случаю

## Простейший пример: Факториал

```cpp
#include <iostream>

// Факториал числа n (n!) = 1 * 2 * 3 * ... * n
// Например: 5! = 1 * 2 * 3 * 4 * 5 = 120

// Рекурсивная функция вычисления факториала
int factorial(int n) {
    // 1. БАЗОВЫЙ СЛУЧАЙ: факториал 0 и 1 равен 1
    if (n <= 1) {
        return 1;
    }
    
    // 2. РЕКУРСИВНЫЙ СЛУЧАЙ: n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main() {
    int number = 5;
    int result = factorial(number);
    std::cout << "Факториал " << number << " = " << result << std::endl;
    return 0;
}
```

## Как работает рекурсия факториала (пошагово):

```
Вызов factorial(5):

Шаг 1: factorial(5)
    n = 5, не базовый случай
    return 5 * factorial(4)   ← ждем результат factorial(4)

Шаг 2: factorial(4)
    n = 4, не базовый случай
    return 4 * factorial(3)   ← ждем результат factorial(3)

Шаг 3: factorial(3)
    n = 3, не базовый случай
    return 3 * factorial(2)   ← ждем результат factorial(2)

Шаг 4: factorial(2)
    n = 2, не базовый случай
    return 2 * factorial(1)   ← ждем результат factorial(1)

Шаг 5: factorial(1)
    n = 1, БАЗОВЫЙ СЛУЧАЙ!
    return 1

Теперь начинается "РАЗВОРАЧИВАНИЕ" рекурсии:

Шаг 4 (продолжение): factorial(2) получает результат factorial(1) = 1
    return 2 * 1 = 2

Шаг 3 (продолжение): factorial(3) получает результат factorial(2) = 2
    return 3 * 2 = 6

Шаг 2 (продолжение): factorial(4) получает результат factorial(3) = 6
    return 4 * 6 = 24

Шаг 1 (продолжение): factorial(5) получает результат factorial(4) = 24
    return 5 * 24 = 120

Итог: factorial(5) = 120
```

## Визуализация стека вызовов:

```
СТЕК ВЫЗОВОВ (растет вниз):

┌─────────────────────────────┐
│ main()                      │
├─────────────────────────────┤
│ factorial(5)                │ ← Первый вызов
│ n = 5                       │
│ ждет: factorial(4)          │
├─────────────────────────────┤
│ factorial(4)                │ ← Второй вызов
│ n = 4                       │
│ ждет: factorial(3)          │
├─────────────────────────────┤
│ factorial(3)                │ ← Третий вызов
│ n = 3                       │
│ ждет: factorial(2)          │
├─────────────────────────────┤
│ factorial(2)                │ ← Четвертый вызов
│ n = 2                       │
│ ждет: factorial(1)          │
├─────────────────────────────┤
│ factorial(1)                │ ← Пятый вызов
│ n = 1                       │
│ БАЗОВЫЙ СЛУЧАЙ!             │
│ возвращает: 1               │
└─────────────────────────────┘

Теперь стек "схлопывается" снизу вверх:

factorial(1) → 1
factorial(2) → 2 * 1 = 2
factorial(3) → 3 * 2 = 6
factorial(4) → 4 * 6 = 24
factorial(5) → 5 * 24 = 120
```

## Классические примеры рекурсии

### 1. **Числа Фибоначчи**

```cpp
#include <iostream>

// Числа Фибоначчи: 0, 1, 1, 2, 3, 5, 8, 13, ...
// Каждое число = сумме двух предыдущих
// F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)

int fibonacci(int n) {
    // Базовые случаи
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Рекурсивный случай
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    for (int i = 0; i < 10; i++) {
        std::cout << "F(" << i << ") = " << fibonacci(i) << std::endl;
    }
    return 0;
}
```

**Проблема:** Дерево рекурсивных вызовов для fibonacci экспоненциально растет:

```
fibonacci(4):
               fib(4)
              /      \
          fib(3)     fib(2)
         /    \      /    \
     fib(2) fib(1) fib(1) fib(0)
     /    \
 fib(1) fib(0)

Много повторных вычислений! fib(2) вычисляется 2 раза.
```

### 2. **Бинарный поиск (рекурсивный)**

```cpp
#include <iostream>
#include <vector>

// Рекурсивный бинарный поиск в отсортированном массиве
int binarySearch(const std::vector<int>& arr, int left, int right, int target) {
    // Базовый случай 1: элемент не найден
    if (left > right) {
        return -1;  // не найден
    }
    
    // Находим середину
    int mid = left + (right - left) / 2;
    
    // Базовый случай 2: элемент найден
    if (arr[mid] == target) {
        return mid;
    }
    
    // Рекурсивные случаи
    if (arr[mid] > target) {
        // Ищем в левой половине
        return binarySearch(arr, left, mid - 1, target);
    } else {
        // Ищем в правой половине
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main() {
    std::vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;
    
    int index = binarySearch(sortedArray, 0, sortedArray.size() - 1, target);
    
    if (index != -1) {
        std::cout << "Элемент " << target << " найден на позиции " << index << std::endl;
    } else {
        std::cout << "Элемент " << target << " не найден" << std::endl;
    }
    
    return 0;
}
```

### 3. **Алгоритм Евклида (НОД)**

```cpp
#include <iostream>

// Наибольший общий делитель (НОД) через рекурсию
int gcd(int a, int b) {
    // Базовый случай: если b == 0, то НОД = a
    if (b == 0) {
        return a;
    }
    
    // Рекурсивный случай: НОД(a, b) = НОД(b, a % b)
    return gcd(b, a % b);
}

int main() {
    int a = 48, b = 18;
    std::cout << "НОД(" << a << ", " << b << ") = " << gcd(a, b) << std::endl;
    return 0;
}
```

**Как работает:**
```
gcd(48, 18):
1. 48 % 18 = 12 → gcd(18, 12)
2. 18 % 12 = 6  → gcd(12, 6)
3. 12 % 6 = 0   → БАЗОВЫЙ СЛУЧАЙ! return 6
```

## Типы рекурсии

### 1. **Прямая рекурсия**
Функция вызывает саму себя напрямую.

```cpp
void directRecursion(int n) {
    if (n <= 0) return;  // базовый случай
    std::cout << n << " ";
    directRecursion(n - 1);  // прямой вызов себя
}
```

### 2. **Косвенная рекурсия**
Функция A вызывает функцию B, а B вызывает A.

```cpp
#include <iostream>

void functionB(int n);  // объявление вперед

void functionA(int n) {
    if (n <= 0) return;
    std::cout << "A: " << n << std::endl;
    functionB(n - 1);  // вызов другой функции
}

void functionB(int n) {
    if (n <= 0) return;
    std::cout << "B: " << n << std::endl;
    functionA(n - 1);  // которая вызывает первую
}

int main() {
    functionA(5);
    return 0;
}
```

### 3. **Хвостовая рекурсия (Tail Recursion)**
Рекурсивный вызов - последняя операция в функции. Может быть оптимизирована компилятором.

```cpp
// Обычная рекурсия (не хвостовая)
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);  // умножение ПОСЛЕ рекурсивного вызова
}

// Хвостовая рекурсия
int factorialTail(int n, int accumulator = 1) {
    if (n <= 1) return accumulator;
    return factorialTail(n - 1, n * accumulator);  // рекурсия В КОНЦЕ
}
```

**Оптимизация хвостовой рекурсии:**
Компилятор может преобразовать хвостовую рекурсию в цикл:
```cpp
// Вместо этого:
int factorialTail(int n, int acc = 1) {
    if (n <= 1) return acc;
    return factorialTail(n - 1, n * acc);
}

// Компилятор может сделать это:
int factorialLoop(int n) {
    int acc = 1;
    while (n > 1) {
        acc = acc * n;
        n = n - 1;
    }
    return acc;
}
```

## Рекурсия vs Итерация

### Пример: Сумма чисел от 1 до n

```cpp
#include <iostream>

// Рекурсивная версия
int sumRecursive(int n) {
    if (n <= 1) return n;  // базовый случай
    return n + sumRecursive(n - 1);  // рекурсивный случай
}

// Итеративная версия (цикл)
int sumIterative(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

int main() {
    int n = 100;
    
    std::cout << "Рекурсивно: сумма от 1 до " << n << " = " << sumRecursive(n) << std::endl;
    std::cout << "Итеративно: сумма от 1 до " << n << " = " << sumIterative(n) << std::endl;
    
    return 0;
}
```

### Сравнение:

| Аспект | Рекурсия | Итерация (циклы) |
|--------|----------|------------------|
| **Читаемость** | Часто более понятна для рекурсивных по природе задач (деревья, графы) | Более понятна для простых задач |
| **Производительность** | Медленнее (вызов функции + стек) | Быстрее (только цикл) |
| **Память** | Использует стек (риск переполнения) | Использует фиксированную память |
| **Сложность отладки** | Сложнее (много уровней вложенности) | Проще (линейный поток) |

## Практические примеры

### 1. **Папки и файлы (обход дерева каталогов)**

```cpp
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

// Рекурсивный обход папок
void listFiles(const fs::path& directory, int depth = 0) {
    // Базовый случай: если это не директория
    if (!fs::exists(directory) || !fs::is_directory(directory)) {
        return;
    }
    
    // Рекурсивный обход
    for (const auto& entry : fs::directory_iterator(directory)) {
        // Отступ для визуализации иерархии
        std::string indent(depth * 2, ' ');
        
        if (fs::is_directory(entry.status())) {
            std::cout << indent << "[DIR] " << entry.path().filename() << std::endl;
            // Рекурсивный вызов для подпапки
            listFiles(entry.path(), depth + 1);
        } else {
            std::cout << indent << "[FILE] " << entry.path().filename() 
                      << " (" << fs::file_size(entry) << " байт)" << std::endl;
        }
    }
}

int main() {
    std::string path = ".";  // Текущая директория
    std::cout << "Содержимое папки '" << path << "':" << std::endl;
    listFiles(path);
    return 0;
}
```

### 2. **Ханойские башни**

```cpp
#include <iostream>

// Классическая задача о Ханойских башнях
void hanoi(int n, char from, char to, char aux) {
    // Базовый случай: если только 1 диск
    if (n == 1) {
        std::cout << "Переместить диск 1 с " << from << " на " << to << std::endl;
        return;
    }
    
    // 1. Переместить n-1 дисков с 'from' на 'aux', используя 'to' как вспомогательный
    hanoi(n - 1, from, aux, to);
    
    // 2. Переместить оставшийся диск с 'from' на 'to'
    std::cout << "Переместить диск " << n << " с " << from << " на " << to << std::endl;
    
    // 3. Переместить n-1 дисков с 'aux' на 'to', используя 'from' как вспомогательный
    hanoi(n - 1, aux, to, from);
}

int main() {
    int disks = 3;
    std::cout << "Решение Ханойских башен для " << disks << " дисков:" << std::endl;
    hanoi(disks, 'A', 'C', 'B');  // A - источник, C - цель, B - вспомогательный
    return 0;
}
```

### 3. **Генерация всех перестановок**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Рекурсивная генерация всех перестановок
void generatePermutations(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
    // Базовый случай: если дошли до конца
    if (start == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    
    // Рекурсивный случай
    for (int i = start; i < nums.size(); i++) {
        // Меняем местами
        std::swap(nums[start], nums[i]);
        
        // Рекурсивный вызов для следующей позиции
        generatePermutations(nums, start + 1, result);
        
        // Возвращаем обратно (backtracking)
        std::swap(nums[start], nums[i]);
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3};
    std::vector<std::vector<int>> permutations;
    
    generatePermutations(numbers, 0, permutations);
    
    std::cout << "Все перестановки:" << std::endl;
    for (const auto& perm : permutations) {
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
```

## Проблемы и ограничения рекурсии

### 1. **Переполнение стека (Stack Overflow)**

```cpp
#include <iostream>

// Опасная рекурсия - нет базового случая!
void infiniteRecursion(int n) {
    std::cout << n << " ";
    infiniteRecursion(n + 1);  // Бесконечная рекурсия!
}

// Неэффективная рекурсия для больших n
int badFibonacci(int n) {
    if (n <= 1) return n;
    return badFibonacci(n - 1) + badFibonacci(n - 2);  // Экспоненциальная сложность!
}

int main() {
    // infiniteRecursion(1);  // ВЫЗОВЕТ ПЕРЕПОЛНЕНИЕ СТЕКА!
    
    // Медленно для больших n
    std::cout << "fibonacci(40) = " << badFibonacci(40) << std::endl;  // Будет считать долго
    
    return 0;
}
```

### 2. **Решение: Мемоизация (кеширование)**

```cpp
#include <iostream>
#include <vector>

// Рекурсия с мемоизацией (кешированием результатов)
int fibonacciMemo(int n, std::vector<int>& memo) {
    // Базовые случаи
    if (n <= 1) return n;
    
    // Если уже вычисляли - возвращаем из кеша
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Вычисляем и сохраняем в кеш
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

int fibonacci(int n) {
    std::vector<int> memo(n + 1, -1);  // Вектор для кеширования
    return fibonacciMemo(n, memo);
}

int main() {
    for (int i = 0; i < 50; i++) {
        std::cout << "F(" << i << ") = " << fibonacci(i) << std::endl;
    }
    return 0;
}
```

## Правила использования рекурсии

1. **Всегда определяйте базовый случай** - без него рекурсия бесконечна
2. **Каждый рекурсивный вызов должен приближать к базовому случаю**
3. **Избегайте повторных вычислений** - используйте мемоизацию
4. **Помните об ограничении стека** - обычно 1-8 МБ
5. **Рассмотрите итеративное решение** - часто более эффективно

## Упражнения для практики

### Задача 1: Сумма цифр числа
```cpp
// Рекурсивно вычислить сумму цифр числа
// sumOfDigits(123) = 1 + 2 + 3 = 6
int sumOfDigits(int n) {
    if (n == 0) return 0;  // базовый случай
    return (n % 10) + sumOfDigits(n / 10);  // последняя цифра + рекурсия для остальных
}
```

### Задача 2: Возведение в степень
```cpp
// Рекурсивное возведение в степень
// power(2, 3) = 2 * 2 * 2 = 8
double power(double base, int exp) {
    if (exp == 0) return 1;  // базовый случай
    if (exp < 0) return 1 / power(base, -exp);  // отрицательная степень
    return base * power(base, exp - 1);  // рекурсивный случай
}
```

### Задача 3: Палиндром
```cpp
// Рекурсивная проверка на палиндром
bool isPalindrome(const std::string& str, int start, int end) {
    if (start >= end) return true;  // базовый случай
    if (str[start] != str[end]) return false;  // не палиндром
    return isPalindrome(str, start + 1, end - 1);  // проверяем внутреннюю часть
}
```

## Итоговая программа с демонстрацией всех концепций

```cpp
#include <iostream>
#include <vector>
#include <string>

// 1. Факториал (базовый пример)
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// 2. Фибоначчи с мемоизацией
int fibMemo(int n, std::vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

int fibonacci(int n) {
    std::vector<int> memo(n + 1, -1);
    return fibMemo(n, memo);
}

// 3. Бинарный поиск
int binarySearch(const std::vector<int>& arr, int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binarySearch(arr, left, mid - 1, target);
    return binarySearch(arr, mid + 1, right, target);
}

// 4. Сумма цифр числа
int sumDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

// 5. Обращение строки
void reverseString(std::string& str, int left, int right) {
    if (left >= right) return;
    std::swap(str[left], str[right]);
    reverseString(str, left + 1, right - 1);
}

int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ РЕКУРСИИ ===\n" << std::endl;
    
    // 1. Факториал
    std::cout << "1. Факториал 5 = " << factorial(5) << std::endl;
    
    // 2. Фибоначчи
    std::cout << "\n2. Числа Фибоначчи:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "F(" << i << ") = " << fibonacci(i) << std::endl;
    }
    
    // 3. Бинарный поиск
    std::vector<int> sorted = {2, 4, 6, 8, 10, 12, 14, 16};
    int target = 10;
    int index = binarySearch(sorted, 0, sorted.size() - 1, target);
    std::cout << "\n3. Бинарный поиск: элемент " << target 
              << (index != -1 ? " найден" : " не найден") << std::endl;
    
    // 4. Сумма цифр
    int number = 12345;
    std::cout << "\n4. Сумма цифр числа " << number 
              << " = " << sumDigits(number) << std::endl;
    
    // 5. Обращение строки
    std::string text = "Hello, World!";
    std::string reversed = text;
    reverseString(reversed, 0, reversed.length() - 1);
    std::cout << "\n5. Обращение строки:" << std::endl;
    std::cout << "Оригинал: " << text << std::endl;
    std::cout << "Обращенная: " << reversed << std::endl;
    
    std::cout << "\n=== КОНЕЦ ДЕМОНСТРАЦИИ ===" << std::endl;
    
    return 0;
}
```

## Заключение

Рекурсия - это мощный инструмент, который:
- Делает код чище и понятнее для рекурсивных по природе задач
- Позволяет решать сложные задачи простым способом
- Требует внимания к базовым случаям и ограничениям стека

**Когда использовать рекурсию:**
- Работа с деревьями и графами
- Задачи типа "разделяй и властвуй"
- Обработка вложенных структур (JSON, XML)
- Задачи, которые естественно описываются рекурсивно

**Когда избегать рекурсии:**
- Простые задачи, решаемые циклами
- Когда глубина рекурсии может быть большой
- В системах с ограниченной памятью
- Когда производительность критически важна