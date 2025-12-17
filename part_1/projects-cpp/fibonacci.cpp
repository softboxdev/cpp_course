#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Сколько числе Фибоначчи вывести? ";
    cin >> n;
    if(n <= 0) {
        cout << "Количество должно быть положительным!" << endl;
        return 1;
    }
    long long a = 0, b = 1; //Первые два числа 
    int count = 0; // Счетчик выведенных чисел
    cout << "Первые "<< n << " чисел ФИбоначчи: " << endl;
    while(count < n) {
        cout << a;
        if(count < n-1) cout <<", ";
        // Вычисляем следующее число
        long long next = a + b;
        a = b;
        b = next;
        count++;
    }
    cout << endl;
    return 0;

}
