#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Введите число для таблицы умножения: ";
    cin >> number;

    cout << "\nТаблица умножения на " << number << ":" << endl;
    cout << "-------------------------------------" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << number << " x " << i << " = " << number * i << endl;
    }
    return 0;

}