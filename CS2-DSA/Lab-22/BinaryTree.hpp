#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

#include "./EmployeeInfo.hpp"

using namespace std;

template <typename T>
class BinaryTree
{
    private:
        struct TreeNode
        {
            TreeNode* _left;
            TreeNode* _right;
            T         _item;
        };

        void insert(TreeNode*& nodePtr, TreeNode*& newNode)
        {
            if (nodePtr == nullptr)
                nodePtr = newNode;
            else if (newNode->_item < nodePtr->_item)
                insert(nodePtr->_left, newNode);
            else 
                insert(nodePtr->_right, newNode);
        }

        void deleteNode(T item, TreeNode*& nodePtr)
        {
            if (item < nodePtr->_item)
                deleteNode(item, nodePtr->_left);
            else if (item > nodePtr->_item)
                deleteNode(item, nodePtr->_right);
            else
                makeDeletion(nodePtr);
        }

        void makeDeletion(TreeNode*& nodePtr)
        {
            TreeNode* tempNodePtr = nullptr;

            if (nodePtr == nullptr)
            {
                cout << "Can't delete empty node." << endl;
            } else if (nodePtr->_right == nullptr)
            {
                tempNodePtr = nodePtr;
                nodePtr = nodePtr->_left;
                delete tempNodePtr;
            } else if (nodePtr->_left == nullptr)
            {
                tempNodePtr = nodePtr;
                nodePtr = nodePtr->_right;
                delete tempNodePtr;
            } else
            {
                tempNodePtr = nodePtr->_right;
                while (tempNodePtr->_left)
                {
                    tempNodePtr = tempNodePtr->_left;    
                }
                tempNodePtr->_left = nodePtr->_left;
                tempNodePtr = nodePtr;
                nodePtr = nodePtr->_right;
                delete tempNodePtr;
            }
        }

        void destroySubTree(TreeNode* nodePtr)
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

    public:
        BinaryTree()
        {
            _root = nullptr;
        }

        ~BinaryTree()
        {
            destroySubTree(_root);
        }

        void insertNode(T item)
        {
            TreeNode* newNode = new TreeNode;
            newNode->_left    = nullptr;
            newNode->_right   = nullptr;
            newNode->_item    = item;

            insert(_root, newNode);
        }

        void searchNode(int id)
        {
            TreeNode* nodeptr = _root;

            while (nodeptr != nullptr)
            {
                if (nodeptr->_item == id)
                {
                    cout << nodeptr->_item;
                    return;
                }
                else if (nodeptr->_item < id)
                    nodeptr = nodeptr->_right;
                else
                    nodeptr = nodeptr->_left;
            }
            cout << "Employee not found." << std::endl;
        }

        bool isEmpty()
        {
            return _root == nullptr ? true : false;
        }

    private:
        TreeNode* _root;
};

#endif