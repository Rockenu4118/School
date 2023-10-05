#include <iostream>

#include "./LinkedList.hpp"

using namespace std;

LinkedList::LinkedList()
{
    _head  = nullptr;
}

LinkedList::~LinkedList()
{
    if (_head == nullptr) 
    {
        cout << "List was empty." << endl;
        return;
    }

    ListNode* temp1 = _head;
    ListNode* temp2 = temp1->_next;

    while (temp1 != nullptr)
    {
        temp2 = temp1->_next;
        delete temp1;
        temp1 = temp2;
    }
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
    ListNode* newNode = new ListNode;
    newNode->_val     = val;

    // If list is empty, point head to newNode
    if (_head == nullptr)
    {
        _head        = newNode;
        _head->_next = nullptr;
        return;
    }

    // If intended insert location is 0, make the newNode point to the current head
    // Make the newNode the new head of the list
    if (location == 0)
    {
        newNode->_next = _head;
        _head          = newNode;
        return;
    }

    ListNode* temp1   = _head;
    ListNode* temp2   = temp1->_next;
    int       nodeNum = 0;

    while (nodeNum != location - 1)
    {
        if (temp1->_next == nullptr)
        {
            temp2 = nullptr;
            break;
        }

        temp1 = temp1->_next;
        temp2 = temp1->_next;
        
        nodeNum++;
    }

    temp1->_next = newNode;
    newNode->_next = temp2;
}

void LinkedList::deleteNode()
{
    if (_head == nullptr)
    {
        cout << "LinkedList empty." << endl;
        return;
    }

    if (_head->_next == nullptr)
    {
        delete _head;
        _head = nullptr;
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

    cout << "Displaying vals: ";
    ListNode* temp = _head;
    while (temp != nullptr)
    {
        cout << temp->_val << " ";
        temp = temp->_next;
    }
    cout << endl;
}
