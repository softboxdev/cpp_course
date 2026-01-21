// 03_practice.cpp

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