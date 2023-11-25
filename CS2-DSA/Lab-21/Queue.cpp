#include <iostream>

#include "./Queue.hpp"

using namespace std;

Queue::Queue()
{
    _front = nullptr;
    _rear  = nullptr;
}

Queue::~Queue()
{
    clear();
}

void Queue::enqueue(int num)
{
    QueueNode* newNode = new QueueNode;
    newNode->_val  = num;
    newNode->_next = nullptr;

    if (_front == nullptr)
    {
        _front         = newNode;
        _rear          = newNode;
        newNode->_next = nullptr;
        return;
    }

    _rear->_next = newNode;
    _rear = newNode;
}

void Queue::dequeue(int& num)
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    QueueNode* temp = _front->_next;
    num = _front->_val;
    delete _front;
    _front = temp;
}

bool Queue::isEmpty()
{
    return _front == nullptr ? true : false;
}

void Queue::clear()
{
    QueueNode* temp = _front;
    while (temp != nullptr)
    {
        temp = temp->_next;
        delete _front;
        _front = temp;
    }
}

void Queue::printQueue()
{
    cout << "Printing queue: ";

    if (isEmpty())
    {
        cout << "empty" << endl;
        return;
    }

    QueueNode* temp = _front;
    while (temp != nullptr)
    {
        cout << temp->_val << " ";
        temp = temp->_next;
    }
    
    cout << endl;
}