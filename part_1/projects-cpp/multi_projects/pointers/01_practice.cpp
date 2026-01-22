#include <iostream>  // Подключаем библиотеку для ввода/вывода

int main() {  // Главная функция программы
    // Объявляем и инициализируем переменные
    int number = 42;           // Создаём целочисленную переменную со значением 42
    double price = 99.99;      // Создаём переменную с плавающей точкой
    
    // Работа с указателями
    int* pointerToNumber = &number;    // Создаём указатель на int и присваиваем адрес number
    double* pointerToPrice = &price;   // Создаём указатель на double и присваиваем адрес price
    
    // Выводим значения и адреса
    std::cout << "=== БАЗОВЫЕ ОПЕРАЦИИ С УКАЗАТЕЛЯМИ ===" << std::endl;
    std::cout << std::endl;
    
    // 1. Выводим значения переменных
    std::cout << "1. Значения переменных:" << std::endl;
    std::cout << "   number = " << number << std::endl;      // Прямой доступ к значению
    std::cout << "   price = " << price << std::endl;        // Прямой доступ к значению
    std::cout << std::endl;
    
    // 2. Выводим адреса переменных
    std::cout << "2. Адреса переменных в памяти:" << std::endl;
    std::cout << "   &number = " << &number << std::endl;    // Адрес переменной number
    std::cout << "   &price = " << &price << std::endl;      // Адрес переменной price
    std::cout << std::endl;
    
    // 3. Выводим значения указателей
    std::cout << "3. Значения указателей:" << std::endl;
    std::cout << "   pointerToNumber = " << pointerToNumber << std::endl;   // Должен совпадать с &number
    std::cout << "   pointerToPrice = " << pointerToPrice << std::endl;     // Должен совпадать с &price
    std::cout << std::endl;
    
    // 4. Разыменование указателей
    std::cout << "4. Разыменование указателей:" << std::endl;
    std::cout << "   *pointerToNumber = " << *pointerToNumber << std::endl;  // Значение по адресу
    std::cout << "   *pointerToPrice = " << *pointerToPrice << std::endl;    // Значение по адресу
    std::cout << std::endl;
    
    // 5. Изменение значения через указатель
    std::cout << "5. Изменение значения через указатель:" << std::endl;
    *pointerToNumber = 100;           // Меняем значение number через указатель
    std::cout << "   После *pointerToNumber = 100:" << std::endl;
    std::cout << "   number = " << number << std::endl;      // Проверяем, что number изменился
    std::cout << "   *pointerToNumber = " << *pointerToNumber << std::endl;  // Проверяем через указатель
    std::cout << std::endl;
    
    // 6. Работа с нулевым указателем
    std::cout << "6. Работа с нулевым указателем:" << std::endl;
    int* nullPointer = nullptr;       // Создаём нулевой указатель (современный C++)
    // int* nullPointer = NULL;       // Старый стиль (лучше не использовать)
    // int* nullPointer = 0;          // Ещё один старый стиль
    
    if (nullPointer == nullptr) {     // Проверяем, является ли указатель нулевым
        std::cout << "   nullPointer равен nullptr" << std::endl;
    }
    
    // НИКОГДА не разыменовывайте нулевой указатель!
    // *nullPointer = 10;  // ОШИБКА: программа упадёт!
    
    return 0;  // Завершаем программу успешно
}