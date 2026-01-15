# **Подробное объяснение условных операторов и логических операций в C++**

## **📌 Введение: Зачем нужны условия?**

В реальной жизни мы постоянно принимаем решения:
- **ЕСЛИ** идёт дождь, **ТО** взять зонтик
- **ЕСЛИ** темно, **ТО** включить свет
- **ЕСЛИ** голоден, **ТО** поесть, **ИНАЧЕ** работать

В программировании это называется **условными конструкциями**. Они позволяют программе "принимать решения" на основе данных.

---

## **1. УСЛОВНЫЙ ОПЕРАТОР if/else**

### **Базовый синтаксис:**
```cpp
if (условие) {
    // код выполнится, ЕСЛИ условие истинно (true)
}
```

### **Пример 1: Простой if**
```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 20;
    
    // ЕСЛИ возраст больше или равен 18
    if (age >= 18) {
        // Этот блок кода выполнится ТОЛЬКО если условие истинно
        cout << "Вы совершеннолетний!" << endl;
    }
    
    // Этот код выполнится ВСЕГДА
    cout << "Программа завершена." << endl;
    
    return 0;
}
```

**Пошаговое выполнение:**
1. `age >= 18` → `20 >= 18` → `true` (истина)
2. Условие истинно → выполняется код в фигурных скобках `{}`
3. Вывод: "Вы совершеннолетний!"
4. Вывод: "Программа завершена."

### **Пример 2: if с else**
```cpp
#include <iostream>
using namespace std;

int main() {
    int temperature = -5;
    
    // ЕСЛИ температура выше нуля
    if (temperature > 0) {
        cout << "На улице тепло" << endl;
    }
    // ИНАЧЕ (если условие ложно)
    else {
        cout << "На улице холодно" << endl;
    }
    
    return 0;
}
```
**Результат:** `-5 > 0` → `false` → выполнится блок `else` → "На улице холодно"

### **Пример 3: Цепочка условий (if-else if-else)**
```cpp
#include <iostream>
using namespace std;

int main() {
    int score = 85;
    char grade;
    
    // Проверка условий по очереди сверху вниз
    if (score >= 90) {
        grade = 'A';
        cout << "Отлично!" << endl;
    }
    else if (score >= 80) {  // Проверяется ТОЛЬКО если первое условие ложно
        grade = 'B';
        cout << "Хорошо!" << endl;
    }
    else if (score >= 70) {  // Проверяется ТОЛЬКО если первые два ложны
        grade = 'C';
        cout << "Удовлетворительно" << endl;
    }
    else {  // Выполняется если ВСЕ предыдущие условия ложны
        grade = 'F';
        cout << "Неудовлетворительно" << endl;
    }
    
    cout << "Ваша оценка: " << grade << endl;
    return 0;
}
```

**Важно:** Выполняется **только первый блок**, условие которого истинно!



---

## **2. ЛОГИЧЕСКИЕ ОПЕРАЦИИ**

Логические операции работают с булевыми значениями (`true`/`false`).

### **Таблица истинности:**

| A | B | A && B | A \|\| B | !A |
|---|----|--------|----------|----|
| false | false | false | false | true |
| false | true | false | true | true |
| true | false | false | true | false |
| true | true | true | true | false |

### **Оператор && (И, AND)**
```cpp
#include <iostream>
using namespace std;

int main() {
    bool hasTicket = true;
    bool hasMoney = true;
    
    // ОБА условия должны быть истинны
    if (hasTicket && hasMoney) {
        cout << "Вы можете пойти в кино" << endl;
    } else {
        cout << "Вы не можете пойти в кино" << endl;
    }
    
    // Практический пример
    int age = 25;
    bool hasLicense = true;
    
    // Можно водить машину если возраст >= 18 И есть права
    if (age >= 18 && hasLicense) {
        cout << "Вы можете водить машину" << endl;
    }
    
    return 0;
}
```

**Ленивое вычисление (short-circuit evaluation):**
Если левая часть `&&` ложна → правая часть НЕ вычисляется!
```cpp
int x = 0;
// Второе условие (x > 5) НЕ будет проверяться!
if (false && (x > 5)) {
    // Этот код никогда не выполнится
}
```

### **Оператор || (ИЛИ, OR)**
```cpp
#include <iostream>
using namespace std;

int main() {
    bool isWeekend = true;
    bool isHoliday = false;
    
    // ХОТЯ БЫ ОДНО условие должно быть истинно
    if (isWeekend || isHoliday) {
        cout << "Можно отдохнуть!" << endl;
    }
    
    // Практический пример: скидка
    bool isStudent = true;
    bool isPensioner = false;
    bool hasDiscountCard = true;
    
    // Скидка если студент ИЛИ пенсионер ИЛИ есть дисконтная карта
    if (isStudent || isPensioner || hasDiscountCard) {
        cout << "Вам предоставляется скидка!" << endl;
    }
    
    return 0;
}
```

**Ленивое вычисление для ||:**
Если левая часть `||` истинна → правая часть НЕ вычисляется!
```cpp
int y = 10;
// Второе условие (y < 0) НЕ будет проверяться!
if (true || (y < 0)) {
    // Этот код всегда выполнится
}
```

### **Оператор ! (НЕ, NOT)**
```cpp
#include <iostream>
using namespace std;

int main() {
    bool doorClosed = true;
    
    // ! превращает true в false, а false в true
    if (!doorClosed) {  // если НЕ doorClosed
        cout << "Дверь открыта" << endl;
    } else {
        cout << "Дверь закрыта" << endl;
    }
    
    // Практический пример: проверка на невалидность
    int age = 15;
    
    if (!(age >= 18)) {  // эквивалентно age < 18
        cout << "Вход запрещён!" << endl;
    }
    
    return 0;
}
```

### **Комбинирование операций**
```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 25;
    bool hasTicket = true;
    bool hasMoney = false;
    
    // Сложное условие с приоритетами
    // 1. !hasMoney = true (так как hasMoney = false)
    // 2. age >= 18 && hasTicket = true && true = true
    // 3. true || true = true
    if ((age >= 18 && hasTicket) || !hasMoney) {
        cout << "Можно пройти на мероприятие" << endl;
    }
    
    // Использование скобок для изменения приоритета
    bool a = true, b = false, c = true;
    
    // Без скобок: && имеет приоритет над ||
    // true && false || true = false || true = true
    if (a && b || c) {
        cout << "Условие 1 истинно" << endl;
    }
    
    // Со скобками: меняем порядок
    // true && (false || true) = true && true = true
    if (a && (b || c)) {
        cout << "Условие 2 истинно" << endl;
    }
    
    return 0;
}
```

**Приоритет операций:**
1. `()` — скобки (самый высокий)
2. `!` — НЕ
3. `&&` — И
4. `||` — ИЛИ (самый низкий)

---

## **3. ТЕРНАРНЫЙ ОПЕРАТОР (?:)**

### **Синтаксис:**
```cpp
условие ? выражение_если_истинно : выражение_если_ложно
```

### **Пример 1: Базовое использование**
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;
    
    // Традиционный способ с if/else
    int max1;
    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }
    
    // Эквивалент с тернарным оператором
    int max2 = (a > b) ? a : b;
    // Читается: ЕСЛИ (a > b) ТО max2 = a ИНАЧЕ max2 = b
    
    cout << "max1 = " << max1 << ", max2 = " << max2 << endl;
    
    return 0;
}
```

### **Пример 2: Вывод разных сообщений**
```cpp
#include <iostream>
using namespace std;

int main() {
    int temperature = 25;
    
    // Использование в выводе
    cout << "На улице " 
         << (temperature > 20 ? "тепло" : "прохладно") 
         << endl;
    
    // Сохранение результата
    string weather = (temperature > 0) ? "Выше нуля" : "Ниже нуля";
    cout << "Температура " << weather << endl;
    
    return 0;
}
```

### **Пример 3: Вложенные тернарные операторы**
```cpp
#include <iostream>
using namespace std;

int main() {
    int score = 85;
    
    // Определение оценки
    char grade = (score >= 90) ? 'A' :
                 (score >= 80) ? 'B' :
                 (score >= 70) ? 'C' :
                 (score >= 60) ? 'D' : 'F';
    
    // Эквивалентный код с if/else if/else:
    /*
    char grade;
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    */
    
    cout << "Оценка: " << grade << endl;
    
    return 0;
}
```

**Важно:** Не злоупотребляйте вложенными тернарными операторами — код становится нечитаемым!

---

## **4. ОПЕРАТОР SWITCH**

Используется для множественного выбора на основе одного значения.

### **Синтаксис:**
```cpp
switch (выражение) {
    case значение1:
        // код для значение1
        break;
    case значение2:
        // код для значение2
        break;
    default:
        // код если ни один case не подошёл
}
```

### **Пример 1: Дни недели**
```cpp
#include <iostream>
using namespace std;

int main() {
    int dayOfWeek = 3;
    
    switch (dayOfWeek) {
        case 1:  // если dayOfWeek == 1
            cout << "Понедельник" << endl;
            break;  // выход из switch
            
        case 2:  // если dayOfWeek == 2
            cout << "Вторник" << endl;
            break;
            
        case 3:
            cout << "Среда" << endl;
            break;
            
        case 4:
            cout << "Четверг" << endl;
            break;
            
        case 5:
            cout << "Пятница" << endl;
            break;
            
        case 6:
        case 7:  // можно объединять несколько case
            cout << "Выходной день" << endl;
            break;
            
        default:  // если ни один case не подошёл
            cout << "Неверный номер дня" << endl;
    }
    
    return 0;
}
```

### **Пример 2: Калькулятор**
```cpp
#include <iostream>
using namespace std;

int main() {
    char operation;
    double a = 10.5, b = 5.2;
    
    cout << "Выберите операцию (+, -, *, /): ";
    cin >> operation;
    
    double result;
    
    switch (operation) {
        case '+':
            result = a + b;
            cout << a << " + " << b << " = " << result << endl;
            break;
            
        case '-':
            result = a - b;
            cout << a << " - " << b << " = " << result << endl;
            break;
            
        case '*':
            result = a * b;
            cout << a << " * " << b << " = " << result << endl;
            break;
            
        case '/':
            if (b != 0) {
                result = a / b;
                cout << a << " / " << b << " = " << result << endl;
            } else {
                cout << "Ошибка: деление на ноль!" << endl;
            }
            break;
            
        default:
            cout << "Неизвестная операция!" << endl;
    }
    
    return 0;
}
```

**Важные правила для switch:**
1. Выражение в `switch` должно быть **целочисленного типа** или `enum`
2. `case` значения должны быть **константами**
3. `break` прерывает выполнение switch (без него выполнится следующий case!)
4. `default` выполняется если ни один `case` не совпал

### **Пример с отсутствующим break (проваливание):**
```cpp
#include <iostream>
using namespace std;

int main() {
    int option = 2;
    
    switch (option) {
        case 1:
            cout << "Выбрана опция 1" << endl;
            // НЕТ break! Выполнение "проваливается" в case 2
        case 2:
            cout << "Выбрана опция 2" << endl;
            // НЕТ break!
        case 3:
            cout << "Выбрана опция 3" << endl;
            break;
        default:
            cout << "Неизвестная опция" << endl;
    }
    
    // Вывод:
    // Выбрана опция 2
    // Выбрана опция 3
    
    return 0;
}
```

---

## **5. ПРАКТИЧЕСКИЙ ПРИМЕР: Проверка пароля**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string correctPassword = "secret123";
    string enteredPassword;
    int attempts = 3;
    
    cout << "=== СИСТЕМА БЕЗОПАСНОСТИ ===" << endl;
    
    for (int i = 1; i <= attempts; i++) {
        cout << "Введите пароль (попытка " << i << "/" << attempts << "): ";
        cin >> enteredPassword;
        
        // Проверяем пароль
        if (enteredPassword == correctPassword) {
            cout << "Доступ разрешён!" << endl;
            
            // Дополнительные проверки
            int hour = 14; // текущий час
            
            // Проверяем время доступа
            bool isWorkingHours = (hour >= 9 && hour <= 18);
            bool isWeekend = false;
            
            // Используем тернарный оператор для сообщения
            cout << (isWorkingHours ? "Рабочее время" : "Вне рабочего времени") << endl;
            
            // Используем логические операторы
            if (isWorkingHours && !isWeekend) {
                cout << "Полный доступ к системе" << endl;
            } else {
                cout << "Ограниченный доступ" << endl;
            }
            
            break; // выходим из цикла
        }
        else {
            cout << "Неверный пароль!" << endl;
            
            // Используем тернарный оператор для вывода оставшихся попыток
            int remaining = attempts - i;
            cout << "Осталось попыток: " 
                 << (remaining > 0 ? to_string(remaining) : "0") 
                 << endl;
            
            // Если попытки закончились
            if (i == attempts) {
                cout << "Доступ заблокирован! Обратитесь к администратору." << endl;
                
                // Используем switch для определения типа блокировки
                int lockType = 2; // 1-временная, 2-постоянная, 3-требует сброса
                
                switch (lockType) {
                    case 1:
                        cout << "Временная блокировка на 24 часа" << endl;
                        break;
                    case 2:
                        cout << "Постоянная блокировка аккаунта" << endl;
                        break;
                    case 3:
                        cout << "Требуется сброс пароля администратором" << endl;
                        break;
                    default:
                        cout << "Неизвестный тип блокировки" << endl;
                }
            }
        }
    }
    
    return 0;
}
```

---

## **🎯 КРАТКИЙ КОНСПЕКТ:**

### **Когда что использовать:**

1. **`if/else`** — когда есть 1-3 условия
2. **`switch`** — когда много вариантов для одного значения
3. **`тернарный оператор`** — простые выборы в одну строку
4. **`&&`** — когда должны выполняться ВСЕ условия
5. **`||`** — когда достаточно ХОТЯ БЫ ОДНОГО условия
6. **`!`** — для инверсии (противоположного значения)

### **Памятка:**
```cpp
// IF/ELSE
if (условие) { /* код */ }
else if (другое_условие) { /* код */ }
else { /* код */ }

// ЛОГИЧЕСКИЕ ОПЕРАЦИИ
if (условие1 && условие2)  // И
if (условие1 || условие2)  // ИЛИ
if (!условие)              // НЕ

// ТЕРНАРНЫЙ
переменная = (условие) ? значение_если_да : значение_если_нет;

// SWITCH
switch (переменная) {
    case значение1: /* код */ break;
    case значение2: /* код */ break;
    default: /* код */
}
```

### **Распространённые ошибки:**
```cpp
// ОШИБКА: присваивание вместо сравнения
if (x = 5)  // НЕПРАВИЛЬНО! Это присваивание
if (x == 5) // ПРАВИЛЬНО! Это сравнение

// ОШИБКА: забыли break в switch
case 1:
    cout << "1";
    // НЕТ break! Выполнится и case 2!

// ОШИБКА: точка с запятой после условия
if (x > 0); {  // НЕПРАВИЛЬНО! Блок выполнится всегда
    cout << "x положительный";
}
```



## 2. Логические операции

### Операторы:
- `&&` — И (AND): оба условия должны быть истинны
- `||` — ИЛИ (OR): хотя бы одно условие должно быть истинно  
- `!` — НЕ (NOT): инвертирует (меняет на противоположное)

```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    bool hasTicket;
    
    cout << "Введите возраст: ";
    cin >> age;
    cout << "Есть ли билет? (1 - да, 0 - нет): ";
    cin >> hasTicket;
    
    // Пример с && (И)
    if (age >= 18 && hasTicket) {  // И возраст ≥ 18, И есть билет
        cout << "Можно войти в клуб" << endl;
    } else {
        cout << "Нельзя войти в клуб" << endl;
    }
    
    // Пример с || (ИЛИ)
    if (age < 7 || age > 65) {  // ИЛИ возраст < 7, ИЛИ возраст > 65
        cout << "Вы имеете право на льготы" << endl;
    }
    
    // Пример с ! (НЕ)
    if (!hasTicket) {  // ЕСЛИ НЕ hasTicket (т.е. если билета нет)
        cout << "Вам нужен билет!" << endl;
    }
    
    // Комбинированный пример
    if ((age >= 12 && age <= 17) || (age >= 60 && hasTicket)) {
        // ИЛИ: (возраст от 12 до 17), ИЛИ: (возраст ≥ 60 И есть билет)
        cout << "Специальные условия" << endl;
    }
    
    return 0;
}
```

**Таблица истинности:**
```
A     B     A && B   A || B   !A
true  true  true     true     false
true  false false    true     false
false true  false    true     true
false false false    false    true
```

---

## 3. Оператор `switch`

### Что это?
Альтернатива цепочке `if/else if`, когда нужно проверить одну переменную на равенство с разными значениями.

```cpp
#include <iostream>
using namespace std;

int main() {
    int dayNumber;
    cout << "Введите номер дня недели (1-7): ";
    cin >> dayNumber;
    
    switch(dayNumber) {  // Проверяем значение переменной dayNumber
        case 1:  // ЕСЛИ dayNumber == 1
            cout << "Понедельник" << endl;
            break;  // Выходим из switch
        
        case 2:  // ЕСЛИ dayNumber == 2
            cout << "Вторник" << endl;
            break;
            
        case 3:
            cout << "Среда" << endl;
            break;
            
        case 4:
            cout << "Четверг" << endl;
            break;
            
        case 5:
            cout << "Пятница" << endl;
            break;
            
        case 6:
            cout << "Суббота" << endl;
            break;
            
        case 7:
            cout << "Воскресенье" << endl;
            break;
            
        default:  // Выполняется, если ни один case не подошел
            cout << "Неверный номер дня!" << endl;
            break;
    }
    
    return 0;
}
```

**Важные моменты:**
- `break;` — обязателен (иначе выполнение "провалится" в следующий case)
- `default:` — необязателен, но хорошая практика
- `switch` работает только с целыми числами и символами

---

## 4. Тернарный оператор `? :`

### Что это?
Сокращенная форма `if/else` для простых присваиваний.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;
    
    // Стандартный if/else:
    int max;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    
    // Тернарный оператор (то же самое в одной строке):
    int max2 = (a > b) ? a : b;
    // Читается так: ЕСЛИ (a > b) ТО a ИНАЧЕ b
    
    cout << "Максимум (if/else): " << max << endl;
    cout << "Максимум (тернарный): " << max2 << endl;
    
    // Еще пример:
    string result = (a == b) ? "числа равны" : "числа разные";
    cout << result << endl;
    
    return 0;
}
```

**Синтаксис:** `условие ? значение_если_истина : значение_если_ложь`

---

## 🧮 ПРИМЕР 1: Простой калькулятор

```cpp
#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;
    
    // Ввод данных
    cout << "Введите первое число: ";
    cin >> num1;  // Считываем первое число
    
    cout << "Введите операцию (+, -, *, /): ";
    cin >> operation;  // Считываем символ операции
    
    cout << "Введите второе число: ";
    cin >> num2;  // Считываем второе число
    
    // Выполнение операции с проверкой
    if (operation == '+') {
        result = num1 + num2;  // Сложение
        cout << num1 << " + " << num2 << " = " << result << endl;
    }
    else if (operation == '-') {
        result = num1 - num2;  // Вычитание
        cout << num1 << " - " << num2 << " = " << result << endl;
    }
    else if (operation == '*') {
        result = num1 * num2;  // Умножение
        cout << num1 << " * " << num2 << " = " << result << endl;
    }
    else if (operation == '/') {
        // Проверка деления на ноль!
        if (num2 != 0) {  // Если делитель не равен нулю
            result = num1 / num2;  // Деление
            cout << num1 << " / " << num2 << " = " << result << endl;
        } else {
            cout << "Ошибка: деление на ноль!" << endl;
        }
    }
    else {  // Если введена неподдерживаемая операция
        cout << "Ошибка: неизвестная операция!" << endl;
    }
    
    return 0;
}
```

---

## 🎯 ПРИМЕР 2: Проверка введенных данных

```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    
    cout << "Введите оценку (0-100): ";
    cin >> score;
    
    // Проверка корректности ввода
    if (score < 0 || score > 100) {  // Если оценка < 0 ИЛИ > 100
        cout << "Ошибка: оценка должна быть от 0 до 100!" << endl;
        return 1;  // Завершаем программу с кодом ошибки
    }
    
    // Определение оценки по буквенной системе
    char grade;
    
    if (score >= 90) {
        grade = 'A';
    } 
    else if (score >= 80) {  // Выполнится только если score < 90
        grade = 'B';
    }
    else if (score >= 70) {  // Выполнится только если score < 80
        grade = 'C';
    }
    else if (score >= 60) {  // Выполнится только если score < 70
        grade = 'D';
    }
    else {  // Выполнится только если score < 60
        grade = 'F';
    }
    
    cout << "Ваша оценка: " << grade << endl;
    
    // Дополнительная проверка с тернарным оператором
    string message = (grade == 'F') ? "Нужно подтянуть знания!" : "Молодец!";
    cout << message << endl;
    
    return 0;
}
```

---

## 🏆 ПРИМЕР 3: Определение времени суток

```cpp
#include <iostream>
using namespace std;

int main() {
    int hour;
    
    cout << "Введите текущий час (0-23): ";
    cin >> hour;
    
    // Проверка корректности
    if (hour < 0 || hour > 23) {
        cout << "Неверное время! Часы должны быть от 0 до 23." << endl;
        return 1;
    }
    
    // Определение времени суток
    cout << "Сейчас ";
    
    if (hour >= 5 && hour < 12) {  // С 5:00 до 11:59
        cout << "утро";
    }
    else if (hour >= 12 && hour < 17) {  // С 12:00 до 16:59
        cout << "день";
    }
    else if (hour >= 17 && hour < 22) {  // С 17:00 до 21:59
        cout << "вечер";
    }
    else {  // С 22:00 до 4:59
        cout << "ночь";
    }
    
    cout << "." << endl;
    
    // Использование switch для конкретных часов
    switch(hour) {
        case 0:
            cout << "Полночь!" << endl;
            break;
        case 12:
            cout << "Полдень!" << endl;
            break;
        case 8:
        case 9:
        case 10:  // Для 8, 9 и 10 выполнится одно и то же
            cout << "Идеальное время для работы!" << endl;
            break;
    }
    
    return 0;
}
```

---

## 📝 Ключевые моменты для запоминания:

### 1. **Синтаксис `if`:**
```cpp
if (условие) {
    // код выполнится, если условие ИСТИННО
}
```

### 2. **Цепочка условий:**
```cpp
if (условие1) {
    // код 1
} else if (условие2) {
    // код 2 (только если условие1 ложно, а условие2 истинно)
} else {
    // код 3 (если все условия ложны)
}
```

### 3. **Логические операторы:**
- `&&` — как "и" в русском: "если идет дождь **И** у меня есть зонт"
- `||` — как "или" в русском: "если у меня есть деньги **ИЛИ** карта"
- `!` — отрицание: "если **НЕ** идет дождь"

### 4. **`switch` vs `if`:**
- Используйте `switch` когда проверяете одну переменную на конкретные значения
- Используйте `if` для сложных условий и диапазонов

### 5. **Всегда проверяйте ввод пользователя!**
```cpp
if (cin.fail()) {  // Проверка на некорректный ввод
    cout << "Ошибка ввода!" << endl;
}
```

---

## 💡 Советы для начинающих:

1. **Всегда используйте фигурные скобки `{}`**, даже если код одна строка
2. **Пишите понятные условия**: `if (age >= 18)` лучше чем `if (age > 17)`
3. **Проверяйте граничные значения**: что будет при 0, при отрицательных числах?
4. **Комментируйте сложные условия**
5. **Тестируйте все возможные варианты**

---

## 🎓 Практическое задание:
Создайте программу, которая:
1. Запрашивает у пользователя температуру
2. Определяет: холодно (< 10°C), тепло (10-25°C), жарко (> 25°C)
3. Проверяет, корректно ли введены данные (температура не ниже -100 и не выше +100)
4. Дополнительно: если температура ниже 0°, выводит "Осторожно, лед!"

Попробуйте решить это задание, используя все изученные конструкции!