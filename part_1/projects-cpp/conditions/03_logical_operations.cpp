// ==============================================
// Файл: 03_logical_operations.cpp
// Описание: Логические операторы &&, ||, !
// ==============================================

#include <iostream>
using namespace std;

// Вспомогательная функция для демонстрации short-circuit
bool check(bool value, const string& name) {
    cout << "Проверка " << name << ": " << (value ? "true" : "false") << endl;
    return value;
}

int main() {
    cout << "=== ДЕМОНСТРАЦИЯ ЛОГИЧЕСКИХ ОПЕРАЦИЙ ===\n" << endl;
    
    // Пример 1: Оператор И (&&)
    cout << "1. Оператор И (&&):" << endl;
    bool hasTicket = true;
    bool hasMoney = true;
    bool hasTime = false;
    
    // ОБА условия должны быть истинны
    if (hasTicket && hasMoney) {
        cout << "Можно пойти в кино" << endl;
    } else {
        cout << "Нельзя пойти в кино" << endl;
    }
    
    // Пример 2: Оператор ИЛИ (||)
    cout << "\n2. Оператор ИЛИ (||):" << endl;
    bool isWeekend = true;
    bool isHoliday = false;
    
    // ХОТЯ БЫ ОДНО условие должно быть истинно
    if (isWeekend || isHoliday) {
        cout << "Можно отдохнуть!" << endl;
    }
    
    // Пример 3: Оператор НЕ (!)
    cout << "\n3. Оператор НЕ (!):" << endl;
    bool doorLocked = true;
    
    if (!doorLocked) {  // Если НЕ doorLocked
        cout << "Дверь открыта" << endl;
    } else {
        cout << "Дверь закрыта" << endl;
    }
    
    // Пример 4: Комбинирование операторов
    cout << "\n4. Комбинирование операторов:" << endl;
    int age = 25;
    bool hasLicense = true;
    bool isSober = true;
    
    // Можно водить если: возраст >= 18 И есть права И трезв
    if (age >= 18 && hasLicense && isSober) {
        cout << "Можно водить машину" << endl;
    }
    
    // Пример 5: Short-circuit evaluation (ленивое вычисление)
    cout << "\n5. Short-circuit evaluation:" << endl;
    
    // Для &&: если левая часть ложна, правая НЕ вычисляется
    cout << "Проверка с && (первое false):" << endl;
    if (check(false, "condition1") && check(true, "condition2")) {
        // Второй check не выполнится!
    }
    
    cout << "\nПроверка с && (первое true):" << endl;
    if (check(true, "condition1") && check(false, "condition2")) {
        // Оба check выполнятся
    }
    
    cout << "\nПроверка с || (первое true):" << endl;
    if (check(true, "condition1") || check(true, "condition2")) {
        // Второй check не выполнится!
    }
    
    // Пример 6: Преобразование типов в условиях
    cout << "\n6. Преобразование типов в условиях:" << endl;
    int value = 5;        // ненулевое значение → true
    int zero = 0;         // ноль → false
    int* ptr = nullptr;   // нулевой указатель → false
        
    if (value) {
        cout << "value считается истиной" << endl;
    }
    
    if (!zero) {
        cout << "zero считается ложью" << endl;
    }
    
    if (!ptr) {
        cout << "nullptr считается ложью" << endl;
    }
    
    return 0;
}