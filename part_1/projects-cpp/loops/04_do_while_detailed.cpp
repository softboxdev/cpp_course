// ==============================================
// Файл: 04_do_while_detailed.cpp
// Детальный анализ цикла do-while
// ==============================================

#include <iostream>
#include <string>
#include <random>
using namespace std;

int main() {
    cout << "=== ГЛУБОКИЙ АНАЛИЗ ЦИКЛА DO-WHILE ===\n" << endl;
    
    // Ключевая особенность: тело выполняется ХОТЯ БЫ ОДИН РАЗ
    // Условие проверяется ПОСЛЕ итерации
    
    // Пример 1: Базовый do-while
    cout << "1. Базовый do-while:" << endl;
    int count = 0;
    
    do {
        cout << "Это сообщение выведется хотя бы 1 раз" << endl;
        count++;
    } while (count < 3);
    
    // Пример 2: Сравнение while и do-while
    cout << "\n2. Сравнение while и do-while:" << endl;
    
    // While: проверка ПЕРЕД выполнением
    int w = 5;
    while (w < 5) {
        cout << "while: это не выполнится" << endl;
        w++;
    }
    
    // Do-while: проверка ПОСЛЕ выполнения
    int d = 5;
    do {
        cout << "do-while: это выполнится 1 раз" << endl;
        d++;
    } while (d < 5);
    
    // Пример 3: Меню пользователя
    cout << "\n3. Меню пользователя (классический пример):" << endl;
    
    int choice;
    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Опция 1" << endl;
        cout << "2. Опция 2" << endl;
        cout << "3. Выход" << endl;
        cout << "Выберите: ";
        cin >> choice;
        
        switch (choice) {
            case 1: cout << "Выбрана опция 1"; break;
            case 2: cout << "Выбрана опция 2"; break;
            case 3: cout << "Выход..."; break;
            default: cout << "Неверный выбор"; break;
        }
    } while (choice != 3);
    
    

    // Пример 4: Игры и симуляции
    cout << "\n4. Игровые циклы:" << endl;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    
    int secret_number = dis(gen);
    int attempts = 0;
    int guess;
    bool guessed = false;
    
    cout << "Угадайте число от 1 до 100" << endl;
    
    do {
        // cout << "Ваша попытка: ";
        // cin >> guess;
        guess = 50;  // для примера
        
        attempts++;
        
        if (guess < secret_number) {
            cout << "Слишком маленькое!" << endl;
        } else if (guess > secret_number) {
            cout << "Слишком большое!" << endl;
        } else {
            guessed = true;
            cout << "Поздравляю! Вы угадали за " << attempts << " попыток" << endl;
        }
    } while (!guessed);
    
    // Пример 5: Обработка до первого успеха
    cout << "\n5. Повтор до успеха:" << endl;
    
    int max_attempts = 5;
    int current_attempt = 0;
    bool success = false;
    
    do {
        current_attempt++;
        cout << "Попытка " << current_attempt << " из " << max_attempts << endl;
        
        // Имитация операции с 30% шансом успеха
        // success = (dis(gen) <= 30);
        success = (current_attempt == 3);  // Успех на 3-й попытке
        
        if (success) {
            cout << "Успех!" << endl;
        } else if (current_attempt < max_attempts) {
            cout << "Неудача, пробуем снова..." << endl;
        } else {
            cout << "Достигнут лимит попыток" << endl;
        }
    } while (!success && current_attempt < max_attempts);
    
    // Пример 6: Обработка последовательностей
    cout << "\n6. Обработка до определенного условия:" << endl;
    
    // Чтение чисел до отрицательного
    vector<int> numbers;
    int num;
    
    cout << "Введите положительные числа (отрицательное для завершения):" << endl;
    
    do {
        cin >> num;
        if (num >= 0) {
            numbers.push_back(num);
        }
    } while (num >= 0);
    
    
    cout << "Введено " << numbers.size() << " чисел" << endl;
    
    return 0;
}