#ifndef MATH_STACK_H
#define MATH_STACK_H

using namespace std;

#include "./IntStack.hpp"

class MathStack : public IntStack
{
    public:
        MathStack(int size);

        void add();
        void sub();
};

#endif