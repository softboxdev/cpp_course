# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++11

# Имя исполняемого файла
TARGET = calculator

# Исходные файлы
SRCS = main.cpp math.cpp

# Объектные файлы (автоматически из SRCS)
OBJS = $(SRCS:.cpp=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Компиляция .cpp в .o
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
    rm -f $(OBJS) $(TARGET)

# Пересборка
rebuild: clean all

# Запуск
run: $(TARGET)
    ./$(TARGET)

.PHONY: all clean rebuild run