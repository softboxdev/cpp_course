# Одномерные и многомерные массивы в C++: полная теория с примерами

## Введение

Массивы — это структуры данных, которые хранят набор элементов одного типа в последовательных ячейках памяти. В C++ есть два типа массивов: статические (фиксированного размера) и динамические.

## Глава 1: Одномерные массивы

### 1.1. Объявление и инициализация одномерных массивов

```cpp
#include <iostream>  // Подключаем библиотеку для ввода/вывода

int main() {  // Главная функция программы
    
    std::cout << "=== ОБЪЯВЛЕНИЕ И ИНИЦИАЛИЗАЦИЯ ОДНОМЕРНЫХ МАССИВОВ ===" << std::endl;
    std::cout << std::endl;
    
    // СПОСОБ 1: Объявление без инициализации
    // Создаём массив из 5 целых чисел (не инициализирован)
    int array1[5];  // int - тип элементов, array1 - имя массива, [5] - размер
    
    std::cout << "1. Объявление без инициализации:" << std::endl;
    std::cout << "   int array1[5];" << std::endl;
    std::cout << "   Элементы содержат 'мусор' (случайные значения)" << std::endl;
    std::cout << std::endl;
    
    // СПОСОБ 2: Объявление с полной инициализацией
    // Создаём массив и сразу заполняем его значениями
    int array2[5] = {10, 20, 30, 40, 50};  
    // = - оператор присваивания
    // {} - список инициализации
    // 10,20,30,40,50 - начальные значения
    
    std::cout << "2. Объявление с полной инициализацией:" << std::endl;
    std::cout << "   int array2[5] = {10, 20, 30, 40, 50};" << std::endl;
    std::cout << "   Все 5 элементов инициализированы" << std::endl;
    std::cout << std::endl;
    
    // СПОСОБ 3: Объявление с частичной инициализацией
    // Создаём массив из 5 элементов, но инициализируем только первые 3
    int array3[5] = {1, 2, 3};  
    // Первые три элемента: 1, 2, 3
    // Остальные два элемента: автоматически 0
    
    std::cout << "3. Объявление с частичной инициализацией:" << std::endl;
    std::cout << "   int array3[5] = {1, 2, 3};" << std::endl;
    std::cout << "   Первые 3 элемента: 1, 2, 3" << std::endl;
    std::cout << "   Остальные: 0 (автоматически)" << std::endl;
    std::cout << std::endl;
    
    // СПОСОБ 4: Автоматическое определение размера
    // Компилятор сам посчитает размер по количеству элементов
    int array4[] = {100, 200, 300, 400, 500, 600};  
    // [] - пустые скобки (размер не указан)
    // Компилятор определит размер = 6
    
    std::cout << "4. Автоматическое определение размера:" << std::endl;
    std::cout << "   int array4[] = {100, 200, 300, 400, 500, 600};" << std::endl;
    std::cout << "   Размер определён компилятором как 6" << std::endl;
    std::cout << std::endl;
    
    // СПОСОБ 5: Инициализация нулями
    // Создаём массив и заполняем все элементы нулями
    int array5[10] = {0};  // Первый элемент = 0, остальные тоже = 0
    
    std::cout << "5. Инициализация нулями:" << std::endl;
    std::cout << "   int array5[10] = {0};" << std::endl;
    std::cout << "   Все 10 элементов = 0" << std::endl;
    std::cout << std::endl;
    
    // СПОСОБ 6: Объявление с использованием константы
    const int SIZE = 8;  // const - константа (неизменяемое значение)
    int array6[SIZE];    // Используем константу для размера
    
    std::cout << "6. Объявление с использованием константы:" << std::endl;
    std::cout << "   const int SIZE = 8;" << std::endl;
    std::cout << "   int array6[SIZE];" << std::endl;
    std::cout << "   Размер массива = 8 (из константы SIZE)" << std::endl;
    std::cout << std::endl;
    
    // СПОСОБ 7: Инициализация с использованием цикла
    int array7[5];  // Объявляем массив
    
    // Заполняем массив с помощью цикла for
    for (int i = 0; i < 5; i++) {  // i - индекс, от 0 до 4
        array7[i] = (i + 1) * 100;  // Заполняем элементы: 100, 200, 300, 400, 500
    }
    
    std::cout << "7. Инициализация с использованием цикла:" << std::endl;
    std::cout << "   Заполнены значениями: 100, 200, 300, 400, 500" << std::endl;
    
    return 0;  // Завершение программы
}
```

### 1.2. Доступ к элементам одномерных массивов

```cpp
#include <iostream>

int main() {
    std::cout << "=== ДОСТУП К ЭЛЕМЕНТАМ ОДНОМЕРНЫХ МАССИВОВ ===" << std::endl;
    std::cout << std::endl;
    
    // Создаём и инициализируем массив
    int numbers[5] = {10, 20, 30, 40, 50};  // Массив из 5 элементов
    
    std::cout << "Массив numbers[5] = {10, 20, 30, 40, 50}" << std::endl;
    std::cout << std::endl;
    
    // 1. Прямой доступ по индексу (самый распространённый способ)
    std::cout << "1. Прямой доступ по индексу:" << std::endl;
    
    std::cout << "   numbers[0] = " << numbers[0] << std::endl;  // Первый элемент (индекс 0)
    std::cout << "   numbers[1] = " << numbers[1] << std::endl;  // Второй элемент (индекс 1)
    std::cout << "   numbers[2] = " << numbers[2] << std::endl;  // Третий элемент (индекс 2)
    std::cout << "   numbers[3] = " << numbers[3] << std::endl;  // Четвёртый элемент (индекс 3)
    std::cout << "   numbers[4] = " << numbers[4] << std::endl;  // Пятый элемент (индекс 4)
    
    // Важно: индексация начинается с 0!
    // numbers[5] - ОШИБКА: выход за границы массива!
    
    std::cout << std::endl;
    
    // 2. Изменение элементов массива
    std::cout << "2. Изменение элементов массива:" << std::endl;
    
    std::cout << "   До изменения: numbers[2] = " << numbers[2] << std::endl;
    
    numbers[2] = 300;  // Присваиваем новое значение третьему элементу
    
    std::cout << "   После numbers[2] = 300:" << std::endl;
    std::cout << "   numbers[2] = " << numbers[2] << std::endl;
    
    std::cout << std::endl;
    
    // 3. Использование переменных в качестве индексов
    std::cout << "3. Использование переменных в качестве индексов:" << std::endl;
    
    int index = 1;  // Создаём переменную-индекс
    
    std::cout << "   index = " << index << std::endl;
    std::cout << "   numbers[index] = " << numbers[index] << std::endl;  // numbers[1] = 20
    
    index = 3;  // Меняем значение переменной
    std::cout << "   После index = 3:" << std::endl;
    std::cout << "   numbers[index] = " << numbers[index] << std::endl;  // numbers[3] = 40
    
    std::cout << std::endl;
    
    // 4. Доступ через арифметику указателей
    std::cout << "4. Доступ через арифметику указателей:" << std::endl;
    
    // Имя массива - это указатель на первый элемент
    int* ptr = numbers;  // ptr указывает на numbers[0]
    
    std::cout << "   *ptr = " << *ptr << std::endl;            // numbers[0]
    std::cout << "   *(ptr + 1) = " << *(ptr + 1) << std::endl;  // numbers[1]
    std::cout << "   *(ptr + 2) = " << *(ptr + 2) << std::endl;  // numbers[2]
    
    // numbers[i] эквивалентно *(numbers + i)
    
    std::cout << std::endl;
    
    // 5. Использование выражения в качестве индекса
    std::cout << "5. Использование выражения в качестве индекса:" << std::endl;
    
    int i = 2, j = 1;
    std::cout << "   i = 2, j = 1" << std::endl;
    std::cout << "   numbers[i + j] = " << numbers[i + j] << std::endl;    // numbers[3] = 40
    std::cout << "   numbers[i * j] = " << numbers[i * j] << std::endl;    // numbers[2] = 300
    
    std::cout << std::endl;
    
    // 6. Необычная нотация (редко используется)
    std::cout << "6. Необычная нотация доступа:" << std::endl;
    
    std::cout << "   2[numbers] = " << 2[numbers] << std::endl;  // Эквивалентно numbers[2]
    // Это работает потому, что numbers[2] преобразуется в *(numbers + 2)
    // А 2[numbers] преобразуется в *(2 + numbers), что то же самое
    
    std::cout << std::endl;
    
    // 7. Итерация по массиву (перебор всех элементов)
    std::cout << "7. Итерация по массиву:" << std::endl;
    
    std::cout << "   Все элементы массива: ";
    
    // Способ 1: for-цикл с индексом
    for (int i = 0; i < 5; i++) {  // i от 0 до 4
        std::cout << numbers[i] << " ";  // Выводим каждый элемент
    }
    std::cout << std::endl;
    
    // Способ 2: range-based for (C++11)
    std::cout << "   Range-based for: ";
    for (int num : numbers) {  // num принимает значение каждого элемента
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Способ 3: while-цикл
    std::cout << "   While-цикл: ";
    int counter = 0;
    while (counter < 5) {
        std::cout << numbers[counter] << " ";
        counter++;  // counter = counter + 1
    }
    std::cout << std::endl;
    
    return 0;
}
```

### 1.3. Операции с одномерными массивами

```cpp
#include <iostream>

int main() {
    std::cout << "=== ОПЕРАЦИИ С ОДНОМЕРНЫМИ МАССИВАМИ ===" << std::endl;
    std::cout << std::endl;
    
    // Создаём два массива
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {10, 20, 30, 40, 50};
    
    std::cout << "Исходные массивы:" << std::endl;
    std::cout << "arr1: 1 2 3 4 5" << std::endl;
    std::cout << "arr2: 10 20 30 40 50" << std::endl;
    std::cout << std::endl;
    
    // 1. Копирование элементов из одного массива в другой
    std::cout << "1. Копирование массива:" << std::endl;
    
    int copy[5];  // Создаём массив для копии
    
    for (int i = 0; i < 5; i++) {
        copy[i] = arr1[i];  // Копируем каждый элемент
    }
    
    std::cout << "   copy после копирования arr1: ";
    for (int i = 0; i < 5; i++) {
        std::cout << copy[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // 2. Сумма двух массивов (поэлементное сложение)
    std::cout << "2. Сумма двух массивов:" << std::endl;
    
    int sum[5];  // Массив для хранения суммы
    
    for (int i = 0; i < 5; i++) {
        sum[i] = arr1[i] + arr2[i];  // Складываем соответствующие элементы
    }
    
    std::cout << "   sum = arr1 + arr2: ";
    for (int i = 0; i < 5; i++) {
        std::cout << sum[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // 3. Поиск минимального и максимального элемента
    std::cout << "3. Поиск минимального и максимального элемента:" << std::endl;
    
    int min = arr1[0];  // Предполагаем, что первый элемент - минимальный
    int max = arr1[0];  // Предполагаем, что первый элемент - максимальный
    
    for (int i = 1; i < 5; i++) {  // Начинаем со второго элемента
        if (arr1[i] < min) {       // Если текущий элемент меньше min
            min = arr1[i];         // Обновляем min
        }
        
        if (arr1[i] > max) {       // Если текущий элемент больше max
            max = arr1[i];         // Обновляем max
        }
    }
    
    std::cout << "   В массиве arr1:" << std::endl;
    std::cout << "   Минимальный элемент: " << min << std::endl;
    std::cout << "   Максимальный элемент: " << max << std::endl;
    std::cout << std::endl;
    
    // 4. Вычисление суммы всех элементов
    std::cout << "4. Вычисление суммы всех элементов:" << std::endl;
    
    int total = 0;  // Переменная для хранения суммы
    
    for (int i = 0; i < 5; i++) {
        total += arr1[i];  // total = total + arr1[i]
    }
    
    std::cout << "   Сумма всех элементов arr1: " << total << std::endl;
    std::cout << std::endl;
    
    // 5. Вычисление среднего значения
    std::cout << "5. Вычисление среднего значения:" << std::endl;
    
    // Используем ранее вычисленную сумму
    double average = static_cast<double>(total) / 5;  // Преобразуем в double для точности
    
    std::cout << "   Среднее значение arr1: " << average << std::endl;
    std::cout << std::endl;
    
    // 6. Поиск элемента в массиве
    std::cout << "6. Поиск элемента в массиве:" << std::endl;
    
    int searchValue = 3;  // Значение, которое ищем
    bool found = false;   // Флаг "найдено/не найдено"
    int position = -1;    // Позиция найденного элемента (-1 если не найден)
    
    for (int i = 0; i < 5; i++) {
        if (arr1[i] == searchValue) {  // Если нашли нужное значение
            found = true;               // Устанавливаем флаг
            position = i;               // Запоминаем позицию
            break;                      // Выходим из цикла
        }
    }
    
    if (found) {
        std::cout << "   Элемент " << searchValue << " найден" << std::endl;
        std::cout << "   Позиция: " << position << std::endl;
    } else {
        std::cout << "   Элемент " << searchValue << " не найден" << std::endl;
    }
    std::cout << std::endl;
    
    // 7. Сортировка массива (простой алгоритм пузырька)
    std::cout << "7. Сортировка массива (пузырьковая):" << std::endl;
    
    int unsorted[5] = {5, 3, 4, 1, 2};  // Неотсортированный массив
    
    std::cout << "   До сортировки: ";
    for (int i = 0; i < 5; i++) {
        std::cout << unsorted[i] << " ";
    }
    std::cout << std::endl;
    
    // Алгоритм пузырьковой сортировки
    for (int i = 0; i < 5 - 1; i++) {          // Внешний цикл
        for (int j = 0; j < 5 - i - 1; j++) {  // Внутренний цикл
            if (unsorted[j] > unsorted[j + 1]) {  // Если текущий больше следующего
                // Меняем местами
                int temp = unsorted[j];
                unsorted[j] = unsorted[j + 1];
                unsorted[j + 1] = temp;
            }
        }
    }
    
    std::cout << "   После сортировки: ";
    for (int i = 0; i < 5; i++) {
        std::cout << unsorted[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

## Глава 2: Многомерные массивы

### 2.1. Двумерные массивы (матрицы)

```cpp
#include <iostream>

int main() {
    std::cout << "=== ДВУМЕРНЫЕ МАССИВЫ (МАТРИЦЫ) ===" << std::endl;
    std::cout << std::endl;
    
    // 1. Объявление двумерного массива (матрица 3x4)
    // 3 строки, 4 столбца
    int matrix[3][4];  // Первый индекс - строка, второй - столбец
    
    std::cout << "1. Объявление матрицы 3x4:" << std::endl;
    std::cout << "   int matrix[3][4];" << std::endl;
    std::cout << "   3 строки, 4 столбца" << std::endl;
    std::cout << "   Всего элементов: 3 * 4 = 12" << std::endl;
    std::cout << std::endl;
    
    // 2. Инициализация двумерного массива
    std::cout << "2. Инициализация двумерного массива:" << std::endl;
    std::cout << std::endl;
    
    // Способ 1: Полная инициализация при объявлении
    int matrix1[2][3] = {
        {1, 2, 3},   // Первая строка: 1, 2, 3
        {4, 5, 6}    // Вторая строка: 4, 5, 6
    };
    // Внешние {} - для всего массива
    // Внутренние {} - для каждой строки
    
    std::cout << "   Способ 1 - полная инициализация:" << std::endl;
    std::cout << "   int matrix1[2][3] = {" << std::endl;
    std::cout << "       {1, 2, 3}," << std::endl;
    std::cout << "       {4, 5, 6}" << std::endl;
    std::cout << "   };" << std::endl;
    std::cout << std::endl;
    
    // Способ 2: Частичная инициализация
    int matrix2[3][3] = {
        {1},        // Первая строка: 1, 0, 0
        {4, 5},     // Вторая строка: 4, 5, 0
        {7, 8, 9}   // Третья строка: 7, 8, 9
    };
    // Неинициализированные элементы = 0
    
    std::cout << "   Способ 2 - частичная инициализация:" << std::endl;
    std::cout << "   Неинициализированные элементы = 0" << std::endl;
    std::cout << std::endl;
    
    // Способ 3: Инициализация в одну строку
    int matrix3[2][3] = {1, 2, 3, 4, 5, 6};
    // Элементы заполняются построчно: 
    // matrix3[0][0]=1, [0][1]=2, [0][2]=3, [1][0]=4, [1][1]=5, [1][2]=6
    
    std::cout << "   Способ 3 - инициализация в одну строку:" << std::endl;
    std::cout << "   int matrix3[2][3] = {1, 2, 3, 4, 5, 6};" << std::endl;
    std::cout << std::endl;
    
    // Способ 4: Автоматическое определение размера
    int matrix4[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    // Можно опустить только первый размер (количество строк)
    // Второй размер (количество столбцов) обязателен!
    
    std::cout << "   Способ 4 - автоматическое определение строк:" << std::endl;
    std::cout << "   int matrix4[][3] = { ... };" << std::endl;
    std::cout << "   Количество строк определено как 3" << std::endl;
    std::cout << std::endl;
    
    // 3. Доступ к элементам двумерного массива
    std::cout << "3. Доступ к элементам двумерного массива:" << std::endl;
    
    // Создаём и инициализируем матрицу 2x3
    int mat[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };
    
    std::cout << "   Матрица mat[2][3]:" << std::endl;
    std::cout << "   Первый индекс - строка (0-1)" << std::endl;
    std::cout << "   Второй индекс - столбец (0-2)" << std::endl;
    std::cout << std::endl;
    
    // Прямой доступ к элементам
    std::cout << "   mat[0][0] = " << mat[0][0] << std::endl;  // Первая строка, первый столбец
    std::cout << "   mat[0][1] = " << mat[0][1] << std::endl;  // Первая строка, второй столбец
    std::cout << "   mat[0][2] = " << mat[0][2] << std::endl;  // Первая строка, третий столбец
    std::cout << "   mat[1][0] = " << mat[1][0] << std::endl;  // Вторая строка, первый столбец
    std::cout << "   mat[1][1] = " << mat[1][1] << std::endl;  // Вторая строка, второй столбец
    std::cout << "   mat[1][2] = " << mat[1][2] << std::endl;  // Вторая строка, третий столбец
    
    std::cout << std::endl;
    
    // 4. Изменение элементов
    std::cout << "4. Изменение элементов матрицы:" << std::endl;
    
    std::cout << "   До изменения: mat[1][1] = " << mat[1][1] << std::endl;
    
    mat[1][1] = 99;  // Изменяем элемент во второй строке, втором столбце
    
    std::cout << "   После mat[1][1] = 99:" << std::endl;
    std::cout << "   mat[1][1] = " << mat[1][1] << std::endl;
    
    std::cout << std::endl;
    
    // 5. Обход (итерация) по двумерному массиву
    std::cout << "5. Обход по двумерному массиву:" << std::endl;
    std::cout << "   Матрица построчно:" << std::endl;
    
    // Внешний цикл - по строкам
    for (int row = 0; row < 2; row++) {        // row - номер строки (от 0 до 1)
        std::cout << "   Строка " << row << ": ";
        
        // Внутренний цикл - по столбцам
        for (int col = 0; col < 3; col++) {    // col - номер столбца (от 0 до 2)
            std::cout << mat[row][col] << "\t";  // Выводим элемент
        }
        
        std::cout << std::endl;  // Переход на новую строку после каждой строки матрицы
    }
    
    std::cout << std::endl;
    
    // 6. Обход по столбцам (в обратном порядке)
    std::cout << "6. Обход по столбцам:" << std::endl;
    std::cout << "   Матрица по столбцам:" << std::endl;
    
    // Внешний цикл - по столбцам
    for (int col = 0; col < 3; col++) {        // col - номер столбца
        std::cout << "   Столбец " << col << ": ";
        
        // Внутренний цикл - по строкам
        for (int row = 0; row < 2; row++) {    // row - номер строки
            std::cout << mat[row][col] << "\t";  // Выводим элемент
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}
```

### 2.2. Трёхмерные и N-мерные массивы

```cpp
#include <iostream>

int main() {
    std::cout << "=== ТРЁХМЕРНЫЕ И N-МЕРНЫЕ МАССИВЫ ===" << std::endl;
    std::cout << std::endl;
    
    // 1. Трёхмерный массив (куб данных)
    // Представьте: 2 слоя, каждый слой - матрица 3x4
    int cube[2][3][4];  // [глубина][строки][столбцы]
    
    std::cout << "1. Трёхмерный массив:" << std::endl;
    std::cout << "   int cube[2][3][4];" << std::endl;
    std::cout << "   Размеры: 2 x 3 x 4 = 24 элемента" << std::endl;
    std::cout << std::endl;
    
    // 2. Инициализация трёхмерного массива
    std::cout << "2. Инициализация трёхмерного массива:" << std::endl;
    
    int cube1[2][2][3] = {
        // Первый слой (depth = 0)
        {
            {1, 2, 3},   // Первая строка первого слоя
            {4, 5, 6}    // Вторая строка первого слоя
        },
        // Второй слой (depth = 1)
        {
            {7, 8, 9},   // Первая строка второго слоя
            {10, 11, 12} // Вторая строка второго слоя
        }
    };
    
    std::cout << "   int cube1[2][2][3] = {" << std::endl;
    std::cout << "       { {1,2,3}, {4,5,6} }," << std::endl;
    std::cout << "       { {7,8,9}, {10,11,12} }" << std::endl;
    std::cout << "   };" << std::endl;
    std::cout << std::endl;
    
    // 3. Доступ к элементам трёхмерного массива
    std::cout << "3. Доступ к элементам трёхмерного массива:" << std::endl;
    std::cout << "   cube1[слой][строка][столбец]" << std::endl;
    std::cout << std::endl;
    
    std::cout << "   cube1[0][0][0] = " << cube1[0][0][0] << std::endl;  // Первый слой, первая строка, первый столбец
    std::cout << "   cube1[0][0][1] = " << cube1[0][0][1] << std::endl;  // Первый слой, первая строка, второй столбец
    std::cout << "   cube1[0][1][2] = " << cube1[0][1][2] << std::endl;  // Первый слой, вторая строка, третий столбец
    std::cout << "   cube1[1][0][0] = " << cube1[1][0][0] << std::endl;  // Второй слой, первая строка, первый столбец
    std::cout << "   cube1[1][1][2] = " << cube1[1][1][2] << std::endl;  // Второй слой, вторая строка, третий столбец
    
    std::cout << std::endl;
    
    // 4. Обход трёхмерного массива
    std::cout << "4. Обход трёхмерного массива:" << std::endl;
    
    // Три вложенных цикла
    for (int layer = 0; layer < 2; layer++) {            // По слоям
        std::cout << "   Слой " << layer << ":" << std::endl;
        
        for (int row = 0; row < 2; row++) {              // По строкам
            std::cout << "      ";
            
            for (int col = 0; col < 3; col++) {          // По столбцам
                std::cout << cube1[layer][row][col] << "\t";  // Выводим элемент
            }
            
            std::cout << std::endl;
        }
        
        std::cout << std::endl;
    }
    
    // 5. Четырёхмерный массив (редко используется)
    std::cout << "5. Четырёхмерный массив:" << std::endl;
    
    int hypercube[2][2][2][2];  // [гиперслой][слой][строка][столбец]
    // 2 * 2 * 2 * 2 = 16 элементов
    
    std::cout << "   int hypercube[2][2][2][2];" << std::endl;
    std::cout << "   4 измерения, 16 элементов" << std::endl;
    std::cout << std::endl;
    
    // 6. Инициализация и использование
    // Заполняем четырёхмерный массив значениями
    int counter = 1;
    
    for (int h = 0; h < 2; h++) {                 // Первое измерение
        for (int l = 0; l < 2; l++) {             // Второе измерение
            for (int r = 0; r < 2; r++) {         // Третье измерение
                for (int c = 0; c < 2; c++) {     // Четвёртое измерение
                    hypercube[h][l][r][c] = counter++;
                }
            }
        }
    }
    
    std::cout << "   Доступ к элементам 4D массива:" << std::endl;
    std::cout << "   hypercube[0][0][0][0] = " << hypercube[0][0][0][0] << std::endl;
    std::cout << "   hypercube[0][0][0][1] = " << hypercube[0][0][0][1] << std::endl;
    std::cout << "   hypercube[0][0][1][0] = " << hypercube[0][0][1][0] << std::endl;
    std::cout << "   hypercube[1][1][1][1] = " << hypercube[1][1][1][1] << std::endl;
    
    std::cout << std::endl;
    
    // 7. Практический пример: хранение данных за несколько дней
    std::cout << "7. Практический пример:" << std::endl;
    std::cout << "   Температура за 3 дня, в 2 городах, по 24 часа" << std::endl;
    
    // [день][город][час]
    double temperature[3][2][24];  // 3 дня, 2 города, 24 часа в сутках
    
    // Заполняем случайными значениями
    for (int day = 0; day < 3; day++) {
        for (int city = 0; city < 2; city++) {
            for (int hour = 0; hour < 24; hour++) {
                // Генерируем "температуру" от 15.0 до 25.0 градусов
                temperature[day][city][hour] = 15.0 + (hour / 2.0);
            }
        }
    }
    
    // Выводим температуру для первого дня
    std::cout << "   Температура в День 1:" << std::endl;
    std::cout << "   Город 0: ";
    for (int hour = 0; hour < 24; hour += 3) {  // Каждые 3 часа
        std::cout << temperature[0][0][hour] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "   Город 1: ";
    for (int hour = 0; hour < 24; hour += 3) {
        std::cout << temperature[0][1][hour] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

## Глава 3: Особенности массивов в C++

### 3.1. Статические vs Динамические массивы

```cpp
#include <iostream>

int main() {
    std::cout << "=== СТАТИЧЕСКИЕ VS ДИНАМИЧЕСКИЕ МАССИВЫ ===" << std::endl;
    std::cout << std::endl;
    
    // 1. СТАТИЧЕСКИЕ МАССИВЫ (в стеке)
    std::cout << "1. СТАТИЧЕСКИЕ МАССИВЫ (stack allocation):" << std::endl;
    
    // Размер должен быть известен на этапе компиляции
    int staticArray[5] = {1, 2, 3, 4, 5};  // Выделяется в стеке
    
    std::cout << "   int staticArray[5] = {1, 2, 3, 4, 5};" << std::endl;
    std::cout << "   Размер фиксирован, известен при компиляции" << std::endl;
    std::cout << "   Память автоматически освобождается при выходе из области видимости" << std::endl;
    std::cout << "   Быстрый доступ" << std::endl;
    std::cout << std::endl;
    
    // 2. ДИНАМИЧЕСКИЕ МАССИВЫ (в куче)
    std::cout << "2. ДИНАМИЧЕСКИЕ МАССИВЫ (heap allocation):" << std::endl;
    
    // Размер может определяться во время выполнения программы
    int size;
    std::cout << "   Введите размер массива: ";
    std::cin >> size;  // Пользователь вводит размер
    
    // Выделяем память в куче с помощью оператора new[]
    int* dynamicArray = new int[size];  // new[] - оператор выделения памяти для массива
    
    std::cout << "   int* dynamicArray = new int[" << size << "];" << std::endl;
    std::cout << "   Размер может определяться во время выполнения" << std::endl;
    std::cout << "   Память нужно освобождать вручную с помощью delete[]" << std::endl;
    std::cout << "   Медленнее статических массивов" << std::endl;
    std::cout << std::endl;
    
    // Заполняем динамический массив
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = (i + 1) * 10;  // 10, 20, 30, ...
    }
    
    std::cout << "   Динамический массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;
    
    // 3. ОСВОБОЖДЕНИЕ ПАМЯТИ
    std::cout << std::endl;
    std::cout << "3. ОСВОБОЖДЕНИЕ ПАМЯТИ:" << std::endl;
    
    // Для динамических массивов обязательно использовать delete[]
    delete[] dynamicArray;  // delete[] - оператор освобождения памяти массива
    dynamicArray = nullptr;  // Хорошая практика: обнулить указатель после удаления
    
    std::cout << "   delete[] dynamicArray;" << std::endl;
    std::cout << "   dynamicArray = nullptr;" << std::endl;
    std::cout << "   Обязательно использовать delete[] (не delete!)" << std::endl;
    std::cout << std::endl;
    
    // 4. СРАВНЕНИЕ sizeof
    std::cout << "4. СРАВНЕНИЕ sizeof:" << std::endl;
    
    int arr[10];
    int* dynArr = new int[10];
    
    std::cout << "   sizeof(arr) = " << sizeof(arr) << std::endl;      // 40 байт (10 * 4)
    std::cout << "   sizeof(dynArr) = " << sizeof(dynArr) << std::endl; // 8 байт (размер указателя)
    
    // Для статического массива sizeof возвращает размер всего массива
    // Для указателя sizeof возвращает размер самого указателя
    
    delete[] dynArr;
    
    std::cout << std::endl;
    
    // 5. МНОГОМЕРНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ
    std::cout << "5. МНОГОМЕРНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ:" << std::endl;
    
    int rows = 3, cols = 4;
    
    // Создаём двумерный динамический массив
    int** matrix = new int*[rows];  // Массив указателей на строки
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];  // Каждая строка - массив столбцов
    }
    
    std::cout << "   Создание матрицы " << rows << "x" << cols << ":" << std::endl;
    std::cout << "   1. int** matrix = new int*[" << rows << "];" << std::endl;
    std::cout << "   2. for: matrix[i] = new int[" << cols << "];" << std::endl;
    std::cout << std::endl;
    
    // Заполняем и выводим
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }
    
    std::cout << "   Матрица:" << std::endl;
    for (int i = 0; i < rows; i++) {
        std::cout << "   ";
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    // Освобождаем память в обратном порядке
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];  // Удаляем каждую строку
    }
    delete[] matrix;         // Удаляем массив указателей
    matrix = nullptr;
    
    std::cout << std::endl;
    std::cout << "   Память освобождена" << std::endl;
    
    return 0;
}
```

### 3.2. Массивы символов и строки C-style

```cpp
#include <iostream>
#include <cstring>  // Для функций работы со строками C

int main() {
    std::cout << "=== МАССИВЫ СИМВОЛОВ И СТРОКИ C-STYLE ===" << std::endl;
    std::cout << std::endl;
    
    // 1. МАССИВЫ СИМВОЛОВ
    std::cout << "1. МАССИВЫ СИМВОЛОВ:" << std::endl;
    std::cout << std::endl;
    
    // Способ 1: Массив символов
    char word1[5] = {'H', 'e', 'l', 'l', 'o'};  // Массив из 5 символов
    
    std::cout << "   Способ 1 - массив символов:" << std::endl;
    std::cout << "   char word1[5] = {'H', 'e', 'l', 'l', 'o'};" << std::endl;
    std::cout << "   Вывод посимвольно: ";
    
    for (int i = 0; i < 5; i++) {
        std::cout << word1[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    // Способ 2: Строка C-style (с терминатором '\0')
    char word2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};  // '\0' - нулевой символ (терминатор)
    
    std::cout << "   Способ 2 - строка C-style:" << std::endl;
    std::cout << "   char word2[6] = {'H', 'e', 'l', 'l', 'o', '\\0'};" << std::endl;
    std::cout << "   Вывод как строка: " << word2 << std::endl;  // Можем выводить как строку
    std::cout << std::endl;
    
    // Способ 3: Строковый литерал (автоматически добавляется '\0')
    char word3[] = "Hello";  // Компилятор автоматически добавляет '\0'
    // Размер массива = 6 (5 символов + '\0')
    
    std::cout << "   Способ 3 - строковый литерал:" << std::endl;
    std::cout << "   char word3[] = \"Hello\";" << std::endl;
    std::cout << "   Размер массива: " << sizeof(word3) << " байт" << std::endl;
    std::cout << "   Содержимое: " << word3 << std::endl;
    std::cout << std::endl;
    
    // 2. ФУНКЦИИ ДЛЯ РАБОТЫ СО СТРОКАМИ C-STYLE
    std::cout << "2. ФУНКЦИИ ДЛЯ РАБОТЫ СО СТРОКАМИ:" << std::endl;
    std::cout << std::endl;
    
    // strlen - длина строки (без учёта '\0')
    std::cout << "   strlen(word3) = " << strlen(word3) << std::endl;  // 5
    std::cout << std::endl;
    
    // strcpy - копирование строк
    char copy[20];  // Должен быть достаточно большим
    strcpy(copy, word3);  // Копируем word3 в copy
    
    std::cout << "   strcpy(copy, word3):" << std::endl;
    std::cout << "   copy = " << copy << std::endl;
    std::cout << std::endl;
    
    // strcat - конкатенация (объединение) строк
    char greeting[50] = "Hello, ";  // Инициализируем
    strcat(greeting, "World!");     // Добавляем
    
    std::cout << "   strcat(greeting, \"World!\"):" << std::endl;
    std::cout << "   greeting = " << greeting << std::endl;
    std::cout << std::endl;
    
    // strcmp - сравнение строк
    char str1[] = "apple";
    char str2[] = "banana";
    
    int result = strcmp(str1, str2);
    
    std::cout << "   strcmp(\"apple\", \"banana\") = " << result << std::endl;
    std::cout << "   < 0 если первая меньше, = 0 если равны, > 0 если первая больше" << std::endl;
    std::cout << std::endl;
    
    // 3. ВВОД СТРОК С КЛАВИАТУРЫ
    std::cout << "3. ВВОД СТРОК С КЛАВИАТУРЫ:" << std::endl;
    
    char name[50];  // Буфер для имени
    
    std::cout << "   Введите ваше имя: ";
    std::cin.getline(name, 50);  // getline читает всю строку (с пробелами)
    // Просто cin >> name; прочитает только до первого пробела
    
    std::cout << "   Привет, " << name << "!" << std::endl;
    std::cout << std::endl;
    
    // 4. ДВУМЕРНЫЙ МАССИВ СТРОК
    std::cout << "4. ДВУМЕРНЫЙ МАССИВ СТРОК:" << std::endl;
    
    // Массив строк (массив массивов символов)
    char names[][20] = {  // Каждая строка - массив из 20 символов
        "Alice",
        "Bob",
        "Charlie",
        "Diana"
    };
    
    std::cout << "   Список имен:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "   " << i + 1 << ". " << names[i] << std::endl;
    }
    
    return 0;
}
```

### 3.3. Массивы структур

```cpp
#include <iostream>
#include <string>  // Для std::string

int main() {
    std::cout << "=== МАССИВЫ СТРУКТУР ===" << std::endl;
    std::cout << std::endl;
    
    // 1. ОПРЕДЕЛЕНИЕ СТРУКТУРЫ
    struct Student {      // struct - ключевое слово для создания структуры
        int id;          // Поле: идентификатор студента
        std::string name; // Поле: имя студента (используем std::string)
        double gpa;      // Поле: средний балл
        int age;         // Поле: возраст
    };
    
    std::cout << "1. Определение структуры Student:" << std::endl;
    std::cout << "   struct Student {" << std::endl;
    std::cout << "       int id;" << std::endl;
    std::cout << "       std::string name;" << std::endl;
    std::cout << "       double gpa;" << std::endl;
    std::cout << "       int age;" << std::endl;
    std::cout << "   };" << std::endl;
    std::cout << std::endl;
    
    // 2. СОЗДАНИЕ МАССИВА СТРУКТУР
    std::cout << "2. Создание массива структур:" << std::endl;
    
    // Массив из 3 студентов
    Student students[3];  // students - массив из 3 элементов типа Student
    
    // 3. ИНИЦИАЛИЗАЦИЯ МАССИВА СТРУКТУР
    std::cout << "3. Инициализация массива структур:" << std::endl;
    std::cout << std::endl;
    
    // Способ 1: Поэлементная инициализация
    students[0].id = 1001;           // Доступ к полю через точку
    students[0].name = "Alice";
    students[0].gpa = 3.8;
    students[0].age = 20;
    
    // Способ 2: Инициализация при объявлении
    Student initialStudents[2] = {
        {2001, "Bob", 3.5, 21},     // Первый студент
        {2002, "Charlie", 4.0, 19}  // Второй студент
    };
    
    // Способ 3: Частичная инициализация (оставшиеся поля = 0/пустые)
    students[1] = {3001, "Diana"};  // Только id и name, остальные = 0
    students[2] = {3002, "Eve", 3.9}; // id, name и gpa, age = 0
    
    // 4. ДОСТУП К ЭЛЕМЕНТАМ МАССИВА СТРУКТУР
    std::cout << "4. Доступ к элементам массива структур:" << std::endl;
    std::cout << std::endl;
    
    // Вывод информации о студентах
    std::cout << "   Список студентов:" << std::endl;
    std::cout << "   ==================================" << std::endl;
    
    for (int i = 0; i < 3; i++) {
        std::cout << "   Студент #" << i + 1 << ":" << std::endl;
        std::cout << "     ID: " << students[i].id << std::endl;    // students[i] - i-й студент
        std::cout << "     Имя: " << students[i].name << std::endl; // .name - поле "имя"
        std::cout << "     GPA: " << students[i].gpa << std::endl;  // .gpa - поле "средний балл"
        std::cout << "     Возраст: " << students[i].age << std::endl;
        std::cout << std::endl;
    }
    
    // 5. ИЗМЕНЕНИЕ ДАННЫХ
    std::cout << "5. Изменение данных в массиве структур:" << std::endl;
    
    // Увеличиваем GPA первого студента
    students[0].gpa += 0.2;  // students[0].gpa = students[0].gpa + 0.2
    
    std::cout << "   После students[0].gpa += 0.2:" << std::endl;
    std::cout << "   Новый GPA Alice: " << students[0].gpa << std::endl;
    std::cout << std::endl;
    
    // 6. ПОИСК В МАССИВЕ СТРУКТУР
    std::cout << "6. Поиск в массиве структур:" << std::endl;
    
    int searchId = 3001;
    bool found = false;
    
    for (int i = 0; i < 3; i++) {
        if (students[i].id == searchId) {  // Если нашли студента с нужным ID
            std::cout << "   Найден студент: " << students[i].name << std::endl;
            found = true;
            break;  // Выходим из цикла
        }
    }
    
    if (!found) {
        std::cout << "   Студент с ID " << searchId << " не найден" << std::endl;
    }
    
    std::cout << std::endl;
    
    // 7. СОРТИРОВКА МАССИВА СТРУКТУР
    std::cout << "7. Сортировка массива структур по GPA:" << std::endl;
    
    // Простая сортировка пузырьком по GPA
    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (students[j].gpa < students[j + 1].gpa) {  // Сортировка по убыванию GPA
                // Меняем местами две структуры
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    std::cout << "   Отсортированный список (по убыванию GPA):" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "   " << students[i].name << ": " << students[i].gpa << std::endl;
    }
    
    std::cout << std::endl;
    
    // 8. МНОГОМЕРНЫЙ МАССИВ СТРУКТУР
    std::cout << "8. Многомерный массив структур:" << std::endl;
    
    // Матрица студентов (например, по классам и партам)
    Student classroom[2][3];  // 2 ряда, 3 парты в каждом
    
    // Заполняем матрицу
    int studentId = 1;
    for (int row = 0; row < 2; row++) {
        for (int desk = 0; desk < 3; desk++) {
            classroom[row][desk].id = studentId++;
            classroom[row][desk].name = "Student_" + std::to_string(row * 3 + desk + 1);
            classroom[row][desk].gpa = 3.0 + (row + desk) * 0.2;
            classroom[row][desk].age = 18 + row;
        }
    }
    
    // Выводим рассадку
    std::cout << "   Рассадка в классе:" << std::endl;
    for (int row = 0; row < 2; row++) {
        std::cout << "   Ряд " << row + 1 << ": ";
        for (int desk = 0; desk < 3; desk++) {
            std::cout << classroom[row][desk].name << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
```

## Глава 4: Лучшие практики и типичные ошибки

### 4.1. Частые ошибки и как их избежать

```cpp
#include <iostream>

int main() {
    std::cout << "=== ЧАСТЫЕ ОШИБКИ И КАК ИХ ИЗБЕЖАТЬ ===" << std::endl;
    std::cout << std::endl;
    
    // 1. ОШИБКА: Выход за границы массива
    std::cout << "1. ОШИБКА: Выход за границы массива" << std::endl;
    
    int arr[5] = {1, 2, 3, 4, 5};
    
    // arr[5] = 10;  // ОПАСНО: обращение к 6-му элементу (индексы 0-4)
    // arr[-1] = 20; // ОПАСНО: обращение к несуществующему элементу
    
    std::cout << "   Правильно: всегда проверяйте индексы!" << std::endl;
    std::cout << "   Используйте переменные для размера массива" << std::endl;
    std::cout << std::endl;
    
    // 2. ОШИБКА: Использование неинициализированного массива
    std::cout << "2. ОШИБКА: Использование неинициализированного массива" << std::endl;
    
    int uninitialized[5];  // Содержит "мусор"
    
    // int sum = 0;
    // for (int i = 0; i < 5; i++) {
    //     sum += uninitialized[i];  // Суммируем случайные значения
    // }
    
    std::cout << "   Правильно: всегда инициализируйте массивы!" << std::endl;
    std::cout << "   int arr[5] = {0};  // Инициализация нулями" << std::endl;
    std::cout << std::endl;
    
    // 3. ОШИБКА: Предположение о размере массива
    std::cout << "3. ОШИБКА: Предположение о размере массива" << std::endl;
    
    int data[10] = {1, 2, 3, 4, 5};  // Только 5 элементов инициализировано
    
    // for (int i = 0; i < 10; i++) {
    //     data[i] *= 2;  // Первые 5 элементов *2, остальные "мусор" *2
    // }
    
    std::cout << "   Правильно: храните размер в переменной!" << std::endl;
    std::cout << "   const int SIZE = 10;" << std::endl;
    std::cout << "   int data[SIZE];" << std::endl;
    std::cout << "   Используйте SIZE везде, где нужен размер" << std::endl;
    std::cout << std::endl;
    
    // 4. ОШИБКА: Неправильное копирование массивов
    std::cout << "4. ОШИБКА: Неправильное копирование массивов" << std::endl;
    
    int a[3] = {1, 2, 3};
    int b[3];
    
    // b = a;  // ОШИБКА: массивы нельзя копировать оператором =
    
    std::cout << "   Правильно: копируйте поэлементно!" << std::endl;
    std::cout << "   for (int i = 0; i < 3; i++) {" << std::endl;
    std::cout << "       b[i] = a[i];" << std::endl;
    std::cout << "   }" << std::endl;
    std::cout << std::endl;
    
    // 5. ОШИБКА: Сравнение массивов
    std::cout << "5. ОШИБКА: Сравнение массивов" << std::endl;
    
    int x[3] = {1, 2, 3};
    int y[3] = {1, 2, 3};
    
    // if (x == y) {  // ОШИБКА: сравниваются адреса, а не содержимое
    //     std::cout << "Массивы равны" << std::endl;
    // }
    
    std::cout << "   Правильно: сравнивайте поэлементно!" << std::endl;
    std::cout << "   bool equal = true;" << std::endl;
    std::cout << "   for (int i = 0; i < 3; i++) {" << std::endl;
    std::cout << "       if (x[i] != y[i]) {" << std::endl;
    std::cout << "           equal = false;" << std::endl;
    std::cout << "           break;" << std::endl;
    std::cout << "       }" << std::endl;
    std::cout << "   }" << std::endl;
    std::cout << std::endl;
    
    // 6. ОШИБКА: Использование sizeof для определения размера в функциях
    std::cout << "6. ОШИБКА: sizeof в функциях" << std::endl;
    
    void wrongFunction(int arr[]) {
        // int size = sizeof(arr) / sizeof(arr[0]);  // ОШИБКА!
        // sizeof(arr) вернёт размер указателя (8 байт), а не массива
    }
    
    std::cout << "   Правильно: передавайте размер как параметр!" << std::endl;
    std::cout << "   void rightFunction(int arr[], int size) {" << std::endl;
    std::cout << "       // Используйте size" << std::endl;
    std::cout << "   }" << std::endl;
    std::cout << std::endl;
    
    // 7. ЛУЧШИЕ ПРАКТИКИ
    std::cout << "7. ЛУЧШИЕ ПРАКТИКИ РАБОТЫ С МАССИВАМИ" << std::endl;
    std::cout << std::endl;
    
    // Практика 1: Использование констант для размеров
    std::cout << "   Практика 1: Использование констант" << std::endl;
    const int MAX_SIZE = 100;
    int buffer[MAX_SIZE];
    std::cout << "   const int MAX_SIZE = 100;" << std::endl;
    std::cout << "   int buffer[MAX_SIZE];" << std::endl;
    std::cout << std::endl;
    
    // Практика 2: Проверка границ
    std::cout << "   Практика 2: Проверка границ" << std::endl;
    int index = 10;
    if (index >= 0 && index < MAX_SIZE) {
        buffer[index] = 42;  // Безопасный доступ
    } else {
        std::cout << "   Ошибка: индекс вне границ" << std::endl;
    }
    std::cout << std::endl;
    
    // Практика 3: Инициализация массивов
    std::cout << "   Практика 3: Инициализация массивов" << std::endl;
    int scores[5] = {0};  // Все элементы = 0
    double prices[10] = {0.0};  // Все элементы = 0.0
    bool flags[3] = {false};  // Все элементы = false
    std::cout << "   Всегда инициализируйте массивы!" << std::endl;
    std::cout << std::endl;
    
    // Практика 4: Использование range-based for (C++11)
    std::cout << "   Практика 4: Range-based for" << std::endl;
    int values[] = {10, 20, 30, 40, 50};
    
    std::cout << "   Элементы: ";
    for (int val : values) {  // Для каждого значения в values
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    // Практика 5: Использование std::array (C++11)
    std::cout << "   Практика 5: Используйте std::array вместо C-массивов" << std::endl;
    // #include <array>
    // std::array<int, 5> modernArray = {1, 2, 3, 4, 5};
    // Преимущества: знает свой размер, безопаснее, поддерживает STL алгоритмы
    std::cout << std::endl;
    
    // Практика 6: Комментирование сложных многомерных массивов
    std::cout << "   Практика 6: Комментирование" << std::endl;
    // Матрица 3x4: 3 строки, 4 столбца
    int matrix[3][4] = {
        // row 0: [col0, col1, col2, col3]
        {11, 12, 13, 14},
        // row 1
        {21, 22, 23, 24},
        // row 2
        {31, 32, 33, 34}
    };
    
    return 0;
}
```

## Заключение

### Ключевые выводы:

1. **Одномерные массивы**:
   - Объявление: `тип имя[размер];`
   - Индексация начинается с 0
   - Размер должен быть константным выражением

2. **Многомерные массивы**:
   - Двумерные: `тип имя[строк][столбцов];`
   - Трёхмерные: `тип имя[слои][строк][столбцов];`
   - Элементы хранятся в памяти последовательно

3. **Инициализация**:
   - Полная: `int arr[3] = {1, 2, 3};`
   - Частичная: `int arr[5] = {1, 2};` (остальные = 0)
   - Автоматический размер: `int arr[] = {1, 2, 3};`

4. **Доступ к элементам**:
   - Через индексы: `arr[i]`
   - Через указатели: `*(arr + i)`
   - Для многомерных: `matrix[i][j]`

5. **Важные правила**:
   - Всегда проверяйте границы массива
   - Инициализируйте массивы перед использованием
   - Используйте константы для размеров
   - Для строк C-style не забывайте про терминатор `\0`

### Практические советы:

1. Используйте `std::array` вместо C-массивов когда возможно
2. Для динамических массивов используйте `std::vector`
3. Всегда проверяйте индексы перед доступом к элементам
4. Используйте `const` для массивов, которые не должны изменяться
5. Комментируйте сложные многомерные структуры данных

Массивы — фундаментальная структура данных в C++, и их правильное использование критически важно для написания эффективного и безопасного кода.