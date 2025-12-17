#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    // Загадываем число от 1 до 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int MAX_ATTEMPTS = 10;
    cout << "===Игра 'Угадай число' ===" << endl;
    cout << "Я загадал число от 1 до 100." << endl;
    cout << "У вас есть " << MAX_ATTEMPTS << " попыток. " << endl;
    cout << "=======================================";

    // Основной цикл игры
    while(attempts < MAX_ATTEMPTS)  {
        attempts++;
        cout << "\nПопытка " << attempts << "/" << MAX_ATTEMPTS << endl;
        cout << "Ваш вариант: " ;
        cin >> guess;

        if(guess == secretNumber) {
            cout << "\n Поздравляю! Вы угадали число "<< secretNumber;
            cout << " за "<< attempts << " попыток! "<< endl;
            break;
        }
        else if(guess < secretNumber) {
            cout << "Мое число БОЛЬШЕ вашего." << endl;
        }
        else {
            cout << "Мое число МЕНЬШЕ вашего." << endl;
        }
        // Подсказка после нескольких неудачных попыток
        if(attempts == MAX_ATTEMPTS /2 ) {
            if(secretNumber % 2 == 0) {
                cout << "Подсказка: число четное!" << endl;
            } else {
                cout << "Подсказка: число нечетное!" << endl;
            }
        }
    }
    //Если закончились попытки
    if(attempts == MAX_ATTEMPTS && guess != secretNumber) {
        cout << "Увы! Вы исчерпали все попытки. " << endl;
        cout << "Загаданное число было: " << secretNumber  << endl;
    }
    // Статистика игры
    cout << "\n===Статистика игры ===" << endl;
    cout << "Загаданное число: " << secretNumber << endl;
    cout << "Потрачено попыток: " << attempts << endl;
    if(attempts <= 5) {
        cout << "Отличный результат!" << endl;
    } else if(attempts <=8) {
        cout << "Хороший результат!" << endl;
    } else {
        cout << "Попрактикуйтесь еще!" << endl;
    }
    return 0;
}