#include <iostream>
#include <iomanip>
using namespace std;

void twoDimensionalArrays() {
    /*
    ЗАДАЧА: Понять, как двумерные массивы располагаются в памяти.
    
    ВОПРОСЫ:
    1. Как устроен двумерный массив в памяти?
    2. В чем разница между статическим и динамическим 2D массивом?
    3. Как эффективно работать с большими матрицами?
    */
    
    cout << "\n\n=== ЗАДАЧА 4: Двумерные массивы в памяти ===" << endl;
    cout << "==========================================" << endl;
    
    const int ROWS = 3;
    const int COLS = 4;
    
    // 1. СТАТИЧЕСКИЙ 2D МАССИВ (в стеке)
    cout << "\n1. Статический 2D массив (стек):" << endl;
    
    int static_matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    cout << "Матрица " << ROWS << "x" << COLS << ":" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(3) << static_matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nАдреса элементов (показывает непрерывность):" << endl;
    cout << "static_matrix[0][0]: " << &static_matrix[0][0] << endl;
    cout << "static_matrix[0][1]: " << &static_matrix[0][1] 
         << " (+" << (char*)&static_matrix[0][1] - (char*)&static_matrix[0][0] << " байт)" << endl;
    cout << "static_matrix[1][0]: " << &static_matrix[1][0] 
         << " (+" << (char*)&static_matrix[1][0] - (char*)&static_matrix[0][0] << " байт)" << endl;
    
    // ВОПРОС: Почему static_matrix[1][0] не сразу после static_matrix[0][3]?
    cout << "\n--- ВОПРОС ---" << endl;
    cout << "Матрица хранится ПОСТРОЧНО в непрерывной памяти:" << endl;
    cout << "[0][0] [0][1] [0][2] [0][3] [1][0] [1][1] ..." << endl;
    
    // 2. ДИНАМИЧЕСКИЙ 2D МАССИВ (в куче) - НЕПРАВИЛЬНЫЙ СПОСОБ
    cout << "\n\n2. Динамический 2D массив (неправильный способ):" << endl;
    
    // Создаем массив указателей на строки
    int** dynamic_matrix_bad = new int*[ROWS];
    
    // Каждая строка - отдельный массив
    for (int i = 0; i < ROWS; i++) {
        dynamic_matrix_bad[i] = new int[COLS];
        for (int j = 0; j < COLS; j++) {
            dynamic_matrix_bad[i][j] = i * COLS + j + 1;
        }
    }
    
    cout << "Создан массив указателей и " << ROWS << " отдельных массивов" << endl;
    
    // Проблема: данные НЕ непрерывны в памяти!
    cout << "\nАдреса строк (показывает НЕ непрерывность):" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "Строка " << i << ": " << dynamic_matrix_bad[i] << endl;
    }
    
    // Проблема: медленный доступ и больше накладных расходов
    cout << "\nПРОБЛЕМЫ этого подхода:" << endl;
    cout << "1. Данные не непрерывны (кэш-промахи)" << endl;
    cout << "2. Много мелких выделений памяти" << endl;
    cout << "3. Сложное освобождение" << endl;
    
    // Освобождаем (в обратном порядке!)
    for (int i = 0; i < ROWS; i++) {
        delete[] dynamic_matrix_bad[i];
    }
    delete[] dynamic_matrix_bad;
    
    // 3. ДИНАМИЧЕСКИЙ 2D МАССИВ (в куче) - ПРАВИЛЬНЫЙ СПОСОБ
    cout << "\n\n3. Динамический 2D массив (правильный способ):" << endl;
    
    // Выделяем один большой непрерывный блок
    int* dynamic_matrix_good = new int[ROWS * COLS];
    
    // Заполняем как одномерный массив
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            dynamic_matrix_good[i * COLS + j] = i * COLS + j + 1;
        }
    }
    
    cout << "Выделен один непрерывный блок " << ROWS * COLS * sizeof(int) 
         << " байт" << endl;
    cout << "Адрес начала: " << dynamic_matrix_good << endl;
    
    // Доступ через формулу: элемент[i][j] = data[i * COLS + j]
    cout << "\nДоступ к элементам:" << endl;
    cout << "dynamic_matrix_good[1][2] = " 
         << dynamic_matrix_good[1 * COLS + 2] << endl;
    
    // Преимущества:
    cout << "\nПРЕИМУЩЕСТВА этого подхода:" << endl;
    cout << "1. Непрерывная память (лучше для кэша)" << endl;
    cout << "2. Одно выделение/освобождение" << endl;
    cout << "3. Быстрее и эффективнее" << endl;
    
    delete[] dynamic_matrix_good;
    
    // 4. ПРАКТИЧЕСКОЕ ЗАДАНИЕ: реализовать класс Matrix
    cout << "\n\n4. ПРАКТИЧЕСКОЕ ЗАДАНИЕ: класс Matrix" << endl;
    
    class Matrix {
    private:
        int rows, cols;
        int* data;  // Один непрерывный блок
        
    public:
        Matrix(int r, int c) : rows(r), cols(c) {
            data = new int[rows * cols];  // Одно выделение
            cout << "Матрица " << rows << "x" << cols 
                 << " создана (" << rows * cols * sizeof(int) << " байт)" << endl;
        }
        
        ~Matrix() {
            delete[] data;  // Одно освобождение
            cout << "Память матрицы освобождена" << endl;
        }
        
        // Доступ к элементу
        int& at(int i, int j) {
            return data[i * cols + j];
        }
        
        // Заполнение
        void fill(int value) {
            for (int i = 0; i < rows * cols; i++) {
                data[i] = value;
            }
        }
        
        // Вывод
        void print() const {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << setw(4) << data[i * cols + j];
                }
                cout << endl;
            }
        }
    };
    
    cout << "\nСоздаем и используем матрицу 4x5:" << endl;
    {
        Matrix m(4, 5);
        m.fill(0);
        
        // Заполняем диагональ
        for (int i = 0; i < 4; i++) {
            m.at(i, i) = i + 1;
        }
        
        m.print();
        // При выходе из блока деструктор освободит память
    }
    
    cout << "\nМатрица автоматически уничтожена (RAII)" << endl;
}

int main() {
    cout << "=== ПРОГРАММА ДЛЯ АНАЛИЗА ПАМЯТИ ===\n" << endl;
    
    // Вызываем первую функцию
    twoDimensionalArrays();

    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    return 0;
}