// Linear Search

// Modify the linked list class you created in the previous programming Assignment. Add to  a print member fuction. 
// The function should display all the values in the linke list. In addition, include a member function named search 
// that returns the position of specific value, x, in the linked list. The first node in the list is at position 0, 
// the second node is at position 1, and so on. If x is not found on the list, the search should return -1, Test these
// member  functions using an appropiate driver program.

#include <iostream>

#include "./LinkedList.hpp"

using namespace std;

int main()
{
    LinkedList list = LinkedList();

    cout << "Appendings vals" << endl;
    list.appendNode(10);
    list.appendNode(22);
    list.appendNode(3);
    list.appendNode(17);
    list.appendNode(8);
    list.appendNode(72);
    list.displayVals();

    cout << "Inserting 50 at position 3" << endl;
    list.insertNode(50, 3);
    list.displayVals();

    cout << "Deleting last node" << endl;
    list.deleteNode();
    list.displayVals();

    return 0;
}
