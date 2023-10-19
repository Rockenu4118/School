#include <iostream>
#include <string>

#include "./Stack.hpp"

using namespace std;


Stack::Stack(int size)
{
    _stackArray = new string[size];
    _stackSize  = size;
    _top        = -1;
}

Stack::~Stack()
{
    delete[] _stackArray;
}

bool Stack::isFull()
{
    return _top == _stackSize - 1 ? true : false;
}

bool Stack::isEmpty()
{
    return _top == -1 ? true : false;
}

void Stack::pop(string& string)
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
    } 
    else 
    {
        string            = _stackArray[_top];
        _stackArray[_top] = "";
        _top--;
    }
}

void Stack::push(string string)
{
    if (isFull())
    {
        cout << "Stack is full." << endl;
    } 
    else 
    {
        _top++;
        _stackArray[_top] = string;
    }
}

void Stack::printStack()
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