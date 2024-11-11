#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
template <typename T>
class Queue
{
public:
    Queue();
    Queue(const Queue& other); // Конструктор копирования
    Queue(Queue&& other) noexcept; // Конструктор перемещения
    Queue& operator=(const Queue& other); // Оператор присваивания копированием
    Queue& operator=(Queue&& other) noexcept; // Оператор присваивания перемещением
    ~Queue();

    void Push(const T& value);
    void Pop();
    bool IsEmpty() const;
    T& GetFront();
    void Clear();
    void Print() const;
    void CopyFrom(const Queue& other);

private:
    struct Node
    {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
};

template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr) {}

template <typename T>
Queue<T>::Queue(const Queue& other) : head(nullptr), tail(nullptr)
{
    CopyFrom(other);
}

template <typename T>
Queue<T>::Queue(Queue&& other) noexcept : head(other.head), tail(other.tail)
{
    other.head = nullptr;
    other.tail = nullptr;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
    if (this != &other)
    {
        Clear();
        CopyFrom(other);
    }
    return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept
{
    if (this != &other)
    {
        Clear();
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

template <typename T>
Queue<T>::~Queue()
{
    Clear();
}

// Метод для добавления элемента в очередь
template <typename T>
void Queue<T>::Push(const T& value)
{
    Node* new_node = new Node(value);
    if (IsEmpty())
    {
        head = new_node;
    }
    else
    {
        tail->next = new_node;
    }
    tail = new_node;
}

// Метод для проверки, пуста ли очередь
template <typename T>
bool Queue<T>::IsEmpty() const
{
    return head == nullptr;
}

// Метод удаления первого элемента
template <typename T>
void Queue<T>::Pop()
{
    if (IsEmpty()) {
        throw std::runtime_error("Queue is empty. Cannot dequeue.");
    }
    Node* temp = head;
    head = head->next;
    if (head == nullptr) // Если очередь стала пустой
    {
        tail = nullptr; // Обновляем tail
    }
    delete temp;
}

// Метод для получения первого элемента
template <typename T>
T& Queue<T>::GetFront()
{
    if (IsEmpty()) throw std::runtime_error("Queue is empty");
    return head->data;
}

// Очистка очереди
template <typename T>
void Queue<T>::Clear()
{
    while (!IsEmpty())
    {
        Pop();
    }
}

template <typename T>
void Queue<T>::CopyFrom(const Queue& other)
{
    if (other.head == nullptr) return;

    Node* temp = other.head;
    while (temp)
    {
        Push(temp->data);
        temp = temp->next;
    }
}

template <typename T>
void Queue<T>::Print() const
{
    Node* temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}



#endif // QUEUE_H_INCLUDED
