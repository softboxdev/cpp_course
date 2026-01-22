#include <iostream>
#include <cstring>  // для strlen, strcpy
using namespace std;

// 1. Функция для обмена значений (работа с указателями)
void swapValues(int* a, int* b) {
    // Классический вопрос: как работает swap?
    int temp = *a;  // Сохраняем значение по адресу a
    *a = *b;        // Записываем значение b в a
    *b = temp;      // Восстанавливаем старое значение a в b
}

// 2. Функция для обмена без временной переменной
void swapWithoutTemp(int* a, int* b) {
    // Трюк с XOR (побитовое исключающее ИЛИ)
    
    *a = *a ^ *b;  // a теперь содержит a XOR b
    *b = *a ^ *b;  // b = (a XOR b) XOR b = a
    *a = *a ^ *b;  // a = (a XOR b) XOR a = b
}

// 3. Функция для подсчета длины строки (аналог strlen)
int stringLength(const char* str) {
    // str - указатель на начало строки
    // Идем пока не встретим нулевой символ '\0'
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;  // Перемещаем указатель на следующий символ
    }
    return length;
}

// 4. Функция для копирования строки (аналог strcpy)
void stringCopy(char* dest, const char* src) {
    // Копируем пока не встретим '\0'
    while (*src != '\0') {
        *dest = *src;  // Копируем символ
        dest++;        // Двигаем указатель приемника
        src++;         // Двигаем указатель источника
    }
    *dest = '\0';  // Завершаем строку нулевым символом
}

// 5. Функция для сравнения строк (аналог strcmp)
int stringCompare(const char* str1, const char* str2) {
    // Сравниваем посимвольно
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return *str1 - *str2;  // Разница символов
        }
        str1++;
        str2++;
    }
    // Если одна строка закончилась раньше
    return *str1 - *str2;
}

// 6. Функция для конкатенации строк (аналог strcat)
void stringConcatenate(char* dest, const char* src) {
    // Находим конец первой строки
    while (*dest != '\0') {
        dest++;
    }
    // Копируем вторую строку в конец первой
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Завершаем строку
}

// 7. Функция для реверса строки на месте
void reverseString(char* str) {
    if (str == nullptr) return;
    
    // Находим конец строки
    char* end = str;
    while (*end != '\0') {
        end++;
    }
    end--;  // Указатель на последний символ (не '\0')
    
    // Меняем символы с начала и конца
    char* start = str;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// 8. Функция для проверки палиндрома
bool isPalindrome(const char* str) {
    if (str == nullptr) return false;
    
    // Находим конец строки
    const char* end = str;
    while (*end != '\0') {
        end++;
    }
    end--;  // Последний символ
    
    // Сравниваем с начала и конца
    while (str < end) {
        if (*str != *end) {
            return false;
        }
        str++;
        end--;
    }
    return true;
}

// 9. Функция для нахождения подстроки (упрощенная)
const char* findSubstring(const char* str, const char* substr) {
    // Если подстрока пустая
    if (*substr == '\0') return str;
    
    // Проходим по основной строке
    for (int i = 0; str[i] != '\0'; i++) {
        // Проверяем, совпадает ли подстрока с текущей позиции
        int j = 0;
        while (substr[j] != '\0' && str[i + j] == substr[j]) {
            j++;
        }
        // Если дошли до конца подстроки - нашли
        if (substr[j] == '\0') {
            return &str[i];
        }
    }
    return nullptr;  // Не нашли
}

void demonstrateStringFunctions() {
    cout << "\n\n=== ЗАДАЧА 4: РАБОТА СО СТРОКАМИ ===" << endl;
    cout << "=================================" << endl;
    
    // 1. Работа с swap
    cout << "1. Обмен значений через указатели:" << endl;
    int x = 5, y = 10;
    cout << "   До обмена: x = " << x << ", y = " << y << endl;
    swapValues(&x, &y);
    cout << "   После swapValues: x = " << x << ", y = " << y << endl;
    
    // Возвращаем значения
    swapValues(&x, &y);
    cout << "   Возвращаем обратно..." << endl;
    
    // 2. Обмен без временной переменной
    cout << "\n2. Обмен без временной переменной (XOR):" << endl;
    cout << "   До обмена: x = " << x << ", y = " << y << endl;
    swapWithoutTemp(&x, &y);
    cout << "   После swapWithoutTemp: x = " << x << ", y = " << y << endl;
    swapWithoutTemp(&x, &y);  // Возвращаем обратно
    
    // 3. Длина строки
    cout << "\n3. Длина строки:" << endl;
    const char* text = "Hello";
    cout << "   Строка: \"" << text << "\"" << endl;
    cout << "   Длина (наша функция): " << stringLength(text) << endl;
    cout << "   Длина (strlen): " << strlen(text) << endl;
    
    // 4. Копирование строк
    cout << "\n4. Копирование строк:" << endl;
    char source[] = "World";
    char destination[20];
    stringCopy(destination, source);
    cout << "   Исходная: \"" << source << "\"" << endl;
    cout << "   Копия: \"" << destination << "\"" << endl;
    
    // 5. Сравнение строк
    cout << "\n5. Сравнение строк:" << endl;
    cout << "   \"Hello\" vs \"Hello\": " << stringCompare("Hello", "Hello") << endl;
    cout << "   \"Apple\" vs \"Banana\": " << stringCompare("Apple", "Banana") << endl;
    cout << "   \"Zebra\" vs \"Apple\": " << stringCompare("Zebra", "Apple") << endl;
    
    // 6. Конкатенация
    cout << "\n6. Конкатенация строк:" << endl;
    char str1[20] = "Hello, ";
    const char* str2 = "World!";
    stringConcatenate(str1, str2);
    cout << "   Результат: \"" << str1 << "\"" << endl;
    
    // 7. Реверс строки
    cout << "\n7. Реверс строки:" << endl;
    char revStr[] = "ABCDE";
    cout << "   До реверса: \"" << revStr << "\"" << endl;
    reverseString(revStr);
    cout << "   После реверса: \"" << revStr << "\"" << endl;
    
    // 8. Проверка палиндрома
    cout << "\n8. Проверка палиндрома:" << endl;
    cout << "   \"radar\": " << (isPalindrome("radar") ? "палиндром" : "не палиндром") << endl;
    cout << "   \"hello\": " << (isPalindrome("hello") ? "палиндром" : "не палиндром") << endl;
    cout << "   \"racecar\": " << (isPalindrome("racecar") ? "палиндром" : "не палиндром") << endl;
    
    // 9. Поиск подстроки
    cout << "\n9. Поиск подстроки:" << endl;
    const char* mainStr = "Hello, beautiful world!";
    const char* subStr = "beautiful";
    const char* found = findSubstring(mainStr, subStr);
    if (found) {
        cout << "   Нашли \"" << subStr << "\" в \"" << mainStr << "\"" << endl;
        cout << "   Начинается с позиции: " << (found - mainStr) << endl;
    } else {
        cout << "   Не нашли" << endl;
    }
}

int main () {
    demonstrateStringFunctions();
    return 0;
}