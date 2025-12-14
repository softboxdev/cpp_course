#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;
    
    // Ввод данных
    cout << "Введите первое число: ";
    cin >> num1;  // Считываем первое число
    
    cout << "Введите операцию (+, -, *, /): ";
    cin >> operation;  // Считываем символ операции
    
    cout << "Введите второе число: ";
    cin >> num2;  // Считываем второе число
    
    // Выполнение операции с проверкой
    if (operation == '+') {
        result = num1 + num2;  // Сложение
        cout << num1 << " + " << num2 << " = " << result << endl;
    }
    else if (operation == '-') {
        result = num1 - num2;  // Вычитание
        cout << num1 << " - " << num2 << " = " << result << endl;
    }
    else if (operation == '*') {
        result = num1 * num2;  // Умножение
        cout << num1 << " * " << num2 << " = " << result << endl;
    }
    else if (operation == '/') {
        // Проверка деления на ноль!
        if (num2 != 0) {  // Если делитель не равен нулю
            result = num1 / num2;  // Деление
            cout << num1 << " / " << num2 << " = " << result << endl;
        } else {
            cout << "Ошибка: деление на ноль!" << endl;
        }
    }
    else {  // Если введена неподдерживаемая операция
        cout << "Ошибка: неизвестная операция!" << endl;
    }
    
    return 0;
}