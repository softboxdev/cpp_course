// string_array.cpp - Реализация функций для строк

#include "string_array.h"
#include <iostream>

using namespace std;

namespace StringArray {
    
    void printStringArray(string arr[], int size) {
        cout << "Строки: ";
        for (int i = 0; i < size; i++) {
            cout << "\"" << arr[i] << "\"";  // Выводим в кавычках
            if (i < size - 1) cout << ", ";
        }
        cout << endl;
    }
    
    string findLongestString(string arr[], int size) {
        if (size == 0) return "";  // Если массив пустой
        
        string longest = arr[0];  // Первая строка - пока самая длинная
        for (int i = 1; i < size; i++) {
            if (arr[i].length() > longest.length()) {  // Сравниваем длины
                longest = arr[i];  // Нашли более длинную
            }
        }
        return longest;
    }
    
    int countStringsStartingWith(string arr[], int size, char letter) {
        int count = 0;  // Счетчик
        for (int i = 0; i < size; i++) {
            if (!arr[i].empty() && arr[i][0] == letter) {  // Если строка не пустая и начинается с letter
                count++;  // Увеличиваем счетчик
            }
        }
        return count;
    }
    
    string joinStrings(string arr[], int size, string separator) {
        if (size == 0) return "";
        
        string result = arr[0];  // Начинаем с первой строки
        for (int i = 1; i < size; i++) {
            result += separator + arr[i];  // Добавляем разделитель и следующую строку
        }
        return result;
    }
}