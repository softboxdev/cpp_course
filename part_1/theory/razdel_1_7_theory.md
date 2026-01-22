# Подробный разбор: Локальные/глобальные переменные, static, extern, namespace в C++

## Часть 1: Локальные и глобальные переменные

### 1.1 Базовые понятия

```cpp
// global_variables.cpp
#include <iostream>
using namespace std;

// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ - объявлены вне всех функций
int global_counter = 0;          // Инициализированная глобальная переменная
double global_pi = 3.14159;      // Еще одна глобальная
const int MAX_SIZE = 100;        // Глобальная константа

// Глобальные переменные:
// 1. Видны во ВСЕХ функциях файла
// 2. Существуют всю программу
// 3. Инициализируются при запуске программы
// 4. По умолчанию инициализируются нулями

void demonstrateLocalGlobal() {
    cout << "=== ЛОКАЛЬНЫЕ и ГЛОБАЛЬНЫЕ переменные ===\n" << endl;
    
    // ЛОКАЛЬНЫЕ ПЕРЕМЕННЫЕ - объявлены внутри функции
    int local_var = 42;          // Локальная переменная
    double local_temp = 25.5;    // Еще одна локальная
    
    cout << "Глобальные переменные в функции:" << endl;
    cout << "global_counter = " << global_counter << endl;
    cout << "global_pi = " << global_pi << endl;
    cout << "MAX_SIZE = " << MAX_SIZE << endl;
    
    cout << "\nЛокальные переменные:" << endl;
    cout << "local_var = " << local_var << endl;
    cout << "local_temp = " << local_temp << endl;
    
    // Изменяем глобальную переменную
    global_counter++;
    cout << "\nПосле global_counter++: " << global_counter << endl;
    
    // Локальная переменная перекрывает глобальную (если имена совпадают)
    double global_pi = 3.14;  // Это НОВАЯ локальная переменная!
    cout << "Локальная global_pi = " << global_pi 
         << " (скрыла глобальную)" << endl;
    
    // Чтобы получить доступ к глобальной переменной, используем ::
    cout << "Глобальная global_pi = " << ::global_pi << endl;
    
    // Область видимости локальных переменных
    {
        int block_var = 100;  // Локальная переменная в блоке
        cout << "\nВнутри блока:" << endl;
        cout << "block_var = " << block_var << endl;
        cout << "local_var (из внешней области) = " << local_var << endl;
        
        // block_var видна ТОЛЬКО внутри этого блока
    }
    
    // ОШИБКА: block_var не видна здесь!
    // cout << block_var << endl;  // Компилятор выдаст ошибку
    
    cout << "\nВыход из функции - локальные переменные уничтожаются!" << endl;
    cout << "Глобальные переменные сохраняют значения." << endl;
}

void anotherFunction() {
    cout << "\n--- В другой функции ---" << endl;
    
    // Здесь тоже видна global_counter
    cout << "global_counter = " << global_counter << endl;
    
    // А local_var из demonstrateLocalGlobal НЕ видна!
    // cout << local_var << endl;  // ОШИБКА!
    
    // Можно создать свою локальную с таким же именем
    int global_counter = 999;  // Это другая переменная!
    cout << "Локальная global_counter = " << global_counter << endl;
    cout << "Глобальная global_counter = " << ::global_counter << endl;
}

// Пример с параметрами функции
void functionWithParams(int param1, double param2) {
    cout << "\n--- Функция с параметрами ---" << endl;
    // param1 и param2 - локальные переменные функции
    cout << "param1 = " << param1 << ", param2 = " << param2 << endl;
    
    // Параметры можно изменять
    param1 = 100;
    param2 = 200.5;
    cout << "После изменения: param1 = " << param1 
         << ", param2 = " << param2 << endl;
}

int main() {
    demonstrateLocalGlobal();
    anotherFunction();
    
    // Вызываем функцию с параметрами
    int x = 10;
    double y = 20.5;
    functionWithParams(x, y);
    
    // x и y не изменились (переданы по значению)
    cout << "\nПосле вызова функции:" << endl;
    cout << "x = " << x << " (не изменился)" << endl;
    cout << "y = " << y << " (не изменился)" << endl;
    
    // Еще раз вызовем первую функцию
    cout << "\n--- Повторный вызов demonstrateLocalGlobal ---" << endl;
    demonstrateLocalGlobal();
    // global_counter сохранила увеличенное значение!
    
    return 0;
}
```

### 1.2 Области видимости

```cpp
// scope_examples.cpp
#include <iostream>
using namespace std;

// Глобальная область видимости (файловая)
int global_x = 100;

namespace Outer {
    int namespace_var = 200;
    
    namespace Inner {
        int nested_var = 300;
    }
}

void scopeExamples() {
    cout << "=== РАЗНЫЕ ОБЛАСТИ ВИДИМОСТИ ===\n" << endl;
    
    // 1. Область видимости функции
    int function_scope = 10;
    cout << "function_scope = " << function_scope << endl;
    
    // 2. Область видимости блока
    {
        int block_scope = 20;
        cout << "block_scope = " << block_scope << endl;
        
        // Видны переменные из внешних областей
        cout << "function_scope (из блока) = " << function_scope << endl;
        cout << "global_x (из блока) = " << global_x << endl;
        
        // Можно скрыть переменную из внешней области
        int global_x = 999;  // Локальная в блоке
        cout << "Локальная global_x = " << global_x << endl;
        cout << "Глобальная global_x = " << ::global_x << endl;
    }
    
    // 3. Область видимости цикла
    for(int i = 0; i < 3; i++) {
        int loop_var = i * 10;
        cout << "Цикл " << i << ": loop_var = " << loop_var << endl;
        
        // i видна только внутри цикла
    }
    
    // ОШИБКА: i не видна вне цикла
    // cout << i << endl;
    
    // 4. Область видимости условия
    if(true) {
        int if_scope = 50;
        cout << "if_scope = " << if_scope << endl;
    }
    
    // ОШИБКА: if_scope не видна
    // cout << if_scope << endl;
    
    // 5. Одновременное существование разных областей
    int x = 1;  // Внешняя область
    
    {
        int x = 2;  // Внутренняя область (скрывает внешнюю)
        cout << "\nВо внутреннем блоке:" << endl;
        cout << "Внутренняя x = " << x << endl;
        
        {
            int x = 3;  // Еще более внутренняя
            cout << "В самом внутреннем блоке:" << endl;
            cout << "Самая внутренняя x = " << x << endl;
        }
        
        cout << "Снова во внутреннем блоке:" << endl;
        cout << "Внутренняя x = " << x << " (внешняя все еще скрыта)" << endl;
    }
    
    cout << "Снова во внешней области:" << endl;
    cout << "Внешняя x = " << x << endl;
}

void shadowingExample() {
    cout << "\n=== ПЕРЕКРЫВАНИЕ ПЕРЕМЕННЫХ (shadowing) ===\n" << endl;
    
    int var = 100;
    cout << "Уровень 1: var = " << var << endl;
    
    {
        int var = 200;  // Перекрывает внешнюю var
        cout << "Уровень 2: var = " << var << endl;
        
        // Можно получить доступ к внешней через новую переменную?
        // НЕТ! В C++ нет прямого способа
        
        {
            int var = 300;  // Перекрывает обе внешние
            cout << "Уровень 3: var = " << var << endl;
        }
        
        cout << "Снова уровень 2: var = " << var << endl;
    }
    
    cout << "Снова уровень 1: var = " << var << endl;
    
    // Рекомендация: избегайте перекрывания!
    // Используйте разные имена для ясности кода
}

int main() {
    scopeExamples();
    shadowingExample();
    return 0;
}
```

## Часть 2: Ключевое слово static

### 2.1 static локальные переменные

```cpp
// static_local.cpp
#include <iostream>
using namespace std;

void counterFunction() {
    // ОБЫЧНАЯ локальная переменная
    int normal_counter = 0;
    
    // STATIC локальная переменная
    static int static_counter = 0;
    
    normal_counter++;
    static_counter++;
    
    cout << "normal_counter = " << normal_counter;
    cout << ", static_counter = " << static_counter << endl;
}

void staticLocalDemo() {
    cout << "=== STATIC локальные переменные ===\n" << endl;
    
    cout << "Вызываем функцию 5 раз:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Вызов " << (i + 1) << ": ";
        counterFunction();
    }
    
    cout << "\nРАЗНИЦА:" << endl;
    cout << "1. normal_counter создается заново каждый вызов" << endl;
    cout << "2. static_counter инициализируется один раз и сохраняет значение" << endl;
    cout << "3. static_counter существует между вызовами функции" << endl;
}

void initializationDemo() {
    cout << "\n=== ИНИЦИАЛИЗАЦИЯ static переменных ===\n" << endl;
    
    // static переменные инициализируются при ПЕРВОМ вызове функции
    for(int i = 0; i < 3; i++) {
        static int initialized_once = []() {
            cout << "Инициализация static переменной!" << endl;
            return 42;
        }();  // Вызывается один раз!
        
        cout << "Вызов " << (i + 1) << ": value = " << initialized_once << endl;
        initialized_once++;
    }
}

void complexStaticExample() {
    cout << "\n=== СЛОЖНЫЙ ПРИМЕР со static ===\n" << endl;
    
    // Функция, которая запоминает предыдущее значение
    static int previous_value = 0;
    
    auto getNextId = []() {
        static int id_counter = 1000;  // Начинаем с 1000
        return id_counter++;
    };
    
    auto getAverage = [](int new_value) {
        static int sum = 0;
        static int count = 0;
        
        sum += new_value;
        count++;
        
        return static_cast<double>(sum) / count;
    };
    
    cout << "Генерация ID:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "ID " << (i + 1) << ": " << getNextId() << endl;
    }
    
    cout << "\nВычисление среднего:" << endl;
    int values[] = {10, 20, 30, 40, 50};
    for(int value : values) {
        double avg = getAverage(value);
        cout << "После добавления " << value 
             << ": среднее = " << avg << endl;
    }
}

class StaticInClass {
public:
    void normalMethod() {
        int local = 0;
        static int static_local = 0;
        
        local++;
        static_local++;
        
        cout << "local = " << local 
             << ", static_local = " << static_local << endl;
    }
};

void staticInMethods() {
    cout << "\n=== STATIC в методах класса ===\n" << endl;
    
    StaticInClass obj1, obj2;
    
    cout << "Объект 1:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Вызов " << (i + 1) << ": ";
        obj1.normalMethod();
    }
    
    cout << "\nОбъект 2:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Вызов " << (i + 1) << ": ";
        obj2.normalMethod();
    }
    
    cout << "\nВывод: static переменная ОБЩАЯ для всех объектов!" << endl;
}

int main() {
    staticLocalDemo();
    initializationDemo();
    complexStaticExample();
    staticInMethods();
    return 0;
}
```

### 2.2 static глобальные переменные и функции

```cpp
// static_global.cpp
#include <iostream>
using namespace std;

// ОБЫЧНАЯ глобальная переменная
int global_var = 100;  // Видна в других файлах при использовании extern

// STATIC глобальная переменная
static int static_global_var = 200;  // Видна ТОЛЬКО в этом файле

// Обычная функция
void normalFunction() {
    cout << "normalFunction() вызвана" << endl;
}

// Static функция
static void staticFunction() {
    cout << "staticFunction() вызвана" << endl;
}

// Функция для демонстрации
void demonstrateStaticGlobal() {
    cout << "=== STATIC глобальные переменные и функции ===\n" << endl;
    
    cout << "global_var = " << global_var << endl;
    cout << "static_global_var = " << static_global_var << endl;
    
    normalFunction();
    staticFunction();
    
    cout << "\nРАЗНИЦА:" << endl;
    cout << "1. global_var: видна в других файлах (если объявить extern)" << endl;
    cout << "2. static_global_var: видна ТОЛЬКО в этом файле" << endl;
    cout << "3. То же самое для функций" << endl;
    cout << "\nЭто называется 'internal linkage' (внутренняя линковка)" << endl;
}

// Пример использования static для скрытия реализации
namespace MathUtils {
    // Внутренняя (private) функция - не экспортируем
    static double validateInput(double x) {
        if(x < 0) {
            cerr << "Предупреждение: отрицательное значение" << endl;
            return 0;
        }
        return x;
    }
    
    // Публичные функции
    double sqrt(double x) {
        x = validateInput(x);
        // Упрощенная реализация
        double result = x;
        for(int i = 0; i < 10; i++) {
            result = (result + x / result) / 2;
        }
        return result;
    }
    
    double power(double base, int exp) {
        double result = 1;
        for(int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }
}

void staticForEncapsulation() {
    cout << "\n=== STATIC для скрытия реализации ===\n" << endl;
    
    cout << "Квадратный корень из 16: " << MathUtils::sqrt(16) << endl;
    cout << "2 в степени 5: " << MathUtils::power(2, 5) << endl;
    
    // НЕЛЬЗЯ вызвать validateInput извне!
    // MathUtils::validateInput(10);  // ОШИБКА!
    
    cout << "\nФункция validateInput скрыта (static)" << endl;
    cout << "Это помогает создавать чистые интерфейсы" << endl;
}

// Еще один пример: счетчик создания объектов
class ObjectCounter {
private:
    static int total_objects;     // Статическое поле класса
    static int active_objects;    // Еще одно статическое поле
    int id;
    
public:
    ObjectCounter() {
        total_objects++;
        active_objects++;
        id = total_objects;
        cout << "Создан объект #" << id << endl;
    }
    
    ~ObjectCounter() {
        active_objects--;
        cout << "Уничтожен объект #" << id << endl;
    }
    
    static int getTotalObjects() {
        return total_objects;
    }
    
    static int getActiveObjects() {
        return active_objects;
    }
    
    int getId() const {
        return id;
    }
};

// Инициализация статических полей класса
int ObjectCounter::total_objects = 0;
int ObjectCounter::active_objects = 0;

void staticClassMembers() {
    cout << "\n=== STATIC члены класса ===\n" << endl;
    
    cout << "До создания объектов:" << endl;
    cout << "Всего объектов: " << ObjectCounter::getTotalObjects() << endl;
    cout << "Активных объектов: " << ObjectCounter::getActiveObjects() << endl;
    
    {
        ObjectCounter obj1;
        ObjectCounter obj2;
        
        cout << "\nПосле создания двух объектов:" << endl;
        cout << "Всего объектов: " << ObjectCounter::getTotalObjects() << endl;
        cout << "Активных объектов: " << ObjectCounter::getActiveObjects() << endl;
        
        ObjectCounter obj3;
        cout << "\nПосле создания третьего объекта:" << endl;
        cout << "Всего объектов: " << ObjectCounter::getTotalObjects() << endl;
        cout << "Активных объектов: " << ObjectCounter::getActiveObjects() << endl;
    }
    
    cout << "\nПосле выхода из блока (уничтожения объектов):" << endl;
    cout << "Всего объектов: " << ObjectCounter::getTotalObjects() << endl;
    cout << "Активных объектов: " << ObjectCounter::getActiveObjects() << endl;
    
    cout << "\nОСОБЕННОСТИ статических членов класса:" << endl;
    cout << "1. Одна копия на весь класс (не на объект)" << endl;
    cout << "2. Существуют без создания объектов класса" << endl;
    cout << "3. Инициализируются вне класса" << endl;
    cout << "4. Вызываются через ClassName::member" << endl;
}

int main() {
    demonstrateStaticGlobal();
    staticForEncapsulation();
    staticClassMembers();
    return 0;
}
```

## Часть 3: Ключевое слово extern

### 3.1 Основы extern

**Файл 1: main.cpp**
```cpp
// main.cpp
#include <iostream>
using namespace std;

// Объявление extern переменных (без выделения памяти)
extern int shared_counter;     // Определена в другом файле
extern const double PI;        // Константа из другого файла
extern void helperFunction();  // Функция из другого файла

// Наша глобальная переменная
int global_in_main = 100;

// Функция, которую будем использовать в другом файле
void functionFromMain() {
    cout << "functionFromMain() вызвана" << endl;
    cout << "global_in_main = " << global_in_main << endl;
}

int main() {
    cout << "=== КЛЮЧЕВОЕ СЛОВО extern ===\n" << endl;
    
    cout << "До изменений:" << endl;
    cout << "shared_counter = " << shared_counter << endl;
    cout << "PI = " << PI << endl;
    
    // Меняем переменную из другого файла
    shared_counter = 999;
    cout << "\nПосле shared_counter = 999:" << endl;
    cout << "shared_counter = " << shared_counter << endl;
    
    // Вызываем функцию из другого файла
    cout << "\nВызываем helperFunction():" << endl;
    helperFunction();
    
    // Снова проверяем shared_counter
    cout << "\nПосле helperFunction():" << endl;
    cout << "shared_counter = " << shared_counter << endl;
    
    return 0;
}
```

**Файл 2: shared.cpp**
```cpp
// shared.cpp
#include <iostream>
using namespace std;

// Определение переменных (выделение памяти)
int shared_counter = 42;          // Глобальная переменная
const double PI = 3.1415926535;   // Глобальная константа

// Объявление функции из main.cpp
extern void functionFromMain();

// Функция, которая использует переменную из main.cpp
void helperFunction() {
    cout << "helperFunction() вызвана" << endl;
    
    // Используем и изменяем нашу переменную
    shared_counter++;
    cout << "shared_counter увеличен: " << shared_counter << endl;
    
    // Вызываем функцию из main.cpp
    cout << "\nВызываем functionFromMain() из helperFunction():" << endl;
    functionFromMain();
}
```

**Компиляция и запуск:**
```bash
g++ main.cpp shared.cpp -o extern_example
./extern_example
```

### 3.2 Практические примеры с extern

```cpp
// extern_examples.cpp
#include <iostream>
using namespace std;

// Пример 1: Разделение конфигурации по файлам

// config.h - заголовочный файл
#ifndef CONFIG_H
#define CONFIG_H

// Объявления (без extern в заголовочных файлах - они уже в declarations.h)
extern const char* APP_NAME;
extern const int MAX_USERS;
extern const double VERSION;

void printConfig();

#endif

// В реальном проекте эти определения были бы в config.cpp

// Пример 2: Общие ресурсы
extern int database_connection_count;  // Определено в database.cpp
extern void connectToDatabase();
extern void disconnectFromDatabase();

// Пример 3: Логирование
extern void logMessage(const char* message);
extern void setLogLevel(int level);

void demonstrateExtern() {
    cout << "=== ПРАКТИЧЕСКИЕ ПРИМЕРЫ extern ===\n" << endl;
    
    // Имитируем использование extern переменных
    cout << "Пример 1: Конфигурация приложения" << endl;
    cout << "APP_NAME, MAX_USERS, VERSION определены в другом файле" << endl;
    
    cout << "\nПример 2: Подсчет соединений с БД" << endl;
    cout << "database_connection_count отслеживается в database.cpp" << endl;
    
    cout << "\nПример 3: Система логирования" << endl;
    cout << "logMessage() и setLogLevel() реализованы в logger.cpp" << endl;
    
    cout << "\nПРЕИМУЩЕСТВА extern:" << endl;
    cout << "1. Разделение кода на несколько файлов" << endl;
    cout << "2. Общие ресурсы между модулями" << endl;
    cout << "3. Сокрытие реализации" << endl;
    cout << "4. Уменьшение времени компиляции" << endl;
}

// Пример с несколькими файлами
namespace Network {
    // Эти переменные определены в network.cpp
    extern int active_connections;
    extern int total_bytes_sent;
    
    void sendData(const char* data) {
        // Реализация в network.cpp
        cout << "Отправка данных: " << data << endl;
    }
}

void simulateNetworkUsage() {
    cout << "\n=== СИМУЛЯЦИЯ ИСПОЛЬЗОВАНИЯ extern ===\n" << endl;
    
    // Используем "внешние" функции и переменные
    cout << "Имитация работы сети..." << endl;
    
    // В реальном коде здесь были бы:
    // Network::sendData("Hello");
    // cout << "Активных соединений: " << Network::active_connections << endl;
    
    cout << "Все функции и переменные Network определены в network.cpp" << endl;
}

// Важное замечание о extern и const
void externAndConst() {
    cout << "\n=== extern И const ===\n" << endl;
    
    // Без extern const имеет internal linkage по умолчанию
    const int INTERNAL_CONST = 100;  // Только в этом файле
    
    // С extern const имеет external linkage
    extern const int EXTERNAL_CONST;  // Определена в другом файле
    
    cout << "INTERNAL_CONST видна только здесь" << endl;
    cout << "EXTERNAL_CONST может использоваться в других файлах" << endl;
}

int main() {
    demonstrateExtern();
    simulateNetworkUsage();
    externAndConst();
    return 0;
}
```

## Часть 4: Пространства имен (namespace)

### 4.1 Базовые namespace

```cpp
// namespace_basic.cpp
#include <iostream>
using namespace std;

// ГЛОБАЛЬНОЕ пространство имен (по умолчанию)
int global_var = 100;

// СОЗДАЕМ свое пространство имен
namespace MyMath {
    const double PI = 3.14159;
    
    double add(double a, double b) {
        return a + b;
    }
    
    double multiply(double a, double b) {
        return a * b;
    }
    
    // Вложенное пространство имен
    namespace Advanced {
        double power(double base, int exp) {
            double result = 1;
            for(int i = 0; i < exp; i++) {
                result *= base;
            }
            return result;
        }
    }
}

// Еще одно пространство имен
namespace Physics {
    const double GRAVITY = 9.81;
    
    double calculateForce(double mass) {
        return mass * GRAVITY;
    }
}

// Анонимное пространство имен (аналог static для функций/переменных)
namespace {
    int hidden_variable = 42;  // Видна только в этом файле
    
    void hiddenFunction() {
        cout << "Эта функция видна только в этом файле" << endl;
    }
}

void demonstrateNamespaces() {
    cout << "=== ПРОСТРАНСТВА ИМЕН (namespace) ===\n" << endl;
    
    // Разные способы доступа
    
    // 1. Полное имя
    cout << "1. Полное имя:" << endl;
    cout << "MyMath::PI = " << MyMath::PI << endl;
    cout << "MyMath::add(2, 3) = " << MyMath::add(2, 3) << endl;
    
    // 2. Using declaration (объявление using)
    {
        using MyMath::PI;
        cout << "\n2. Using declaration:" << endl;
        cout << "PI = " << PI << endl;  // Без MyMath::
        // cout << add(2, 3) << endl;  // ОШИБКА: add не объявлена
    }
    
    // 3. Using directive (директива using)
    {
        using namespace MyMath;
        cout << "\n3. Using directive:" << endl;
        cout << "PI = " << PI << endl;
        cout << "add(5, 7) = " << add(5, 7) << endl;
    }
    
    // 4. Вложенные namespace
    cout << "\n4. Вложенные namespace:" << endl;
    cout << "MyMath::Advanced::power(2, 3) = " 
         << MyMath::Advanced::power(2, 3) << endl;
    
    // 5. Псевдонимы (aliases)
    namespace MM = MyMath;  // Псевдоним
    namespace MMA = MyMath::Advanced;  // Псевдоним для вложенного
    
    cout << "\n5. Псевдонимы:" << endl;
    cout << "MM::PI = " << MM::PI << endl;
    cout << "MMA::power(3, 2) = " << MMA::power(3, 2) << endl;
    
    // 6. Конфликты имен
    cout << "\n6. Конфликты имен:" << endl;
    
    // Создаем локальную переменную с таким же именем
    double PI = 3.14;  // Локальная переменная
    
    cout << "Локальная PI = " << PI << endl;
    cout << "MyMath::PI = " << MyMath::PI << endl;
    cout << "Глобальная ::global_var = " << ::global_var << endl;
    
    // 7. Анонимное пространство имен
    cout << "\n7. Анонимное namespace:" << endl;
    cout << "hidden_variable = " << hidden_variable << endl;
    hiddenFunction();
}

// Пример: организация кода библиотеки
namespace Graphics {
    // Внутренние детали (не экспортируем)
    namespace detail {
        void renderPixel(int x, int y, int color) {
            cout << "Пиксель (" << x << "," << y << ") = цвет " << color << endl;
        }
    }
    
    // Публичный интерфейс
    void drawLine(int x1, int y1, int x2, int y2) {
        cout << "Рисуем линию от (" << x1 << "," << y1 
             << ") до (" << x2 << "," << y2 << ")" << endl;
        // Используем внутреннюю функцию
        detail::renderPixel(x1, y1, 1);
        detail::renderPixel(x2, y2, 1);
    }
    
    void drawCircle(int center_x, int center_y, int radius) {
        cout << "Рисуем круг с центром (" << center_x << "," << center_y 
             << "), радиус " << radius << endl;
    }
}

void libraryExample() {
    cout << "\n=== ПРИМЕР: ОРГАНИЗАЦИЯ БИБЛИОТЕКИ ===\n" << endl;
    
    // Используем публичный интерфейс
    Graphics::drawLine(0, 0, 10, 10);
    Graphics::drawCircle(5, 5, 3);
    
    // НЕЛЬЗЯ использовать внутренние функции!
    // Graphics::detail::renderPixel(0, 0, 1);  // ОШИБКА (если detail в .cpp)
    
    cout << "\nПубличный интерфейс скрывает реализацию" << endl;
}

// inline namespace (C++11)
namespace Library {
    namespace v1 {  // Старая версия
        void process() {
            cout << "Обработка v1" << endl;
        }
    }
    
    inline namespace v2 {  // Текущая версия (по умолчанию)
        void process() {
            cout << "Обработка v2 (улучшенная)" << endl;
        }
    }
}

void inlineNamespaceDemo() {
    cout << "\n=== INLINE NAMESPACE (C++11) ===\n" << endl;
    
    // Можно обращаться к v2 как к основной версии
    Library::process();  // Используется v2::process
    
    // Но можно и явно указать версию
    Library::v1::process();
    Library::v2::process();
    
    cout << "\ninline namespace позволяет:" << endl;
    cout << "1. Иметь версии API" << endl;
    cout << "2. Поддерживать обратную совместимость" << endl;
    cout << "3. Плавно обновлять версии" << endl;
}

int main() {
    demonstrateNamespaces();
    libraryExample();
    inlineNamespaceDemo();
    return 0;
}
```

### 4.2 Продвинутое использование namespace

```cpp
// namespace_advanced.cpp
#include <iostream>
#include <string>
using namespace std;

// Пример 1: Использование в больших проектах
namespace Company {
    namespace Project {
        namespace ModuleA {
            class Processor {
            public:
                void process() {
                    cout << "ModuleA::Processor работает" << endl;
                }
            };
        }
        
        namespace ModuleB {
            class Analyzer {
            public:
                void analyze() {
                    cout << "ModuleB::Analyzer анализирует" << endl;
                }
            };
        }
        
        // Общие утилиты
        namespace Utils {
            string formatString(const string& str) {
                return "[" + str + "]";
            }
        }
    }
}

// Пример 2: Разделение на заголовочные и исходные файлы
// В заголовочном файле (например, calculator.h):
namespace Calculator {
    // Объявления
    double add(double a, double b);
    double subtract(double a, double b);
    
    namespace Scientific {
        double sin(double x);
        double cos(double x);
    }
}

// В исходном файле (calculator.cpp) были бы определения:
/*
namespace Calculator {
    double add(double a, double b) {
        return a + b;
    }
    
    double subtract(double a, double b) {
        return a - b;
    }
    
    namespace Scientific {
        double sin(double x) {
            // реализация
            return 0;
        }
    }
}
*/

void largeProjectStructure() {
    cout << "=== ОРГАНИЗАЦИЯ БОЛЬШИХ ПРОЕКТОВ ===\n" << endl;
    
    // Использование глубоко вложенных namespace
    Company::Project::ModuleA::Processor processor;
    processor.process();
    
    Company::Project::ModuleB::Analyzer analyzer;
    analyzer.analyze();
    
    string formatted = Company::Project::Utils::formatString("Hello");
    cout << "Форматированная строка: " << formatted << endl;
    
    cout << "\nПРЕИМУЩЕСТВА такой организации:" << endl;
    cout << "1. Четкая структура проекта" << endl;
    cout << "2. Избегание конфликтов имен" << endl;
    cout << "3. Логическая группировка функционала" << endl;
    cout << "4. Упрощение навигации по коду" << endl;
}

// Пример 3: ADL (Argument Dependent Lookup)
namespace ADL_Example {
    class MyString {
    private:
        string data;
    public:
        MyString(const string& s) : data(s) {}
        
        // Дружественная функция в том же namespace
        friend ostream& operator<<(ostream& os, const MyString& str) {
            return os << "MyString: " << str.data;
        }
    };
    
    void print(const MyString& str) {
        // Благодаря ADL, operator<< находится автоматически
        cout << str << endl;
    }
}

void demonstrateADL() {
    cout << "\n=== ADL (Argument Dependent Lookup) ===\n" << endl;
    
    ADL_Example::MyString str("Hello ADL");
    
    // Без ADL пришлось бы писать:
    // ADL_Example::operator<<(cout, str);
    
    // С ADL можно просто:
    cout << str << endl;
    
    // Или:
    ADL_Example::print(str);
    
    cout << "\nADL автоматически ищет функции в namespace аргументов" << endl;
    cout << "Это упрощает использование операторов и других функций" << endl;
}

// Пример 4: Использование using с caution
void usingWithCaution() {
    cout << "\n=== ОСТОРОЖНОЕ ИСПОЛЬЗОВАНИЕ using ===\n" << endl;
    
    // ПЛОХО в глобальной области (в заголовочных файлах):
    // using namespace std;  // Загрязняет глобальное пространство имен
    
    // ХОРОШО: использовать в ограниченных областях
    {
        using namespace std;
        cout << "Здесь можно использовать cout без std::" << endl;
    }
    
    // ЛУЧШЕ: using declaration для конкретных имен
    using std::cout;
    using std::endl;
    
    cout << "Теперь можно использовать только cout и endl" << endl;
    
    // ЕЩЕ ЛУЧШЕ в методах классов
    class MyClass {
    public:
        void print() {
            using std::cout;
            using std::endl;
            cout << "Печать из MyClass" << endl;
        }
    };
    
    cout << "\nРЕКОМЕНДАЦИИ:" << endl;
    cout << "1. Избегайте 'using namespace' в заголовочных файлах" << endl;
    cout << "2. Используйте в ограниченных областях видимости" << endl;
    cout << "3. Предпочитайте using declaration using directive" << endl;
    cout << "4. В .cpp файлах можно быть менее строгим" << endl;
}

int main() {
    largeProjectStructure();
    demonstrateADL();
    usingWithCaution();
    return 0;
}
```

## Часть 5: Комплексный пример

```cpp
// comprehensive_example.cpp
#include <iostream>
#include <string>
using namespace std;

// ========== МОДУЛЬ 1: Конфигурация ==========
namespace Config {
    // Глобальные настройки (extern для использования в других файлах)
    extern const string APP_NAME;
    extern const double VERSION;
    
    // Static для внутреннего использования
    static int internal_counter = 0;
    
    // Функция для работы с internal_counter
    static void incrementCounter() {
        internal_counter++;
    }
    
    // Публичная функция
    void printConfig() {
        incrementCounter();
        cout << "Конфигурация (вызов #" << internal_counter << "):" << endl;
        cout << "  Приложение: " << APP_NAME << endl;
        cout << "  Версия: " << VERSION << endl;
    }
}

// Определения (обычно в .cpp файле)
const string Config::APP_NAME = "MySuperApp";
const double Config::VERSION = 1.5;

// ========== МОДУЛЬ 2: Логирование ==========
namespace Logger {
    // Static переменная для этого файла
    static int log_level = 1;  // 0=off, 1=error, 2=warning, 3=info, 4=debug
    
    // Внутренняя функция
    static string getCurrentTime() {
        return "12:34:56";  // Упрощенно
    }
    
    // Публичные функции
    void setLogLevel(int level) {
        if(level >= 0 && level <= 4) {
            log_level = level;
            cout << "Уровень логирования установлен: " << level << endl;
        }
    }
    
    void logError(const string& message) {
        if(log_level >= 1) {
            cout << "[ERROR][" << getCurrentTime() << "] " << message << endl;
        }
    }
    
    void logInfo(const string& message) {
        if(log_level >= 3) {
            cout << "[INFO][" << getCurrentTime() << "] " << message << endl;
        }
    }
}

// ========== МОДУЛЬ 3: Математика ==========
namespace Math {
    // Константы
    const double PI = 3.141592653589793;
    const double E = 2.718281828459045;
    
    // Вспомогательная функция (static)
    static double validateNumber(double x) {
        if(x < 0) {
            Logger::logError("Отрицательное число в математической функции");
            return 0;
        }
        return x;
    }
    
    // Публичные функции
    double circleArea(double radius) {
        radius = validateNumber(radius);
        return PI * radius * radius;
    }
    
    namespace Statistics {
        double average(const double* numbers, int count) {
            if(count <= 0) {
                Logger::logError("Некорректное количество чисел");
                return 0;
            }
            
            double sum = 0;
            for(int i = 0; i < count; i++) {
                sum += numbers[i];
            }
            return sum / count;
        }
    }
}

// ========== ГЛАВНАЯ ПРОГРАММА ==========
int main() {
    cout << "=== КОМПЛЕКСНЫЙ ПРИМЕР ===\n" << endl;
    
    // 1. Используем Config модуль
    cout << "1. Конфигурация приложения:" << endl;
    Config::printConfig();
    Config::printConfig();  // internal_counter увеличится
    
    // 2. Используем Logger модуль
    cout << "\n2. Система логирования:" << endl;
    Logger::setLogLevel(3);  // Устанавливаем уровень
    Logger::logError("Тестовая ошибка");
    Logger::logInfo("Тестовая информация");
    
    // 3. Используем Math модуль
    cout << "\n3. Математические вычисления:" << endl;
    double radius = 5.0;
    double area = Math::circleArea(radius);
    cout << "Площадь круга радиусом " << radius << " = " << area << endl;
    
    // Пробуем с отрицательным радиусом
    double bad_area = Math::circleArea(-5.0);
    cout << "Площадь с отрицательным радиусом = " << bad_area 
         << " (проверка сработала)" << endl;
    
    // 4. Статистика
    cout << "\n4. Статистика:" << endl;
    double numbers[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    double avg = Math::Statistics::average(numbers, 5);
    cout << "Среднее значение: " << avg << endl;
    
    // 5. Демонстрация различных областей видимости
    cout << "\n5. Демонстрация областей видимости:" << endl;
    
    // Локальная переменная
    int local_var = 100;
    
    // Static локальная
    static int static_counter = 0;
    static_counter++;
    
    // Попытка доступа к internal переменным других модулей
    // Config::internal_counter = 10;  // ОШИБКА: static!
    // Logger::log_level = 5;          // ОШИБКА: static!
    // Math::validateNumber(10);       // ОШИБКА: static!
    
    cout << "local_var = " << local_var << endl;
    cout << "static_counter = " << static_counter << endl;
    
    // 6. Еще раз вызовем main функции
    cout << "\n6. Повторный 'вызов' (имитация):" << endl;
    {
        // Новые локальные переменные (другая область видимости)
        int local_var = 200;  // Это ДРУГАЯ переменная!
        static int static_counter = 0;  // Это ДРУГОЙ static!
        static_counter++;
        
        cout << "В блоке: local_var = " << local_var << endl;
        cout << "В блоке: static_counter = " << static_counter << endl;
    }
    
    cout << "\nПосле блока: local_var = " << local_var << endl;
    cout << "После блока: static_counter (главный) = " << static_counter << endl;
    
    cout << "\n=== ВЫВОДЫ И РЕКОМЕНДАЦИИ ===\n" << endl;
    cout << "1. ЛОКАЛЬНЫЕ переменные:" << endl;
    cout << "   • Видны только в своей области видимости" << endl;
    cout << "   • Создаются/уничтожаются при входе/выходе" << endl;
    cout << "   • Используйте для временных данных" << endl;
    
    cout << "\n2. STATIC локальные:" << endl;
    cout << "   • Сохраняют значение между вызовами" << endl;
    cout << "   • Инициализируются один раз" << endl;
    cout << "   • Используйте для кэширования, счетчиков" << endl;
    
    cout << "\n3. ГЛОБАЛЬНЫЕ переменные:" << endl;
    cout << "   • Видны во всем файле" << endl;
    cout << "   • Существуют всю программу" << endl;
    cout << "   • Избегайте или используйте аккуратно" << endl;
    
    cout << "\n4. STATIC глобальные:" << endl;
    cout << "   • Видны только в своем файле" << endl;
    cout << "   • Хороши для скрытия реализации" << endl;
    
    cout << "\n5. EXTERN:" << endl;
    cout << "   • Связывает переменные между файлами" << endl;
    cout << "   • Используйте для разделения кода" << endl;
    
    cout << "\n6. NAMESPACE:" << endl;
    cout << "   • Группирует логически связанный код" << endl;
    cout << "   • Избегает конфликтов имен" << endl;
    cout << "   • Создает четкие интерфейсы" << endl;
    
    return 0;
}
```

## Ключевые выводы для новичков:

### **Когда что использовать:**

1. **Локальные переменные** - для временных данных внутри функций
2. **Static локальные** - когда нужно сохранять состояние между вызовами
3. **Глобальные переменные** - используйте редко, только для общедоступных констант
4. **Static глобальные** - для скрытия реализации в .cpp файлах
5. **Extern** - для разделения кода на несколько файлов
6. **Namespace** - для организации больших проектов

### **Лучшие практики:**

1. Минимизируйте использование глобальных переменных
2. Используйте static для скрытия внутренних деталей
3. Организуйте код в namespace по логическим модулям
4. Избегайте `using namespace` в заголовочных файлах
5. Используйте extern для разделения объявлений и определений

### **Типичные ошибки:**

1. Использование глобальных переменных для временных данных
2. Забывание освободить память для static указателей
3. Конфликты имен из-за отсутствия namespace
4. Использование `using namespace std` в заголовочных файлах
5. Неправильное использование extern (множественные определения)

Этот разбор дает полное понимание областей видимости и хранения данных в C++. Практикуйтесь на примерах, и вы быстро освоите эти важные концепции!