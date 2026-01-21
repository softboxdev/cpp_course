
# Объявление и определение функций, параметры по значению/ссылке, возвращаемые значения, рекурсия - Исчерпывающее руководство по указателям и ссылкам в C++

## 📌 Основные понятия

### Что такое указатель?
**Указатель** - это переменная, которая хранит **адрес памяти** другой переменной.

### Что такое ссылка?
**Ссылка** - это псевдоним (алиас) для существующей переменной.

---

## Часть 1: Указатели - полный синтаксис

### 1.1 Базовый синтаксис указателей

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;        // обычная переменная
    int* ptr = &x;     // указатель на int
    
    cout << "Значение x: " << x << endl;           // 10
    cout << "Адрес x: " << &x << endl;            // 0x7fff...
    cout << "Значение ptr: " << ptr << endl;      // 0x7fff... (адрес x)
    cout << "Адрес ptr: " << &ptr << endl;        // адрес самого указателя
    cout << "Значение по адресу ptr: " << *ptr << endl; // 10 (разыменование)
    
    return 0;
}
```

### 1.2 Операторы работы с указателями

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 10;
    
    // 1. Оператор взятия адреса (&)
    int* ptr_a = &a;  // ptr_a хранит адрес a
    int* ptr_b = &b;  // ptr_b хранит адрес b
    
    // 2. Оператор разыменования (*)
    *ptr_a = 20;      // изменяем значение a через указатель
    cout << "a = " << a << endl;  // 20
    
    // 3. Арифметика указателей
    int arr[5] = {10, 20, 30, 40, 50};
    int* arr_ptr = arr;  // указатель на первый элемент
    
    cout << "\nАрифметика указателей:" << endl;
    cout << "arr_ptr = " << arr_ptr << endl;
    cout << "*arr_ptr = " << *arr_ptr << endl;  // 10
    
    arr_ptr++;  // переход к следующему элементу
    cout << "После arr_ptr++:" << endl;
    cout << "arr_ptr = " << arr_ptr << endl;
    cout << "*arr_ptr = " << *arr_ptr << endl;  // 20
    
    arr_ptr += 2;  // сдвиг на 2 элемента вперед
    cout << "После arr_ptr += 2:" << endl;
    cout << "*arr_ptr = " << *arr_ptr << endl;  // 40
    
    arr_ptr--;  // сдвиг на 1 элемент назад
    cout << "После arr_ptr--:" << endl;
    cout << "*arr_ptr = " << *arr_ptr << endl;  // 30
    
    // Разница между указателями
    int* ptr1 = &arr[0];
    int* ptr2 = &arr[3];
    cout << "\nРазница ptr2 - ptr1 = " << (ptr2 - ptr1) << " элементов" << endl; // 3
    
    return 0;
}
```

### 1.3 Указатель на указатель (двойной указатель)

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int* ptr = &x;      // указатель на int
    int** ptr_ptr = &ptr; // указатель на указатель на int
    
    cout << "x = " << x << endl;                // 42
    cout << "&x = " << &x << endl;              // адрес x
    cout << "ptr = " << ptr << endl;            // адрес x
    cout << "*ptr = " << *ptr << endl;          // 42
    
    cout << "\nptr_ptr = " << ptr_ptr << endl;  // адрес ptr
    cout << "*ptr_ptr = " << *ptr_ptr << endl;  // адрес x
    cout << "**ptr_ptr = " << **ptr_ptr << endl;// 42
    
    // Изменение через двойной указатель
    **ptr_ptr = 100;
    cout << "\nПосле **ptr_ptr = 100:" << endl;
    cout << "x = " << x << endl;                // 100
    
    // Тройной указатель
    int*** ptr_ptr_ptr = &ptr_ptr;
    ***ptr_ptr_ptr = 200;
    cout << "После ***ptr_ptr_ptr = 200:" << endl;
    cout << "x = " << x << endl;                // 200
    
    return 0;
}
```

### 1.4 Указатель на массив vs массив указателей

```cpp
#include <iostream>
using namespace std;

int main() {
    // 1. Указатель на массив
    int arr[5] = {1, 2, 3, 4, 5};
    int (*ptr_to_array)[5] = &arr;  // указатель на массив из 5 int
    
    cout << "Указатель на массив:" << endl;
    cout << "arr = " << arr << endl;                  // адрес первого элемента
    cout << "&arr = " << &arr << endl;                // адрес всего массива
    cout << "ptr_to_array = " << ptr_to_array << endl;
    
    // Доступ через указатель на массив
    for(int i = 0; i < 5; i++) {
        cout << (*ptr_to_array)[i] << " ";  // доступ через разыменование
    }
    cout << endl;
    
    // 2. Массив указателей
    int x = 10, y = 20, z = 30;
    int* array_of_pointers[3] = {&x, &y, &z};
    
    cout << "\nМассив указателей:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "array_of_pointers[" << i << "] = " << array_of_pointers[i];
        cout << ", * = " << *array_of_pointers[i] << endl;
    }
    
    // 3. Двумерный массив через указатели
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*ptr_to_matrix)[3] = matrix;  // указатель на массив из 3 int
    
    cout << "\nДоступ к матрице через указатель:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << ptr_to_matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

### 1.5 Указатели на функции

```cpp
#include <iostream>
using namespace std;

// Объявление функций
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
double divide(int a, int b) { return static_cast<double>(a) / b; }

int main() {
    // Указатель на функцию, возвращающую int и принимающую два int
    int (*func_ptr)(int, int);
    
    func_ptr = add;  // присваиваем адрес функции add
    cout << "add(5, 3) = " << func_ptr(5, 3) << endl;  // 8
    
    func_ptr = subtract;
    cout << "subtract(5, 3) = " << func_ptr(5, 3) << endl;  // 2
    
    func_ptr = multiply;
    cout << "multiply(5, 3) = " << func_ptr(5, 3) << endl;  // 15
    
    // Массив указателей на функции
    int (*operations[3])(int, int) = {add, subtract, multiply};
    char* op_names[3] = {"Сложение", "Вычитание", "Умножение"};
    
    cout << "\nМассив указателей на функции:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << op_names[i] << ": " << operations[i](10, 5) << endl;
    }
    
    // Указатель на функцию с другим типом возвращаемого значения
    double (*div_ptr)(int, int) = divide;
    cout << "\nДеление: 10 / 3 = " << div_ptr(10, 3) << endl;
    
    // typedef для упрощения
    typedef int (*MathOperation)(int, int);
    MathOperation op1 = add;
    MathOperation op2 = multiply;
    
    cout << "\nИспользование typedef:" << endl;
    cout << "op1(7, 2) = " << op1(7, 2) << endl;  // 9
    cout << "op2(7, 2) = " << op2(7, 2) << endl;  // 14
    
    return 0;
}
```

### 1.6 const с указателями (4 варианта!)

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;
    
    cout << "=== 4 варианта const с указателями ===" << endl;
    
    // 1. Указатель на константу (pointer to const)
    // Значение нельзя изменить через указатель, но указатель можно перенаправить
    const int* ptr_to_const = &x;
    // *ptr_to_const = 30;  // ОШИБКА: нельзя изменить значение
    ptr_to_const = &y;     // ОК: можно изменить сам указатель
    cout << "1. Указатель на константу: *ptr = " << *ptr_to_const << endl;
    
    // 2. Константный указатель (const pointer)
    // Указатель нельзя перенаправить, но значение можно изменить
    int* const const_ptr = &x;
    *const_ptr = 30;       // ОК: можно изменить значение
    // const_ptr = &y;     // ОШИБКА: нельзя изменить указатель
    cout << "2. Константный указатель: *ptr = " << *const_ptr << endl;
    
    // 3. Константный указатель на константу (const pointer to const)
    // Ничего нельзя изменить
    const int* const const_ptr_to_const = &x;
    // *const_ptr_to_const = 40;  // ОШИБКА
    // const_ptr_to_const = &y;   // ОШИБКА
    cout << "3. Константный указатель на константу: *ptr = " 
         << *const_ptr_to_const << endl;
    
    // 4. Указатель на константный указатель на константу
    const int* const* complex_ptr = &const_ptr_to_const;
    cout << "4. Сложный указатель: **ptr = " << **complex_ptr << endl;
    
    // Практический пример
    cout << "\n=== Практический пример ===" << endl;
    const int data[] = {1, 2, 3, 4, 5};
    const int* data_ptr = data;  // указатель на константу
    
    // Перебор массива
    for(int i = 0; i < 5; i++) {
        cout << "data[" << i << "] = " << *(data_ptr + i) << endl;
        // *(data_ptr + i) = 0;  // ОШИБКА: данные константные
    }
    
    return 0;
}
```

### 1.7 void указатели (универсальные указатели)

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 42;
    double y = 3.14;
    char z = 'A';
    
    // void* может указывать на данные любого типа
    void* void_ptr;
    
    void_ptr = &x;  // указывает на int
    cout << "int value: " << *(static_cast<int*>(void_ptr)) << endl;
    
    void_ptr = &y;  // указывает на double
    cout << "double value: " << *(static_cast<double*>(void_ptr)) << endl;
    
    void_ptr = &z;  // указывает на char
    cout << "char value: " << *(static_cast<char*>(void_ptr)) << endl;
    
    // Пример: функция для вывода значения любого типа
    cout << "\nФункция printAnyValue:" << endl;
    
    // Нельзя разыменовать void* без приведения типа!
    // cout << *void_ptr;  // ОШИБКА
    
    // Массив void указателей
    void* values[3];
    values[0] = &x;
    values[1] = &y;
    values[2] = &z;
    
    char* types[3] = {"int", "double", "char"};
    
    for(int i = 0; i < 3; i++) {
        cout << "Тип " << types[i] << ": ";
        
        if(types[i] == string("int")) {
            cout << *(static_cast<int*>(values[i])) << endl;
        }
        else if(types[i] == string("double")) {
            cout << *(static_cast<double*>(values[i])) << endl;
        }
        else if(types[i] == string("char")) {
            cout << *(static_cast<char*>(values[i])) << endl;
        }
    }
    
    return 0;
}
```

### 1.8 Указатели и динамическая память

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "=== Динамическое выделение памяти ===" << endl;
    
    // 1. Выделение памяти для одного значения
    int* single_ptr = new int(42);
    cout << "Динамическое int: " << *single_ptr << endl;
    
    // 2. Выделение памяти для массива
    int size = 5;
    int* array_ptr = new int[size];
    
    // Заполнение массива
    for(int i = 0; i < size; i++) {
        array_ptr[i] = i * 10;
    }
    
    cout << "Динамический массив: ";
    for(int i = 0; i < size; i++) {
        cout << array_ptr[i] << " ";
    }
    cout << endl;
    
    // 3. Изменение размера массива
    int new_size = 8;
    int* new_array_ptr = new int[new_size];
    
    // Копирование старых данных
    for(int i = 0; i < size && i < new_size; i++) {
        new_array_ptr[i] = array_ptr[i];
    }
    
    // Освобождение старой памяти
    delete[] array_ptr;
    array_ptr = new_array_ptr;
    size = new_size;
    
    cout << "После увеличения размера: ";
    for(int i = 0; i < size; i++) {
        cout << array_ptr[i] << " ";
    }
    cout << endl;
    
    // 4. Двумерный динамический массив
    int rows = 3, cols = 4;
    int** matrix = new int*[rows];
    
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = i * 10 + j;
        }
    }
    
    cout << "\nДинамическая матрица " << rows << "x" << cols << ":" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // 5. ОСВОБОЖДЕНИЕ ПАМЯТИ (ВАЖНО!)
    delete single_ptr;      // для одиночного значения
    delete[] array_ptr;     // для массива
    
    // Для двумерного массива
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    // 6. Указатель после delete
    int* ptr = new int(100);
    delete ptr;
    ptr = nullptr;  // хорошая практика
    
    // Проверка на nullptr перед использованием
    if(ptr != nullptr) {
        cout << "Значение: " << *ptr << endl;
    } else {
        cout << "Указатель nullptr" << endl;
    }
    
    return 0;
}
```

---

## Часть 2: Ссылки - полный синтаксис

### 2.1 Базовый синтаксис ссылок

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    
    // Объявление ссылки (должна быть инициализирована сразу)
    int& ref = x;  // ref - это псевдоним для x
    
    cout << "x = " << x << endl;        // 10
    cout << "ref = " << ref << endl;    // 10
    cout << "&x = " << &x << endl;      // адрес x
    cout << "&ref = " << &ref << endl;  // тот же адрес
    
    // Изменение через ссылку изменяет оригинальную переменную
    ref = 20;
    cout << "\nПосле ref = 20:" << endl;
    cout << "x = " << x << endl;        // 20
    cout << "ref = " << ref << endl;    // 20
    
    // Ссылка не может быть перенаправлена!
    int y = 30;
    // ref = y;  // Это присвоение значения, не перенаправление ссылки
    ref = y;     // x = 30, ref = 30, но ref все еще ссылается на x
    cout << "\nПосле ref = y (y=30):" << endl;
    cout << "x = " << x << endl;        // 30
    cout << "ref = " << ref << endl;    // 30
    cout << "y = " << y << endl;        // 30
    
    // Можно создать ссылку на ссылку (фактически, ссылку на ту же переменную)
    int& ref_ref = ref;  // ref_ref тоже ссылается на x
    ref_ref = 40;
    cout << "\nПосле ref_ref = 40:" << endl;
    cout << "x = " << x << endl;        // 40
    
    return 0;
}
```

### 2.2 Ссылки как параметры функций

```cpp
#include <iostream>
using namespace std;

// 1. Параметр по значению (копия)
void incrementByValue(int x) {
    x++;
    cout << "Внутри incrementByValue: x = " << x << endl;
}

// 2. Параметр по ссылке (работа с оригиналом)
void incrementByReference(int& x) {
    x++;
    cout << "Внутри incrementByReference: x = " << x << endl;
}

// 3. Константная ссылка (чтение без копирования)
void printValue(const int& x) {
    // x = 100;  // ОШИБКА: нельзя изменить константную ссылку
    cout << "Внутри printValue: x = " << x << endl;
}

// 4. Возврат ссылки (ОПАСНО, если возвращается ссылка на локальную переменную)
int& getElement(int arr[], int index) {
    return arr[index];  // OK: возвращаем ссылку на элемент массива
}

// НЕПРАВИЛЬНО: возврат ссылки на локальную переменную
int& badFunction() {
    int x = 100;        // локальная переменная
    return x;           // ОШИБКА: x уничтожится после выхода из функции
}

int main() {
    int a = 5;
    
    cout << "До incrementByValue: a = " << a << endl;
    incrementByValue(a);
    cout << "После incrementByValue: a = " << a << endl;  // не изменился
    
    cout << "\nДо incrementByReference: a = " << a << endl;
    incrementByReference(a);
    cout << "После incrementByReference: a = " << a << endl;  // изменился!
    
    cout << "\nВызов printValue: ";
    printValue(a);
    
    // Работа с возвращаемой ссылкой
    int arr[5] = {10, 20, 30, 40, 50};
    getElement(arr, 2) = 999;  // изменяем элемент через возвращенную ссылку
    
    cout << "\nПосле getElement(arr, 2) = 999:" << endl;
    cout << "arr[2] = " << arr[2] << endl;  // 999
    
    return 0;
}
```

### 2.3 Ссылки на массивы

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    
    // 1. Ссылка на массив фиксированного размера
    int (&ref_to_array)[5] = arr;
    
    cout << "Ссылка на массив:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "ref_to_array[" << i << "] = " << ref_to_array[i] << endl;
    }
    
    // 2. Изменение через ссылку
    ref_to_array[0] = 100;
    cout << "\nПосле ref_to_array[0] = 100:" << endl;
    cout << "arr[0] = " << arr[0] << endl;  // 100
    
    // 3. Ссылка на массив как параметр функции
    auto printArray = [](int (&array)[5]) {
        cout << "В функции: ";
        for(int i = 0; i < 5; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    };
    
    printArray(arr);
    
    // 4. Ссылка на двумерный массив
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (&ref_to_matrix)[2][3] = matrix;
    
    cout << "\nСсылка на матрицу:" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << ref_to_matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

### 2.4 const со ссылками

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    const int y = 20;
    
    cout << "=== const со ссылками ===" << endl;
    
    // 1. Обычная ссылка на неконстантную переменную
    int& ref1 = x;        // OK
    // int& ref2 = y;     // ОШИБКА: нельзя ссылаться на const через не-const ссылку
    
    // 2. Константная ссылка на неконстантную переменную
    const int& cref1 = x;  // OK: доступ только для чтения
    cout << "cref1 = " << cref1 << endl;
    // cref1 = 30;        // ОШИБКА: нельзя изменить через const ссылку
    
    // 3. Константная ссылка на константную переменную
    const int& cref2 = y;  // OK
    cout << "cref2 = " << cref2 << endl;
    
    // 4. Временные объекты и const ссылки
    const int& temp_ref = 42;  // OK: const ссылка может ссылаться на временное значение
    cout << "temp_ref = " << temp_ref << endl;
    
    // int& bad_temp_ref = 42;  // ОШИБКА: не-const ссылка не может ссылаться на временное значение
    
    // 5. Константная ссылка продлевает время жизни временного объекта
    const int& extended_life = x + y;  // временный объект живет, пока жива ссылка
    cout << "extended_life = " << extended_life << endl;
    
    // Практический пример
    cout << "\n=== Практический пример ===" << endl;
    int a = 5, b = 3;
    
    // Функция, возвращающая константную ссылку на больший аргумент
    auto& max_ref = (a > b) ? a : b;
    const auto& max_cref = (a > b) ? a : b;
    
    max_ref = 100;  // можно изменить
    // max_cref = 100;  // ОШИБКА
    
    cout << "a = " << a << ", b = " << b << endl;
    
    return 0;
}
```

### 2.5 Ссылки на указатели и указатели на ссылки

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;
    
    cout << "=== Ссылки на указатели ===" << endl;
    
    // 1. Ссылка на указатель
    int*& ref_to_ptr = ptr;  // ссылка на указатель
    
    cout << "x = " << x << endl;              // 10
    cout << "*ptr = " << *ptr << endl;        // 10
    cout << "*ref_to_ptr = " << *ref_to_ptr << endl;  // 10
    
    // Изменяем указатель через ссылку
    int y = 20;
    ref_to_ptr = &y;  // теперь ptr указывает на y
    
    cout << "\nПосле ref_to_ptr = &y:" << endl;
    cout << "*ptr = " << *ptr << endl;        // 20
    cout << "*ref_to_ptr = " << *ref_to_ptr << endl;  // 20
    cout << "x = " << x << endl;              // 10 (не изменилось)
    
    // 2. Указатель на ссылку - НЕ СУЩЕСТВУЕТ!
    // int&* ptr_to_ref = &x;  // ОШИБКА: нельзя создать указатель на ссылку
    
    // 3. Ссылка на константный указатель
    int* const& ref_to_const_ptr = ptr;
    // ref_to_const_ptr = &x;  // ОШИБКА: нельзя изменить указатель через ссылку
    *ref_to_const_ptr = 30;    // OK: можно изменить значение
    
    cout << "\nПосле *ref_to_const_ptr = 30:" << endl;
    cout << "y = " << y << endl;  // 30
    
    // 4. Ссылка на указатель на константу
    const int*& ref_to_ptr_to_const = ptr;
    // *ref_to_ptr_to_const = 40;  // ОШИБКА: нельзя изменить значение через указатель на константу
    
    // 5. Сложный пример: ссылка на указатель на указатель
    int** ptr_ptr = &ptr;
    int**& ref_to_ptr_ptr = ptr_ptr;
    
    cout << "\nСсылка на указатель на указатель:" << endl;
    cout << "**ptr_ptr = " << **ptr_ptr << endl;            // 30
    cout << "**ref_to_ptr_ptr = " << **ref_to_ptr_ptr << endl;  // 30
    
    return 0;
}
```

### 2.6 Rvalue-ссылки (C++11 и выше)

```cpp
#include <iostream>
#include <utility>  // для std::move
using namespace std;

int main() {
    cout << "=== Rvalue-ссылки (C++11) ===" << endl;
    
    int x = 10;
    
    // Lvalue-ссылка (обычная ссылка)
    int& lref = x;  // OK: x - lvalue
    
    // Rvalue-ссылка (ссылка на временное значение)
    int&& rref = 20;  // OK: 20 - rvalue
    cout << "rref = " << rref << endl;  // 20
    
    // Rvalue-ссылка на временный объект
    int&& rref2 = x + 5;  // OK: x+5 - rvalue
    cout << "rref2 = " << rref2 << endl;  // 15
    
    // Нельзя создать lvalue-ссылку на rvalue
    // int& bad_ref = 30;  // ОШИБКА
    
    // Пример с std::move
    cout << "\nИспользование std::move:" << endl;
    
    string str1 = "Hello";
    string str2 = "World";
    
    cout << "До move:" << endl;
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    
    // Перемещение содержимого (без копирования)
    str2 = std::move(str1);
    
    cout << "\nПосле str2 = std::move(str1):" << endl;
    cout << "str1 = " << str1 << endl;  // пустая или в неопределенном состоянии
    cout << "str2 = " << str2 << endl;  // "Hello"
    
    // Пример функции с rvalue-ссылкой
    auto processValue = [](int&& val) {
        cout << "Обработка rvalue: " << val << endl;
    };
    
    auto processLValue = [](int& val) {
        cout << "Обработка lvalue: " << val << endl;
    };
    
    cout << "\nВызов функций:" << endl;
    processValue(42);      // OK: 42 - rvalue
    // processValue(x);    // ОШИБКА: x - lvalue
    
    processLValue(x);      // OK: x - lvalue
    // processLValue(42);  // ОШИБКА: 42 - rvalue
    
    // Универсальная ссылка (шаблонная rvalue-ссылка)
    auto universalRef = [](auto&& param) {
        cout << "Универсальная ссылка: " << param << endl;
    };
    
    cout << "\nУниверсальные ссылки:" << endl;
    universalRef(x);   // OK: lvalue
    universalRef(42);  // OK: rvalue
    
    return 0;
}
```

---

## Часть 3: Сравнение указателей и ссылок

### 3.1 Основные различия

```cpp
#include <iostream>
using namespace std;

void comparePointersAndReferences() {
    int x = 10;
    int y = 20;
    
    cout << "=== Сравнение указателей и ссылок ===" << endl;
    
    // УКАЗАТЕЛИ:
    int* ptr = &x;
    cout << "\nУказатели:" << endl;
    cout << "1. Могут быть nullptr: " << (ptr == nullptr ? "да" : "нет") << endl;
    cout << "2. Можно перенаправить: ";
    ptr = &y;
    cout << "теперь указывает на y, *ptr = " << *ptr << endl;
    cout << "3. Имеют свой адрес: &ptr = " << &ptr << endl;
    cout << "4. Требуют разыменования: *ptr для доступа к значению" << endl;
    
    // ССЫЛКИ:
    int& ref = x;
    cout << "\nСсылки:" << endl;
    cout << "1. Не могут быть nullptr" << endl;
    cout << "2. Нельзя перенаправить после инициализации" << endl;
    cout << "3. Не имеют своего адреса: &ref = адрес x = " << &ref << endl;
    cout << "4. Не требуют разыменования: ref напрямую дает значение" << endl;
    
    // Инициализация:
    cout << "\nИнициализация:" << endl;
    // int* ptr2;  // ОК: неинициализированный указатель (опасно!)
    // int& ref2;  // ОШИБКА: ссылка должна быть инициализирована
    
    // Арифметика:
    cout << "\nАрифметика:" << endl;
    cout << "Указатели: можно ptr++, ptr--, ptr + n" << endl;
    cout << "Ссылки: арифметики нет" << endl;
    
    // Размер:
    cout << "\nРазмер в памяти:" << endl;
    cout << "sizeof(ptr) = " << sizeof(ptr) << " байт" << endl;
    cout << "sizeof(ref) = " << sizeof(ref) << " байт (размер типа)" << endl;
    
    // Массивы:
    cout << "\nРабота с массивами:" << endl;
    int arr[3] = {1, 2, 3};
    int* arr_ptr = arr;  // OK
    // int& arr_ref = arr;  // ОШИБКА: нужен конкретный синтаксис для ссылки на массив
    int (&arr_ref)[3] = arr;  // правильный синтаксис
}
```

### 3.2 Когда что использовать

```cpp
#include <iostream>
#include <vector>
using namespace std;

// ✅ ИСПОЛЬЗОВАТЬ ССЫЛКИ:
// 1. Параметры функций для модификации
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. Для избежания копирования больших объектов
void processVector(const vector<int>& vec) {
    // Без копирования, только чтение
    for(const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

// 3. Возврат элемента из контейнера
int& getElement(vector<int>& vec, size_t index) {
    return vec[index];  // возвращаем ссылку на элемент
}

// ✅ ИСПОЛЬЗОВАТЬ УКАЗАТЕЛИ:
// 1. Динамическое выделение памяти
int* createArray(int size) {
    return new int[size];
}

// 2. Когда параметр может отсутствовать
void printIfNotNull(const int* ptr) {
    if(ptr != nullptr) {
        cout << "Значение: " << *ptr << endl;
    } else {
        cout << "Указатель равен nullptr" << endl;
    }
}

// 3. Работа с массивами в C-стиле
void processCArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// 4. Полиморфизм и наследование
class Base {
public:
    virtual void print() { cout << "Base" << endl; }
};

class Derived : public Base {
public:
    void print() override { cout << "Derived" << endl; }
};

void polymorphicExample() {
    Derived d;
    Base* ptr = &d;  // указатель для полиморфизма
    ptr->print();    // вызовет Derived::print()
}

int main() {
    cout << "=== Рекомендации по использованию ===" << endl;
    
    // Пример 1: Ссылки лучше для простых случаев
    int a = 5, b = 10;
    swap(a, b);
    cout << "После swap: a=" << a << ", b=" << b << endl;
    
    // Пример 2: Указатели для опциональных параметров
    int x = 42;
    printIfNotNull(&x);
    printIfNotNull(nullptr);
    
    // Пример 3: Ссылки для возврата значений
    vector<int> vec = {1, 2, 3, 4, 5};
    getElement(vec, 2) = 100;  // изменяем элемент через ссылку
    
    cout << "\nВектор после изменения: ";
    processVector(vec);
    
    // Пример 4: Указатели для динамической памяти
    int* dynamic_arr = createArray(5);
    for(int i = 0; i < 5; i++) {
        dynamic_arr[i] = i * 10;
    }
    
    cout << "\nДинамический массив: ";
    for(int i = 0; i < 5; i++) {
        cout << dynamic_arr[i] << " ";
    }
    cout << endl;
    
    delete[] dynamic_arr;
    
    return 0;
}
```

---

## Часть 4: Продвинутые примеры

### 4.1 Умные указатели (C++11 и выше)

```cpp
#include <iostream>
#include <memory>  // для умных указателей
using namespace std;

class Resource {
public:
    Resource() { cout << "Resource создан" << endl; }
    ~Resource() { cout << "Resource уничтожен" << endl; }
    void use() { cout << "Resource используется" << endl; }
};

int main() {
    cout << "=== Умные указатели ===" << endl;
    
    // 1. unique_ptr - эксклюзивное владение
    {
        cout << "\n=== unique_ptr ===" << endl;
        unique_ptr<Resource> ptr1(new Resource());
        // unique_ptr<Resource> ptr2 = ptr1;  // ОШИБКА: нельзя копировать
        unique_ptr<Resource> ptr2 = move(ptr1);  // можно перемещать
        
        if(ptr1) cout << "ptr1 владеет ресурсом" << endl;
        else cout << "ptr1 не владеет ресурсом" << endl;
        
        ptr2->use();
    } // ресурс автоматически удаляется
    
    // 2. shared_ptr - разделяемое владение (счетчик ссылок)
    {
        cout << "\n=== shared_ptr ===" << endl;
        shared_ptr<Resource> ptr1 = make_shared<Resource>();
        {
            shared_ptr<Resource> ptr2 = ptr1;  // можно копировать
            cout << "Количество ссылок: " << ptr1.use_count() << endl;  // 2
            
            shared_ptr<Resource> ptr3 = ptr1;
            cout << "Количество ссылок: " << ptr1.use_count() << endl;  // 3
        } // ptr2 и ptr3 уничтожаются
        
        cout << "Количество ссылок: " << ptr1.use_count() << endl;  // 1
        ptr1->use();
    } // ресурс удаляется, когда счетчик становится 0
    
    // 3. weak_ptr - слабая ссылка (не увеличивает счетчик)
    {
        cout << "\n=== weak_ptr ===" << endl;
        shared_ptr<Resource> shared = make_shared<Resource>();
        weak_ptr<Resource> weak = shared;
        
        cout << "Количество ссылок shared: " << shared.use_count() << endl;  // 1
        
        if(auto temp = weak.lock()) {  // создаем shared_ptr из weak_ptr
            cout << "Ресурс еще существует" << endl;
            temp->use();
        }
        
        shared.reset();  // удаляем ресурс
        
        if(auto temp = weak.lock()) {
            cout << "Ресурс еще существует" << endl;
        } else {
            cout << "Ресурс уже удален" << endl;
        }
    }
    
    // 4. Пользовательский делитер
    {
        cout << "\n=== Пользовательский делитер ===" << endl;
        auto custom_deleter = [](Resource* res) {
            cout << "Пользовательский делитер вызывается" << endl;
            delete res;
        };
        
        unique_ptr<Resource, decltype(custom_deleter)> 
            ptr(new Resource(), custom_deleter);
        ptr->use();
    }
    
    return 0;
}
```

### 4.2 Функциональные объекты и указатели на члены класса

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
public:
    string name;
    int age;
    
    Person(string n, int a) : name(n), age(a) {}
    
    void print() const {
        cout << name << " (" << age << " лет)" << endl;
    }
    
    bool isAdult() const {
        return age >= 18;
    }
};

int main() {
    cout << "=== Указатели на члены класса ===" << endl;
    
    vector<Person> people = {
        Person("Анна", 25),
        Person("Борис", 17),
        Person("Виктор", 30),
        Person("Галина", 16)
    };
    
    // 1. Указатель на член-данные
    int Person::* age_ptr = &Person::age;
    string Person::* name_ptr = &Person::name;
    
    cout << "\nДоступ через указатели на члены:" << endl;
    for(auto& person : people) {
        cout << person.*name_ptr << ": " << person.*age_ptr << endl;
    }
    
    // 2. Указатель на метод класса
    void (Person::* print_ptr)() const = &Person::print;
    bool (Person::* adult_ptr)() const = &Person::isAdult;
    
    cout << "\nВызов методов через указатели:" << endl;
    for(auto& person : people) {
        (person.*print_ptr)();
        cout << "Совершеннолетний: " << ((person.*ad_ptr)() ? "да" : "нет") << endl;
    }
    
    // 3. Использование с алгоритмами STL
    cout << "\nСовершеннолетние люди:" << endl;
    for(auto& person : people) {
        if((person.*adult_ptr)()) {
            (person.*print_ptr)();
        }
    }
    
    // 4. std::function и указатели на методы
    cout << "\nИспользование std::function:" << endl;
    vector<function<void()>> callbacks;
    
    for(auto& person : people) {
        // Захватываем person по ссылке и вызываем метод через указатель
        callbacks.push_back([&person, print_ptr]() {
            (person.*print_ptr)();
        });
    }
    
    for(auto& callback : callbacks) {
        callback();
    }
    
    return 0;
}
```

### 4.3 typeid и указатели

```cpp
#include <iostream>
#include <typeinfo>  // для typeid
using namespace std;

class Base {
public:
    virtual ~Base() {}  // виртуальный деструктор для полиморфизма
};

class Derived : public Base {};

int main() {
    cout << "=== typeid и указатели ===" << endl;
    
    int x = 10;
    double y = 3.14;
    Base base;
    Derived derived;
    
    // typeid для обычных переменных
    cout << "typeid(x) = " << typeid(x).name() << endl;
    cout << "typeid(y) = " << typeid(y).name() << endl;
    cout << "typeid(base) = " << typeid(base).name() << endl;
    cout << "typeid(derived) = " << typeid(derived).name() << endl;
    
    // typeid для указателей (без разыменования)
    Base* ptr1 = &base;
    Base* ptr2 = &derived;
    
    cout << "\nДля указателей:" << endl;
    cout << "typeid(ptr1) = " << typeid(ptr1).name() << endl;    // Base*
    cout << "typeid(ptr2) = " << typeid(ptr2).name() << endl;    // Base*
    cout << "typeid(*ptr1) = " << typeid(*ptr1).name() << endl;  // Base
    cout << "typeid(*ptr2) = " << typeid(*ptr2).name() << endl;  // Derived (полиморфизм!)
    
    // Сравнение типов
    cout << "\nСравнение типов:" << endl;
    cout << "typeid(x) == typeid(int): " << (typeid(x) == typeid(int)) << endl;
    cout << "typeid(ptr1) == typeid(Base*): " << (typeid(ptr1) == typeid(Base*)) << endl;
    cout << "typeid(*ptr1) == typeid(Base): " << (typeid(*ptr1) == typeid(Base)) << endl;
    cout << "typeid(*ptr2) == typeid(Derived): " << (typeid(*ptr2) == typeid(Derived)) << endl;
    
    // Динамическое приведение типов
    cout << "\nДинамическое приведение типов:" << endl;
    Base* bptr = &derived;
    
    // dynamic_cast возвращает nullptr при неудаче
    Derived* dptr = dynamic_cast<Derived*>(bptr);
    if(dptr) {
        cout << "Приведение успешно" << endl;
    }
    
    // Для ссылок dynamic_cast бросает исключение при неудаче
    try {
        Derived& dref = dynamic_cast<Derived&>(*bptr);
        cout << "Приведение ссылки успешно" << endl;
    } catch(const bad_cast& e) {
        cout << "Приведение не удалось: " << e.what() << endl;
    }
    
    return 0;
}
```

---

## Часть 5: Практические задания

### Задание 1: Реализация связного списка

```cpp
#include <iostream>
using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    
    Node* head;
    
public:
    LinkedList() : head(nullptr) {}
    
    ~LinkedList() {
        Node* current = head;
        while(current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    void add(T val) {
        Node* new_node = new Node(val);
        if(!head) {
            head = new_node;
        } else {
            Node* current = head;
            while(current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    
    void print() const {
        Node* current = head;
        while(current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    
    // Другие методы: удаление, поиск, реверс и т.д.
};

int main() {
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.print();
    
    LinkedList<string> str_list;
    str_list.add("Hello");
    str_list.add("World");
    str_list.print();
    
    return 0;
}
```

### Задание 2: Умный массив с копированием при записи

```cpp
#include <iostream>
#include <cstring>
using namespace std;

class SmartString {
private:
    struct StringData {
        char* data;
        size_t length;
        int ref_count;
        
        StringData(const char* str) {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
            ref_count = 1;
        }
        
        ~StringData() {
            delete[] data;
        }
    };
    
    StringData* ptr;
    
    void detach() {
        if(ptr && ptr->ref_count > 1) {
            ptr->ref_count--;
            ptr = new StringData(ptr->data);
        }
    }
    
public:
    SmartString(const char* str = "") : ptr(new StringData(str)) {}
    
    SmartString(const SmartString& other) : ptr(other.ptr) {
        ptr->ref_count++;
    }
    
    ~SmartString() {
        if(--ptr->ref_count == 0) {
            delete ptr;
        }
    }
    
    SmartString& operator=(const SmartString& other) {
        if(this != &other) {
            if(--ptr->ref_count == 0) {
                delete ptr;
            }
            ptr = other.ptr;
            ptr->ref_count++;
        }
        return *this;
    }
    
    char& operator[](size_t index) {
        detach();
        return ptr->data[index];
    }
    
    const char& operator[](size_t index) const {
        return ptr->data[index];
    }
    
    const char* c_str() const {
        return ptr->data;
    }
    
    int get_ref_count() const {
        return ptr->ref_count;
    }
};

int main() {
    SmartString s1 = "Hello";
    SmartString s2 = s1;  // копирование, без дублирования данных
    
    cout << "После создания:" << endl;
    cout << "s1: " << s1.c_str() << " (refs: " << s1.get_ref_count() << ")" << endl;
    cout << "s2: " << s2.c_str() << " (refs: " << s2.get_ref_count() << ")" << endl;
    
    s2[0] = 'J';  // копирование при записи
    
    cout << "\nПосле модификации s2:" << endl;
    cout << "s1: " << s1.c_str() << " (refs: " << s1.get_ref_count() << ")" << endl;
    cout << "s2: " << s2.c_str() << " (refs: " << s2.get_ref_count() << ")" << endl;
    
    return 0;
}
```

---

## 📚 Итоговая таблица сравнения

| Характеристика | Указатели | Ссылки |
|----------------|-----------|--------|
| **Инициализация** | Можно объявить без инициализации | Должны быть инициализированы сразу |
| **nullptr** | Могут быть nullptr | Не могут быть nullptr |
| **Перенаправление** | Можно перенаправить | Нельзя перенаправить после инициализации |
| **Разыменование** | Требуют * для доступа к значению | Не требуют разыменования |
| **Арифметика** | Поддерживают арифметику | Не поддерживают арифметику |
| **Свой адрес** | Имеют свой адрес (&ptr) | Не имеют своего адреса (&ref = адрес объекта) |
| **Размер** | sizeof(ptr) = размер указателя | sizeof(ref) = размер объекта |
| **Массивы** | int* ptr = arr | int (&ref)[N] = arr |
| **const варианты** | 4 варианта (см. выше) | 2 варианта (const &, &) |
| **Безопасность** | Менее безопасны | Более безопасны |

## 🎯 Золотые правила

1. **Используйте ссылки**, когда:
   - Параметр должен быть всегда валидным
   - Нужно изменить оригинальный объект
   - Хотите избежать копирования больших объектов
   - Работаете с существующими переменными

2. **Используйте указатели**, когда:
   - Параметр может отсутствовать (nullptr)
   - Работаете с динамической памятью
   - Нужна арифметика указателей
   - Реализуете структуры данных
   - Работаете с полиморфизмом

3. **Всегда используйте `const`** там, где это возможно
4. **Используйте умные указатели** вместо сырых для динамической памяти
5. **Проверяйте указатели на nullptr** перед использованием
6. **Не возвращайте ссылки/указатели на локальные переменные**

Это полное руководство покрывает все аспекты работы с указателями и ссылками в C++. Практикуйтесь с каждым примером, чтобы глубоко понять различия и правильно выбирать нужный инструмент для каждой задачи!
