#include <iostream>
using namespace std;

int main() {
    // Массив с числами
    int numbers[8] = {23, 45, 67, 12, 89, 34, 56, 78};
    
    // Число, которое будем искать
    int searchNumber;
    
    // Переменная для хранения индекса найденного элемента
    // -1 означает, что элемент еще не найден
    int foundIndex = -1;
    
    // Переменная для хранения минимального значения в массиве
    int minValue = numbers[0];
    // Индекс минимального значения
    int minIndex = 0;
    
    cout << "Массив: ";
    for(int i = 0; i < 8; i++) {
        cout << numbers[i] << " ";
        
        // Заодно ищем минимальный элемент и его индекс
        if(numbers[i] < minValue) {
            minValue = numbers[i];
            minIndex = i;
        }
    }
    cout << endl;
    
    // Выводим информацию о минимальном элементе
    cout << "Минимальный элемент: " << minValue << endl;
    cout << "Его индекс в массиве: " << minIndex << endl;
    
    // Запрашиваем у пользователя число для поиска
    cout << "Введите число для поиска: ";
    cin >> searchNumber;
    
    // Ищем число в массиве
    for(int i = 0; i < 8; i++) {
        if(numbers[i] == searchNumber) {
            foundIndex = i; // Запоминаем индекс найденного элемента
            break; // Прерываем цикл, так как элемент найден
        }
    }
    
    // Выводим результат поиска
    if(foundIndex != -1) {
        cout << "Число " << searchNumber << " найдено на позиции " << foundIndex << endl;
    } else {
        cout << "Число " << searchNumber << " не найдено в массиве" << endl;
    }
    
    return 0;
}