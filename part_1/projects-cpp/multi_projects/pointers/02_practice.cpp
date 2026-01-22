#include <iostream>

int main() {
    std::cout << "=== УКАЗАТЕЛИ И МАССИВЫ ===" << std::endl;
    std::cout << std::endl;
    
    // Создаём массив из 5 элементов
    int numbers[5] = {10, 20, 30, 40, 50};  // Статический массив в стеке
    
    // 1. Имя массива - это указатель на первый элемент
    std::cout << "1. Имя массива как указатель:" << std::endl;
    std::cout << "   numbers = " << numbers << std::endl;        // Адрес первого элемента
    std::cout << "   &numbers[0] = " << &numbers[0] << std::endl; // Тот же адрес
    std::cout << "   *numbers = " << *numbers << std::endl;      // Первый элемент (10)
    std::cout << std::endl;
    
    // 2. Создаём указатель на массив
    int* ptr = numbers;  // ptr указывает на numbers[0]
    
    std::cout << "2. Работа через указатель:" << std::endl;
    std::cout << "   ptr = " << ptr << std::endl;
    std::cout << "   *ptr = " << *ptr << std::endl;      // numbers[0]
    std::cout << std::endl;
    
    // 3. Арифметика указателей
    std::cout << "3. Арифметика указателей:" << std::endl;
    std::cout << "   ptr + 1 = " << ptr + 1 << std::endl;    // Адрес numbers[1]
    std::cout << "   *(ptr + 1) = " << *(ptr + 1) << std::endl;  // numbers[1] = 20
    std::cout << std::endl;
    
    // 4. Итерация по массиву через указатель
    std::cout << "4. Итерация по массиву через указатель:" << std::endl;
    std::cout << "   Элементы массива: ";
    
    // Первый способ: через указатель
    int* current = numbers;  // Начинаем с первого элемента
    for (int i = 0; i < 5; i++) {
        std::cout << *current << " ";  // Выводим значение
        current++;                      // Переходим к следующему элементу
    }
    std::cout << std::endl;
    
    // Второй способ: через индексы
    std::cout << "   Через индексы: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *(numbers + i) << " ";  // numbers[i] эквивалентно *(numbers + i)
    }
    std::cout << std::endl;
    
    // 5. Изменение элементов через указатель
    std::cout << std::endl;
    std::cout << "5. Изменение элементов через указатель:" << std::endl;
    
    ptr = numbers;          // Возвращаем указатель на начало
    *(ptr + 2) = 300;       // Меняем третий элемент (индекс 2)
    
    std::cout << "   После *(ptr + 2) = 300:" << std::endl;
    std::cout << "   numbers[2] = " << numbers[2] << std::endl;  // Должно быть 300
    
    return 0;
}