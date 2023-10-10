// Write your own version of a class that will create a stactic stack of 
// String data type. The static stack class needs to have  the following members:
// 
// 1. Member Variables. stackArray (a pointer variable which is going to be used 
// to dynamically  allocate an array for storage), stacksize (an integer to hold the 
// size of the stack) and top (an integer that is used to mark the top of the stack).
//
// 2. Member Functions. Constructor  (it accepts an integer argument that specifies 
// the size of the stak), Destructor, isFull, isEmpty, pop, and push. 
//
// Demonstrate the class with a driver program.


#include <iostream>

#include "./Stack.hpp"

using namespace std;

int main()
{
    cout << "Program running..." << endl;

    Stack  stack = Stack(4);
    string string1;
    string string2;

    stack.pop(string1);

    stack.push("hello");
    stack.push("word1");
    stack.push("test");
    stack.push("another");
    stack.push("last");

    stack.printStack();

    stack.pop(string1);
    cout << "Popped word 1: " << string1 << endl;
    
    stack.pop(string2);
    cout << "Popped word 2: " << string2 << endl;
    
    stack.printStack();

    return 0;
}
