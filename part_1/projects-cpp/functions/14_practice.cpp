#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;
    
    cout << "=== Полный разбор ссылок на указатели ===" << endl;
    cout << "x = " << x << ", y = " << y << endl << endl;
    
    // 1. Базовые типы указателей
    cout << "1. Базовые типы указателей:" << endl;
    cout << "----------------------------" << endl;
    
    int* ptr = &x;                    // указатель на int
    const int* ptr_to_const = &x;     // указатель на const int
    int* const const_ptr = &x;        // константный указатель на int
    const int* const const_ptr_to_const = &x;  // константный указатель на const int
    
    cout << "int* ptr: можно изменить и указатель, и значение" << endl;
    cout << "const int* ptr_to_const: можно изменить указатель, НЕЛЬЗЯ изменить значение" << endl;
    cout << "int* const const_ptr: НЕЛЬЗЯ изменить указатель, можно изменить значение" << endl;
    cout << "const int* const: НЕЛЬЗЯ изменить ни указатель, ни значение" << endl << endl;
    
    // 2. Ссылки на разные типы указателей
    cout << "2. Ссылки на указатели:" << endl;
    cout << "-------------------------" << endl;
    
    // а) Ссылка на обычный указатель
    int*& ref_to_ptr = ptr;
    cout << "int*& ref_to_ptr = ptr;" << endl;
    cout << "  *ptr = " << *ptr << ", *ref_to_ptr = " << *ref_to_ptr << endl;
    
    // Меняем указатель через ссылку
    ref_to_ptr = &y;
    cout << "  После ref_to_ptr = &y:" << endl;
    cout << "  *ptr = " << *ptr << ", *ref_to_ptr = " << *ref_to_ptr << endl;
    cout << "  y = " << y << endl;
    
    // Возвращаем указатель обратно на x
    ptr = &x;
    
    // б) Ссылка на указатель на константу
    const int* ptr2 = &x;
    const int*& ref_to_ptr_to_const = ptr2;  // OK!
    cout << "\nconst int*& ref_to_ptr_to_const = ptr2;" << endl;
    cout << "  *ptr2 = " << *ptr2 << ", *ref_to_ptr_to_const = " << *ref_to_ptr_to_const << endl;
    
    // Можно изменить указатель, но не значение
    ptr2 = &y;
    cout << "  После ptr2 = &y:" << endl;
    cout << "  *ptr2 = " << *ptr2 << endl;
    // *ptr2 = 50;  // ОШИБКА!
    
    // в) Ссылка на константный указатель
    int* const const_ptr2 = &x;
    int* const& ref_to_const_ptr = const_ptr2;  // OK!
    cout << "\nint* const& ref_to_const_ptr = const_ptr2;" << endl;
    cout << "  *const_ptr2 = " << *const_ptr2 << endl;
    
    // Можно изменить значение, но не указатель
    *const_ptr2 = 100;
    cout << "  После *const_ptr2 = 100:" << endl;
    cout << "  x = " << x << endl;
    // const_ptr2 = &y;  // ОШИБКА!
    
    // г) Почему была ошибка в исходном коде?
    cout << "\n3. Разбор ошибки:" << endl;
    cout << "------------------" << endl;
    cout << "Исходная ошибка: const int*& ref = ptr;" << endl;
    cout << "Где ptr имеет тип int*" << endl << endl;
    
    cout << "Проблема: мы пытаемся создать ссылку, которая обещает," << endl;
    cout << "что через нее нельзя изменить значение (const int*), но" << endl;
    cout << "привязываем ее к указателю, который МОЖЕТ изменять значение." << endl << endl;
    
    cout << "Аналогия: обещаем не менять книгу (const), но даем ссылку" << endl;
    cout << "на полку, где лежит обычная книга (не const)." << endl;
    cout << "Кто-то другой может через исходный указатель изменить книгу," << endl;
    cout << "и наше обещание будет нарушено." << endl;
    
    // 4. Правильный способ работы с разными типами
    cout << "\n4. Правильные преобразования:" << endl;
    cout << "------------------------------" << endl;
    
    // Можно преобразовать int* в const int*, но не наоборот
    const int* safe_ptr = ptr;  // OK: добавляем константность
    cout << "const int* safe_ptr = ptr;  // OK" << endl;
    cout << "*safe_ptr = " << *safe_ptr << endl;
    
    // А вот ссылки более строгие:
    // const int*& ref = ptr;  // ОШИБКА!
    // Но можно через промежуточную переменную:
    const int* const_ptr3 = ptr;
    const int*& ref = const_ptr3;  // OK
    cout << "\nЧерез промежуточную переменную:" << endl;
    cout << "const int* const_ptr3 = ptr;" << endl;
    cout << "const int*& ref = const_ptr3;  // OK" << endl;
    
    // 5. Указатель на указатель и ссылки на них
    cout << "\n5. Указатели на указатели:" << endl;
    cout << "----------------------------" << endl;
    
    int** pp = &ptr;  // указатель на указатель
    int**& ref_to_pp = pp;  // ссылка на указатель на указатель
    int*** ppp = &pp;  // указатель на указатель на указатель
    
    cout << "int** pp = &ptr;" << endl;
    cout << "int**& ref_to_pp = pp;" << endl;
    cout << "int*** ppp = &pp;" << endl << endl;
    
    // Работа с двойным разыменованием
    cout << "Значения:" << endl;
    cout << "  x = " << x << endl;
    cout << "  *ptr = " << *ptr << endl;
    cout << "  **pp = " << **pp << endl;
    cout << "  **ref_to_pp = " << **ref_to_pp << endl;
    
    // Меняем x через двойной указатель
    **pp = 999;
    cout << "\n  После **pp = 999:" << endl;
    cout << "  x = " << x << endl;
    cout << "  *ptr = " << *ptr << endl;
    cout << "  **pp = " << **pp << endl;
    
    return 0;
}