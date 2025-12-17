#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Введите число N для обратного отсчета: ";
    cin >> n;

    cout << "Обратный отсчет от " << " до 1:" << endl;

    int counter = n;

    do {
        cout << counter << endl;
        counter--;

    } while(counter >= 1);

    cout << "Поехали!" << endl;

    return 0;
}