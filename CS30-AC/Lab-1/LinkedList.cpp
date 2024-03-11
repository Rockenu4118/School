#include <string>

#include "./LinkedList.hpp"


LinkedList::LinkedList(const LinkedList& rhs) : head(nullptr)
{
    append(rhs);
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        popBack();
    }
}

const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    return rhs;
}

void LinkedList::insertToFront(const ItemType& val)
{
    Node* newNode = new Node;
    newNode->value = val;

    newNode->next = head;
    head = newNode;
}

void LinkedList::printList() const
{
    Node* curr = head;

    cout << "List: ";

    while (curr != nullptr)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }

    cout << "\n";
}

bool LinkedList::get(int i, ItemType& item) const
{
    Node* temp = head;
    int currI = 0;

    while (currI != i)
    {
        temp = temp->next;

        if (temp == nullptr)
            return false;

        currI++;
    }

    item = temp->value;
    
    return true;
}

void LinkedList::reverseList()
{
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
 
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void LinkedList::printReverse() const
{
    cout << "Reverse list: ";
    reversePrint(head);
    cout << "\n";
}

void LinkedList::append(const LinkedList& other)
{
    for (int i = 0 ; i < other.size() ; i++)
    {
        ItemType val;
        other.get(i, val);
        pushBack(val);
    }
}

void LinkedList::swap(LinkedList& other)
{
    Node* temp = head;
    head = other.ptrHead();
    other.setHead(temp);
}

int LinkedList::size() const
{
    Node* temp = head;

    int size = 0;

    while (temp != nullptr)
    {
        size++;

        temp = temp->next;
    }

    return size;
}

void LinkedList::popBack()
{
    if (head == nullptr)
    {
        std::cout << "Linked List empty.\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void LinkedList::pushBack(const ItemType val)
{   
    Node* newNode = new Node;
    newNode->value = val;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void LinkedList::reversePrint(Node* head) const
{
    if (head == nullptr)
        return;

    reversePrint(head->next);

    cout << head->value << " ";
}