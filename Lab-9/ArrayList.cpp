#include <iostream>

#include "./ArrayList.hpp"

using namespace std;

void ArrayList::insert(int num)
{
    if (isFull()) {
        cout << "Array is full." << endl;
        return;
    }

    _nums[_elements] = num;
    _elements++;
}

void ArrayList::remove()
{
    _nums[_elements - 1] = 0;
    _elements--;
}

bool ArrayList::isFull()
{
    return sizeof(_nums) / sizeof(_nums[0]) == _elements;
}

int ArrayList::find(int index)
{
    return _nums[index];
}

int ArrayList::getLength()
{
    return _elements;
}

void ArrayList::makeEmpty()
{
    for (int i = 0 ; i < _elements ; i++)
    {
        _nums[i] = 0;
    }

    _elements = 0;
}

void ArrayList::showValues()
{
    if (_elements == 0) {
        cout << "Array empty" << endl;
        return;
    }

    cout << "Array values: ";

    for (int i = 0 ; i < _elements ; i++)
    {
        cout << _nums[i];

        if (i == _elements - 1) {
            cout << endl;
        } else {
            cout << ", ";
        }
    }
}

