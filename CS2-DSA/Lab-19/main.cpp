// Assignment #19
//
// Write your own version of a class template that will create a binary tree that can
// hold values of any data type. Demonstrate the class with a driver program.

#include <iostream>

#include "./BinaryTree.hpp"

using namespace std;

int main()
{
    cout << "Program running." << endl;

    BinaryTree<int> tree;

    tree.insertNode(5);
    tree.insertNode(9);
    tree.insertNode(7);
    tree.insertNode(3);
    tree.insertNode(8);
    tree.insertNode(12);
    tree.insertNode(6);
    tree.insertNode(4);
    tree.insertNode(20);

    tree.displayPreOrder();
    tree.displayPostOrder();
    tree.displayInOrder();

    cout << "Contains 7?: "  << tree.searchNode(7)  << endl;
    cout << "Contains 16?: " << tree.searchNode(16) << endl;

    tree.remove(9);

    tree.displayInOrder();

    return 0;
}
