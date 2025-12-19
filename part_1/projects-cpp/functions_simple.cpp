#include <iostream>

// Объявляем прототип функции - говорим компилятору, что такая функция будет


int calculateSum(int firstNumber, int secondNumber);

// Объявление функции с параметром по ссылке
void modifyNumber(int& numberToModify);

// Объявление функции с параметром по константной ссылке
void printNumber(const int& numberToPrint);

int main() {
    int a = 5;
    int b = 10;
    // a и b передаются ПО ЗНАЧЕНИЮ (копируются)
    int result = calculateSum(a, b);
    std::cout<< "Сумма: " << result << std::endl;
    modifyNumber(a);
    std::cout << "Измененное а: " << a << std::endl;

    printNumber(a);


    return 0;

}

int calculateSum(int firstNumber, int secondNumber) {

    // firstNumber и secondNumber - КОПИИ значений из main()
    int sum = firstNumber + secondNumber;
    return sum;
    }
void modifyNumber(int& numberToModify) {

    // numberToModify - это ССЫЛКА на переменную
    numberToModify = numberToModify * 2;
    // здесь нет return, так как фнукция возвращает void
}
void printNumber(const int& numberToPrint) {
    std::cout << "Число: " << numberToPrint << std::endl;

}