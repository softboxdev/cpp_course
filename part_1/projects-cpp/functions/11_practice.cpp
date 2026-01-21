#include <iostream>
using namespace std;

// 1. Параметр по значению (копия)
void incrementByValue(int x) {
    x++;
    cout << "Внутри incrementByValue: x = " << x << endl;
}

// 2. Параметр по ссылке (работа с оригиналом)
void incrementByReference(int& x) {
    x++;
    cout << "Внутри incrementByReference: x = " << x << endl;
}

// 3. Константная ссылка (чтение без копирования)
void printValue(const int& x) {
    // x = 100;  // ОШИБКА: нельзя изменить константную ссылку
    cout << "Внутри printValue: x = " << x << endl;
}

// 4. Возврат ссылки (ОПАСНО, если возвращается ссылка на локальную переменную)
int& getElement(int arr[], int index) {
    return arr[index];  // OK: возвращаем ссылку на элемент массива
}

// НЕПРАВИЛЬНО: возврат ссылки на локальную переменную
int& badFunction() {
    int x = 100;        // локальная переменная
    return x;           // ОШИБКА: x уничтожится после выхода из функции
}

int main() {
    int a = 5;
    
    cout << "До incrementByValue: a = " << a << endl;
    incrementByValue(a);
    cout << "После incrementByValue: a = " << a << endl;  // не изменился
    
    cout << "\nДо incrementByReference: a = " << a << endl;
    incrementByReference(a);
    cout << "После incrementByReference: a = " << a << endl;  // изменился!
    
    cout << "\nВызов printValue: ";
    printValue(a);
    
    // Работа с возвращаемой ссылкой
    int arr[5] = {10, 20, 30, 40, 50};
    getElement(arr, 2) = 999;  // изменяем элемент через возвращенную ссылку
    
    cout << "\nПосле getElement(arr, 2) = 999:" << endl;
    cout << "arr[2] = " << arr[2] << endl;  // 999
    
    return 0;
}