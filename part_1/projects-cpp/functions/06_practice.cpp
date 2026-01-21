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