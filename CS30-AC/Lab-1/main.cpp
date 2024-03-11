#include <iostream>
#include <string>

#include "./LinkedList.hpp"

using namespace std;

int main()
{
    cout << "Linked List...\n\n";

    LinkedList ls;
    ls.insertToFront("Jack");
    ls.insertToFront("Germaine");
    ls.insertToFront("Agatha");
    ls.insertToFront("Agnes");

    for (int k = 0; k < ls.size(); k++)
    {
        string x;
        ls.get(k, x);
        cout << x << endl;
    }

    ls.printList();
    ls.printReverse();

    LinkedList e1;
    e1.insertToFront("bell");
    e1.insertToFront("biv");
    e1.insertToFront("devoe");
    LinkedList e2;
    e2.insertToFront("Andre");
    e2.insertToFront("Big Boi");
    e1.append(e2);

    e1.printList();

    return 0;
}
