// Сохраните как example1_leak.cpp
#include <iostream>

int main() {
    std::cout << "=== Пример 1: Простая утечка памяти ===\n" << std::endl;
    
    // ВЫДЕЛЯЕМ память в куче
    int* number = new int(42);
    
    std::cout << "Выделили память для int: " << *number << std::endl;
    
    // ЗАБЫВАЕМ освободить память - УТЕЧКА!
    // delete number;  // ЭТОЙ СТРОЧКИ НЕТ!
    
    std::cout << "Завершение программы...\n";
    std::cout << "Память для 'number' НЕ освобождена!" << std::endl;
    
    return 0;
}