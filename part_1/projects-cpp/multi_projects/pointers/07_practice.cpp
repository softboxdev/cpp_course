#include <iostream>
using namespace std;

void basicPointerOperations() {
    /*
    ЗАДАЧА: Понять основы работы с указателями.
    ВОПРОСЫ :
    1. Что такое указатель?
    2. Как получить адрес переменной?
    3. Как получить значение по указателю?
    4. Что такое разыменование?
    */
    
    cout << "=== ЗАДАЧА 1: БАЗОВЫЕ ОПЕРАЦИИ ===" << endl;
    cout << "================================" << endl;
    
    // 1. Создаем переменную и указатель на нее
    int number = 42;
    int* ptr = &number;  // & - оператор взятия адреса
    
    cout << "1. Базовая работа:" << endl;
    cout << "   number = " << number << endl;
    cout << "   &number = " << &number << " (адрес number)" << endl;
    cout << "   ptr = " << ptr << " (хранит адрес number)" << endl;
    cout << "   *ptr = " << *ptr << " (разыменование - значение по адресу)" << endl;
    
    // 2. Изменяем значение через указатель
    *ptr = 100;  // Меняем number через указатель
    cout << "\n2. После *ptr = 100:" << endl;
    cout << "   number = " << number << " (изменилось!)" << endl;
    cout << "   *ptr = " << *ptr << endl;
    
    // 3. Указатель на другой тип
    double price = 99.99;
    double* pricePtr = &price;
    cout << "\n3. Указатель на double:" << endl;
    cout << "   price = " << price << endl;
    cout << "   *pricePtr = " << *pricePtr << endl;
    
    // 4. Указатель на указатель
    int** ptrToPtr = &ptr;
    cout << "\n4. Указатель на указатель:" << endl;
    cout << "   ptrToPtr = " << ptrToPtr << " (адрес указателя ptr)" << endl;
    cout << "   *ptrToPtr = " << *ptrToPtr << " (значение ptr - адрес number)" << endl;
    cout << "   **ptrToPtr = " << **ptrToPtr << " (значение number)" << endl;
    
    // 5. Null указатель
    int* nullPtr = nullptr;
    cout << "\n5. Null указатель:" << endl;
    cout << "   nullPtr = " << nullPtr << endl;
    // *nullPtr = 5;  // ОШИБКА: segmentation fault!
    
    // 6. Проверка перед использованием
    if (nullPtr != nullptr) {
        *nullPtr = 10;  // Не выполнится
    } else {
        cout << "   Указатель равен nullptr, использовать нельзя!" << endl;
    }
}

void arrayAndPointerRelationship() {
    /*
    ЗАДАЧА: Понять связь массивов и указателей.
    ВОПРОСЫ:
    1. Как массив связан с указателем?
    2. Что такое арифметика указателей?
    3. Как получить доступ к элементам массива через указатели?
    */
    
    cout << "\n\n=== ЗАДАЧА 2: МАССИВЫ И УКАЗАТЕЛИ ===" << endl;
    cout << "==================================" << endl;
    
    int arr[5] = {10, 20, 30, 40, 50};
    
    // 1. Имя массива - указатель на первый элемент
    cout << "1. Имя массива как указатель:" << endl;
    cout << "   arr = " << arr << " (адрес первого элемента)" << endl;
    cout << "   &arr[0] = " << &arr[0] << " (то же самое!)" << endl;
    cout << "   *arr = " << *arr << " (первый элемент)" << endl;
    
    // 2. Арифметика указателей
    cout << "\n2. Арифметика указателей:" << endl;
    int* ptr = arr;  // ptr указывает на arr[0]
    
    cout << "   ptr = " << ptr << " → *ptr = " << *ptr << endl;
    ptr++;  // Перемещаемся к следующему элементу
    cout << "   После ptr++:" << endl;
    cout << "   ptr = " << ptr << " → *ptr = " << *ptr << " (arr[1])" << endl;
    
    ptr += 2;  // Перемещаемся на 2 элемента вперед
    cout << "   После ptr += 2:" << endl;
    cout << "   ptr = " << ptr << " → *ptr = " << *ptr << " (arr[3])" << endl;
    
    ptr--;  // Назад на один элемент
    cout << "   После ptr--:" << endl;
    cout << "   ptr = " << ptr << " → *ptr = " << *ptr << " (arr[2])" << endl;
    
    // 3. Разные способы доступа к элементам
    cout << "\n3. Способы доступа к элементам:" << endl;
    cout << "   arr[2] = " << arr[2] << endl;
    cout << "   *(arr + 2) = " << *(arr + 2) << endl;
    cout << "   2[arr] = " << 2[arr] << " (работает, но не используйте!)" << endl;
    
    // 4. Итерация по массиву через указатели
    cout << "\n4. Итерация через указатели:" << endl;
    cout << "   Массив: ";
    for (int* p = arr; p < arr + 5; p++) {
        cout << *p << " ";
    }
    cout << endl;
    
    // 5. Указатель на весь массив vs указатель на элемент
    cout << "\n5. Разница указателей:" << endl;
    int (*ptrToArray)[5] = &arr;  // Указатель на массив из 5 int
    int* ptrToElement = arr;      // Указатель на int
    
    cout << "   sizeof(ptrToArray) = " << sizeof(ptrToArray) << " (размер указателя)" << endl;
    cout << "   sizeof(ptrToElement) = " << sizeof(ptrToElement) << " (тоже размер указателя)" << endl;
    cout << "   sizeof(arr) = " << sizeof(arr) << " (размер всего массива: 5 * sizeof(int))" << endl;
}

int main()  {
    basicPointerOperations();
    arrayAndPointerRelationship();
    return 0;
}