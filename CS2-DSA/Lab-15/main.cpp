#include <iostream>

#include "./IntStack.hpp"
#include "./MathStack.hpp"

using namespace std;

int main()
{
    MathStack stack = MathStack(5);
    int num1;
    int num2;

    stack.pop(num1);

    stack.push(22);
    stack.push(55);
    stack.push(19);
    stack.push(11);
    stack.push(3);

    stack.printStack();

    stack.add();
    stack.printStack();
    stack.sub();
    stack.printStack();
    stack.add();
    stack.printStack();
    stack.add();
    stack.printStack();
    stack.add();

    return 0;
}