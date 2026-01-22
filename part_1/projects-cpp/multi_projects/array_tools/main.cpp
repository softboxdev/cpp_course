// main.cpp - ГЛАВНАЯ программа
// Здесь мы ИСПОЛЬЗУЕМ наши функции

#include <iostream>      // Для ввода/вывода
#include "array_tools.h" // Включаем наши функции для работы с массивами

using namespace std;     // Чтобы не писать std:: перед cout

int main() {  // Начало программы
    cout << "=== ПРОСТОЙ ПРОЕКТ С МАССИВАМИ ===" << endl;
    cout << "=================================" << endl;
    
    // 1. Создаем массив из 5 чисел
    const int SIZE = 5;  // Константа - размер массива (нельзя изменить)
    int numbers[SIZE];   // Объявляем массив из 5 элементов
    
    // 2. Заполняем массив случайными числами от 1 до 10
    fillRandom(numbers, SIZE, 1, 10);
    
    // 3. Печатаем массив
    printArray(numbers, SIZE);
    
    // 4. Находим и выводим сумму элементов
    int total = sumArray(numbers, SIZE);
    cout << "Сумма элементов: " << total << endl;
    
    // 5. Находим и выводим максимальный элемент
    int maximum = findMax(numbers, SIZE);
    cout << "Максимальный элемент: " << maximum << endl;
    
    // 6. Создаем еще один массив
    cout << "\n=== ВТОРОЙ МАССИВ ===" << endl;
    int anotherArray[3] = {10, 20, 30};  // Создаем и сразу заполняем
    
    // 7. Используем наши функции с новым массивом
    printArray(anotherArray, 3);
    cout << "Сумма: " << sumArray(anotherArray, 3) << endl;
    cout << "Максимум: " << findMax(anotherArray, 3) << endl;
    
    cout << "\nПрограмма завершена!" << endl;
    return 0;  // Конец программы (все хорошо)
}