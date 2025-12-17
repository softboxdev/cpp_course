#include <iostream>
using namespace std;

int main() {
    int n;
    long long factorial = 1;
    cout << "Введите число N: ";
    cin >> n;
    if (n < 0) {
        cout << "Ошибка: факториал определен только для неотрицательных чисел!" << endl;
        return 1;
    }
    if(n > 20) {
        cout << "Внимание: результат может быть неверным для N > 20 " << endl;
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        factorial *= i; // factorial = factorial * i
    }
    cout << n << "! = " << factorial << endl;
    return 0;
}