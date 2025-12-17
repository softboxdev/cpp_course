#include  <iostream>
using namespace std;

int main() {
    int number;
    int sum = 0;
    cout << "Вводите числа от (0 для завершения) : " << endl;

    while (true) {
        cout << "Введите число: ";
        cin >> number;
        if(number == 0) {
            break;
        }
        sum += number;
    }
    cout << "Сумма всех введенных чисел: " << sum << endl;
    return 0;
}