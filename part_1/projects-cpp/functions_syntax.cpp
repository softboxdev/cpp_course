#include <iostream>
void simpleByValue(int num, double price, char grade) {
    // Все параметры передаем, как локальные копии
    num = 100;
    price = 99.99;
    grade = 'A';

    std::cout << "Внутри функции: " << num << "," << price << ", " <<grade << std::endl;
}

void pointerByValue(int* ptr) {
    // ptr - копия указателя, указывает на те же самые данные
    *ptr = 100;
    ptr = nulptr;

}