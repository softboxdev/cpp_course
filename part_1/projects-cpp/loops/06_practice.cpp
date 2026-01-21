#include <iostream>
using namespace std;

int main() {
    // Массив с разными числами
    int numbers[10] = {5, -3, 0, 12, -7, 0, 8, -1, 4, -9};
    
    // Счетчики для разных типов чисел
    int positiveCount = 0;  // счетчик положительных чисел
    int negativeCount = 0;  // счетчик отрицательных чисел
    int zeroCount = 0;      // счетчик нулей
    
    cout << "Анализируемый массив: ";
    for(int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
        
        // Проверяем тип текущего числа
        if(numbers[i] > 0) {
            positiveCount++;  // увеличиваем счетчик положительных
        } 
        else if(numbers[i] < 0) {
            negativeCount++;  // увеличиваем счетчик отрицательных
        } 
        else {
            zeroCount++;      // увеличиваем счетчик нулей
        }
    }
    cout << endl;
    
    // Выводим статистику
    cout << "\nСтатистика по массиву:" << endl;
    cout << "Положительных чисел: " << positiveCount << endl;
    cout << "Отрицательных чисел: " << negativeCount << endl;
    cout << "Нулей: " << zeroCount << endl;
    
    // Дополнительно: находим сумму всех положительных чисел
    int positiveSum = 0;
    for(int i = 0; i < 10; i++) {
        if(numbers[i] > 0) {
            positiveSum += numbers[i];
        }
    }
    cout << "Сумма положительных чисел: " << positiveSum << endl;
    
    return 0;
}