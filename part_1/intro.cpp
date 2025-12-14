#include <iostream>
using namespace std;

int main() {
    // Объявление переменных
    const double TAX_RATE = 0.20; // Константа
    double salary = 50000.0;      // Переменная
    double tax;

    // Вычисление
    tax = salary * TAX_RATE;

    // Вывод результатов
    cout << "Зарплата: " << salary << endl;
    cout << "Налог (" << TAX_RATE * 100 << "%): " << tax << endl;
    cout << "На руки: " << salary - tax << endl;

    return 0;
}