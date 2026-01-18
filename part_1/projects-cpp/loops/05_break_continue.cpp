// ==============================================
// Файл: 05_break_continue.cpp
// Детальный анализ break и continue
// ==============================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cout << "=== BREAK И CONTINUE: КОНТРОЛЬ ПОТОКА ===\n" << endl;
    
    // BREAK: немедленный выход из текущего цикла
    // CONTINUE: переход к следующей итерации
    
    // Пример 1: Break для досрочного выхода
    cout << "1. Оператор break:" << endl;
    
    // Поиск первого отрицательного числа
    vector<int> numbers = {5, 3, -2, 8, -1, 4};
    
    for (int num : numbers) {
        if (num < 0) {
            cout << "Найдено первое отрицательное число: " << num << endl;
            break;  // Выход из цикла
        }
        cout << "Проверяем " << num << " (положительное)" << endl;
    }
    
    // Пример 2: Continue для пропуска итерации
    cout << "\n2. Оператор continue:" << endl;
    
    // Сумма только положительных чисел
    int sum = 0;
    for (int num : numbers) {
        if (num < 0) {
            cout << "Пропускаем отрицательное: " << num << endl;
            continue;  // Пропустить остаток итерации
        }
        sum += num;
        cout << "Добавляем " << num << ", сумма = " << sum << endl;
    }
    cout << "Итоговая сумма положительных: " << sum << endl;
    
    // Пример 3: Break во вложенных циклах
    cout << "\n3. Break во вложенных циклах:" << endl;
    
    // Поиск в матрице
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int target = 5;
    bool found = false;
    
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == target) {
                cout << "Найдено " << target << " на позиции [" 
                     << i << "][" << j << "]" << endl;
                found = true;
                break;  // Выход только из внутреннего цикла!
            }
        }
        if (found) break;  // Выход из внешнего цикла
    }
    
    // Пример 4: Метка для выхода из вложенных циклов
    cout << "\n4. Метки (не в C++, но в других языках):" << endl;
    
    // В C++ нет меток для break/continue
    // Альтернатива: флаги или goto (не рекомендуется)
    
    found = false;
    for (size_t i = 0; i < matrix.size() && !found; i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == target) {
                cout << "Найдено с флагом" << endl;
                found = true;
                break;
            }
        }
    }
    
    // Пример 5: Continue с меткой в других языках
    cout << "\n5. Эмуляция сложных сценариев:" << endl;
    
    // Обработка только диагональных элементов
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            if (i != j) continue;  // Пропустить недиагональные
            
            cout << "Диагональный элемент [" << i << "][" << j 
                 << "] = " << matrix[i][j] << endl;
        }
    }
    
    // Пример 6: Бесконечные циклы с break
    cout << "\n6. Бесконечные циклы с условием выхода:" << endl;
    
    int attempts = 0;
    const int max_attempts = 10;
    
    while (true) {  // Бесконечный цикл
        attempts++;
        cout << "Попытка " << attempts << endl;
        
        // Условие выхода
        if (attempts >= max_attempts) {
            cout << "Достигнут лимит попыток" << endl;
            break;
        }
        
        // Успешное завершение
        if (attempts == 5) {
            cout << "Успех на 5-й попытке!" << endl;
            break;
        }
    }
    
    // Пример 7: Continue в do-while
    cout << "\n7. Continue в do-while (особенности):" << endl;
    
    int n = 0;
    do {
        n++;
        
        if (n % 2 == 0) {
            continue;  // Пропустить четные числа
        }
        
        cout << n << " ";
        
        // В do-while continue переходит к проверке условия!
        // Это важно: условие проверяется ПОСЛЕ continue
        
    } while (n < 10);
    cout << endl;
    
    // Пример 8: Оптимизация с break/continue
    cout << "\n8. Оптимизация производительности:" << endl;
    
    // Поиск простых чисел с оптимизацией
    vector<int> primes;
    const int limit = 30;
    
    for (int num = 2; num <= limit; num++) {
        bool is_prime = true;
        
        // Проверка деления на числа до sqrt(num)
        for (int divisor = 2; divisor * divisor <= num; divisor++) {
            if (num % divisor == 0) {
                is_prime = false;
                break;  // Не простое, дальше проверять не нужно
            }
        }
        
        if (is_prime) {
            primes.push_back(num);
        }
    }
    
    cout << "Простые числа до " << limit << ": ";
    for (int p : primes) cout << p << " ";
    cout << endl;
    
    return 0;
}