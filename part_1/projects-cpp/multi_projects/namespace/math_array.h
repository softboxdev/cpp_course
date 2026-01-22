// math_array.h - Математические функции для массивов

#ifndef MATH_ARRAY_H
#define MATH_ARRAY_H

// Создаем ПРОСТРАНСТВО ИМЕН MathArray
// Все функции внутри будут принадлежать этому пространству
namespace MathArray {
    // Функция сложения двух массивов
    void addArrays(int arr1[], int arr2[], int result[], int size);
    // arr1 - первый массив, arr2 - второй
    // result - массив для результата, size - размер всех массивов
    
    // Функция умножения массива на число
    void multiplyByNumber(int arr[], int size, int number, int result[]);
    
    // Функция нахождения среднего значения
    double findAverage(int arr[], int size);  // Возвращает double (дробное число)
    
    // Функция проверки, отсортирован ли массив
    bool isSorted(int arr[], int size);  // Возвращает true или false
}

#endif