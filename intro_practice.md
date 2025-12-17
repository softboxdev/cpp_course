# Практическая работа: Тензорные операции и обратное распространение для понимания LLM

## Цель работы
Освоить базовые операции над тензорами и реализовать метод обратного распространения ошибки для понимания основных принципов работы LLM-моделей.

---

## Часть 1: Операции над тензорами

### Задание 1.1: Создание и базовые операции

```python
import numpy as np
import torch

def tensor_operations():
    """Базовые операции с тензорами"""
    
    # 1. Создание тензоров
    # С использованием NumPy
    tensor_np = np.array([[1, 2, 3], [4, 5, 6]])
    print("NumPy тензор:")
    print(tensor_np)
    print(f"Форма: {tensor_np.shape}, Размерность: {tensor_np.ndim}")
    
    # С использованием PyTorch
    tensor_pt = torch.tensor([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
    print("\nPyTorch тензор:")
    print(tensor_pt)
    print(f"Форма: {tensor_pt.shape}, Размерность: {tensor_pt.dim()}")
    
    # 2. Тензорные операции
    # Сложение
    A = torch.tensor([[1, 2], [3, 4]])
    B = torch.tensor([[5, 6], [7, 8]])
    C = A + B
    print(f"\nСложение:\n{A} + \n{B} = \n{C}")
    
    # Умножение (элементное)
    D = A * B
    print(f"\nЭлементное умножение:\n{A} * \n{B} = \n{D}")
    
    # Матричное умножение
    E = torch.matmul(A, B)
    print(f"\nМатричное умножение:\n{A} @ \n{B} = \n{E}")
    
    # 3. Изменение формы тензора
    tensor_3d = torch.randn(2, 3, 4)
    print(f"\nИсходный тензор (2, 3, 4): {tensor_3d.shape}")
    
    # Reshape
    reshaped = tensor_3d.reshape(3, 8)
    print(f"Reshape в (3, 8): {reshaped.shape}")
    
    # Transpose
    transposed = tensor_3d.transpose(0, 2)
    print(f"Transpose (0,2): {transposed.shape}")
    
    return A, B, C, D, E

# Запуск
tensors = tensor_operations()
```

### Задание 1.2: Операции, используемые в LLM

```python
def llm_tensor_operations():
    """Операции, характерные для LLM моделей"""
    
    # 1. Тензоры эмбеддингов (входные данные)
    # В LLM слова преобразуются в векторы эмбеддингов
    batch_size = 2
    seq_length = 4
    embedding_dim = 3
    
    embeddings = torch.randn(batch_size, seq_length, embedding_dim)
    print(f"Эмбеддинги: форма {embeddings.shape}")
    print(f"Batch: {batch_size}, Sequence: {seq_length}, Embedding dim: {embedding_dim}")
    
    # 2. Матрицы весов (как в линейных слоях)
    hidden_dim = 5
    weight_matrix = torch.randn(embedding_dim, hidden_dim)
    bias = torch.randn(hidden_dim)
    
    print(f"\nМатрица весов: {weight_matrix.shape}")
    print(f"Bias: {bias.shape}")
    
    # 3. Линейное преобразование (аналог Dense слоя)
    # Берем первый токен из каждого примера в батче
    first_tokens = embeddings[:, 0, :]  # форма: (batch_size, embedding_dim)
    print(f"\nПервые токены: {first_tokens.shape}")
    
    # Линейное преобразование: y = xW^T + b
    linear_output = torch.matmul(first_tokens, weight_matrix.T) + bias
    print(f"Выход линейного слоя: {linear_output.shape}")
    
    # 4. Операция Softmax (для вероятностей)
    logits = torch.randn(batch_size, 10)  # 10 классов
    probabilities = torch.softmax(logits, dim=-1)
    
    print(f"\nLogits: {logits.shape}")
    print(f"Probabilities (softmax): сумма = {probabilities.sum().item():.2f}")
    
    # 5. Внимание (Attention) - ключевая операция в LLM
    # Упрощенный расчет внимания
    Q = torch.randn(batch_size, seq_length, embedding_dim)  # Query
    K = torch.randn(batch_size, seq_length, embedding_dim)  # Key  
    V = torch.randn(batch_size, seq_length, embedding_dim)  # Value
    
    # Вычисление внимания: Attention(Q,K,V) = softmax(QK^T/√d)V
    attention_scores = torch.matmul(Q, K.transpose(1, 2)) / np.sqrt(embedding_dim)
    attention_weights = torch.softmax(attention_scores, dim=-1)
    attention_output = torch.matmul(attention_weights, V)
    
    print(f"\nAttention операция:")
    print(f"Q: {Q.shape}, K: {K.shape}, V: {V.shape}")
    print(f"Attention output: {attention_output.shape}")
    
    return embeddings, weight_matrix, linear_output, attention_output

# Запуск
llm_tensors = llm_tensor_operations()
```

---

## Часть 2: Метод обратного распространения ошибки

### Задание 2.1: Ручное вычисление градиентов

```python
def manual_backpropagation():
    """Ручное вычисление градиентов для простой сети"""
    
    # Прямой проход для простой сети: y = w2 * relu(w1 * x + b1) + b2
    
    # Входные данные
    x = torch.tensor(2.0, requires_grad=False)
    target = torch.tensor(3.0)
    
    # Параметры (инициализируем случайными значениями)
    w1 = torch.tensor(1.5, requires_grad=True)
    b1 = torch.tensor(0.5, requires_grad=True)
    w2 = torch.tensor(2.0, requires_grad=True)
    b2 = torch.tensor(1.0, requires_grad=True)
    
    # Прямой проход
    z1 = w1 * x + b1           # Линейное преобразование
    a1 = torch.relu(z1)        # Функция активации ReLU
    y_pred = w2 * a1 + b2      # Выход
    
    # Функция потерь (MSE)
    loss = (y_pred - target) ** 2
    
    print("=== Ручное обратное распространение ===")
    print(f"x = {x.item()}, target = {target.item()}")
    print(f"Параметры: w1={w1.item()}, b1={b1.item()}, w2={w2.item()}, b2={b2.item()}")
    print(f"Предсказание: y_pred = {y_pred.item():.4f}")
    print(f"Потери: L = {loss.item():.4f}")
    
    # Обратный проход (ручной расчет градиентов)
    # 1. Градиент по loss
    dL_dy_pred = 2 * (y_pred - target)
    
    # 2. Градиенты для второго слоя
    dL_dw2 = dL_dy_pred * a1
    dL_db2 = dL_dy_pred * 1
    
    # 3. Градиенты через ReLU
    dL_da1 = dL_dy_pred * w2
    dL_dz1 = dL_da1 * (z1 > 0).float()  # Производная ReLU
    
    # 4. Градиенты для первого слоя
    dL_dw1 = dL_dz1 * x
    dL_db1 = dL_dz1 * 1
    
    print("\nГрадиенты (ручной расчет):")
    print(f"dL/dw1 = {dL_dw1.item():.4f}")
    print(f"dL/db1 = {dL_db1.item():.4f}")
    print(f"dL/dw2 = {dL_dw2.item():.4f}")
    print(f"dL/db2 = {dL_db2.item():.4f}")
    
    # Автоматическое вычисление градиентов
    loss.backward()
    
    print("\nГрадиенты (autograd):")
    print(f"dL/dw1 = {w1.grad.item():.4f}")
    print(f"dL/db1 = {b1.grad.item():.4f}")
    print(f"dL/dw2 = {w2.grad.item():.4f}")
    print(f"dL/db2 = {b2.grad.item():.4f}")
    
    # Проверка совпадения
    print("\nПроверка:")
    print(f"Градиенты w1 совпадают: {torch.allclose(dL_dw1, w1.grad)}")
    print(f"Градиенты b1 совпадают: {torch.allclose(dL_db1, b1.grad)}")
    
    return {
        'parameters': (w1, b1, w2, b2),
        'grads_manual': (dL_dw1, dL_db1, dL_dw2, dL_db2),
        'grads_auto': (w1.grad, b1.grad, w2.grad, b2.grad)
    }

# Запуск
grad_results = manual_backpropagation()
```

### Задание 2.2: Реализация миниатюрной LLM-подобной модели

```python
class SimpleLLM(torch.nn.Module):
    """Упрощенная модель, демонстрирующая принципы LLM"""
    
    def __init__(self, vocab_size=10, embedding_dim=4, hidden_dim=8):
        super().__init__()
        
        # Эмбеддинг-слой (преобразует индексы токенов в векторы)
        self.embedding = torch.nn.Embedding(vocab_size, embedding_dim)
        
        # Линейные слои (аналогично feed-forward сети в трансформере)
        self.linear1 = torch.nn.Linear(embedding_dim, hidden_dim)
        self.linear2 = torch.nn.Linear(hidden_dim, vocab_size)
        
        # Функция активации
        self.relu = torch.nn.ReLU()
        
        # Функция потерь
        self.loss_fn = torch.nn.CrossEntropyLoss()
        
    def forward(self, token_ids):
        """Прямой проход"""
        # 1. Эмбеддинг токенов
        embeddings = self.embedding(token_ids)  # (batch, seq_len, embedding_dim)
        
        # 2. Усредняем эмбеддинги по последовательности (упрощение)
        # В реальных LLM используется внимание
        pooled = embeddings.mean(dim=1)  # (batch, embedding_dim)
        
        # 3. Проход через нейронную сеть
        hidden = self.relu(self.linear1(pooled))
        logits = self.linear2(hidden)  # (batch, vocab_size)
        
        return logits
    
    def train_step(self, token_ids, targets, lr=0.01):
        """Один шаг обучения с обратным распространением"""
        
        # Прямой проход
        logits = self.forward(token_ids)
        
        # Вычисление потерь
        loss = self.loss_fn(logits, targets)
        
        # Обратный проход
        loss.backward()
        
        # Сбор градиентов для анализа
        gradients = []
        for name, param in self.named_parameters():
            if param.grad is not None:
                gradients.append((name, param.grad.norm().item()))
        
        # Обновление параметров (упрощенный SGD)
        with torch.no_grad():
            for param in self.parameters():
                param -= lr * param.grad
                param.grad.zero_()
        
        return loss.item(), gradients

def train_mini_llm():
    """Обучение миниатюрной LLM-подобной модели"""
    
    # Инициализация модели
    model = SimpleLLM(vocab_size=10, embedding_dim=4, hidden_dim=8)
    
    print("=== Миниатюрная LLM модель ===")
    print(f"Количество параметров: {sum(p.numel() for p in model.parameters())}")
    print("\nСтруктура модели:")
    for name, param in model.named_parameters():
        print(f"{name}: {param.shape}")
    
    # Создание синтетических данных
    # В реальных LLM это были бы последовательности токенов
    batch_size = 4
    seq_length = 3
    
    # Токены (индексы слов)
    token_ids = torch.randint(0, 10, (batch_size, seq_length))
    # Целевые классы (например, следующий токен)
    targets = torch.randint(0, 10, (batch_size,))
    
    print(f"\nВходные данные:")
    print(f"Token IDs: {token_ids.shape}")
    print(f"Targets: {targets.shape}")
    
    # Несколько шагов обучения
    print("\nОбучение:")
    for step in range(5):
        # Один шаг обучения
        loss, gradients = model.train_step(token_ids, targets, lr=0.1)
        
        print(f"Шаг {step+1}: Loss = {loss:.4f}")
        
        # Вывод градиентов на первом шаге
        if step == 0:
            print("Нормы градиентов (шаг 1):")
            for name, grad_norm in gradients:
                print(f"  {name}: {grad_norm:.6f}")
    
    # Тестирование
    with torch.no_grad():
        test_logits = model.forward(token_ids)
        test_predictions = torch.argmax(test_logits, dim=-1)
        accuracy = (test_predictions == targets).float().mean().item()
        
        print(f"\nТочность на обучающих данных: {accuracy*100:.1f}%")
    
    return model

# Запуск
mini_llm = train_mini_llm()
```

### Задание 2.3: Визуализация процесса обучения

```python
def visualize_training():
    """Визуализация процесса обучения"""
    
    import matplotlib.pyplot as plt
    
    # Простая модель для визуализации
    class SimpleModel(torch.nn.Module):
        def __init__(self):
            super().__init__()
            self.w = torch.nn.Parameter(torch.randn(1))
            self.b = torch.nn.Parameter(torch.randn(1))
            
        def forward(self, x):
            return self.w * x + self.b
    
    # Данные: y = 2x + 1 + шум
    torch.manual_seed(42)
    x_data = torch.linspace(-3, 3, 20)
    y_data = 2 * x_data + 1 + torch.randn_like(x_data) * 0.5
    
    # Модель и функция потерь
    model = SimpleModel()
    optimizer = torch.optim.SGD(model.parameters(), lr=0.1)
    criterion = torch.nn.MSELoss()
    
    # История потерь
    losses = []
    w_values = []
    b_values = []
    
    # Обучение
    for epoch in range(50):
        # Прямой проход
        y_pred = model(x_data)
        loss = criterion(y_pred, y_data)
        
        # Обратный проход
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        
        # Сохранение для визуализации
        losses.append(loss.item())
        w_values.append(model.w.item())
        b_values.append(model.b.item())
    
    # Визуализация
    fig, axes = plt.subplots(1, 3, figsize=(15, 4))
    
    # 1. Исходные данные и финальная модель
    axes[0].scatter(x_data, y_data, alpha=0.5, label='Данные')
    x_line = torch.linspace(-3, 3, 100)
    y_line = model.w * x_line + model.b
    axes[0].plot(x_line.detach(), y_line.detach(), 'r-', label=f'Модель: y={model.w.item():.2f}x+{model.b.item():.2f}')
    axes[0].set_xlabel('x')
    axes[0].set_ylabel('y')
    axes[0].legend()
    axes[0].set_title('Исходные данные и обученная модель')
    
    # 2. Функция потерь
    axes[1].plot(losses)
    axes[1].set_xlabel('Эпоха')
    axes[1].set_ylabel('Потери (MSE)')
    axes[1].set_title('Сходимость функции потерь')
    axes[1].grid(True, alpha=0.3)
    
    # 3. Изменение параметров
    axes[2].plot(w_values, label='w (наклон)')
    axes[2].plot(b_values, label='b (смещение)')
    axes[2].axhline(y=2.0, color='r', linestyle='--', alpha=0.5, label='Истинный w')
    axes[2].axhline(y=1.0, color='g', linestyle='--', alpha=0.5, label='Истинный b')
    axes[2].set_xlabel('Эпоха')
    axes[2].set_ylabel('Значение параметра')
    axes[2].set_title('Изменение параметров во время обучения')
    axes[2].legend()
    axes[2].grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.show()
    
    print("\nФинальные параметры модели:")
    print(f"w = {model.w.item():.4f} (близко к истинному значению 2.0)")
    print(f"b = {model.b.item():.4f} (близко к истинному значению 1.0)")
    
    return model, losses

# Запуск (раскомментируйте при наличии matplotlib)
# trained_model, loss_history = visualize_training()
```

---

## Часть 3: Практические задания для самостоятельной работы

### Задание 3.1: Реализуйте операцию внимания

```python
def implement_attention(Q, K, V, mask=None):
    """
    Реализуйте операцию внимания из Transformer.
    
    Формула: Attention(Q,K,V) = softmax(QK^T/√d_k)V
    
    Args:
        Q: Query тензор, форма (batch, seq_len_q, d_k)
        K: Key тензор, форма (batch, seq_len_k, d_k)  
        V: Value тензор, форма (batch, seq_len_k, d_v)
        mask: Опциональная маска
        
    Returns:
        output: Выход внимания, форма (batch, seq_len_q, d_v)
        attention_weights: Веса внимания, форма (batch, seq_len_q, seq_len_k)
    """
    # TODO: Реализуйте вычисление внимания
    # 1. Вычислите QK^T
    # 2. Масштабируйте на √d_k
    # 3. Примените mask если предоставлена
    # 4. Примените softmax
    # 5. Умножьте на V
    
    pass  # Замените на свою реализацию
```

### Задание 3.2: Реализуйте слой нормализации

```python
class LayerNorm:
    """Реализуйте слой нормализации как в Transformer"""
    
    def __init__(self, features, eps=1e-6):
        # TODO: Инициализируйте параметры gamma и beta
        pass
    
    def forward(self, x):
        """
        Нормализуйте по последнему измерению.
        
        Формула: y = γ * (x - μ)/√(σ² + ε) + β
        """
        # TODO: Реализуйте forward pass
        pass
    
    def backward(self, grad_output):
        # TODO: Реализуйте backward pass для обучения
        pass
```

### Задание 3.3: Анализ градиентов в глубокой сети

```python
def analyze_gradient_flow():
    """
    Создайте глубокую сеть и проанализируйте:
    1. Исчезающие градиенты
    2. Взрывающиеся градиенты  
    3. Эффект от инициализации
    """
    # TODO: Создайте сеть с 10+ слоями
    # TODO: Проанализируйте распределение градиентов
    # TODO: Поэкспериментируйте с разными инициализациями
    pass
```

---

## Выводы и вопросы для размышления

1. **Какие тензорные операции наиболее важны для LLM и почему?**
   - Матричное умножение (линейные слои)
   - Attention mechanism  
   - Операции над эмбеддингами

2. **Как обратное распространение позволяет обучать модели с миллионами параметров?**
   - Цепное правило для эффективного вычисления градиентов
   - Автоматическое дифференцирование

3. **Какие вызовы возникают при обучении больших моделей?**
   - Исчезающие/взрывающиеся градиенты
   - Вычислительная сложность
   - Потребление памяти

4. **Как принципы из этой работы применяются в реальных LLM?**
   - Архитектура Transformer
   - Механизм внимания
   - Оптимизация AdamW

---

## Дополнительные ресурсы

1. [PyTorch Tutorials](https://pytorch.org/tutorials/)
2. [The Annotated Transformer](http://nlp.seas.harvard.edu/2018/04/03/attention.html)
3. [Understanding Backpropagation](https://medium.com/@karpathy/yes-you-should-understand-backprop-e2f06eab496b)

---

**Примечание:** Для запуска визуализаций может потребоваться установка matplotlib:
```bash
# Установка всех необходимых зависимостей
!pip install torch numpy matplotlib

# Проверка установки
import torch
import numpy as np
import matplotlib.pyplot as plt

print(f"PyTorch version: {torch.__version__}")
print(f"NumPy version: {np.__version__}")
print("Все зависимости успешно установлены!")
```