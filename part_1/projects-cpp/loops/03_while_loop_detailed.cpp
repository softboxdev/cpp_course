// ==============================================
// Файл: 03_while_loop_detailed.cpp
// Детальный анализ цикла while
// ==============================================

#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

int main() {
    cout << "=== ГЛУБОКИЙ АНАЛИЗ ЦИКЛА WHILE ===\n" << endl;
    
    // Пример 1: Базовый while
    cout << "1. Базовый while:" << endl;
    int counter = 0;
    while (counter < 5) {  // Условие проверяется ПЕРЕД итерацией
        cout << "counter = " << counter << endl;
        counter++;  // Инкремент в теле
    }
    
    // Ключевое отличие от for:
    // for: инициализация, условие, инкремент в заголовке
    // while: только условие в заголовке
    
    // Пример 2: While для обработки ввода
    cout << "\n2. Обработка пользовательского ввода:" << endl;
    
    int sum = 0;
    int value;
    cout << "Вводите числа (0 для завершения): ";
    
    while (cin >> value && value != 0) {
        sum += value;
    }
    cout << "Сумма: " << sum << endl;
    
    
    // Пример 3: While с сложным условием
    cout << "\n3. Сложные условия:" << endl;
    int x = 10;
    int y = 20;
    
    while (x < 15 && y > 15) {
        cout << "x = " << x << ", y = " << y << endl;
        x++;
        y--;
    }
    
    // Пример 4: Бесконечный while
    cout << "\n4. Бесконечные циклы:" << endl;
    /*
    // Вариант 1: явное true
    while (true) {
        // Бесконечный цикл
        // Нужен break для выхода
    }
    
    // Вариант 2: условие всегда истинно
    int flag = 1;
    while (flag) {  // flag никогда не становится 0
        // ...
    }
    */
    
    // Пример 5: While с инвариантами
    cout << "\n5. Инварианты цикла:" << endl;
    // Инвариант - условие, которое истинно перед каждой итерацией
    
    int n = 10;
    int factorial = 1;
    int i = 1;
    
    // Инвариант: factorial = (i-1)!
    while (i <= n) {
        factorial *= i;  // Теперь factorial = i!
        i++;             // Теперь factorial = (i-1)!
        // Инвариант восстановлен
    }
    cout << n << "! = " << factorial << endl;
    
    // Пример 6: While для обработки строк
    cout << "\n6. Обработка строк:" << endl;
    string text = "Hello, World!";
    size_t pos = 0;
    
    // Найти все пробелы
    while ((pos = text.find(' ', pos)) != string::npos) {
        cout << "Пробел в позиции: " << pos << endl;
        pos++;  // Ищем с следующей позиции
    }
    
    // Пример 7: Сравнение for и while
    cout << "\n7. Эквивалентность for и while:" << endl;
    
    // Этот for:
    for (int i = 0; i < 3; i++) {
        cout << "for: " << i << endl;
    }
    
    // Эквивалентен этому while:
    {
        int i = 0;          // Инициализация
        while (i < 3) {     // Условие
            cout << "while: " << i << endl;
            i++;            // Инкремент
        }
    }
    
    // Правило: любой for можно переписать как while
    // Обратное не всегда верно
    
    // Пример 8: While для симуляции
    cout << "\n8. Симуляция процессов:" << endl;
    
    // Симуляция падения мяча с отскоком
    double height = 10.0;  // начальная высота
    const double gravity = 9.81;
    const double restitution = 0.8;  // упругость
    const double threshold = 0.01;   // порог остановки
    
    int bounces = 0;
    while (height > threshold) {
        // Время падения: t = sqrt(2h/g)
        double time_to_fall = sqrt(2 * height / gravity);
        
        cout << "Отскок " << ++bounces 
             << ": высота = " << height 
             << " м, время падения = " << time_to_fall << " с" << endl;
        
        // Новая высота после отскока
        height *= restitution * restitution;  // энергия теряется дважды
    }
    
    cout << "Мяч остановился после " << bounces << " отскоков" << endl;
    
    return 0;
}