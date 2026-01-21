#include <iostream>
using namespace std;

int main() {
    int x = 10;
    const int y = 20;
    
    cout << "=== const со ссылками ===" << endl;
    
    // 1. Обычная ссылка на неконстантную переменную
    int& ref1 = x;        // OK
    // int& ref2 = y;     // ОШИБКА: нельзя ссылаться на const через не-const ссылку
    
    // 2. Константная ссылка на неконстантную переменную
    const int& cref1 = x;  // OK: доступ только для чтения
    cout << "cref1 = " << cref1 << endl;
    // cref1 = 30;        // ОШИБКА: нельзя изменить через const ссылку
    
    // 3. Константная ссылка на константную переменную
    const int& cref2 = y;  // OK
    cout << "cref2 = " << cref2 << endl;
    
    // 4. Временные объекты и const ссылки
    const int& temp_ref = 42;  // OK: const ссылка может ссылаться на временное значение
    cout << "temp_ref = " << temp_ref << endl;
    
    // int& bad_temp_ref = 42;  // ОШИБКА: не-const ссылка не может ссылаться на временное значение
    
    // 5. Константная ссылка продлевает время жизни временного объекта
    const int& extended_life = x + y;  // временный объект живет, пока жива ссылка
    cout << "extended_life = " << extended_life << endl;
    
    // Практический пример
    cout << "\n=== Практический пример ===" << endl;
    int a = 5, b = 3;
    
    // Функция, возвращающая константную ссылку на больший аргумент
    auto& max_ref = (a > b) ? a : b;
    const auto& max_cref = (a > b) ? a : b;
    
    max_ref = 100;  // можно изменить
    // max_cref = 100;  // ОШИБКА
    
    cout << "a = " << a << ", b = " << b << endl;
    
    return 0;
}