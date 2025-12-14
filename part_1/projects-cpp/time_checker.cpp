#include <iostream>
using namespace std;

int main() {
    int hour;
    
    cout << "Введите текущий час (0-23): ";
    cin >> hour;
    
    // Проверка корректности
    if (hour < 0 || hour > 23) {
        cout << "Неверное время! Часы должны быть от 0 до 23." << endl;
        return 1;
    }
    
    // Определение времени суток
    cout << "Сейчас ";
    
    if (hour >= 5 && hour < 12) {  // С 5:00 до 11:59
        cout << "утро";
    }
    else if (hour >= 12 && hour < 17) {  // С 12:00 до 16:59
        cout << "день";
    }
    else if (hour >= 17 && hour < 22) {  // С 17:00 до 21:59
        cout << "вечер";
    }
    else {  // С 22:00 до 4:59
        cout << "ночь";
    }
    
    cout << "." << endl;
    
    // Использование switch для конкретных часов
    switch(hour) {
        case 0:
            cout << "Полночь!" << endl;
            break;
        case 12:
            cout << "Полдень!" << endl;
            break;
        case 8:
        case 9:
        case 10:  // Для 8, 9 и 10 выполнится одно и то же
            cout << "Идеальное время для работы!" << endl;
            break;
    }
    
    return 0;
}