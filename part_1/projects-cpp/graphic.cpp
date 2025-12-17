#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "График функции y = x^2" << endl;
    cout << "x от -5 до 5" << endl;
    cout << "==========================" << endl;
    for(int x = -5; x < 5; x++) {
        int y = x * x;
        cout << "x=" << x << " y=" << y << "";
        // Рисуем график 
        int stars = y / 2;
        if (stars > 30)  stars = 30;
        for(int i = 0; i < stars; i ++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;

}