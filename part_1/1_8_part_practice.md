# Практическая работа по указателям и функциям для работы с массивами


**Цель:** Освоить основы работы с указателями и создание функций для обработки массивов в C++

## Часть 1: Основы указателей (15 минут)

### Задание 1.1: Базовые операции с указателями

```cpp
#include <iostream>  // Подключаем библиотеку для ввода/вывода

int main() {  // Главная функция программы
    // Объявляем и инициализируем переменные
    int number = 42;           // Создаём целочисленную переменную со значением 42
    double price = 99.99;      // Создаём переменную с плавающей точкой
    
    // Работа с указателями
    int* pointerToNumber = &number;    // Создаём указатель на int и присваиваем адрес number
    double* pointerToPrice = &price;   // Создаём указатель на double и присваиваем адрес price
    
    // Выводим значения и адреса
    std::cout << "=== БАЗОВЫЕ ОПЕРАЦИИ С УКАЗАТЕЛЯМИ ===" << std::endl;
    std::cout << std::endl;
    
    // 1. Выводим значения переменных
    std::cout << "1. Значения переменных:" << std::endl;
    std::cout << "   number = " << number << std::endl;      // Прямой доступ к значению
    std::cout << "   price = " << price << std::endl;        // Прямой доступ к значению
    std::cout << std::endl;
    
    // 2. Выводим адреса переменных
    std::cout << "2. Адреса переменных в памяти:" << std::endl;
    std::cout << "   &number = " << &number << std::endl;    // Адрес переменной number
    std::cout << "   &price = " << &price << std::endl;      // Адрес переменной price
    std::cout << std::endl;
    
    // 3. Выводим значения указателей
    std::cout << "3. Значения указателей:" << std::endl;
    std::cout << "   pointerToNumber = " << pointerToNumber << std::endl;   // Должен совпадать с &number
    std::cout << "   pointerToPrice = " << pointerToPrice << std::endl;     // Должен совпадать с &price
    std::cout << std::endl;
    
    // 4. Разыменование указателей
    std::cout << "4. Разыменование указателей:" << std::endl;
    std::cout << "   *pointerToNumber = " << *pointerToNumber << std::endl;  // Значение по адресу
    std::cout << "   *pointerToPrice = " << *pointerToPrice << std::endl;    // Значение по адресу
    std::cout << std::endl;
    
    // 5. Изменение значения через указатель
    std::cout << "5. Изменение значения через указатель:" << std::endl;
    *pointerToNumber = 100;           // Меняем значение number через указатель
    std::cout << "   После *pointerToNumber = 100:" << std::endl;
    std::cout << "   number = " << number << std::endl;      // Проверяем, что number изменился
    std::cout << "   *pointerToNumber = " << *pointerToNumber << std::endl;  // Проверяем через указатель
    std::cout << std::endl;
    
    // 6. Работа с нулевым указателем
    std::cout << "6. Работа с нулевым указателем:" << std::endl;
    int* nullPointer = nullptr;       // Создаём нулевой указатель (современный C++)
    // int* nullPointer = NULL;       // Старый стиль (лучше не использовать)
    // int* nullPointer = 0;          // Ещё один старый стиль
    
    if (nullPointer == nullptr) {     // Проверяем, является ли указатель нулевым
        std::cout << "   nullPointer равен nullptr" << std::endl;
    }
    
    // НИКОГДА не разыменовывайте нулевой указатель!
    // *nullPointer = 10;  // ОШИБКА: программа упадёт!
    
    return 0;  // Завершаем программу успешно
}
```

### Задание 1.2: Указатели и массивы

```cpp
#include <iostream>

int main() {
    std::cout << "=== УКАЗАТЕЛИ И МАССИВЫ ===" << std::endl;
    std::cout << std::endl;
    
    // Создаём массив из 5 элементов
    int numbers[5] = {10, 20, 30, 40, 50};  // Статический массив в стеке
    
    // 1. Имя массива - это указатель на первый элемент
    std::cout << "1. Имя массива как указатель:" << std::endl;
    std::cout << "   numbers = " << numbers << std::endl;        // Адрес первого элемента
    std::cout << "   &numbers[0] = " << &numbers[0] << std::endl; // Тот же адрес
    std::cout << "   *numbers = " << *numbers << std::endl;      // Первый элемент (10)
    std::cout << std::endl;
    
    // 2. Создаём указатель на массив
    int* ptr = numbers;  // ptr указывает на numbers[0]
    
    std::cout << "2. Работа через указатель:" << std::endl;
    std::cout << "   ptr = " << ptr << std::endl;
    std::cout << "   *ptr = " << *ptr << std::endl;      // numbers[0]
    std::cout << std::endl;
    
    // 3. Арифметика указателей
    std::cout << "3. Арифметика указателей:" << std::endl;
    std::cout << "   ptr + 1 = " << ptr + 1 << std::endl;    // Адрес numbers[1]
    std::cout << "   *(ptr + 1) = " << *(ptr + 1) << std::endl;  // numbers[1] = 20
    std::cout << std::endl;
    
    // 4. Итерация по массиву через указатель
    std::cout << "4. Итерация по массиву через указатель:" << std::endl;
    std::cout << "   Элементы массива: ";
    
    // Первый способ: через указатель
    int* current = numbers;  // Начинаем с первого элемента
    for (int i = 0; i < 5; i++) {
        std::cout << *current << " ";  // Выводим значение
        current++;                      // Переходим к следующему элементу
    }
    std::cout << std::endl;
    
    // Второй способ: через индексы
    std::cout << "   Через индексы: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *(numbers + i) << " ";  // numbers[i] эквивалентно *(numbers + i)
    }
    std::cout << std::endl;
    
    // 5. Изменение элементов через указатель
    std::cout << std::endl;
    std::cout << "5. Изменение элементов через указатель:" << std::endl;
    
    ptr = numbers;          // Возвращаем указатель на начало
    *(ptr + 2) = 300;       // Меняем третий элемент (индекс 2)
    
    std::cout << "   После *(ptr + 2) = 300:" << std::endl;
    std::cout << "   numbers[2] = " << numbers[2] << std::endl;  // Должно быть 300
    
    return 0;
}
```

## Часть 2: Функции для работы с массивами (15 минут)

### Задание 2.1: Базовые функции обработки массивов

```cpp
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
```

### Задание 2.2: Функции с возвратом указателей

```cpp
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
```

## Часть 3: Практические задачи (15 минут)

### Задача 3.1: Калькулятор статистики массива

```cpp
#include <iostream>

// Структура для хранения статистики
struct ArrayStats {
    int min;
    int max;
    int sum;
    double average;
};

// Функция для вычисления статистики массива
ArrayStats calculateStats(const int* arr, int size) {
    ArrayStats stats;  // Создаём объект структуры
    
    if (size <= 0) {  // Проверка на пустой массив
        // Устанавливаем значения по умолчанию
        stats.min = 0;
        stats.max = 0;
        stats.sum = 0;
        stats.average = 0.0;
        return stats;
    }
    
    // Инициализируем значения первым элементом
    stats.min = arr[0];
    stats.max = arr[0];
    stats.sum = 0;
    
    // Проходим по всем элементам массива
    for (int i = 0; i < size; i++) {
        // Обновляем минимум
        if (arr[i] < stats.min) {
            stats.min = arr[i];
        }
        
        // Обновляем максимум
        if (arr[i] > stats.max) {
            stats.max = arr[i];
        }
        
        // Суммируем
        stats.sum += arr[i];
    }
    
    // Вычисляем среднее
    stats.average = static_cast<double>(stats.sum) / size;
    
    return stats;  // Возвращаем структуру
}

// Функция для вывода статистики
void printStats(const ArrayStats& stats) {
    std::cout << "=== СТАТИСТИКА МАССИВА ===" << std::endl;
    std::cout << "Минимальное значение: " << stats.min << std::endl;
    std::cout << "Максимальное значение: " << stats.max << std::endl;
    std::cout << "Сумма элементов: " << stats.sum << std::endl;
    std::cout << "Среднее значение: " << stats.average << std::endl;
}

int main() {
    std::cout << "=== КАЛЬКУЛЯТОР СТАТИСТИКИ МАССИВА ===" << std::endl;
    std::cout << std::endl;
    
    // Создаём тестовый массив
    const int SIZE = 8;
    int testArray[SIZE] = {23, 45, 12, 67, 89, 34, 56, 78};
    
    // Выводим исходный массив
    std::cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << testArray[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Вычисляем статистику
    ArrayStats stats = calculateStats(testArray, SIZE);
    
    // Выводим результаты
    printStats(stats);
    
    std::cout << std::endl;
    
    // Дополнительная задача: найти медиану
    // Для этого нужно отсортировать массив
    
    return 0;
}
```

### Задача 3.2: Поиск и замена в массиве

```cpp
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
```

### Задача 3.3: Объединение двух массивов

```cpp
#include <iostream>

// Функция для объединения двух массивов
// Возвращает указатель на новый массив
int* mergeArrays(const int* arr1, int size1, const int* arr2, int size2) {
    // Вычисляем общий размер
    int totalSize = size1 + size2;
    
    // Выделяем память для нового массива
    int* merged = new int[totalSize];
    
    // Копируем элементы из первого массива
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    
    // Копируем элементы из второго массива
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
    
    return merged;  // Возвращаем указатель на новый массив
}

// Функция для сортировки массива (простой алгоритм)
void sortArray(int* arr, int size) {
    // Используем простой алгоритм сортировки пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Меняем местами
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    std::cout << "=== ОБЪЕДИНЕНИЕ ДВУХ МАССИВОВ ===" << std::endl;
    std::cout << std::endl;
    
    // Создаём два массива
    int array1[] = {3, 7, 1, 9};
    int array2[] = {4, 2, 8, 6, 5};
    
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    
    // Выводим исходные массивы
    std::cout << "Первый массив: ";
    for (int i = 0; i < size1; i++) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Второй массив: ";
    for (int i = 0; i < size2; i++) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Объединяем массивы
    int* merged = mergeArrays(array1, size1, array2, size2);
    int totalSize = size1 + size2;
    
    std::cout << "Объединённый массив: ";
    for (int i = 0; i < totalSize; i++) {
        std::cout << merged[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // Сортируем объединённый массив
    sortArray(merged, totalSize);
    
    std::cout << "Отсортированный объединённый массив: ";
    for (int i = 0; i < totalSize; i++) {
        std::cout << merged[i] << " ";
    }
    std::cout << std::endl;
    
    // Освобождаем память
    delete[] merged;
    merged = nullptr;
    
    std::cout << std::endl;
    std::cout << "Память освобождена" << std::endl;
    
    return 0;
}
```

## Заключение и домашнее задание

### Что мы изучили за 45 минут:

1. **Основы указателей**: создание, инициализация, разыменование
2. **Связь указателей и массивов**: имя массива как указатель
3. **Функции для работы с массивами**: передача массивов в функции
4. **Динамическое выделение памяти**: операторы `new` и `delete`
5. **Практические задачи**: статистика, поиск, замена, объединение

### Домашнее задание:

1. **Задача 1**: Напишите функцию, которая находит второй по величине элемент в массиве
2. **Задача 2**: Создайте функцию, которая удаляет все повторяющиеся элементы из массива
3. **Задача 3**: Напишите программу, которая считывает массив с клавиатуры и сортирует его
4. **Задача 4**: Создайте функцию, которая проверяет, является ли массив палиндромом
5. **Задача 5**: Реализуйте простую базу данных студентов с использованием структур и массивов

### Советы для дальнейшего изучения:

1. Изучите `std::vector` для работы с динамическими массивами
2. Познакомьтесь с умными указателями (`std::unique_ptr`, `std::shared_ptr`)
3. Изучите алгоритмы сортировки (быстрая сортировка, сортировка слиянием)
4. Практикуйтесь на сайтах типа LeetCode или CodeWars

**Важно**: Всегда проверяйте указатели на `nullptr` перед использованием и не забывайте освобождать динамически выделенную память!