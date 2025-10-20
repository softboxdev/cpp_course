# Знакомство с API ОС Linux: Подробное руководство

## 1. Введение в API Linux

### Что такое API в контексте ОС?

**API (Application Programming Interface)** - это набор функций, структур данных, констант и протоколов, которые предоставляет операционная система для взаимодействия приложений с:
- Ядром ОС
- Аппаратными ресурсами
- Другими приложениями
- Системными службами

### Уровни API в Linux

```
┌─────────────────┐
│  Приложения     │
├─────────────────┤
│  Библиотеки C   │ (libc) - POSIX API
├─────────────────┤
│  Системные      │ (syscalls)
│  вызовы         │
├─────────────────┤
│   Ядро Linux    │
└─────────────────┘
```

## 2. Основные компоненты API Linux

### Системные вызовы (System Calls)

**Системные вызовы** - это интерфейс между пользовательским пространством и ядром Linux.

```c
#include <unistd.h>
#include <sys/syscall.h>

// Прямой системный вызов
long syscall(long number, ...);

// Пример: получение ID процесса
pid_t getpid(void) {
    return syscall(SYS_getpid);
}
```

### Стандартная библиотека C (libc)

**Glibc** - основная реализация стандартной библиотеки C в Linux, предоставляющая:
- Обертки для системных вызовов
- Стандартные функции ввода-вывода
- Функции работы со строками и памятью
- Математические функции

## 3. Основные категории системных вызовов

### Управление процессами

```c
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Создание процесса
pid_t fork(void);

// Запуск программы
int execve(const char *pathname, char *const argv[], char *const envp[]);

// Ожидание завершения процесса
pid_t waitpid(pid_t pid, int *wstatus, int options);

// Завершение процесса
void _exit(int status);
```

**Практический пример:**
```c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Дочерний процесс
        printf("Child process: PID = %d, Parent PID = %d\n", 
               getpid(), getppid());
        _exit(0);
    } else {
        // Родительский процесс
        printf("Parent process: PID = %d, Child PID = %d\n", 
               getpid(), pid);
        waitpid(pid, NULL, 0);
    }
    return 0;
}
```

### Файловая система и ввод-вывод

```c
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// Открытие файла
int open(const char *pathname, int flags, mode_t mode);

// Чтение/запись
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);

// Управление файлами
int close(int fd);
off_t lseek(int fd, off_t offset, int whence);

// Информация о файле
int stat(const char *pathname, struct stat *statbuf);
```

**Практический пример:**
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    // Создание и запись в файл
    int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    const char *text = "Hello, Linux API!\n";
    write(fd, text, strlen(text));
    close(fd);
    
    // Чтение из файла
    fd = open("example.txt", O_RDONLY);
    char buffer[256];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytes_read] = '\0';
    
    printf("Read from file: %s", buffer);
    close(fd);
    
    return 0;
}
```

### Управление памятью

```c
#include <sys/mman.h>
#include <unistd.h>

// Выделение памяти
void *malloc(size_t size);  // библиотечная функция
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

// Освобождение памяти
void free(void *ptr);
int munmap(void *addr, size_t length);

// Изменение размера сегмента данных
void *sbrk(intptr_t increment);
```

**Пример использования mmap:**
```c
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    // Создание анонимного отображения памяти
    size_t size = 4096;  // 4KB
    void *memory = mmap(NULL, size, PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    
    if (memory == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    
    // Использование выделенной памяти
    strcpy((char*)memory, "Hello from mmap!");
    printf("Memory content: %s\n", (char*)memory);
    
    // Освобождение памяти
    munmap(memory, size);
    
    return 0;
}
```

### Межпроцессное взаимодействие (IPC)

#### Каналы (Pipes)
```c
#include <unistd.h>

int pipe(int pipefd[2]);  // pipefd[0] - чтение, pipefd[1] - запись
```

#### Очереди сообщений
```c
#include <sys/msg.h>

int msgget(key_t key, int msgflg);
int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
```

#### Разделяемая память
```c
#include <sys/shm.h>

int shmget(key_t key, size_t size, int shmflg);
void *shmat(int shmid, const void *shmaddr, int shmflg);
int shmdt(const void *shmaddr);
```

**Пример использования pipe:**
```c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    char buffer[256];
    
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // Дочерний процесс - запись в канал
        close(pipefd[0]);  // закрываем чтение
        
        const char *message = "Hello from child process!";
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
        _exit(0);
    } else {
        // Родительский процесс - чтение из канала
        close(pipefd[1]);  // закрываем запись
        
        ssize_t bytes_read = read(pipefd[0], buffer, sizeof(buffer));
        printf("Received from child: %s\n", buffer);
        close(pipefd[0]);
        waitpid(pid, NULL, 0);
    }
    
    return 0;
}
```

### Управление сигналами

```c
#include <signal.h>

// Установка обработчика сигнала
sighandler_t signal(int signum, sighandler_t handler);

// Расширенное управление сигналами
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

// Отправка сигнала
int kill(pid_t pid, int sig);

// Ожидание сигнала
int pause(void);
int sigsuspend(const sigset_t *mask);
```

**Пример обработки сигналов:**
```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

volatile sig_atomic_t signal_received = 0;

void signal_handler(int sig) {
    signal_received = sig;
    printf("Received signal: %d (%s)\n", sig, strsignal(sig));
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    // Установка обработчиков для SIGINT и SIGTERM
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
    
    printf("Process PID: %d\n", getpid());
    printf("Send signals using: kill -SIGINT %d\n", getpid());
    
    while (!signal_received) {
        printf("Working...\n");
        sleep(1);
    }
    
    printf("Exiting due to signal %d\n", signal_received);
    return 0;
}
```

## 4. Работа с сетевыми сокетами

```c
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Создание сокета
int socket(int domain, int type, int protocol);

// Привязка адреса
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

// Прослушивание соединений
int listen(int sockfd, int backlog);

// Принятие соединения
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

// Установка соединения
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

**Пример TCP-сервера:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Создание сокета
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Настройка опций сокета
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Привязка сокета к порту
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Прослушивание соединений
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d\n", PORT);
    
    // Принятие соединения
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                            (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    // Чтение данных от клиента
    read(new_socket, buffer, BUFFER_SIZE);
    printf("Received: %s\n", buffer);
    
    // Отправка ответа
    const char *hello = "Hello from server";
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    
    close(new_socket);
    close(server_fd);
    return 0;
}
```

## 5. Работа с файловой системой и метаданными

```c
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

// Работа с директориями
DIR *opendir(const char *name);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);

// Изменение прав доступа
int chmod(const char *pathname, mode_t mode);
int chown(const char *pathname, uid_t owner, gid_t group);

// Получение информации о файловой системе
int statvfs(const char *path, struct statvfs *buf);
```

**Пример обхода директории:**
```c
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void list_directory(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }
    
    struct dirent *entry;
    struct stat file_stat;
    char full_path[1024];
    
    printf("Contents of directory: %s\n", path);
    printf("----------------------------------------\n");
    
    while ((entry = readdir(dir)) != NULL) {
        // Пропускаем текущую и родительскую директории
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
            
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        
        if (stat(full_path, &file_stat) == 0) {
            printf("%s", entry->d_name);
            
            if (S_ISDIR(file_stat.st_mode)) {
                printf(" (directory)");
            } else if (S_ISREG(file_stat.st_mode)) {
                printf(" (file, size: %ld bytes)", file_stat.st_size);
            } else if (S_ISLNK(file_stat.st_mode)) {
                printf(" (symlink)");
            }
            
            printf("\n");
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *path = (argc > 1) ? argv[1] : ".";
    list_directory(path);
    return 0;
}
```

## 6. Расширенное управление процессами

### Сессии и группы процессов
```c
#include <unistd.h>

// Создание новой сессии
pid_t setsid(void);

// Получение идентификаторов
pid_t getpgid(pid_t pid);
int setpgid(pid_t pid, pid_t pgid);

// Управление терминалом
pid_t tcgetpgrp(int fd);
int tcsetpgrp(int fd, pid_t pgrp);
```

### Приоритеты и планирование
```c
#include <sched.h>
#include <sys/resource.h>

// Установка политики планирования
int sched_setscheduler(pid_t pid, int policy, const struct sched_param *param);

// Установка приоритета
int setpriority(int which, id_t who, int prio);
int nice(int inc);
```

## 7. Инструменты для работы с API

### Отладка с помощью strace
```bash
# Просмотр системных вызовов программы
strace ./my_program

# Запись в файл
strace -o trace.log ./my_program

# Подсчет системных вызовов
strace -c ./my_program

# Фильтрация по системным вызовам
strace -e open,read,write ./my_program
```

### Анализ с помощью ltrace
```bash
# Просмотр вызовов библиотечных функций
ltrace ./my_program
```

### Использование man-страниц
```bash
# Системные вызовы
man 2 fork
man 2 open

# Библиотечные функции  
man 3 printf
man 3 malloc

# Общие команды
man 1 ls
```

## 8. Практические рекомендации

### Обработка ошибок
```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void handle_error(const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

int safe_open(const char *filename, int flags, mode_t mode) {
    int fd = open(filename, flags, mode);
    if (fd == -1) {
        handle_error("open failed");
    }
    return fd;
}
```

### Современные альтернативы устаревшим функциям
```c
// Вместо signal() используйте sigaction()
// Вмето gets() используйте fgets()
// Вместо sprintf() используйте snprintf()
```

## Заключение

API Linux предоставляет богатый набор инструментов для системного программирования. Ключевые моменты:

1. **Понимание уровней абстракции** - от системных вызовов до библиотечных функций
2. **Правильная обработка ошибок** - всегда проверяйте возвращаемые значения
3. **Использование современных практик** - избегайте устаревших функций
4. **Отладка и анализ** - используйте strace, ltrace и другие инструменты
5. **Изучение документации** - man-страницы ваш лучший друг

Практикуйтесь с простыми примерами, постепенно переходя к более сложным проектам, чтобы глубоко понять работу API Linux.