#include <iostream>

// Функция для объединения двух массивов
// Возвращает указатель на новый массив
int* mergeArrays(const int* arr1, int size1, const int* arr2, int size2) {
    // Вычисляем общий размер
    int totalSize = size1 + size2;
    
    // Выделяем память для нового массива
    int* merged = new int[totalSize];
    
    // Копируем элементы из первого массива
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    
    // Копируем элементы из второго массива
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
    
    return merged;  // Возвращаем указатель на новый массив
}

// Функция для сортировки массива (простой алгоритм)
void sortArray(int* arr, int size) {
    // Используем простой алгоритм сортировки пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Меняем местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::cout << "=== ОБЪЕДИНЕНИЕ ДВУХ МАССИВОВ ===" << std::endl;
    std::cout << std::endl;
    
    // Создаём два массива
    int array1[] = {3, 7, 1, 9};
    int array2[] = {4, 2, 8, 6, 5};
    
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    
    // Выводим исходные массивы
    std::cout << "Первый массив: ";
    for (int i = 0; i < size1; i++) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Второй массив: ";
    for (int i = 0; i < size2; i++) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Объединяем массивы
    int* merged = mergeArrays(array1, size1, array2, size2);
    int totalSize = size1 + size2;
    
    std::cout << "Объединённый массив: ";
    for (int i = 0; i < totalSize; i++) {
        std::cout << merged[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Сортируем объединённый массив
    sortArray(merged, totalSize);
    
    std::cout << "Отсортированный объединённый массив: ";
    for (int i = 0; i < totalSize; i++) {
        std::cout << merged[i] << " ";
    }
    std::cout << std::endl;
    
    // Освобождаем память
    delete[] merged;
    merged = nullptr;
    
    std::cout << std::endl;
    std::cout << "Память освобождена" << std::endl;
    
    return 0;
}