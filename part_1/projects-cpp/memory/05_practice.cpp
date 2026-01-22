#include <iostream>
#include <cstring>
using namespace std;

// Глобальный счетчик для отслеживания выделений
static int allocation_count = 0;
static int deallocation_count = 0;

// Перегружаем new и delete для отслеживания
void* operator new(size_t size) {
    allocation_count++;
    cout << "[NEW] Выделено " << size << " байт. Всего выделений: " 
         << allocation_count << endl;
    return malloc(size);
}

void operator delete(void* ptr) noexcept {
    deallocation_count++;
    cout << "[DELETE] Освобождена память. Всего освобождений: " 
         << deallocation_count << endl;
    free(ptr);
}



void debugMemoryIssues() {
    /*
    ЗАДАЧА: Найти и исправить проблемы с памятью.
    
    ВОПРОСЫ:
    1. Где происходит утечка памяти?
    2. Где возможен доступ к неинициализированной памяти?
    3. Как правильно исправить код?
    */
    
    cout << "\n\n=== ЗАДАЧА 5: Отладка проблем с памятью ===" << endl;
    cout << "==========================================" << endl;
    
    allocation_count = 0;
    deallocation_count = 0;
    
    cout << "Начальное состояние: выделений=" << allocation_count 
         << ", освобождений=" << deallocation_count << endl;
    
    // КОД С ОШИБКАМИ (найдите и исправьте!)
    cout << "\n--- КОД С ОШИБКАМИ ---" << endl;
    
    // ОШИБКА 1: Неинициализированный указатель
    cout << "\n1. Неинициализированный указатель:" << endl;
    {
        int* ptr1;  // ОШИБКА: не инициализирован
        // *ptr1 = 42;  // ОПАСНО: указатель указывает "в никуда"
        
        // ИСПРАВЛЕНИЕ:
        int* ptr1_fixed = nullptr;  // Инициализируем
        // или лучше: int* ptr1_fixed = new int(42);
    }
    
    // ОШИБКА 2: Утечка памяти
    cout << "\n2. Утечка памяти:" << endl;
    {
        int* ptr2 = new int(100);
        cout << "Создали: " << *ptr2 << endl;
        // ЗАБЫЛИ: delete ptr2;  // УТЕЧКА!
        
        // ИСПРАВЛЕНИЕ:
        delete ptr2;  // Не забываем!
        ptr2 = nullptr;
    }
    
    // ОШИБКА 3: Двойное удаление
    cout << "\n3. Двойное удаление:" << endl;
    {
        int* ptr3 = new int(200);
        delete ptr3;  // Первое удаление - OK
        
        // delete ptr3;  // ОШИБКА: второе удаление того же указателя!
        
        // ИСПРАВЛЕНИЕ:
        ptr3 = nullptr;  // После delete устанавливаем в nullptr
        // Тогда повторный delete безопасен (delete nullptr ничего не делает)
    }
    
    // ОШИБКА 4: Доступ после удаления
    cout << "\n4. Доступ после удаления:" << endl;
    {
        int* ptr4 = new int(300);
        delete ptr4;  // Освободили память
        
        // *ptr4 = 400;  // ОПАСНО: доступ к освобожденной памяти!
        
        // ИСПРАВЛЕНИЕ:
        ptr4 = nullptr;  // Обнуляем указатель
        // Теперь попытка доступа будет явной ошибкой
    }
    
    // ОШИБКА 5: Несоответствие new[] и delete
    cout << "\n5. Несоответствие new[] и delete:" << endl;
    {
        int* arr = new int[5];  // Выделили массив
        
        // delete arr;  // ОШИБКА: нужно delete[] arr
        
        // ИСПРАВЛЕНИЕ:
        delete[] arr;  // Правильно для массивов
    }
    
    // ОШИБКА 6: Переполнение буфера
    cout << "\n6. Переполнение буфера:" << endl;
    {
        char buffer[10];
        // strcpy(buffer, "Очень длинная строка, которая не помещается"); // ОПАСНО!
        
        // ИСПРАВЛЕНИЕ:
        strncpy(buffer, "Короткая", sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = '\0';  // Гарантируем завершающий ноль
    }
    
    // ПРАКТИЧЕСКОЕ ЗАДАНИЕ: найти все ошибки
    cout << "\n--- ПРАКТИЧЕСКОЕ ЗАДАНИЕ ---" << endl;
    cout << "Найдите все ошибки в следующем коде:" << endl;
    
    cout << "\nКОД ДЛЯ АНАЛИЗА:" << endl;
    cout << "{" << endl;
    cout << "    int* p1 = new int(10);" << endl;
    cout << "    int* p2 = p1;" << endl;
    cout << "    " << endl;
    cout << "    delete p1;" << endl;
    cout << "    " << endl;
    cout << "    *p2 = 20;  // ОШИБКА 1: доступ через висячий указатель" << endl;
    cout << "    " << endl;
    cout << "    char* str = new char[50];" << endl;
    cout << "    strcpy(str, \"Hello\");" << endl;
    cout << "    delete str;  // ОШИБКА 2: нужно delete[]" << endl;
    cout << "    " << endl;
    cout << "    int* arr = new int[100];" << endl;
    cout << "    // Забыли delete[] arr  // ОШИБКА 3: утечка" << endl;
    cout << "}" << endl;
    
    // АНАЛИЗ ТЕКУЩЕГО СОСТОЯНИЯ
    cout << "\n--- АНАЛИЗ ТЕКУЩЕГО СОСТОЯНИЯ ---" << endl;
    cout << "Выделений: " << allocation_count << endl;
    cout << "Освобождений: " << deallocation_count << endl;
    
    if (allocation_count > deallocation_count) {
        cout << "ОБНАРУЖЕНА УТЕЧКА ПАМЯТИ!" << endl;
        cout << "Не освобождено: " << allocation_count - deallocation_count 
             << " блоков памяти" << endl;
    } else if (allocation_count == deallocation_count) {
        cout << "Память управляется правильно (без утечек)" << endl;
    } else {
        cout << "Странная ситуация: освобождений больше чем выделений!" << endl;
    }
    
    // ВОССТАНОВЛЕНИЕ ОРИГИНАЛЬНЫХ new/delete
    cout << "\nВосстанавливаем оригинальные операторы new/delete..." << endl;
}

int main() {
    cout << "=== ПРОГРАММА ДЛЯ АНАЛИЗА ПАМЯТИ ===\n" << endl;
    
    // Вызываем первую функцию
    debugMemoryIssues();
    
    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    return 0;
}