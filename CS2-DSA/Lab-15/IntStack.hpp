#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class IntStack
{
    public:
        IntStack(int size);
        virtual ~IntStack();

        bool isFull();
        bool isEmpty();
        void pop(int& num);
        void push(int num);
        void printStack();
        
    protected:
        int* _stackArray;
        int  _stackSize;
        int  _top;
};

#endif
