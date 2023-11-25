// Assignment 21
//
// Write a program that stores a series of integer numbers in a binary tree. 
// Then have the program insert the values into a queue in ascending order. 
// Dequeue the values and display them on the screen to confirm that they were stored in the proper order.

#include <iostream>

#include "./BinaryTree.hpp"
#include "./Queue.hpp"

using namespace std;

int main()
{
    BinaryTree* tree = new BinaryTree();
    Queue* queue     = new Queue();

    tree->insertNode(5);
    tree->insertNode(9);
    tree->insertNode(7);
    tree->insertNode(18);
    tree->insertNode(3);
    tree->insertNode(8);
    tree->insertNode(12);
    tree->insertNode(6);
    tree->insertNode(4);
    tree->insertNode(20);

    tree->displayInOrder();

    tree->populateQueue(queue);

    queue->printQueue();

    cout << "Dequeuing: ";
    for (int i = 0 ; i < 10 ; i++)
    {
        int num = 0;
        queue->dequeue(num);
        cout << num << " ";
    }
    cout << endl;

    delete tree;
    delete queue;

    return 0;
}
