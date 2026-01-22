// math_array.cpp - Реализация математических функций

#include "math_array.h"  // Наш заголовочный файл
#include <iostream>

using namespace std;

// Указываем, что реализуем функции из пространства имен MathArray
namespace MathArray {
    
    void addArrays(int arr1[], int arr2[], int result[], int size) {
        for (int i = 0; i < size; i++) {
            result[i] = arr1[i] + arr2[i];  // Складываем соответствующие элементы
        }
    }
    
    void multiplyByNumber(int arr[], int size, int number, int result[]) {
        for (int i = 0; i < size; i++) {
            result[i] = arr[i] * number;  // Умножаем каждый элемент на число
        }
    }
    
    double findAverage(int arr[], int size) {
        if (size == 0) return 0.0;  // Защита от деления на 0
        
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return static_cast<double>(sum) / size;  // Приводим к double для точности
    }
    
    bool isSorted(int arr[], int size) {
        if (size < 2) return true;  // Массив из 0 или 1 элемента считается отсортированным
        
        // Проверяем, отсортирован ли по возрастанию
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[i - 1]) {  // Если текущий меньше предыдущего
                return false;  // Не отсортирован
            }
        }
        return true;  // Если дошли до конца, значит отсортирован
    }
}