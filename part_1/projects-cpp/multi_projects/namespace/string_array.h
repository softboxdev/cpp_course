// string_array.h - Функции для массивов строк

#ifndef STRING_ARRAY_H
#define STRING_ARRAY_H

#include <string>  // Для использования std::string

// Другое пространство имен
namespace StringArray {
    // Функция печати массива строк
    void printStringArray(std::string arr[], int size);
    
    // Функция поиска самой длинной строки
    std::string findLongestString(std::string arr[], int size);
    
    // Функция подсчета строк, начинающихся с буквы
    int countStringsStartingWith(std::string arr[], int size, char letter);
    // letter - буква, с которой должна начинаться строка
    
    // Функция объединения всех строк в одну
    std::string joinStrings(std::string arr[], int size, std::string separator);
    // separator - разделитель между строками
}

#endif