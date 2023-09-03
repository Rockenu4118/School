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
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::setfill;
using std::left;


void getSales(string salsaNames[5], int salsaSales[5]);
void calcTotalSales(int salsaSales[5], int& totalSales);
void calcHighLowSellers(string salsaNames[5], int salsaSales[5], string& highestSeller, string& lowestSeller);
void displaySalesData(string salsaNames[5], int salsaSales[5], int totalSales, string highestSeller, string lowestSeller);


int main()
{
    string salsaNames[5] = { "mild", "medium", "sweet", "hot", "zesty" };
    int    salsaSales[5];
    int    totalSales = 0;
    string highestSeller;
    string lowestSeller;
    

    getSales(salsaNames, salsaSales);
    
    calcTotalSales(salsaSales, totalSales);
    
    calcHighLowSellers(salsaNames, salsaSales, highestSeller, lowestSeller);

    displaySalesData(salsaNames, salsaSales, totalSales, highestSeller, lowestSeller);
    

    return 0;
}

void getSales(string salsaNames[5], int salsaSales[5])
{
    for (int i = 0 ; i < 5 ; i++)
    {
        cout << "Enter sales for " << salsaNames[i] << " salsa..." << endl;
        cin >> salsaSales[i];

        while (salsaSales[i] < 0)
        {
            cout << "Invalid input, no negative values. Please try again..." << endl;
            cin >> salsaSales[i];
        }
    }
}

void calcTotalSales(int salsaSales[5], int& totalSales)
{
    for (int i = 0 ; i < 5 ; i++)
    {
        totalSales = totalSales + salsaSales[i];
    }
}

void calcHighLowSellers(string salsaNames[5], int salsaSales[5], string& highestSeller, string& lowestSeller)
{
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
}

void displaySalesData(string salsaNames[5], int salsaSales[5], int totalSales, string highestSeller, string lowestSeller)
{
    cout << "\nSales Data...\n" << endl;
    
    for (int i = 0 ; i < 5 ; i++)
    {   
        cout << setw(16) << left << salsaNames[i];
        cout << salsaSales[i] << " jars" << endl;
    }
    
    cout << setw(16) << left << "Total sales"    << totalSales    << " jars" << endl;
    cout << setw(16) << left << "Highest seller" << highestSeller << endl;
    cout << setw(16) << left << "Lowest seller"  << lowestSeller  << endl;
}
