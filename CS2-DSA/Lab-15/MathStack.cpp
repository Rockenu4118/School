#include <iostream>

#include "./MathStack.hpp"

using namespace std;


MathStack::MathStack(int size) : IntStack(size)
{}

void MathStack::add()
{
    if (_top < 1)
    {
        cout << "Insufficient elements within stack." << endl;
    }
    else 
    {
        int num1 = _stackArray[_top];
        int num2 = _stackArray[_top - 1];
        
        _stackArray[_top] = 0;
        _stackArray[_top - 1] = num1 + num2;

        _top--;
    }
}

void MathStack::sub()
{
    if (_top < 1)
    {
        cout << "Insufficient elements within stack." << endl;
    }
    else
    {
        int num1 = _stackArray[_top];
        int num2 = _stackArray[_top - 1];

        _stackArray[_top] = 0;
        _stackArray[_top - 1] = num1 - num2;

        _top--;
    }
}