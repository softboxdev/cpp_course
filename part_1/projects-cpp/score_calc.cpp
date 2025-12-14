#include <iostream>
using namespace std;

int main() {
    int score;
    
    cout << "Введите оценку (0-100): ";
    cin >> score;
    
    // Проверка корректности ввода
    if (score < 0 || score > 100) {  // Если оценка < 0 ИЛИ > 100
        cout << "Ошибка: оценка должна быть от 0 до 100!" << endl;
        return 1;  // Завершаем программу с кодом ошибки
    }
    
    // Определение оценки по буквенной системе
    char grade;
    
    if (score >= 90) {
        grade = 'A';
    } 
    else if (score >= 80) {  // Выполнится только если score < 90
        grade = 'B';
    }
    else if (score >= 70) {  // Выполнится только если score < 80
        grade = 'C';
    }
    else if (score >= 60) {  // Выполнится только если score < 70
        grade = 'D';
    }
    else {  // Выполнится только если score < 60
        grade = 'F';
    }
    
    cout << "Ваша оценка: " << grade << endl;
    
    // Дополнительная проверка с тернарным оператором
    string message = (grade == 'F') ? "Нужно подтянуть знания!" : "Молодец!";
    cout << message << endl;
    
    return 0;
}