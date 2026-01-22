// main.cpp
#include <iostream>
#include "calculator.h"  // ПОДКЛЮЧАЕМ заголовочный файл

int main() {
    std::cout << "Пример работы:" << std::endl;
    std::cout << "6 * 7 = " << Calculator::multiply(6, 7) << std::endl;
    std::cout << "15 / 4 = " << Calculator::divide(15, 4) << std::endl;
    return 0;
}