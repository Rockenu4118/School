#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class Stack
{
    public:
        Stack(int size);
        ~Stack();

        bool isFull();
        bool isEmpty();
        void pop(string& string);
        void push(string string);
        void printStack();
        
    private:
        string* _stackArray;
        int     _stackSize;
        int     _top;
};

#endif
