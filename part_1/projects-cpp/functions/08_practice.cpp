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