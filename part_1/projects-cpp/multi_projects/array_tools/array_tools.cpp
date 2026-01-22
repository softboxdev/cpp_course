// array_tools.cpp - ИСХОДНЫЙ файл
// Здесь пишем РЕАЛИЗАЦИЮ функций (их код)

#include "array_tools.h"  // Включаем наш заголовочный файл
#include <iostream>       // Для cout (вывода на экран)
#include <cstdlib>        // Для rand() (случайные числа)
#include <ctime>          // Для time() (чтобы rand() работал)

using namespace std;      // Чтобы писать cout вместо std::cout

// Реализация функции печати массива
void printArray(int arr[], int size) {
    cout << "Массив: [";
    for (int i = 0; i < size; i++) {  // Проходим по всем элементам
        cout << arr[i];               // Выводим элемент
        if (i < size - 1) {           // Если не последний элемент
            cout << ", ";             // Ставим запятую
        }
    }
    cout << "]" << endl;              // Закрываем скобку и переходим на новую строку
}

// Реализация функции заполнения случайными числами
void fillRandom(int arr[], int size, int min, int max) {
    srand(time(0));  // Инициализация генератора случайных чисел
    for (int i = 0; i < size; i++) {
        // Генерируем число от min до max
        arr[i] = min + rand() % (max - min + 1);
    }
}

// Реализация функции суммы
int sumArray(int arr[], int size) {
    int sum = 0;  // Переменная для суммы
    for (int i = 0; i < size; i++) {
        sum += arr[i];  // Добавляем каждый элемент к сумме
    }
    return sum;  // Возвращаем результат
}

// Реализация функции поиска максимума
int findMax(int arr[], int size) {
    if (size == 0) return 0;  // Если массив пустой, возвращаем 0
    
    int max = arr[0];  // Предполагаем, что первый элемент - максимальный
    for (int i = 1; i < size; i++) {  // Начинаем со второго элемента
        if (arr[i] > max) {  // Если нашли элемент больше
            max = arr[i];    // Запоминаем его
        }
    }
    return max;  // Возвращаем максимум
}