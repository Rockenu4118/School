#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

#include "./Queue.hpp"

using namespace std;

class BinaryTree
{
    private:
        struct TreeNode
        {
            TreeNode* _left;
            TreeNode* _right;
            int       _item;
        };

        void insert(TreeNode*& nodePtr, TreeNode*& newNode);
        void displayInOrder(TreeNode* nodePtr);
        void destroySubTree(TreeNode* nodePtr);

        // Assignment 21 Specific func
        void insertIntoQueue(TreeNode* nodePtr, Queue* queue);

    public:
        BinaryTree();
        ~BinaryTree();

        // Assignment 21 Specific func
        void populateQueue(Queue* queue);
        
        void insertNode(int item);
        void displayInOrder();
        bool isEmpty();

    private:
        TreeNode* _root;
};

#endif