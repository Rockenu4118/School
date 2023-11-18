#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

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

        void displayInOrder(TreeNode* nodePtr)
        {
            if (nodePtr != nullptr)
            {
                displayInOrder(nodePtr->_left);
                cout << nodePtr->_item << " ";
                displayInOrder(nodePtr->_right);
            }
        }

        void displayPreOrder(TreeNode* nodeptr)
        {
            if (nodeptr != nullptr)
            {
                cout << nodeptr->_item << " ";
                displayPreOrder(nodeptr->_left);
                displayPreOrder(nodeptr->_right);
            }
        }

        void displayPostOrder(TreeNode* nodePtr)
        {
            if (nodePtr != nullptr)
            {
                displayPostOrder(nodePtr->_left);
                displayPostOrder(nodePtr->_right);
                cout << nodePtr->_item << " ";
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

        int treeHeight(TreeNode* nodePtr)
        {
            if (nodePtr == nullptr)
                return 0;
            else
            {
                int leftHeight = treeHeight(nodePtr->_left);
                int rightHeight = treeHeight(nodePtr->_right);

                if (leftHeight > rightHeight)
                    return (leftHeight + 1);
                else
                    return (rightHeight + 1);
            }
        }

        int nodeCount(TreeNode* nodePtr)
        {
            if (nodePtr == nullptr)
                return 0;
            else
            {
                int leftCount = nodeCount(nodePtr->_left);
                int rightCount = nodeCount(nodePtr->_right);

                return (1 + leftCount + rightCount);
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

        int getTreeHeight()
        {
            return treeHeight(_root);
        }

        int getNodeCount()
        {
            return nodeCount(_root);
        }

        void insertNode(T item)
        {
            TreeNode* newNode = new TreeNode;
            newNode->_left    = nullptr;
            newNode->_right   = nullptr;
            newNode->_item    = item;

            insert(_root, newNode);
        }

        bool searchNode(T item)
        {
            TreeNode* nodeptr = _root;

            while (nodeptr != nullptr)
            {
                if (nodeptr->_item == item)
                    return true;
                else if (item < nodeptr->_item)
                    nodeptr = nodeptr->_left;
                else
                    nodeptr = nodeptr->_right;
            }
            return false;
        }

        void remove(T item)
        {
            if (searchNode(item))
                deleteNode(item, _root);
            else
                cout << "Item not present." << endl;
        }

        void displayInOrder()
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

        void displayPreOrder()
        {
            if (isEmpty())
            {
                cout << "Binary tree is empty." << endl;
                return;
            }

            cout << "Display Pre Order: ";
            displayPreOrder(_root);
            cout << endl;
        }

        void displayPostOrder()
        {
            if (isEmpty())
            {
                cout << "Binary tree is empty." << endl;
                return;
            }

            cout << "Display Post Order: ";
            displayPostOrder(_root);
            cout << endl;
        }

        bool isEmpty()
        {
            return _root == nullptr ? true : false;
        }

    private:
        TreeNode* _root;
};

#endif
