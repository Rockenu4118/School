#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
    private:
        struct QueueNode
        {
            int        _val;
            QueueNode* _next;
        };

    public:
        Queue();
        ~Queue();

        void enqueue(int num);
        void dequeue(int& num);
        bool isEmpty();
        void clear();
        void printQueue();

    private:
        QueueNode* _front;
        QueueNode* _rear;
};

#endif