// Lab 14
//
// Write your own version of the class template that will create a static queue of any data type. Demonstrate the class with a driver program.

#include <iostream>

#include "./StaticQueue.hpp"

using namespace std;

int main()
{   
    StaticQueue<int> queue = StaticQueue<int>(5);

    int val;

    queue.dequeue(val);

    queue.enqueue(10);
    queue.enqueue(12);
    queue.enqueue(3);
    queue.enqueue(7);
    queue.enqueue(9);
    queue.enqueue(33);

    queue.printQueue();

    queue.dequeue(val);
    cout << "Dequeued val: " << val << endl;

    queue.dequeue(val);
    cout << "Dequeued val: " << val << endl;

    queue.printQueue();

    return 0;
}