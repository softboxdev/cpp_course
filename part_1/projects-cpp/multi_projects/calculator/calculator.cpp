// calculator.cpp
#include "calculator.h"

namespace Calculator {
    // Реализация функции multiply
    int multiply(int a, int b) {
        return a * b;
    }
    
    // Реализация функции divide  
    double divide(int a, int b) {
        if (b == 0) {
            return 0.0;  // защита от деления на ноль
        }
        return static_cast<double>(a) / b;
    }
}