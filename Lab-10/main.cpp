// Lab 10
// 
// Design our own linked list class to hold a series of integers. The class should have member 
// function for appending, inserting, and deleting nodes. Do not forget to add a destructor that 
// destroy the list. Demonstrate the class with a driver program. 

#include <iostream>

#include "./LinkedList.hpp"

using namespace std;

int main()
{
    std::cout << "Program running..." << std::endl;
    LinkedList list = LinkedList();

    list.appendNode(10);
    list.appendNode(22);
    list.appendNode(3);
    list.appendNode(17);
    list.appendNode(8);

    list.deleteNode();
    
    list.displayVals();




    return 0;
}
