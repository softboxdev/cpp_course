// ==============================================
// Файл: 02_range_based_for.cpp
// Range-based for (C++11 и выше)
// ==============================================

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <string>
using namespace std;

int main() {
    cout << "=== RANGE-BASED FOR (C++11+) ===\n" << endl;
    
    // Пример 1: Массив
    cout << "1. Массивы:" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    
    // Копирование элементов (по значению)
    // for  (тип элемент : контейнер)
    for (int x : arr) {  // x - копия элемента
        cout << x << " ";
        x = 0;  // Не влияет на исходный массив!
    }

    cout << "\nИсходный массив: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Ссылка (изменяет оригинал)
    for (int& x : arr) {
        x *= 2;  // Удваиваем каждый элемент
    }
    cout << "После удвоения: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // Константная ссылка (только чтение)
    cout << "После удвоения - Константная ссылка (только чтение): ";
    for (const int& x : arr) {
        cout << x << " ";  // Можно только читать
        // x = 0;  // Ошибка компиляции
    }
    cout << endl;
    
    // Пример 2: STL контейнеры
    cout << "\n2. STL контейнеры:" << endl;
    vector<string> words = {"apple", "banana", "cherry"};
    
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    // Пример 3: Автоматическое определение типа
    cout << "\n3. Auto type deduction:" << endl;
    
    for (auto& word : words) {  // auto = string
        word += "!";  // Добавляем восклицательный знак
    }
    
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    // Пример 4: Пользовательские контейнеры
    cout << "\n4. Пользовательские типы:" << endl;
    
    class SimpleContainer {
        int data[5] = {10, 20, 30, 40, 50};
    public:
        // Для range-based for нужны begin() и end()
        int* begin() { return data; }
        int* end() { return data + 5; }
        const int* begin() const { return data; }
        const int* end() const { return data + 5; }
    };
    
    SimpleContainer container;
    for (int val : container) {
        cout << val << " ";
    }
    cout << endl;
    
    // Пример 5: Initializer list
    cout << "\n5. Initializer lists:" << endl;
    for (int x : {1, 1, 2, 3, 5, 8}) {  // Фибоначчи
        cout << x << " ";
    }
    cout << endl;
    
    // Пример 6: Range-based for с map
    cout << "\n6. Ассоциативные контейнеры:" << endl;
    map<int, string> id_to_name = {
        {1, "Alice"},
        {2, "Bob"},
        {3, "Charlie"}
    };
    
    // Элементы map - пары (key, value)
    for (const auto& pair : id_to_name) {
        cout << "ID: " << pair.first 
             << ", Name: " << pair.second << endl;
    }
    
    // C++17: Structured bindings
    cout << "\n7. Structured bindings (C++17):" << endl;
    for (const auto& [id, name] : id_to_name) {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    
    // Пример 7: Вложенные range-based for
    cout << "\n8. Вложенные циклы:" << endl;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}