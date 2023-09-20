// Write a program that uses a structure to store the following data about a customer account:
//
//     Customer name
//     Customer address
//     City
//     State
//     ZIP code
//     Telephone
//     Account balance
//     Date of last payment
//
// The program should use an array of at least 20 structures. It should let the user enter data into the array,
// change the contents of any element, and display all the data stored in the array. The program should have a menu-driven user interface.
//
// Prompts And Output Labels. Your main menu should be the following:
//     1. Enter new account information
//     2. Change account information
//     3. Display all account information
//     4. Exit the program
// The user is expected to enter 1 or 2 or 3 or 4.
// The main menu is displayed at the start of the program and after the handling of choices 1, 2 and 3.
//
// If 1 is entered for the main menu, the program prompts for each of the data listed above, in the order listed above, using the above
// data descriptions (e.g. "ZIP code") as prompts (followed in each case by a colon). After reading in and processing the data, the program
// prints
//     You have entered information for customer number X
// where X is the customer number: 0 for the first customer and increasing by 1 for each subsequent customer that is entered.
//
// If 2 is entered for the main menu, the program prompts for the customer number:
//     Customer number:
// Upon entering a valid customer number the program displays all the data for the particular customer that has been saved:
//     Customer name: ...
//     Customer address: ...
//     City: ...
//     State: ...
//     ZIP code: ...
//     Telephone: ...
//     Account balance: ...
//     Date of last payment: ...
//
// The program then skips one or two lines and prompts for a change, using the same prompts as in choice 1 above for all the data items
// associated with a customer.
//
// If 3 is entered for the main menu, the program displays all the data for each customer that has been saved, using the display format in
// choice 2 above. After the display of each customer the program prompts "Press enter to continue..." and waits for the user to hit
// return.
//
// If 4 is entered for the main menu, the program terminates.
//
// Input Validation (OPTIONAL).When the data for a new account is entered, be sure the user enters data for all the fields. No negative account balances should be
// entered
//


#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;


struct Customer
{
    string name;
    string address;
    string city;
    string state;
    int    zipCode;
    string telephone;
    double accountBalance;
    string dateLastPayment;
};

void displayMenu(int& selection);
void createAccount(Customer customers[], int& customerCount);
void modifyAccount(Customer customers[], int customerCount);
void displayAllAccounts(Customer customers[], int customerCount);


int main()
{
    Customer customers[20];
    int      customerCount = 0;

    int selection = 0;
    
    
    do
    {
        displayMenu(selection);
        
        switch (selection) {
            case 1:
                createAccount(customers, customerCount);
                break;
            case 2:
                modifyAccount(customers, customerCount);
                break;
            case 3:
                displayAllAccounts(customers, customerCount);
                break;
            case 4:
                cout << "Closing account menu..." << endl;
                break;
            default:
                cout << "Invalid selection, please try again..." << endl;
                break;
        }
    }
    while (selection != 4);
    
    
    return 0;
}

void displayMenu(int& selection)
{
    cout << "Account Menu, please select an option...\n" << endl;
    cout << "1. Enter new account information" << endl;
    cout << "2. Change account information" << endl;
    cout << "3. Display all account information" << endl;
    cout << "4. Exit the program" << endl;
    
    cout << "\nSelection: ";
    cin >> selection;
}

void createAccount(Customer customers[], int& customerCount)
{
    cout << "Please enter info for customer #" << customerCount << ": " << endl;
    cout << "Customer name: ";
    cin  >> customers[customerCount].name;
    cout << "Customer address: ";
    cin  >> customers[customerCount].address;
    cout << "City: ";
    cin  >> customers[customerCount].city;
    cout << "State: ";
    cin  >> customers[customerCount].state;
    cout << "ZIP code: ";
    cin  >> customers[customerCount].zipCode;
    cout << "Telephone: ";
    cin  >> customers[customerCount].telephone;
    cout << "Account balance: ";
    cin  >> customers[customerCount].accountBalance;
    cout << "Date of last payment: ";
    cin  >> customers[customerCount].dateLastPayment;
    
    cout << "You have entered information for customer number " << customerCount << endl;
    cout << endl;
    
    customerCount++;
}

void modifyAccount(Customer customers[], int customerCount)
{
    int customerNum;

    if (customerCount == 0) {
        cout << "No customer accounts available.\n" << endl;
        return;
    }
    
    do 
    {
        cout << "Customer number: ";
        cin >> customerNum;
        
        if (!(customerNum < customerCount) || (customerNum < 0)) {
            cout << "Invalid customer number, please try again!" << endl;
        }
    }
    while (!(customerNum < customerCount) || (customerNum < 0));

    
}

void displayAllAccounts(Customer customers[], int customerCount)
{
    if (customerCount == 0) {
        cout << "No customer accounts available.\n\n";
    } else {
        cout << "Displaying all accounts...\n\n";
    }

    for (int i = 0 ; i < customerCount ; i++)
    {
        cout << "Customer number: "      << customerCount                << endl;
        cout << "Customer name: "        << customers[i].name            << endl; 
        cout << "Customer address: "     << customers[i].address         << endl;
        cout << "City: "                 << customers[i].city            << endl;
        cout << "State: "                << customers[i].state           << endl;
        cout << "ZIP code: "             << customers[i].zipCode         << endl;
        cout << "Telephone: "            << customers[i].telephone       << endl;
        cout << "Account balance: "      << customers[i].accountBalance  << endl;
        cout << "Date of last payment: " << customers[i].dateLastPayment << endl;
        cout << endl;
    }
}
