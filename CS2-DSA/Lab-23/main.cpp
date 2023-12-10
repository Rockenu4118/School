// Lab 23
//
// Design a class named PersonData with the following member variables:
//
// lastName
// firstName
// address
// city
// state
// zip
// phone
//
// Write the appropriate accessor and mutator functions for these member variables. Next, design a 
// class named CustomerData, which is derived from the PersonData class. The CustomerData class 
// should have the following member variables:
// customerNumber
// mailingList
//
// The customerNumber variable will be used to hold a unique integer for each customer. The mailingList 
// variable should be a bool. It will be set to true if the customer wishes to be on a mailing list, or 
// false if the customer does not wish to be on a mail- ing list. Write appropriate accessor and mutator 
// functions for these member variables. Demonstrate an object of the CustomerData class in a simple program.

#include <iostream>

#include "./CustomerData.hpp"

using namespace std;

int main()
{
    CustomerData customer1;

    string inputStr;
    int    inputNum;
    char   inputChar;

    cout << "Enter customer's last name: ";
    cin >> inputStr;
    customer1.setLastName(inputStr);
    cout << "Enter customer's first name: ";
    cin >> inputStr;
    cin.ignore();
    customer1.setFirstName(inputStr);
    cout << "Enter customer's address: ";
    getline(cin, inputStr);
    customer1.setAddress(inputStr);
    cout << "Enter customer's city: ";
    getline(cin, inputStr);
    customer1.setCity(inputStr);
    cout << "Enter customer's state: ";
    getline(cin, inputStr);
    customer1.setState(inputStr);
    cout << "Enter customer's Zip: ";
    cin >> inputNum;
    customer1.setZip(inputNum);
    cout << "Enter customer's Phone number: ";
    cin >> inputStr;
    customer1.setPhone(inputStr);
    cout << "Enter customer's Customer number: ";
    cin >> inputNum;
    customer1.setCustomerNumber(inputNum);
    cout << "Enter 'y' if customer is on mailing list, 'n' if not: ";
    cin >> inputChar;
    if (inputChar == 'y')
        customer1.setMailingList(true);
    else
        customer1.setMailingList(false);

    cout << "Displaying customer data."                          << endl;
    cout << "Last name:       " << customer1.getLastName()       << endl;
    cout << "First name:      " << customer1.getFirstName()      << endl;
    cout << "Address:         " << customer1.getAddress()        << endl;
    cout << "City:            " << customer1.getCity()           << endl;
    cout << "State:           " << customer1.getState()          << endl;
    cout << "Zip:             " << customer1.getZip()            << endl;
    cout << "Phone number:    " << customer1.getPhone()          << endl;
    cout << "Customer number: " << customer1.getCustomerNumber() << endl;

    cout << "Mailing list:    " << (customer1.getMailingList() ? "Yes" : "No") << endl;

    return 0;
}
