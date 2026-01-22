#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

void performanceComparison() {
    /*
    ЗАДАЧА: Сравнить производительность стека и кучи.
    
    ВОПРОСЫ:
    1. Что быстрее: выделение в стеке или куче?
    2. Почему есть разница в скорости?
    3. Когда стоит использовать каждый подход?
    */
    
    cout << "\n\n=== ЗАДАЧА 3: Производительность стека vs кучи ===" << endl;
    cout << "=================================================" << endl;
    
    const int ITERATIONS = 100000;
    const int ARRAY_SIZE = 100;
    
    // 1. ТЕСТ: выделение в стеке
    cout << "\n1. ТЕСТ: Выделение в стеке" << endl;
    
    auto start_stack = high_resolution_clock::now();
    
    for (int i = 0; i < ITERATIONS; i++) {
        // Выделяем массив в стеке
        int stack_array[ARRAY_SIZE];
        
        // Используем массив (чтобы компилятор не оптимизировал)
        for (int j = 0; j < ARRAY_SIZE; j++) {
            stack_array[j] = j;
        }
        
        // Массив автоматически уничтожается при выходе из области видимости
    }
    
    auto end_stack = high_resolution_clock::now();
    auto duration_stack = duration_cast<microseconds>(end_stack - start_stack);
    
    cout << "Время стека: " << duration_stack.count() << " микросекунд" << endl;
    cout << "Среднее время на итерацию: " 
         << duration_stack.count() / ITERATIONS << " мкс" << endl;
    
    // 2. ТЕСТ: выделение в куче
    cout << "\n2. ТЕСТ: Выделение в куче" << endl;
    
    auto start_heap = high_resolution_clock::now();
    
    for (int i = 0; i < ITERATIONS; i++) {
        // Выделяем массив в куче
        int* heap_array = new int[ARRAY_SIZE];
        
        // Используем массив
        for (int j = 0; j < ARRAY_SIZE; j++) {
            heap_array[j] = j;
        }
        
        // ОБЯЗАТЕЛЬНО освобождаем память
        delete[] heap_array;
    }
    
    auto end_heap = high_resolution_clock::now();
    auto duration_heap = duration_cast<microseconds>(end_heap - start_heap);
    
    cout << "Время кучи: " << duration_heap.count() << " микросекунд" << endl;
    cout << "Среднее время на итерацию: " 
         << duration_heap.count() / ITERATIONS << " мкс" << endl;
    
    // 3. АНАЛИЗ РЕЗУЛЬТАТОВ
    cout << "\n--- АНАЛИЗ РЕЗУЛЬТАТОВ ---" << endl;
    
    double ratio = (double)duration_heap.count() / duration_stack.count();
    cout << "Куча медленнее стека в " << ratio << " раз" << endl;
    
    cout << "\nПОЧЕМУ ТАК ПРОИСХОДИТ:" << endl;
    cout << "1. Стек: простое перемещение указателя стека (очень быстро)" << endl;
    cout << "2. Куча: поиск свободного блока, работа с менеджером памяти" << endl;
    cout << "3. Куча: дополнительная фрагментация и метаданные" << endl;
    
    // 4. ТЕСТ: большое выделение (где куча имеет смысл)
    cout << "\n3. ТЕСТ: Большое выделение (1MB)" << endl;
    
    const int BIG_SIZE = 1000000;  // 1 миллион int ~ 4MB
    
    // Стек: НЕЛЬЗЯ! Слишком большой массив
    // int huge_stack[BIG_SIZE];  // Stack Overflow!
    
    // Куча: можно
    auto start_big_heap = high_resolution_clock::now();
    
    int* big_heap_array = new int[BIG_SIZE];
    for (int i = 0; i < BIG_SIZE; i++) {
        big_heap_array[i] = i;
    }
    delete[] big_heap_array;
    
    auto end_big_heap = high_resolution_clock::now();
    auto duration_big_heap = duration_cast<microseconds>(end_big_heap - start_big_heap);
    
    cout << "Выделение 4MB в куче: " << duration_big_heap.count() << " мкс" << endl;
    
    // 5. ВЫВОДЫ И РЕКОМЕНДАЦИИ
    cout << "\n--- РЕКОМЕНДАЦИИ ---" << endl;
    cout << "ИСПОЛЬЗУЙТЕ СТЕК, когда:" << endl;
    cout << "• Небольшие объекты (< 1KB)" << endl;
    cout << "• Временные данные (в пределах функции)" << endl;
    cout << "• Требуется максимальная производительность" << endl;
    
    cout << "\nИСПОЛЬЗУЙТЕ КУЧУ, когда:" << endl;
    cout << "• Большие объекты (> 1KB)" << endl;
    cout << "• Данные должны жить дольше функции" << endl;
    cout << "• Размер известен только во время выполнения" << endl;
    cout << "• Нужны сложные структуры данных" << endl;
    
    // 6. ПРАКТИЧЕСКИЙ ПРИМЕР
    cout << "\n--- ПРАКТИЧЕСКИЙ ПРИМЕР ---" << endl;
    
    // ПЛОХО: выделение мелких объектов в куче
    cout << "ПЛОХОЙ КОД (утечки и медленно):" << endl;
    for (int i = 0; i < 1000; i++) {
        int* bad = new int(i);  // Мелкий объект в куче
        // Используем...
        // delete bad;  // Часто забывают
    }
    
    // ХОРОШО: стек для мелких объектов
    cout << "\nХОРОШИЙ КОД (быстро и безопасно):" << endl;
    for (int i = 0; i < 1000; i++) {
        int good = i;  // В стеке - быстро и автоматически
        // Используем...
    }
}

int main() {
    cout << "=== ПРОГРАММА ДЛЯ АНАЛИЗА ПАМЯТИ ===\n" << endl;
    
    // Вызываем первую функцию
    performanceComparison();
    
    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    return 0;
}