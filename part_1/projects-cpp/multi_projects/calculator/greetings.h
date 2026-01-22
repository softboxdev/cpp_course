// greetings.h - Заголовочный файл для приветствий

#ifndef GREETINGS_H
#define GREETINGS_H

// Объявляем функции
void sayHello();
void sayGoodbye();
void showMathExample();
// Пространство имен для работы с приветствиями
namespace Greetings {
    // Функция, которая возвращает приветствие
    std::string getHelloMessage();
    
    // Функция с параметром
    std::string getPersonalHello(const std::string& name);
    
    // Функция для прощания
    std::string getGoodbyeMessage();
    
    // Внутренняя функция (не экспортируем в .h)
    // static или в отдельном файле реализации
}
#endif // GREETINGS_H