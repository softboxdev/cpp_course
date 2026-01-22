// greetings.cpp - Еще один исходный файл

#include <iostream>  // Для использования cout
#include "greetings.h"  // Включаем наш заголовочный файл
using namespace std; // Чтобы писать cout вместо std::cout

// Функция для приветствия
void sayHello() {
    cout << "Привет из greetings.cpp!" << endl;
}

// Функция для прощания
void sayGoodbye() {
    cout << "Пока! Заходи еще!" << endl;
}

// Функция, которая показывает использование математических функций
void showMathExample() {
    cout << "Пример из greetings.cpp:" << endl;
    // Здесь мы НЕ можем вызвать add() напрямую
    // потому что не подключили math.h
    // Но main.cpp подключит и math.h, и greetings.cpp
}
namespace Greetings {
    // Простая функция
    string getHelloMessage() {
        return "Здравствуйте!";
    }
    
    // Функция с параметром
    string getPersonalHello(const string& name) {
        return "Привет, " + name + "! Рад тебя видеть!";
    }
    
    // Еще одна функция
    string getGoodbyeMessage() {
        return "Всего доброго! Приходи еще!";
    }
    
    // Внутренняя вспомогательная функция
    // (не объявлена в .h, поэтому видна только здесь)
    string toUpperCase(const string& text) {
        string result = text;
        for (char& c : result) {
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }
        }
        return result;
    }
}