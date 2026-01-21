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