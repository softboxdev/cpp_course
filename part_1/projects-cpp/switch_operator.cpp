#include <iostream>
using namespace std;

int main() {
    int dayNumber;
    cout << "Введите номер дня недели (1-7): ";
    cin >> dayNumber;
    
    switch(dayNumber) {  // Проверяем значение переменной dayNumber
        case 1:  // ЕСЛИ dayNumber == 1
            cout << "Понедельник" << endl;
            break;  // Выходим из switch
        
        case 2:  // ЕСЛИ dayNumber == 2
            cout << "Вторник" << endl;
            break;
            
        case 3:
            cout << "Среда" << endl;
            break;
            
        case 4:
            cout << "Четверг" << endl;
            break;
            
        case 5:
            cout << "Пятница" << endl;
            break;
            
        case 6:
            cout << "Суббота" << endl;
            break;
            
        case 7:
            cout << "Воскресенье" << endl;
            break;
            
        default:  // Выполняется, если ни один case не подошел
            cout << "Неверный номер дня!" << endl;
            break;
    }
    
    return 0;
}