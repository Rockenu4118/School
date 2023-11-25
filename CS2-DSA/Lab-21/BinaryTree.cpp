#include <iostream>

#include "./Queue.hpp"
#include "./BinaryTree.hpp"

using namespace std;

BinaryTree::BinaryTree()
{
    _root = nullptr;
}

BinaryTree::~BinaryTree()
{
    destroySubTree(_root);
}

void BinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->_item < nodePtr->_item)
        insert(nodePtr->_left, newNode);
    else 
        insert(nodePtr->_right, newNode);
}

void BinaryTree::displayInOrder(TreeNode* nodePtr)
{
    if (nodePtr != nullptr)
    {
        displayInOrder(nodePtr->_left);
        cout << nodePtr->_item << " ";
        displayInOrder(nodePtr->_right);    
    }
}

void BinaryTree::destroySubTree(TreeNode* nodePtr)
{
    if (nodePtr != nullptr)
    {
        if (nodePtr->_left != nullptr)
            destroySubTree(nodePtr->_left);
        else if (nodePtr->_right != nullptr)
            destroySubTree(nodePtr->_right);
        else
            delete nodePtr;
    }
}

void BinaryTree::insertIntoQueue(TreeNode* nodePtr, Queue* queue)
{
    if (nodePtr != nullptr)
    {
        insertIntoQueue(nodePtr->_left, queue);
        queue->enqueue(nodePtr->_item);
        insertIntoQueue(nodePtr->_right, queue);    
    }
}

void BinaryTree::populateQueue(Queue* queue)
{
    insertIntoQueue(_root, queue);
}

void BinaryTree::insertNode(int item)
{
    TreeNode* newNode = new TreeNode;
    newNode->_left    = nullptr;
    newNode->_right   = nullptr;
    newNode->_item    = item;

    insert(_root, newNode);
}

void BinaryTree::displayInOrder()
{
    if (isEmpty())
    {
        cout << "Binary tree is empty." << endl;
        return;
    }

    cout << "Display In Order: ";
    displayInOrder(_root);
    cout << endl;
}

bool BinaryTree::isEmpty()
{
    return _root == nullptr ? true : false;
}