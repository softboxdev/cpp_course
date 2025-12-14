#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;
    
    // Стандартный if/else:
    int max;
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    
    // Тернарный оператор (то же самое в одной строке):
    int max2 = (a > b) ? a : b;
    // Читается так: ЕСЛИ (a > b) ТО a ИНАЧЕ b
    
    cout << "Максимум (if/else): " << max << endl;
    cout << "Максимум (тернарный): " << max2 << endl;
    
    // Еще пример:
    string result = (a == b) ? "числа равны" : "числа разные";
    cout << result << endl;
    
    return 0;
}