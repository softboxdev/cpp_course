#include <iostream>
using namespace std;

int main() {
    int x = 10;
    
    // Объявление ссылки (должна быть инициализирована сразу)
    int& ref = x;  // ref - это псевдоним для x
    
    cout << "x = " << x << endl;        // 10
    cout << "ref = " << ref << endl;    // 10
    cout << "&x = " << &x << endl;      // адрес x
    cout << "&ref = " << &ref << endl;  // тот же адрес
    
    // Изменение через ссылку изменяет оригинальную переменную
    ref = 20;
    cout << "\nПосле ref = 20:" << endl;
    cout << "x = " << x << endl;        // 20
    cout << "ref = " << ref << endl;    // 20
    
    // Ссылка не может быть перенаправлена!
    int y = 30;
    // ref = y;  // Это присвоение значения, не перенаправление ссылки
    ref = y;     // x = 30, ref = 30, но ref все еще ссылается на x
    cout << "\nПосле ref = y (y=30):" << endl;
    cout << "x = " << x << endl;        // 30
    cout << "ref = " << ref << endl;    // 30
    cout << "y = " << y << endl;        // 30
    
    // Можно создать ссылку на ссылку (фактически, ссылку на ту же переменную)
    int& ref_ref = ref;  // ref_ref тоже ссылается на x
    ref_ref = 40;
    cout << "\nПосле ref_ref = 40:" << endl;
    cout << "x = " << x << endl;        // 40
    
    return 0;
}