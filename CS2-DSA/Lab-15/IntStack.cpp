#include <iostream>
#include <string>

#include "./IntStack.hpp"

using namespace std;


IntStack::IntStack(int size)
{
    _stackArray = new int[size];
    _stackSize  = size;
    _top        = -1;
}

IntStack::~IntStack()
{
    delete[] _stackArray;
}

bool IntStack::isFull()
{
    return _top == _stackSize - 1 ? true : false;
}

bool IntStack::isEmpty()
{
    return _top == -1 ? true : false;
}

void IntStack::pop(int& num)
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    } 
    else 
    {
        num               = _stackArray[_top];
        _stackArray[_top] = 0;
        _top--;
    }
}

void IntStack::push(int num)
{
    if (isFull())
    {
        cout << "Stack is full." << endl;
    } 
    else 
    {
        _top++;
        _stackArray[_top] = num;
    }
}

void IntStack::printStack()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Printing stack." << endl;

    for (int i = _stackSize - 1 ; i >= 0 ; i--)
    {
        cout << "#" << i << ": " << _stackArray[i] << endl;
    }
}