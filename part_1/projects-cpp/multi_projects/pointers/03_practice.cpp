#include <iostream>

// ФУНКЦИЯ 1: Вывод массива
// Принимает указатель на массив и его размер
void printArray(int* arr, int size) {
    std::cout << "Массив [" << size << "]: ";
    
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";  // arr[i] эквивалентно *(arr + i)
    }
    
    std::cout << std::endl;
}

// ФУНКЦИЯ 2: Заполнение массива
// Принимает указатель на массив, его размер и значение для заполнения
void fillArray(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        arr[i] = value;  // Заполняем каждый элемент заданным значением
    }
}

// ФУНКЦИЯ 3: Поиск максимального элемента
// Принимает указатель на массив и его размер
// Возвращает максимальный элемент
int findMax(int* arr, int size) {
    if (size <= 0) {  // Проверка на пустой массив
        return 0;     // Возвращаем 0 в случае ошибки
    }
    
    int max = arr[0];  // Предполагаем, что первый элемент - максимальный
    
    for (int i = 1; i < size; i++) {  // Начинаем со второго элемента
        if (arr[i] > max) {           // Если текущий элемент больше max
            max = arr[i];             // Обновляем max
        }
    }
    
    return max;  // Возвращаем найденный максимум
}

// ФУНКЦИЯ 4: Сумма элементов массива
// Принимает указатель на массив и его размер
// Возвращает сумму всех элементов
int sumArray(int* arr, int size) {
    int sum = 0;  // Инициализируем сумму нулём
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];  // Добавляем каждый элемент к сумме
    }
    
    return sum;  // Возвращаем сумму
}

// ФУНКЦИЯ 5: Обратный порядок массива
// Принимает указатель на массив и его размер
// Меняет порядок элементов на обратный
void reverseArray(int* arr, int size) {
    int start = 0;           // Индекс начала
    int end = size - 1;      // Индекс конца
    
    while (start < end) {    // Пока не встретились в середине
        // Меняем местами элементы
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Двигаемся к центру
        start++;
        end--;
    }
}

int main() {
    std::cout << "=== ФУНКЦИИ ДЛЯ РАБОТЫ С МАССИВАМИ ===" << std::endl;
    std::cout << std::endl;
    
    const int SIZE = 6;  // Константа для размера массива
    int arr[SIZE];       // Объявляем массив
    
    // 1. Заполняем и выводим массив
    std::cout << "1. Заполнение массива:" << std::endl;
    fillArray(arr, SIZE, 0);  // Заполняем нулями
    printArray(arr, SIZE);    // Выводим
    
    // 2. Меняем значения и снова выводим
    std::cout << std::endl;
    std::cout << "2. Изменение значений:" << std::endl;
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (i + 1) * 10;  // Заполняем значениями 10, 20, 30, ...
    }
    
    printArray(arr, SIZE);
    
    // 3. Находим максимальный элемент
    std::cout << std::endl;
    std::cout << "3. Поиск максимального элемента:" << std::endl;
    
    int max = findMax(arr, SIZE);
    std::cout << "   Максимальный элемент: " << max << std::endl;
    
    // 4. Вычисляем сумму элементов
    std::cout << std::endl;
    std::cout << "4. Сумма элементов:" << std::endl;
    
    int sum = sumArray(arr, SIZE);
    std::cout << "   Сумма всех элементов: " << sum << std::endl;
    
    // 5. Обратный порядок
    std::cout << std::endl;
    std::cout << "5. Обратный порядок:" << std::endl;
    
    std::cout << "   До reverse: ";
    printArray(arr, SIZE);
    
    reverseArray(arr, SIZE);
    
    std::cout << "   После reverse: ";
    printArray(arr, SIZE);
    
    // 6. Среднее арифметическое (используем ранее созданные функции)
    std::cout << std::endl;
    std::cout << "6. Среднее арифметическое:" << std::endl;
    
    double average = static_cast<double>(sum) / SIZE;  // Преобразуем sum в double для точности
    std::cout << "   Среднее значение: " << average << std::endl;
    
    return 0;
}