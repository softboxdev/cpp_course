#include <iostream>
using namespace std;

int main() {
    // Массив с оценками студента
    int grades[7] = {5, 4, 3, 5, 4, 5, 4};
    
    // Переменная для хранения суммы
    int sum = 0;
    
    // Переменная для хранения минимальной оценки
    int minGrade = grades[0];
    
    // Переменная для хранения максимальной оценки
    int maxGrade = grades[0];
    
    // Проходим по всем элементам массива
    for(int i = 0; i < 7; i++) {
        // Добавляем текущую оценку к сумме
        sum = sum + grades[i];
        
        // Проверяем, является ли текущая оценка новой минимальной
        if(grades[i] < minGrade) {
            minGrade = grades[i];
        }
        
        // Проверяем, является ли текущая оценка новой максимальной
        if(grades[i] > maxGrade) {
            maxGrade = grades[i];
        }
    }
    
    // Вычисляем среднее значение
    // Важно: преобразуем sum к типу double для точного деления
    double average = (double)sum / 7;
    
    // Выводим результаты
    cout << "Все оценки: ";
    for(int i = 0; i < 7; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
    
    cout << "Сумма всех оценок: " << sum << endl;
    cout << "Средний балл: " << average << endl;
    cout << "Минимальная оценка: " << minGrade << endl;
    cout << "Максимальная оценка: " << maxGrade << endl;
    
    return 0;
}