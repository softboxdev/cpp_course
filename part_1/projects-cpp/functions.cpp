#include <iostream>
using namespace std;

int add(int a, int b);
void printHello();
double calculateCircleArea(double radius);
void printNumber(int number);

int main() {
    printHello();
    int x = 10, y = 20;
    int result = add(x,y);
    printNumber(result);

    double radius = 5.5;
    double area = calculateCircleArea(radius);
    cout << "Площадь круга : "<< area << endl;

    return 0;


}

// 3. ОПРЕДЕЛЕНИЯ ФУНКЦИЙ
void printHello() {
    cout << "Привет из функции !" << endl;
    
}

int add(int a, int b) {
    return a + b;
}

void printNumber(int number) {
    cout << "Число: " << number << endl;
}

double calculateCircleArea(double radius) {
    const double PI = 3.14159;
    return radius * radius * PI;
}
