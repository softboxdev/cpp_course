#include <iostream>
using namespace std;

int main() {
    // Два исходных массива
    int arr1[4] = {10, 20, 30, 40};
    int arr2[5] = {50, 60, 70, 80, 90};
    
    // Вычисляем размеры массивов
    int size1 = 4;
    int size2 = 5;
    
    // Создаем массив для результата (сумма размеров двух массивов)
    int result[9];  // 4 + 5 = 9
    int resultSize = size1 + size2;
    
    cout << "Первый массив: ";
    for(int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    cout << "Второй массив: ";
    for(int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    // Копируем элементы из первого массива
    for(int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }
    
    // Копируем элементы из второго массива
    // Начинаем с позиции size1 (после последнего элемента первого массива)
    for(int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }
    
    cout << "\nОбъединенный массив: ";
    for(int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    // Дополнительно: сортируем объединенный массив пузырьком
    for(int i = 0; i < resultSize - 1; i++) {
        for(int j = 0; j < resultSize - 1 - i; j++) {
            if(result[j] > result[j + 1]) {
                // Меняем местами
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }
    
    cout << "Отсортированный объединенный массив: ";
    for(int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}