// main.cpp - Главная программа с использованием пространств имен

#include <iostream>
#include "math_array.h"
#include "string_array.h"

using namespace std;

int main() {
    cout << "=== ПРОЕКТ С ПРОСТРАНСТВАМИ ИМЕН ===" << endl;
    cout << "===================================" << endl;
    
    // ЧАСТЬ 1: Математические операции с массивами чисел
    cout << "\n1. МАТЕМАТИЧЕСКИЕ ОПЕРАЦИИ:" << endl;
    cout << "----------------------------" << endl;
    
    int numbers1[5] = {1, 2, 3, 4, 5};
    int numbers2[5] = {10, 20, 30, 40, 50};
    int result[5];
    
    // Использование функций из MathArray
    MathArray::addArrays(numbers1, numbers2, result, 5);
    cout << "Сложение массивов: ";
    for (int i = 0; i < 5; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    MathArray::multiplyByNumber(numbers1, 5, 2, result);
    cout << "Умножение на 2: ";
    for (int i = 0; i < 5; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    double avg = MathArray::findAverage(numbers1, 5);
    cout << "Среднее чисел 1-5: " << avg << endl;
    
    bool sorted = MathArray::isSorted(numbers1, 5);
    cout << "Массив отсортирован? " << (sorted ? "Да" : "Нет") << endl;
    
    // ЧАСТЬ 2: Операции с массивами строк
    cout << "\n2. ОПЕРАЦИИ СО СТРОКАМИ:" << endl;
    cout << "------------------------" << endl;
    
    string fruits[4] = {"яблоко", "банан", "апельсин", "арбуз"};
    
    // Использование функций из StringArray
    StringArray::printStringArray(fruits, 4);
    
    string longest = StringArray::findLongestString(fruits, 4);
    cout << "Самая длинная строка: " << longest << endl;
    
    int countA = StringArray::countStringsStartingWith(fruits, 4, 'a');
    cout << "Строк на 'а': " << countA << endl;
    
    string joined = StringArray::joinStrings(fruits, 4, ", ");
    cout << "Объединенные строки: " << joined << endl;
    
    // ЧАСТЬ 3: Разные способы использования namespace
    cout << "\n3. РАЗНЫЕ СПОСОБЫ ИСПОЛЬЗОВАНИЯ:" << endl;
    cout << "-------------------------------" << endl;
    
    // Способ 1: Полное имя (уже использовали выше)
    cout << "Способ 1: MathArray::findAverage = " 
         << MathArray::findAverage(numbers2, 5) << endl;
    
    // Способ 2: Using declaration (для конкретной функции)
    using MathArray::isSorted;
    int testArray[3] = {3, 1, 2};
    cout << "Способ 2: isSorted? " << (isSorted(testArray, 3) ? "Да" : "Нет") << endl;
    
    // Способ 3: Using directive (для всех функций в namespace)
    {
        using namespace StringArray;
        string colors[3] = {"красный", "зеленый", "синий"};
        cout << "Способ 3: Самая длинный цвет: " << findLongestString(colors, 3) << endl;
    }
    
    cout << "\nПрограмма завершена!" << endl;
    return 0;
}