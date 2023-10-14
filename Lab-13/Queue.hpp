#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
    private:
        struct QueueNode
        {
            double     _val;
            QueueNode* _next;
        };

    public:
        Queue();
        ~Queue();

        void enqueue(double num);
        void dequeue(double& num);
        bool isEmpty();
        void clear();
        void printQueue();

    private:
        QueueNode* _front;
        QueueNode* _rear;
};

#endif