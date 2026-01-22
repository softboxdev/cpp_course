// main.cpp - ГЛАВНЫЙ ФАЙЛ ПРОГРАММЫ
// Точка входа в программу

#include <iostream>   // Для ввода/вывода
#include "math.h"     // Наши математические функции
#include "greetings.h"
// greetings.cpp подключим при компиляции

using namespace std;  // Чтобы не писать std:: перед cout

int main() {  // Начало программы
    cout << "=== ПРОСТОЙ МНОГОФАЙЛОВЫЙ ПРОЕКТ ===" << endl;
    cout << "===================================" << endl;
    
    // Используем математические функции
    cout << "\nМатематические операции:" << endl;
    cout << "5 + 3 = " << add(5, 3) << endl;
    cout << "10 - 4 = " << subtract(10, 4) << endl;
    cout << "6 * 7 = " << multiply(6, 7) << endl;
    cout << "15 / 4 = " << divide(15, 4) << endl;
    
    // Проверка деления на ноль
    cout << "8 / 0 = " << divide(8, 0) << " (защита от деления на ноль)" << endl;
    
    // Здесь мы не можем вызвать sayHello() напрямую,
    // потому что не объявили ее в greetings.h

    sayHello();
    showMathExample();
    sayGoodbye();
    
    cout << "\nПрограмма завершена успешно!" << endl;
    
    return 0;  // Возвращаем 0 - все хорошо
}