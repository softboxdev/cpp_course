#include <iostream>
using namespace std;

int main() {
    int age;
    bool hasTicket;
    
    cout << "Введите возраст: ";
    cin >> age;
    cout << "Есть ли билет? (1 - да, 0 - нет): ";
    cin >> hasTicket;
    
    // Пример с && (И)
    if (age >= 18 && hasTicket) {  // И возраст ≥ 18, И есть билет
        cout << "Можно войти в клуб" << endl;
    } else {
        cout << "Нельзя войти в клуб" << endl;
    }
    
    // Пример с || (ИЛИ)
    if (age < 7 || age > 65) {  // ИЛИ возраст < 7, ИЛИ возраст > 65
        cout << "Вы имеете право на льготы" << endl;
    }
    
    // Пример с ! (НЕ)
    if (!hasTicket) {  // ЕСЛИ НЕ hasTicket (т.е. если билета нет)
        cout << "Вам нужен билет!" << endl;
    }
    
    // Комбинированный пример
    if ((age >= 12 && age <= 17) || (age >= 60 && hasTicket)) {
        // ИЛИ: (возраст от 12 до 17), ИЛИ: (возраст ≥ 60 И есть билет)
        cout << "Специальные условия" << endl;
    }
    
    return 0;
}