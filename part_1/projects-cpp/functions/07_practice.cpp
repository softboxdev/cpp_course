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