#include <iostream>
using namespace std;

int main() {
    
    int number;
    int sum = 0;

    cout << "Вводите числа (отрицательное для выхода): " << endl;
    while(true) {
        cout << "Введите число: ";
        cin >> number;
        // Проврека на выход
        if(number < 0) {
            cout << "Обнаружено отрицательное число. Выход."<< endl;
            break; // Немедленно выходи из цикла
        }
        // Проверка на кратность 3
        if(number % 3 == 0) {
            cout << "Число " << number << " кратно 3, пропускаем." << endl;
            continue; // Переходим к следующей итерации
        }
        // 
        sum += number;
        cout << "Добавлено " << number << " . Текущая сумма: " << sum << endl; 
    }
    cout << "\n Итоговая сумма: " << sum << endl;
    
    return 0;
}