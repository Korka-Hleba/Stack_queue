#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <stdexcept>


template <typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack& other); // ����������� �����������
    Stack(Stack&& other) noexcept; // ����������� �����������
    Stack& operator=(const Stack& other); // �������� ������������ ������������
    Stack& operator=(Stack&& other) noexcept; // �������� ������������ ������������
    ~Stack();

    void Push(const T& value);
    void Pop();
    bool IsEmpty() const;
    T& GetFront();
    void Clear();
    void Print() const; // ����� ��� ������ ����� �� �����
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

// ���������� ������������ �� ���������
template <typename T>
Stack<T>::Stack() : head(nullptr) {}

// ���������� ������������ �����������
template <typename T>
Stack<T>::Stack(const Stack& other) : head(nullptr)
{
    CopyFrom(other);
}

// ���������� ������������ �����������
template <typename T>
Stack<T>::Stack(Stack&& other) noexcept : head(other.head)
{
    other.head = nullptr;
}

// �������� ������������ ������������
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

// �������� ������������ ������������
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

// ����������
template <typename T>
Stack<T>::~Stack()
{
    Clear();
}

// ����� ��� ���������� �������� � ����
template <typename T>
void Stack<T>::Push(const T& value)
{
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

// ����� ��� ��������, ���� �� ����
template <typename T>
bool Stack<T>::IsEmpty() const
{
    return head == nullptr;
}

// ����� �������� �������� ��������
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

// ����� ��� ��������� �������� ��������
template <typename T>
T& Stack<T>::GetFront()
{
    if (IsEmpty()) throw std::runtime_error("Stack is empty");
    return head->data;
}

// ������� �����
template <typename T>
void Stack<T>::Clear()
{
    while (!IsEmpty())
    {
        Pop();
    }
}

// ����� ��� ����������� ����������� �����
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

// ����� Print ��� ������ ����������� �����
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
