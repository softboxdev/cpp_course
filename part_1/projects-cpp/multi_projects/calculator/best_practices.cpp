// best_practices.cpp - Лучшие практики для новичков

#include <iostream>
#include <string>

/*
СОВЕТ 1: Организация проекта
---------------------------
ХОРОШО:                           ПЛОХО:
project/                          project.cpp (все в одном файле)
├── main.cpp                      
├── module1.cpp
├── module1.h
├── module2.cpp
└── module2.h
*/

/*
СОВЕТ 2: Заголовочные файлы (.h)
-------------------------------
В .h файлах:
1. Только объявления (declarations)
2. Никогда не пишите реализацию (кроме шаблонов)
3. Всегда используйте #ifndef/#define/#endif
4. Минимизируйте #include в .h файлах
*/

/*
СОВЕТ 3: Пространства имен
--------------------------
Используйте namespace для:
1. Группировки связанного кода
2. Избегания конфликтов имен
3. Создания логической структуры

Пример хорошей структуры:
namespace CompanyName {
    namespace ProjectName {
        namespace ModuleName {
            // ваш код
        }
    }
}
*/

/*
СОВЕТ 4: Именование файлов
--------------------------
ХОРОШИЕ ИМЕНА:                 ПЛОХИЕ ИМЕНА:
- calculator.h                 - file1.h
- student_database.cpp         - mycode.cpp  
- math_utils.cpp               - project.cpp
- config_settings.h            - header.h
*/

// Простой пример хорошей структуры
namespace GoodExample {
    
    // math_operations.h будет содержать:
    namespace Math {
        int add(int a, int b);
        int multiply(int a, int b);
    }
    
    // string_utils.h будет содержать:
    namespace StringUtils {
        std::string toUpperCase(const std::string& str);
        std::string trim(const std::string& str);
    }
    
}

int main() {
    std::cout << "=== ЛУЧШИЕ ПРАКТИКИ ===" << std::endl;
    std::cout << "======================" << std::endl;
    
    std::cout << "\n1. Разделяйте код на логические модули" << std::endl;
    std::cout << "2. Используйте понятные имена файлов" << std::endl;
    std::cout << "3. Всегда защищайте заголовочные файлы" << std::endl;
    std::cout << "4. Используйте пространства имен" << std::endl;
    std::cout << "5. Комментируйте ваш код" << std::endl;
    
    return 0;
}