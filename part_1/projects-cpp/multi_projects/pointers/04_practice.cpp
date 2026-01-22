#include <iostream>

// ФУНКЦИЯ 1: Поиск элемента в массиве
// Возвращает указатель на найденный элемент или nullptr
int* findElement(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {       // Если нашли нужное значение
            return &arr[i];          // Возвращаем указатель на этот элемент
            // Можно также вернуть: return arr + i;
        }
    }
    
    return nullptr;  // Если не нашли, возвращаем nullptr
}

// ФУНКЦИЯ 2: Создание и заполнение массива
// Возвращает указатель на динамически созданный массив
int* createArray(int size, int initialValue) {
    int* newArray = new int[size];  // Выделяем память в куче
    
    for (int i = 0; i < size; i++) {
        newArray[i] = initialValue;  // Заполняем массив
    }
    
    return newArray;  // Возвращаем указатель на созданный массив
}

// ФУНКЦИЯ 3: Копирование массива
// Возвращает указатель на копию массива
int* copyArray(const int* source, int size) {
    int* copy = new int[size];  // Выделяем память для копии
    
    for (int i = 0; i < size; i++) {
        copy[i] = source[i];     // Копируем каждый элемент
    }
    
    return copy;  // Возвращаем указатель на копию
}

int main() {
    std::cout << "=== ФУНКЦИИ С ВОЗВРАТОМ УКАЗАТЕЛЕЙ ===" << std::endl;
    std::cout << std::endl;
    
    int staticArray[5] = {10, 20, 30, 40, 50};
    
    // 1. Поиск элемента
    std::cout << "1. Поиск элемента в массиве:" << std::endl;
    
    int* found = findElement(staticArray, 5, 30);
    
    if (found != nullptr) {
        std::cout << "   Найден элемент: " << *found << std::endl;
        std::cout << "   По адресу: " << found << std::endl;
        
        // Можем изменить найденный элемент
        *found = 300;
        std::cout << "   После изменения: staticArray[2] = " << staticArray[2] << std::endl;
    } else {
        std::cout << "   Элемент не найден" << std::endl;
    }
    
    // 2. Создание динамического массива
    std::cout << std::endl;
    std::cout << "2. Создание динамического массива:" << std::endl;
    
    int* dynamicArray = createArray(5, 7);  // Создаём массив из 5 элементов со значением 7
    
    std::cout << "   Динамический массив: ";
    for (int i = 0; i < 5; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;
    
    // 3. Копирование массива
    std::cout << std::endl;
    std::cout << "3. Копирование массива:" << std::endl;
    
    int* copiedArray = copyArray(staticArray, 5);
    
    std::cout << "   Оригинал: ";
    for (int i = 0; i < 5; i++) {
        std::cout << staticArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "   Копия: ";
    for (int i = 0; i < 5; i++) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Изменяем копию (оригинал не должен измениться)
    copiedArray[0] = 999;
    
    std::cout << "   После изменения копии:" << std::endl;
    std::cout << "   Оригинал[0] = " << staticArray[0] << std::endl;
    std::cout << "   Копия[0] = " << copiedArray[0] << std::endl;
    
    // ВАЖНО: освобождаем динамически выделенную память
    delete[] dynamicArray;  // Освобождаем первый массив
    delete[] copiedArray;   // Освобождаем второй массив
    
    // Обнуляем указатели (хорошая практика)
    dynamicArray = nullptr;
    copiedArray = nullptr;
    
    std::cout << std::endl;
    std::cout << "Память освобождена, указатели обнулены" << std::endl;
    
    return 0;
}