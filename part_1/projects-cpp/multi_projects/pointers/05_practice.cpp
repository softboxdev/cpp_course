#include <iostream>

// Функция для поиска всех вхождений значения
// Возвращает количество найденных элементов
int findAll(const int* arr, int size, int value, int* positions) {
    int count = 0;  // Счётчик найденных элементов
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {        // Если нашли нужное значение
            if (positions != nullptr) { // Если передан массив для позиций
                positions[count] = i;  // Сохраняем позицию
            }
            count++;                   // Увеличиваем счётчик
        }
    }
    
    return count;  // Возвращаем количество найденных
}

// Функция для замены всех вхождений одного значения на другое
// Возвращает количество заменённых элементов
int replaceAll(int* arr, int size, int oldValue, int newValue) {
    int replaced = 0;  // Счётчик замен
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == oldValue) {  // Если нашли старое значение
            arr[i] = newValue;     // Заменяем на новое
            replaced++;            // Увеличиваем счётчик
        }
    }
    
    return replaced;  // Возвращаем количество замен
}

// Функция для вывода массива с подсветкой позиций
void printArrayWithHighlights(const int* arr, int size, 
                              const int* positions, int posCount) {
    std::cout << "Массив: ";
    
    for (int i = 0; i < size; i++) {
        bool isHighlighted = false;
        
        // Проверяем, нужно ли подсветить этот элемент
        for (int j = 0; j < posCount; j++) {
            if (positions[j] == i) {
                isHighlighted = true;
                break;
            }
        }
        
        if (isHighlighted) {
            std::cout << "[" << arr[i] << "] ";  // Подсветка
        } else {
            std::cout << arr[i] << " ";          // Обычный вывод
        }
    }
    
    std::cout << std::endl;
}

int main() {
    std::cout << "=== ПОИСК И ЗАМЕНА В МАССИВЕ ===" << std::endl;
    std::cout << std::endl;
    
    // Создаём тестовый массив
    const int SIZE = 10;
    int array[SIZE] = {2, 5, 2, 8, 2, 9, 5, 2, 1, 2};
    
    // Выводим исходный массив
    std::cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // 1. Поиск всех вхождений числа 2
    std::cout << "1. Поиск всех вхождений числа 2:" << std::endl;
    
    int positions[SIZE];  // Массив для хранения позиций
    int count = findAll(array, SIZE, 2, positions);
    
    std::cout << "   Найдено " << count << " вхождений" << std::endl;
    
    if (count > 0) {
        std::cout << "   Позиции: ";
        for (int i = 0; i < count; i++) {
            std::cout << positions[i] << " ";
        }
        std::cout << std::endl;
        
        // Выводим массив с подсветкой найденных элементов
        printArrayWithHighlights(array, SIZE, positions, count);
    }
    
    std::cout << std::endl;
    
    // 2. Замена всех двоек на семёрки
    std::cout << "2. Замена всех 2 на 7:" << std::endl;
    
    int replaced = replaceAll(array, SIZE, 2, 7);
    
    std::cout << "   Заменено " << replaced << " элементов" << std::endl;
    std::cout << "   Массив после замены: ";
    
    for (int i = 0; i < SIZE; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // 3. Поиск всех пятёрок (после замены)
    std::cout << "3. Поиск всех вхождений числа 5:" << std::endl;
    
    count = findAll(array, SIZE, 5, positions);
    
    std::cout << "   Найдено " << count << " вхождений" << std::endl;
    
    if (count > 0) {
        printArrayWithHighlights(array, SIZE, positions, count);
    }
    
    return 0;
}