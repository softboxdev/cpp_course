#include <iostream>
#include <cstring>
#include <memory>
#include <vector>
using namespace std;

// Счетчик "утечек" для демонстрации
static int leak_counter = 0;

void demonstrateMemoryLeaks() {
    /*
    ЗАДАЧА: Показать различные виды утечек памяти.
    
    ВОПРОСЫ:
    1. Как возникают утечки памяти?
    2. Как их обнаружить?
    3. Как предотвратить?
    */
    
    cout << "\n\n=== ЗАДАЧА 2: Утечки памяти ===" << endl;
    cout << "==============================" << endl;
    
    cout << "Текущее количество 'утечек': " << leak_counter << endl;
    
    // 1. ПРОСТАЯ УТЕЧКА: забыли delete
    cout << "\n1. Простая утечка:" << endl;
    int* simple_leak = new int(100);
    cout << "Выделена память: " << simple_leak 
         << " значение: " << *simple_leak << endl;
    // ЗАБЫЛИ: delete simple_leak;
    leak_counter++;
    
    // 2. УТЕЧКА В ЦИКЛЕ: выделение без освобождения в цикле
    cout << "\n2. Утечка в цикле:" << endl;
    for (int i = 0; i < 5; i++) {
        int* cycle_leak = new int(i * 10);
        cout << "Цикл " << i << ": выделено " << cycle_leak << endl;
        // УТЕЧКА: каждый new без delete
        leak_counter++;
    }
    
    // 3. УТЕЧКА ПРИ ДОСРОЧНОМ ВОЗВРАТЕ
    cout << "\n3. Утечка при досрочном возврате:" << endl;
    int* early_return_leak = new int(999);
    
    if (true) {  // Условие всегда истинно
        cout << "Досрочный возврат!" << endl;
        // return;  // Если бы был return - утечка!
    }
    
    delete early_return_leak;  // Сделали правильно
    cout << "Память освобождена (утечки нет)" << endl;
    
    // 4. УТЕЧКА В ВЕТКАХ УСЛОВИЙ
    cout << "\n4. Утечка в ветках условий:" << endl;
    bool condition = true;
    int* conditional_leak = nullptr;
    
    if (condition) {
        conditional_leak = new int(111);
        cout << "Выделили в if: " << *conditional_leak << endl;
    } else {
        conditional_leak = new int(222);
        cout << "Выделили в else: " << *conditional_leak << endl;
    }
    
    // ОПАСНОСТЬ: можно забыть delete в одной из веток
    delete conditional_leak;  // Не забыли!
    
    // 5. УТЕЧКА ПРИ ИСКЛЮЧЕНИЯХ
    cout << "\n5. Утечка при исключениях:" << endl;
    int* exception_leak = new int(333);
    
    try {
        cout << "Пытаемся что-то сделать..." << endl;
        // throw runtime_error("Исключение!");  // Раскомментировать для теста
        delete exception_leak;  // Если исключение - не выполнится!
    } catch (...) {
        cout << "Поймали исключение, но память не освободили!" << endl;
        // delete exception_leak;  // Нужно здесь!
        leak_counter++;
    }
    
    // РЕШЕНИЯ:
    cout << "\n--- РЕШЕНИЯ ПРОБЛЕМ УТЕЧЕК ---" << endl;
    
    // Решение 1: RAII (деструктор освобождает)
    class SafeInt {
    private:
        int* data;
    public:
        SafeInt(int value) {
            data = new int(value);
            cout << "SafeInt создан: " << *data << endl;
        }
        
        ~SafeInt() {
            delete data;
            cout << "SafeInt уничтожен, память освобождена" << endl;
        }
    };
    
    {
        cout << "\nРешение 1: RAII класс" << endl;
        SafeInt safe(555);  // Память выделена
        // При выходе из блока деструктор автоматически освободит память
    }
    
    // Решение 2: умные указатели
    cout << "\nРешение 2: умные указатели" << endl;
    {
        unique_ptr<int> smart_ptr = make_unique<int>(666);
        cout << "Умный указатель: " << *smart_ptr << endl;
        // Автоматически удалится при выходе из блока
    }
    
    // Решение 3: контейнеры STL
    cout << "\nРешение 3: контейнеры STL" << endl;
    vector<int> numbers = {1, 2, 3, 4, 5};
    numbers.push_back(6);  // Автоматическое управление памятью
    
    cout << "\nИтоговое количество 'утечек': " << leak_counter << endl;
    cout << "Эти утечки существуют только в демонстрационных целях" << endl;
    cout << "В реальной программе они привели бы к росту потребления памяти!" << endl;
}

int main() {
    cout << "=== ПРОГРАММА ДЛЯ АНАЛИЗА ПАМЯТИ ===\n" << endl;
    
    // Вызываем первую функцию
    demonstrateMemoryLeaks();
    
    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    return 0;
}