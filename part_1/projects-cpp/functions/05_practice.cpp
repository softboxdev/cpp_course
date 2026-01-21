#include <iostream>
using namespace std;

// Объявление функций
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
double divide(int a, int b) { return static_cast<double>(a) / b; }

int main() {
    // Указатель на функцию, возвращающую int и принимающую два int
    int (*func_ptr)(int, int);
    
    func_ptr = add;  // присваиваем адрес функции add
    cout << "add(5, 3) = " << func_ptr(5, 3) << endl;  // 8
    
    func_ptr = subtract;
    cout << "subtract(5, 3) = " << func_ptr(5, 3) << endl;  // 2
    
    func_ptr = multiply;
    cout << "multiply(5, 3) = " << func_ptr(5, 3) << endl;  // 15
    
    // Массив указателей на функции
    int (*operations[3])(int, int) = {add, subtract, multiply};
    char* op_names[3] = {"Сложение", "Вычитание", "Умножение"};
    
    cout << "\nМассив указателей на функции:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << op_names[i] << ": " << operations[i](10, 5) << endl;
    }
    
    // Указатель на функцию с другим типом возвращаемого значения
    double (*div_ptr)(int, int) = divide;
    cout << "\nДеление: 10 / 3 = " << div_ptr(10, 3) << endl;
    
    // typedef для упрощения
    typedef int (*MathOperation)(int, int);
    MathOperation op1 = add;
    MathOperation op2 = multiply;
    
    cout << "\nИспользование typedef:" << endl;
    cout << "op1(7, 2) = " << op1(7, 2) << endl;  // 9
    cout << "op2(7, 2) = " << op2(7, 2) << endl;  // 14
    
    return 0;
}