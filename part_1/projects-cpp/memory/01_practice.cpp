#include <iostream>
#include <vector>
using namespace std;

// Глобальные переменные - статическая память
int global_var = 100;
const char* global_str = "Global String";

void analyzeMemoryLocations() {
    /*
    ЗАДАЧА: Проанализировать, где находятся разные переменные.
    
    ВОПРОСЫ:
    1. Какие переменные находятся в стеке, а какие в статической памяти?
    2. Почему адреса глобальных переменных отличаются от локальных?
    3. Что происходит с памятью при выходе из функции?
    */
    
    cout << "=== ЗАДАЧА 1: Анализ размещения переменных ===" << endl;
    cout << "============================================" << endl;
    
    // 1. Локальные переменные (стек)
    int local_int = 42;
    double local_array[3] = {1.1, 2.2, 3.3};
    
    // 2. Статическая локальная переменная
    static int static_local = 999;
    
    // 3. Динамическая память (куча)
    int* heap_int = new int(777);
    vector<int>* heap_vector = new vector<int>{1, 2, 3};
    
    cout << "\nАДРЕСА ПЕРЕМЕННЫХ:" << endl;
    cout << "-----------------" << endl;
    
    // Глобальные переменные (статика)
    cout << "Глобальные (статика):" << endl;
    cout << "  global_var:  " << &global_var 
         << "  значение: " << global_var << endl;
    cout << "  global_str:  " << (void*)global_str 
         << "  значение: \"" << global_str << "\"" << endl;
    
    // Локальные переменные (стек)
    cout << "\nЛокальные (стек):" << endl;
    cout << "  local_int:   " << &local_int 
         << "  значение: " << local_int << endl;
    cout << "  local_array: " << local_array 
         << "  первый элемент: " << local_array[0] << endl;
    
    // Статическая локальная
    cout << "\nСтатическая локальная:" << endl;
    cout << "  static_local: " << &static_local 
         << "  значение: " << static_local << endl;
    
    // Динамические переменные (куча)
    cout << "\nДинамические (куча):" << endl;
    cout << "  heap_int:    " << heap_int 
         << "  значение: " << *heap_int << endl;
    cout << "  Адрес указателя heap_int в стеке: " << &heap_int << endl;
    
    // ВОПРОС ДЛЯ АНАЛИЗА:
    cout << "\n--- ВОПРОСЫ ДЛЯ АНАЛИЗА ---" << endl;
    cout << "1. Почему адрес global_var сильно отличается от local_int?" << endl;
    cout << "   Ответ: Они в разных сегментах памяти (статика vs стек)" << endl;
    
    cout << "\n2. Почему &heap_int и heap_int разные?" << endl;
    cout << "   Ответ: &heap_int - адрес указателя в стеке," << endl;
    cout << "   heap_int - адрес данных в куче, на которые он указывает" << endl;
    
    cout << "\n3. Что произойдет с памятью при выходе из функции?" << endl;
    cout << "   Ответ: Локальные переменные (стек) уничтожатся," << endl;
    cout << "   статическая переменная сохранится," << endl;
    cout << "   динамическая память останется выделенной (утечка!)" << endl;
    
    // Важная часть: освобождение памяти
    cout << "\n--- ОСВОБОЖДЕНИЕ ПАМЯТИ ---" << endl;
    delete heap_int;
    delete heap_vector;
    heap_int = nullptr;
    
    cout << "Память освобождена (без утечек!)" << endl;
}

// Дополнительный анализ
void memoryDistanceAnalysis() {
    cout << "\n\n=== ДОПОЛНИТЕЛЬНЫЙ АНАЛИЗ: Расстояния между адресами ===" << endl;
    
    // Создаем несколько локальных переменных
    int a = 1;
    int b = 2;
    int c = 3;
    
    cout << "\nЛокальные переменные в стеке:" << endl;
    cout << "a: " << &a << " значение: " << a << endl;
    cout << "b: " << &b << " значение: " << b << endl;
    cout << "c: " << &c << " значение: " << c << endl;
    
    // Вычисляем расстояния
    cout << "\nРасстояния между адресами:" << endl;
    cout << "От a до b: " << (char*)&b - (char*)&a << " байт" << endl;
    cout << "От b до c: " << (char*)&c - (char*)&b << " байт" << endl;
    cout << "От a до c: " << (char*)&c - (char*)&a << " байт" << endl;
    
    // ВОПРОС:
    cout << "\n--- ВОПРОС ---" << endl;
    cout << "Почему расстояния не равны 4 байтам (размер int)?" << endl;
    cout << "Ответ: Компилятор может добавлять выравнивание (padding)" << endl;
    cout << "для оптимизации доступа к памяти." << endl;
}

int main() {
    cout << "=== ПРОГРАММА ДЛЯ АНАЛИЗА ПАМЯТИ ===\n" << endl;
    
    // Вызываем первую функцию
    analyzeMemoryLocations();
    
    // Вызываем вторую функцию
    memoryDistanceAnalysis();
    
    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    return 0;
}