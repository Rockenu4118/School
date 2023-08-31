// Chips and Salsa
//
// Write a program that lets a maker of chips and salsa keep track of sales for five different types of salsa: mild, medium, sweet, hot, and zesty. The program should
// use two parallel 5-element arrays: an array of strings that holds the five salsa names, and an array of integers  that holds the numers of jars sold  during the last
// past month for each salsa type. The salsa names should be stored using an initialization list at the time the name is created. The program should prompt the user to
// enter the number of jars sold for each type. Once this sales data has been entered, the program shold produce a report that display sales for each salsa
// type,total sales and the name of the highest selling and lowest selling products.
//
// Input validation: Do not accept nagative values for the number of the jars sold

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;


int main()
{
    string salsaNames[5] = { "mild", "medium", "sweet", "hot", "zesty" };
    int    salsaSales[5];
    int    totalSales = 0;
    string highestSeller;
    string lowestSeller;
    
    // Enter sales data
    for (int i = 0 ; i < 5 ; i++)
    {
        cout << "Enter sales for " << salsaNames[i] << " salsa..." << endl;
        cin >> salsaSales[i];
        
        while(salsaSales[i] < 0)
        {
            cout << "Invalid input, no negative values. Please try again..." << endl;
            cin >> salsaSales[i];
        }
    }
    
    // Calculate total sales
    for (int i = 0 ; i < 5 ; i++)
    {
        totalSales = totalSales + salsaSales[i];
    }
    
    // Calculate best and worst performers
    int iHigh = 0;
    int iLow = 0;
    
    for (int i = 0 ; i < 5 ; i++)
    {
        if (salsaSales[i] > salsaSales[iHigh]) {
            iHigh = i;
        }
        
        if (salsaSales[i] < salsaSales[iLow]) {
            iLow = i;
        }
    }
    
    highestSeller = salsaNames[iHigh];
    lowestSeller = salsaNames[iLow];
    
    // Display sales data
    cout << "\nDisplaying sales data...\n" << endl;
    
    for (int i = 0 ; i < 5 ; i++)
    {
        cout << salsaNames[i] << ": " << salsaSales[i] << endl;
    }
    
    cout << "\nTotal sales: " << totalSales << endl;
    
    cout << "\nHighest seller: " << highestSeller << endl;
    cout << "Lowest seller: " << lowestSeller << endl;
    
    
    return 0;
}
