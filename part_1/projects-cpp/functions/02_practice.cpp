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