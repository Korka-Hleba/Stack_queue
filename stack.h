#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <stdexcept>


template <typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack& other); // Конструктор копирования
    Stack(Stack&& other) noexcept; // Конструктор перемещения
    Stack& operator=(const Stack& other); // Оператор присваивания копированием
    Stack& operator=(Stack&& other) noexcept; // Оператор присваивания перемещением
    ~Stack();

    void Push(const T& value);
    void Pop();
    bool IsEmpty() const;
    T& GetFront();
    void Clear();
    void Print() const; // Метод для вывода стека на экран
    void CopyFrom(const Stack& other);


private:
    struct Node
    {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;
};

// Реализация конструктора по умолчанию
template <typename T>
Stack<T>::Stack() : head(nullptr) {}

// Реализация конструктора копирования
template <typename T>
Stack<T>::Stack(const Stack& other) : head(nullptr)
{
    CopyFrom(other);
}

// Реализация конструктора перемещения
template <typename T>
Stack<T>::Stack(Stack&& other) noexcept : head(other.head)
{
    other.head = nullptr;
}

// Оператор присваивания копированием
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
    if (this != &other)
    {
        Clear();
        CopyFrom(other);
    }
    return *this;
}

// Оператор присваивания перемещением
template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept
{
    if (this != &other)
    {
        Clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

// Деструктор
template <typename T>
Stack<T>::~Stack()
{
    Clear();
}

// Метод для добавления элемента в стек
template <typename T>
void Stack<T>::Push(const T& value)
{
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

// Метод для проверки, пуст ли стек
template <typename T>
bool Stack<T>::IsEmpty() const
{
    return head == nullptr;
}

// Метод удаления верхнего элемента
template <typename T>
void Stack<T>::Pop()
{
    if (IsEmpty())
    {
        throw std::runtime_error("Stack is empty");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Метод для получения верхнего элемента
template <typename T>
T& Stack<T>::GetFront()
{
    if (IsEmpty()) throw std::runtime_error("Stack is empty");
    return head->data;
}

// Очистка стека
template <typename T>
void Stack<T>::Clear()
{
    while (!IsEmpty())
    {
        Pop();
    }
}

// Метод для копирования содержимого стека
template <typename T>
void Stack<T>::CopyFrom(const Stack& other)
{
    if (other.head == nullptr) return;

    Node* temp = other.head;
    head = new Node(temp->data);
    Node* copy_node = head;
    temp = temp->next;

    while (temp)
    {
        copy_node->next = new Node(temp->data);
        copy_node = copy_node->next;
        temp = temp->next;
    }
}

// Метод Print для вывода содержимого стека
template <typename T>
void Stack<T>::Print() const
{
    Node* temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif // STACK_H_INCLUDED
