# Практическая работа: "Библиотека для работы с геометрическими фигурами"

## Цель работы
Освоить создание многофайловых проектов, использование пространств имён, разделение кода на заголовочные файлы и файлы реализации в C++.

## Структура проекта
```
geometry_library/
├── include/                 # Заголовочные файлы
│   ├── geometry.h          # Основной заголовок
│   ├── shapes.h           # Базовые фигуры
│   └── operations.h       # Математические операции
├── src/                   # Файлы реализации
│   ├── shapes.cpp        # Реализация фигур
│   ├── operations.cpp    # Реализация операций
│   └── main.cpp          # Главный файл программы
└── README.md             # Описание проекта
```

## Подробный код с комментариями каждого слова

### Файл 1: `include/geometry.h`

```cpp
// Защита от множественного включения (include guard)
// Если GEOMETRY_H не определено, определяем его и включаем код
#ifndef GEOMETRY_H        // #ifndef = если не определено
#define GEOMETRY_H        // #define = определить

// Подключаем стандартную библиотеку ввода/вывода
#include <iostream>

// Подключаем математическую библиотеку
#include <cmath>

// Подключаем библиотеку для строк
#include <string>

// Включение других заголовочных файлов нашего проекта
#include "shapes.h"       // shapes.h в той же папке
#include "operations.h"   // operations.h в той же папке

// Объявляем основное пространство имён для всей геометрической библиотеки
namespace Geometry {      // namespace = пространство имён
    
    // Константы в пространстве имён
    // const = константа (неизменяемое значение)
    // double = число с плавающей точкой двойной точности
    const double PI = 3.141592653589793;  // Число π
    
    // Вспомогательная функция для форматированного вывода
    // void = функция не возвращает значение
    // printHeader = имя функции
    // const std::string& = константная ссылка на строку (эффективная передача)
    void printHeader(const std::string& title) {
        // std::cout = стандартный поток вывода
        // << = оператор вставки в поток
        // std::endl = конец строки + сброс буфера
        std::cout << "\n=== " << title << " ===" << std::endl;
    }
    
    // Функция для демонстрации работы всей библиотеки
    void demonstrateLibrary();
    
} // Конец пространства имён Geometry

// Конец защиты от множественного включения
#endif // GEOMETRY_H       // #endif = конец условия #ifndef
```

### Файл 2: `include/shapes.h`

```cpp
// Защита от множественного включения
#ifndef SHAPES_H
#define SHAPES_H

// Включаем заголовок geometry.h для использования PI
#include "geometry.h"

// Пространство имён для фигур внутри Geometry
namespace Geometry {     // Открываем то же пространство имён
    
    // Абстрактный базовый класс для всех фигур
    // class = определение класса
    // Shape = имя класса
    class Shape {
    // protected: = защищённые члены (доступны в наследниках)
    protected:
        // std::string = строка из стандартной библиотеки
        // name = имя фигуры
        std::string name;
        // int = целое число
        // id = уникальный идентификатор
        int id;
        // static = общая для всех объектов класса
        // nextId = следующий доступный ID
        static int nextId;  // Объявление статической переменной
        
    // public: = публичные члены (доступны извне)
    public:
        // Конструктор класса
        // Shape = имя конструктора (совпадает с именем класса)
        // const std::string& = константная ссылка на строку
        // shapeName = параметр конструктора
        Shape(const std::string& shapeName);
        
        // Виртуальный деструктор (обеспечивает правильное удаление наследников)
        // virtual = виртуальный метод (может быть переопределён)
        // ~Shape = деструктор
        virtual ~Shape();
        
        // Чисто виртуальная функция (делает класс абстрактным)
        // virtual = виртуальный
        // double = возвращает число double
        // calculateArea() = имя функции
        // const = функция не изменяет объект
        // = 0 = чисто виртуальная (должна быть реализована в наследниках)
        virtual double calculateArea() const = 0;
        
        // Виртуальная функция с реализацией по умолчанию
        virtual double calculatePerimeter() const;
        
        // Обычная (не виртуальная) функция
        void displayInfo() const;
        
        // Геттер для имени
        // const = возвращает константную ссылку
        const std::string& getName() const;
        
        // Геттер для ID
        int getId() const;
    };
    
    // Класс Круг, наследуется от Shape
    // class = определение класса
    // Circle = имя класса
    // : = наследование
    // public Shape = публичное наследование от Shape
    class Circle : public Shape {
    // private: = приватные члены (доступны только внутри класса)
    private:
        // double = число с плавающей точкой
        // radius = радиус круга
        double radius;
        
    public:
        // Конструктор круга
        // Circle = имя конструктора
        // const std::string& = имя круга
        // double = радиус круга
        Circle(const std::string& circleName, double circleRadius);
        
        // Переопределение виртуальной функции
        // override = явное указание на переопределение (C++11)
        double calculateArea() const override;
        
        // Переопределение функции периметра
        double calculatePerimeter() const override;
        
        // Сеттер для радиуса
        // void = не возвращает значение
        // setRadius = имя функции
        void setRadius(double newRadius);
        
        // Геттер для радиуса
        double getRadius() const;
    };
    
    // Класс Прямоугольник
    class Rectangle : public Shape {
    private:
        // Два измерения прямоугольника
        double width;
        double height;
        
    public:
        // Конструктор прямоугольника
        Rectangle(const std::string& rectName, double rectWidth, double rectHeight);
        
        // Переопределение виртуальных функций
        double calculateArea() const override;
        double calculatePerimeter() const override;
        
        // Метод для проверки, является ли квадратом
        bool isSquare() const;
        
        // Геттеры
        double getWidth() const;
        double getHeight() const;
        
        // Сеттеры
        void setDimensions(double newWidth, double newHeight);
    };
    
    // Класс Треугольник
    class Triangle : public Shape {
    private:
        // Три стороны треугольника
        double sideA;
        double sideB;
        double sideC;
        
    public:
        // Конструктор треугольника
        Triangle(const std::string& triName, double a, double b, double c);
        
        // Переопределение виртуальных функций
        double calculateArea() const override;
        double calculatePerimeter() const override;
        
        // Метод для проверки типа треугольника
        std::string getTriangleType() const;
        
        // Проверка на прямоугольный треугольник
        bool isRightAngled() const;
    };
    
} // Конец пространства имён Geometry

#endif // SHAPES_H
```

### Файл 3: `include/operations.h`

```cpp
#ifndef OPERATIONS_H
#define OPERATIONS_H

// Включаем заголовок shapes.h для использования классов фигур
#include "shapes.h"

// Пространство имён для математических операций
namespace Geometry {
    
    // Класс для математических операций с фигурами
    class GeometryOperations {
    public:
        // Статический метод для сравнения площадей двух фигур
        // static = метод класса (не требует создания объекта)
        // int = возвращает целое число (-1, 0, 1)
        // compareAreas = имя функции
        // const Shape& = константная ссылка на фигуру
        static int compareAreas(const Shape& shape1, const Shape& shape2);
        
        // Статический метод для вычисления суммы площадей
        static double sumAreas(const Shape& shape1, const Shape& shape2);
        
        // Статический метод для масштабирования фигуры
        // Принимает указатель на фигуру (можно изменить)
        static void scaleShape(Shape* shape, double factor);
        
        // Шаблонная функция для работы с массивом фигур
        // template = объявление шаблона
        // <typename T> = параметр шаблона (тип)
        // T = может быть любым типом, наследником Shape
        template<typename T>
        static double calculateTotalArea(const T* shapes, int count) {
            // double = возвращаемый тип
            double total = 0.0;  // Инициализация переменной
            
            // for = цикл
            // int i = 0 = инициализация счётчика
            // i < count = условие продолжения
            // i++ = инкремент на каждой итерации
            for (int i = 0; i < count; i++) {
                // total += shapes[i].calculateArea();
                // += = оператор присваивания с сложением
                total += shapes[i].calculateArea();
            }
            
            // return = возврат значения из функции
            return total;
        }
    };
    
    // Отдельные функции вне класса
    // extern = объявление функции (определение в другом файле)
    extern void demonstrateOperations();
    
} // Конец пространства имён Geometry

#endif // OPERATIONS_H
```

### Файл 4: `src/shapes.cpp`

```cpp
// Подключаем заголовочный файл shapes.h
// #include = директива препроцессора для включения файла
#include "../include/shapes.h"  // .. = на уровень выше, затем include/shapes.h

// Используем пространство имён std для удобства
// using namespace = директива использования пространства имён
using namespace std;  // Теперь можно писать cout вместо std::cout

// Определяем статическую переменную класса Shape
// int = тип переменной
// Geometry::Shape::nextId = полное квалифицированное имя
// = 1 = инициализация значением 1
int Geometry::Shape::nextId = 1;

// Реализация конструктора класса Shape
// Geometry::Shape::Shape = конструктор Shape в пространстве имён Geometry
// : = список инициализации
// name(shapeName) = инициализация поля name параметром shapeName
// , = разделитель
// id(nextId++) = инициализация id значением nextId с последующим увеличением
Geometry::Shape::Shape(const string& shapeName) 
    : name(shapeName), id(nextId++) {
    // Тело конструктора (пустое в данном случае)
}

// Реализация деструктора класса Shape
// Geometry::Shape::~Shape = деструктор Shape
Geometry::Shape::~Shape() {
    // Вывод отладочной информации
    // cout = стандартный поток вывода (console output)
    cout << "Фигура \"" << name << "\" (ID: " << id << ") уничтожена" << endl;
}

// Реализация метода calculatePerimeter()
// double = возвращаемый тип
// Geometry::Shape::calculatePerimeter = метод класса Shape
// const = метод не изменяет объект
double Geometry::Shape::calculatePerimeter() const {
    // Базовая реализация возвращает 0
    // return = оператор возврата значения
    return 0.0;
}

// Реализация метода displayInfo()
// void = функция не возвращает значение
void Geometry::Shape::displayInfo() const {
    // Вывод информации о фигуре
    cout << "Фигура: " << name << " (ID: " << id << ")" << endl;
    // Вызов виртуальной функции calculateArea()
    // this = указатель на текущий объект
    // -> = оператор доступа к члену через указатель
    cout << "Площадь: " << this->calculateArea() << endl;
    cout << "Периметр: " << this->calculatePerimeter() << endl;
}

// Реализация геттера для имени
// const string& = возвращает константную ссылку на строку
const string& Geometry::Shape::getName() const {
    // return = возврат значения
    return name;
}

// Реализация геттера для ID
// int = возвращаемый тип
int Geometry::Shape::getId() const {
    return id;
}

// Реализация конструктора класса Circle
// Geometry::Circle::Circle = конструктор Circle
// : Shape(circleName) = вызов конструктора базового класса
// , radius(circleRadius) = инициализация поля radius
Geometry::Circle::Circle(const string& circleName, double circleRadius)
    : Shape(circleName), radius(circleRadius) {
    // Проверка корректности радиуса
    // if = условный оператор
    // radius <= 0 = условие
    if (radius <= 0) {
        // throw = оператор выбрасывания исключения
        // invalid_argument = тип исключения (неправильный аргумент)
        throw invalid_argument("Радиус должен быть положительным числом");
    }
}

// Реализация метода calculateArea() для Circle
// override = указание на переопределение виртуальной функции
double Geometry::Circle::calculateArea() const {
    // Формула площади круга: π * r²
    // PI * radius * radius = вычисление площади
    return Geometry::PI * radius * radius;
}

// Реализация метода calculatePerimeter() для Circle
double Geometry::Circle::calculatePerimeter() const {
    // Формула длины окружности: 2 * π * r
    return 2 * Geometry::PI * radius;
}

// Реализация сеттера для радиуса
// void = функция не возвращает значение
void Geometry::Circle::setRadius(double newRadius) {
    // Проверка корректности нового радиуса
    if (newRadius <= 0) {
        throw invalid_argument("Радиус должен быть положительным числом");
    }
    // Присваивание нового значения полю radius
    radius = newRadius;
}

// Реализация геттера для радиуса
double Geometry::Circle::getRadius() const {
    return radius;
}

// Реализация конструктора класса Rectangle
Geometry::Rectangle::Rectangle(const string& rectName, double rectWidth, double rectHeight)
    : Shape(rectName), width(rectWidth), height(rectHeight) {
    // Проверка корректности размеров
    if (width <= 0 || height <= 0) {
        throw invalid_argument("Ширина и высота должны быть положительными числами");
    }
}

// Реализация метода calculateArea() для Rectangle
double Geometry::Rectangle::calculateArea() const {
    // Площадь прямоугольника: ширина * высота
    return width * height;
}

// Реализация метода calculatePerimeter() для Rectangle
double Geometry::Rectangle::calculatePerimeter() const {
    // Периметр прямоугольника: 2 * (ширина + высота)
    return 2 * (width + height);
}

// Реализация метода isSquare() для Rectangle
// bool = возвращаемый тип (логический: true/false)
bool Geometry::Rectangle::isSquare() const {
    // Проверка равенства ширины и высоты
    // == = оператор сравнения на равенство
    return width == height;
}

// Реализация геттеров для Rectangle
double Geometry::Rectangle::getWidth() const {
    return width;
}

double Geometry::Rectangle::getHeight() const {
    return height;
}

// Реализация сеттера для Rectangle
void Geometry::Rectangle::setDimensions(double newWidth, double newHeight) {
    // Проверка корректности новых размеров
    if (newWidth <= 0 || newHeight <= 0) {
        throw invalid_argument("Ширина и высота должны быть положительными числами");
    }
    // Присваивание новых значений
    width = newWidth;
    height = newHeight;
}

// Реализация конструктора класса Triangle
Geometry::Triangle::Triangle(const string& triName, double a, double b, double c)
    : Shape(triName), sideA(a), sideB(b), sideC(c) {
    // Проверка корректности сторон треугольника
    if (sideA <= 0 || sideB <= 0 || sideC <= 0) {
        throw invalid_argument("Все стороны треугольника должны быть положительными числами");
    }
    
    // Проверка неравенства треугольника
    // a + b > c, a + c > b, b + c > a
    if (sideA + sideB <= sideC || 
        sideA + sideC <= sideB || 
        sideB + sideC <= sideA) {
        throw invalid_argument("Неравенство треугольника не выполняется");
    }
}

// Реализация метода calculateArea() для Triangle
double Geometry::Triangle::calculateArea() const {
    // Формула Герона для площади треугольника
    // p = полупериметр
    double p = (sideA + sideB + sideC) / 2;
    
    // sqrt = функция квадратного корня из cmath
    // Формула: √(p(p-a)(p-b)(p-c))
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

// Реализация метода calculatePerimeter() для Triangle
double Geometry::Triangle::calculatePerimeter() const {
    // Периметр треугольника: сумма всех сторон
    return sideA + sideB + sideC;
}

// Реализация метода getTriangleType() для Triangle
string Geometry::Triangle::getTriangleType() const {
    // Проверка типа треугольника по сторонам
    if (sideA == sideB && sideB == sideC) {
        return "Равносторонний";
    } else if (sideA == sideB || sideA == sideC || sideB == sideC) {
        return "Равнобедренный";
    } else {
        return "Разносторонний";
    }
}

// Реализация метода isRightAngled() для Triangle
bool Geometry::Triangle::isRightAngled() const {
    // Проверка теоремы Пифагора для всех комбинаций сторон
    // Проверяем, является ли треугольник прямоугольным
    
    // Массив сторон для удобства проверки
    double sides[3] = {sideA, sideB, sideC};
    
    // Проверяем все комбинации
    for (int i = 0; i < 3; i++) {
        // Вычисляем квадраты сторон
        double a2 = sides[i] * sides[i];
        double b2 = sides[(i + 1) % 3] * sides[(i + 1) % 3];
        double c2 = sides[(i + 2) % 3] * sides[(i + 2) % 3];
        
        // Проверяем теорему Пифагора с небольшой погрешностью
        const double epsilon = 0.0001;
        if (abs(a2 + b2 - c2) < epsilon) {
            return true;
        }
    }
    
    return false;
}
```

### Файл 5: `src/operations.cpp`

```cpp
// Подключаем заголовочный файл operations.h
#include "../include/operations.h"

// Используем пространство имён std
using namespace std;

// Реализация метода compareAreas()
// int = возвращаемый тип
// Geometry::GeometryOperations::compareAreas = полное имя метода
int Geometry::GeometryOperations::compareAreas(const Shape& shape1, const Shape& shape2) {
    // Вычисляем площади обеих фигур
    // shape1.calculateArea() = вызов виртуального метода
    double area1 = shape1.calculateArea();
    double area2 = shape2.calculateArea();
    
    // Сравниваем площади
    // if = условный оператор
    if (area1 > area2) {
        return 1;  // Первая фигура имеет большую площадь
    } else if (area1 < area2) {
        return -1; // Вторая фигура имеет большую площадь
    } else {
        return 0;  // Площади равны
    }
}

// Реализация метода sumAreas()
double Geometry::GeometryOperations::sumAreas(const Shape& shape1, const Shape& shape2) {
    // Суммируем площади обеих фигур
    return shape1.calculateArea() + shape2.calculateArea();
}

// Реализация метода scaleShape()
// void = функция не возвращает значение
// Shape* = указатель на объект Shape
// shape = параметр-указатель
// double factor = коэффициент масштабирования
void Geometry::GeometryOperations::scaleShape(Shape* shape, double factor) {
    // Проверка указателя на nullptr (нулевой указатель)
    // if = условный оператор
    // !shape = если shape равен nullptr
    if (!shape) {
        // throw = выбрасывание исключения
        throw invalid_argument("Указатель на фигуру не может быть nullptr");
    }
    
    // Проверка корректности коэффициента
    if (factor <= 0) {
        throw invalid_argument("Коэффициент масштабирования должен быть положительным");
    }
    
    // Приведение типа для доступа к специфичным методам
    // dynamic_cast = динамическое приведение типа (во время выполнения)
    // <Circle*> = попытка привести к указателю на Circle
    Circle* circle = dynamic_cast<Circle*>(shape);
    if (circle) {
        // Если фигура - круг, масштабируем радиус
        double newRadius = circle->getRadius() * factor;
        circle->setRadius(newRadius);
        return;
    }
    
    // Проверка для прямоугольника
    Rectangle* rectangle = dynamic_cast<Rectangle*>(shape);
    if (rectangle) {
        // Если фигура - прямоугольник, масштабируем оба измерения
        double newWidth = rectangle->getWidth() * factor;
        double newHeight = rectangle->getHeight() * factor;
        rectangle->setDimensions(newWidth, newHeight);
        return;
    }
    
    // Для треугольника масштабирование не поддерживается
    // (можно было бы добавить, но для примера оставим так)
    throw runtime_error("Масштабирование не поддерживается для этого типа фигуры");
}

// Реализация функции demonstrateOperations()
void Geometry::demonstrateOperations() {
    // Создание фигур для демонстрации операций
    // try = начало блока обработки исключений
    try {
        // Создаём круг с радиусом 5
        Circle circle("Круг 1", 5.0);
        // Создаём прямоугольник 3x4
        Rectangle rectangle("Прямоугольник 1", 3.0, 4.0);
        // Создаём треугольник со сторонами 3,4,5
        Triangle triangle("Треугольник 1", 3.0, 4.0, 5.0);
        
        // Демонстрация сравнения площадей
        printHeader("Сравнение площадей");
        int comparison = GeometryOperations::compareAreas(circle, rectangle);
        cout << "Сравнение круга и прямоугольника: ";
        // switch = оператор выбора
        switch (comparison) {
            case 1:
                cout << "круг больше" << endl;
                break;
            case -1:
                cout << "прямоугольник больше" << endl;
                break;
            case 0:
                cout << "площади равны" << endl;
                break;
        }
        
        // Демонстрация суммы площадей
        printHeader("Сумма площадей");
        double totalArea = GeometryOperations::sumAreas(circle, triangle);
        cout << "Сумма площадей круга и треугольника: " << totalArea << endl;
        
        // Демонстрация масштабирования
        printHeader("Масштабирование фигур");
        cout << "До масштабирования:" << endl;
        circle.displayInfo();
        
        // Масштабируем круг в 2 раза
        GeometryOperations::scaleShape(&circle, 2.0);
        
        cout << "\nПосле масштабирования (2x):" << endl;
        circle.displayInfo();
        
        // Демонстрация работы с массивом фигур
        printHeader("Работа с массивом фигур");
        
        // Создаём массив указателей на фигуры
        // Shape* = указатель на базовый класс
        // [] = массив
        // 3 = размер массива
        Shape* shapes[] = {&circle, &rectangle, &triangle};
        
        double arrayTotal = 0;
        // for = цикл по массиву
        // auto = автоматическое определение типа (C++11)
        // shape = текущий указатель
        // : shapes = диапазон для итерации
        for (auto shape : shapes) {
            arrayTotal += shape->calculateArea();
        }
        
        cout << "Общая площадь всех фигур: " << arrayTotal << endl;
        
    // catch = блок обработки исключений
    // const exception& = ловим все исключения, производные от exception
    // e = объект исключения
    } catch (const exception& e) {
        // cerr = стандартный поток ошибок (console error)
        cerr << "Ошибка: " << e.what() << endl;
    }
}
```

### Файл 6: `src/main.cpp`

```cpp
// Главный файл программы - точка входа

// Подключаем основной заголовочный файл нашей библиотеки
#include "../include/geometry.h"

// Используем пространство имён std для удобства
using namespace std;

// Главная функция программы
// int = возвращаемый тип (код завершения)
// main = имя функции (точка входа)
// () = пустой список параметров
int main() {
    // Вывод приветственного сообщения
    cout << "========================================" << endl;
    cout << "   Геометрическая библиотека v1.0" << endl;
    cout << "========================================" << endl;
    
    // Демонстрация работы библиотеки
    // try = попытка выполнения кода с возможными исключениями
    try {
        // Демонстрация работы с фигурами
        Geometry::printHeader("Создание и работа с фигурами");
        
        // 1. Создание круга
        cout << "\n1. Создание круга:" << endl;
        // Geometry::Circle = полное имя класса
        // circle = имя переменной
        // ("Большой круг", 10.0) = вызов конструктора
        Geometry::Circle circle("Большой круг", 10.0);
        // Вызов метода displayInfo()
        circle.displayInfo();
        // Вызов специфичного метода круга
        cout << "Радиус круга: " << circle.getRadius() << endl;
        
        // 2. Создание прямоугольника
        cout << "\n2. Создание прямоугольника:" << endl;
        Geometry::Rectangle rectangle("Прямоугольник А", 6.0, 8.0);
        rectangle.displayInfo();
        // Проверка, является ли квадратом
        // if = условный оператор
        if (rectangle.isSquare()) {
            cout << "Это квадрат!" << endl;
        } else {
            cout << "Это не квадрат" << endl;
        }
        
        // 3. Создание треугольника
        cout << "\n3. Создание треугольника:" << endl;
        Geometry::Triangle triangle("Треугольник Б", 5.0, 12.0, 13.0);
        triangle.displayInfo();
        cout << "Тип треугольника: " << triangle.getTriangleType() << endl;
        // Проверка на прямоугольность
        if (triangle.isRightAngled()) {
            cout << "Это прямоугольный треугольник" << endl;
        }
        
        // 4. Работа с массивом фигур через базовый класс
        Geometry::printHeader("Полиморфизм: работа через базовый класс");
        
        // Создаём массив указателей на базовый класс
        // new = динамическое выделение памяти
        Geometry::Shape* shapes[3];
        shapes[0] = new Geometry::Circle("Маленький круг", 3.0);
        shapes[1] = new Geometry::Rectangle("Квадрат", 4.0, 4.0);
        shapes[2] = new Geometry::Triangle("Треугольник С", 6.0, 8.0, 10.0);
        
        // Проходим по массиву и вызываем виртуальные методы
        // for = цикл
        // int i = 0 = инициализация счётчика
        // i < 3 = условие продолжения
        // i++ = увеличение счётчика
        for (int i = 0; i < 3; i++) {
            cout << "\nФигура #" << (i + 1) << ":" << endl;
            // shapes[i] = указатель на i-й элемент
            // -> = оператор доступа через указатель
            shapes[i]->displayInfo();
        }
        
        // 5. Демонстрация математических операций
        Geometry::printHeader("Математические операции");
        // Вызов функции демонстрации операций
        Geometry::demonstrateOperations();
        
        // 6. Освобождение динамически выделенной памяти
        Geometry::printHeader("Очистка памяти");
        for (int i = 0; i < 3; i++) {
            // delete = освобождение памяти
            delete shapes[i];
            cout << "Память для фигуры #" << (i + 1) << " освобождена" << endl;
        }
        
        // 7. Демонстрация обработки исключений
        Geometry::printHeader("Обработка исключений");
        
        try {
            // Попытка создать фигуру с некорректными параметрами
            cout << "\nПопытка создать круг с отрицательным радиусом:" << endl;
            Geometry::Circle badCircle("Некорректный круг", -5.0);
        } 
        // catch = обработка исключения
        // const invalid_argument& = конкретный тип исключения
        // e = объект исключения
        catch (const invalid_argument& e) {
            cerr << "Поймано исключение: " << e.what() << endl;
        }
        
        try {
            // Попытка создать некорректный треугольник
            cout << "\nПопытка создать невозможный треугольник:" << endl;
            Geometry::Triangle badTriangle("Невозможный", 1.0, 2.0, 10.0);
        } catch (const invalid_argument& e) {
            cerr << "Поймано исключение: " << e.what() << endl;
        }
        
    // Обработка любых других исключений
    } catch (const exception& e) {
        cerr << "\n!!! Неожиданная ошибка: " << e.what() << endl;
        return 1;  // Возвращаем код ошибки
    }
    
    // Финальное сообщение
    cout << "\n========================================" << endl;
    cout << "   Программа успешно завершена!" << endl;
    cout << "========================================" << endl;
    
    // return = возврат из функции
    // 0 = код успешного завершения
    return 0;
}
```

### Файл 7: `README.md` (документация проекта)

```markdown
# Геометрическая библиотека на C++

## Описание проекта
Проект демонстрирует создание многофайловой структуры на C++ с использованием пространств имён. Библиотека предоставляет классы для работы с геометрическими фигурами и операции над ними.

## Структура проекта

```
geometry_library/
├── include/           # Заголовочные файлы (.h)
│   ├── geometry.h    # Основные объявления и константы
│   ├── shapes.h      # Классы фигур (базовый и производные)
│   └── operations.h  # Математические операции
├── src/              # Файлы реализации (.cpp)
│   ├── shapes.cpp    # Реализация методов фигур
│   ├── operations.cpp # Реализация операций
│   └── main.cpp      # Главная программа для демонстрации
└── README.md         # Этот файл
```

## Ключевые концепции C++ в проекте

### 1. Многофайловая структура
- **Разделение интерфейса и реализации**: заголовочные файлы (.h) содержат объявления, файлы реализации (.cpp) содержат определения
- **Include guards**: защита от множественного включения через `#ifndef/#define/#endif`
- **Относительные пути**: использование `../include/` для доступа к заголовкам

### 2. Пространства имён (Namespaces)
- **`namespace Geometry`**: основное пространство имён для всей библиотеки
- **Вложенные пространства**: возможность организации кода внутри пространств имён
- **Квалифицированные имена**: `Geometry::Circle`, `Geometry::Shape`

### 3. Классы и наследование
- **Абстрактный базовый класс**: `Shape` с чисто виртуальными методами
- **Наследование**: `Circle`, `Rectangle`, `Triangle` наследуются от `Shape`
- **Полиморфизм**: работа с фигурами через указатели на базовый класс

### 4. Ключевое слово static
- **Статические члены класса**: `Shape::nextId` - общий счётчик для всех объектов
- **Статические методы**: `GeometryOperations::compareAreas()` - методы класса

### 5. Обработка исключений
- **`try/catch`**: обработка ошибок времени выполнения
- **`throw`**: генерация исключений при некорректных параметрах

## Компиляция и запуск

### Для Linux/macOS:
```bash
g++ -std=c++11 -I./include src/*.cpp -o geometry_app
./geometry_app
```

### Для Windows (MinGW):
```bash
g++ -std=c++11 -I./include src/*.cpp -o geometry_app.exe
geometry_app.exe
```

### Для Visual Studio:
1. Создать новый проект C++
2. Добавить все файлы из `include/` и `src/`
3. Настроить пути включения (`Additional Include Directories`)
4. Скомпилировать и запустить

## Пример вывода программы

```
========================================
   Геометрическая библиотека v1.0
========================================

=== Создание и работа с фигурами ===

1. Создание круга:
Фигура: Большой круг (ID: 1)
Площадь: 314.159
Периметр: 62.8319
Радиус круга: 10

2. Создание прямоугольника:
Фигура: Прямоугольник А (ID: 2)
Площадь: 48
Периметр: 28
Это не квадрат

... и т.д.
```

## Задания для самостоятельной работы

1. **Добавьте новую фигуру** (например, `Ellipse` или `Square`)
2. **Реализуйте новые операции** (например, пересечение фигур)
3. **Добавьте сериализацию** (сохранение фигур в файл)
4. **Создайте юнит-тесты** для проверки корректности вычислений
5. **Реализуйте паттерн "Фабрика"** для создания фигур

## Примечания

- Проект использует стандарт C++11
- Все исключения обрабатываются в main()
- Память динамически выделенных объектов освобождается
- Код содержит подробные комментарии для обучения

## Автор
[Cтудент/Разработчик]

## Лицензия
Учебный проект для освоения C++
```

## Инструкция по сборке и запуску

### Шаг 1: Создание структуры проекта
```bash
mkdir geometry_library
cd geometry_library
mkdir include src
```

### Шаг 2: Создание файлов
Скопируйте код из каждого раздела в соответствующие файлы.

### Шаг 3: Компиляция (Linux/macOS)
```bash
# Компилируем все .cpp файлы вместе
g++ -std=c++11 -I./include src/shapes.cpp src/operations.cpp src/main.cpp -o geometry_app

# Или по отдельности (рекомендуется для больших проектов)
g++ -std=c++11 -I./include -c src/shapes.cpp -o shapes.o
g++ -std=c++11 -I./include -c src/operations.cpp -o operations.o
g++ -std=c++11 -I./include -c src/main.cpp -o main.o
g++ shapes.o operations.o main.o -o geometry_app
```

### Шаг 4: Запуск
```bash
./geometry_app
```

## Что изучается в этой работе:

1. **Организация кода в несколько файлов**
2. **Разделение заголовочных файлов (.h) и файлов реализации (.cpp)**
3. **Использование пространств имён для избежания конфликтов**
4. **Создание иерархии классов с наследованием**
5. **Работа с виртуальными функциями и полиморфизмом**
6. **Использование статических членов и методов**
7. **Обработка исключений**
8. **Шаблонные функции**
9. **Динамическое выделение и освобождение памяти**
10. **Создание библиотеки с чётким API**

Эта практическая работа охватывает все основные аспекты создания реальных проектов на C++ и даёт понимание того, как организовывать код в профессиональных разработках.