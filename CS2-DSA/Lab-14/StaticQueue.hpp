#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class StaticQueue
{
    public:
        StaticQueue(int size)
        {
            _queueArray = new T[size];
            _queueSize  = size;
            _rear       = -1;
        }

        ~StaticQueue()
        {
            delete[] _queueArray;
        }

        bool isEmpty()
        {
            return _rear == -1 ? true : false;
        }

        bool isFull()
        {
            return _queueSize == _rear + 1 ? true : false;
        }

        void enqueue(T val)
        {
            if (isFull())
            {
                cout << "Queue is full." << endl;
                return;
            }
            
            _rear++;
            _queueArray[_rear] = val;
        }

        void dequeue(T& val)
        {
            if (isEmpty())
            {
                cout << "Queue is empty." << endl;
                return;
            }

            val = _queueArray[0];
            _rear--;

            // shift all elements to the front of the array
            for (int i = 0 ; i < _queueSize - 1 ; i++)
            {
                _queueArray[i] = _queueArray[i + 1];
            }
        }
        void printQueue()
        {
            cout << "Printing queue: ";

            for (int i = 0 ; i < _rear + 1 ; i++)
            {
                cout << _queueArray[i] << " ";
            }

            cout << endl;
        }

    private:
        T*  _queueArray;
        int _queueSize;
        int _rear;
};

#endif