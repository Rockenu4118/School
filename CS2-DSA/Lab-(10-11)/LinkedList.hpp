#ifndef LINKED_LIST_H
#define LINKED_LIST_H


class LinkedList
{
    private:
        struct ListNode
        {
            int       _val;
            ListNode* _next;
        };

    public:
        LinkedList();
        ~LinkedList();

        void appendNode(int val);
        void insertNode(int val, int location);
        void deleteNode();
        int  search(int val);
        void displayVals();

    private:
        ListNode* _head;
};

#endif