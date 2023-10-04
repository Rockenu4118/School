#include <iostream>

#include "./LinkedList.hpp"

using namespace std;

LinkedList::LinkedList()
{
    _head  = nullptr;
}

LinkedList::~LinkedList()
{
    // TODO
}

void LinkedList::appendNode(int val)
{
    ListNode* newNode = new ListNode;
    newNode->_val = val;
    newNode->_next = nullptr;

    // If LinkedList is empty, set new node to be head
    if (_head == nullptr)
    {
        _head = newNode;
        return;
    }

    // If LinkedList has nodes, traverse through list until
    // temp is set to last node
    ListNode* temp = _head;
    while (temp->_next != nullptr)
    {   
        temp = temp->_next;
    }

    // set new node to be _next of temp
    temp->_next = newNode;
}

void LinkedList::insertNode(int val, int location)
{
    // TODO
}

void LinkedList::deleteNode()
{
    if (_head == nullptr)
    {
        cout << "LinkedList empty." << endl;
        return;
    }

    ListNode* temp = _head;
    while (temp->_next->_next != nullptr)
    {
        temp = temp->_next;
    }

    delete temp->_next;
    temp->_next = nullptr;
}

void LinkedList::displayVals()
{
    if (_head == nullptr)
    {
        cout << "LinkedList empty." << endl;
        return;
    }

    ListNode* temp = _head;
    while (temp != nullptr)
    {
        cout << temp->_val << " " << endl;
        temp = temp->_next;
    }
}