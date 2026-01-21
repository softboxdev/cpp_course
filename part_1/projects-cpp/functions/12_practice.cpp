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