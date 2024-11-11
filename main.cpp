#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int main()

{
    Stack<int> stack;
    int stack_size;

    Queue<int> queue;
    int queue_size;

    std::cout << "Enter size of stack : ";
    std::cin >> stack_size;
    std::cout << "Enter elements:\n";
    for (int i = 0; i < stack_size; ++i)
    {
        int elem;
        std::cin >> elem;
        stack.Push(elem);
    }

    std::cout << "Your stack: " << std::endl;
    stack.Print();

    if (!stack.IsEmpty())
    {
        std::cout << "Head element: " << stack.GetFront() << std::endl;
        stack.Pop();
        std::cout << "Stack after Pop: " << std::endl;
        stack.Print();
    }



    std::cout << "Enter size of queue : ";
    std::cin >> queue_size;
    std::cout << "Enter elements:\n";
    for (int i = 0; i < queue_size; ++i)
    {
        int elem;
        std::cin >> elem;
        queue.Push(elem);
    }

    std::cout << "Your queue: " <<std::endl;
    queue.Print();
    if (!queue.IsEmpty())
    {
        std::cout << "Head element: " << queue.GetFront() << std::endl;
        queue.Pop();
        std::cout << "Queue after Pop: " << std::endl;
        queue.Print();
    }

    return 0;
}

