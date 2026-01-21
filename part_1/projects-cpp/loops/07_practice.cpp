#include <iostream>
using namespace std;

int main() {
    // Массив с повторяющимися элементами
    int arr[12] = {1, 2, 3, 2, 4, 5, 1, 6, 3, 7, 8, 5};
    int size = 12;
    
    cout << "Исходный массив (" << size << " элементов): ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Создаем новый массив для уникальных элементов
    // Максимальный размер - как у исходного массива
    int uniqueArr[12];
    int uniqueCount = 0;  // счетчик уникальных элементов
    
    // Проходим по всем элементам исходного массива
    for(int i = 0; i < size; i++) {
        bool isDuplicate = false;  // флаг, указывающий на дубликат
        
        // Проверяем, есть ли текущий элемент уже в массиве уникальных
        for(int j = 0; j < uniqueCount; j++) {
            if(arr[i] == uniqueArr[j]) {
                isDuplicate = true;  // нашли дубликат
                break;  // прерываем внутренний цикл
            }
        }
        
        // Если элемент не дубликат, добавляем его в массив уникальных
        if(!isDuplicate) {
            uniqueArr[uniqueCount] = arr[i];
            uniqueCount++;  // увеличиваем счетчик уникальных элементов
        }
    }
    
    cout << "\nМассив без дубликатов (" << uniqueCount << " элементов): ";
    for(int i = 0; i < uniqueCount; i++) {
        cout << uniqueArr[i] << " ";
    }
    cout << endl;
    
    return 0;
}