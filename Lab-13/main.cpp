// Write your own version of a class that will create a Dynamic Queue of 
// double data type.The dynamic queue class needs to have  the following members:
//
// Member Functions. Constructor, Destructor, enqueue, dequeue, isEmpty,and clear. 
// 
// Demonstrate the class with a driver program.

#include <iostream>

#include "./Queue.hpp"

using namespace std;

int main()
{
    Queue queue;

    queue.printQueue();

    queue.enqueue(10.5);
    queue.enqueue(7.8);
    queue.enqueue(14.1);
    queue.enqueue(22.9);

    queue.printQueue();

    double test;

    queue.dequeue(test);
    cout << "Dequeue: " << test << endl;

    queue.dequeue(test);
    cout << "Dequeue: " << test << endl;

    queue.printQueue();

    queue.clear();

    queue.printQueue();

    queue.dequeue(test);
    
    return 0;
}
