#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Введите N (верхнюю границу): ";
    cin >> n;
    if(n < 2) {
        cout << "Простые числа начинаются с 2!" << endl;
        return 1;
    }
    cout  << "Простые числа от 2 до " << n << ":" << endl;
    // Перебираем все числа от 2 до N
    for(int i =2; i <= n; i++) {
        bool isPrime = true;
        //Проверяем делители от 2 до корня из i
        for(int j = 2; j * j <= i; j++) {
            //Если i делится на j без остатка
            if(i % j == 0) {
                isPrime = false;
                break;

            }
        }
        //  Если число простое, выводит его
        if(isPrime) {
            cout << i << " ";
        }
        
    }
    cout << endl;
    return 0;
}