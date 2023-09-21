// Payroll
// 
// Design a PayRoll class that has data members for an employee’s hourly pay rate, 
// number of hours worked of type double. The default constructor will set the hours 
// worked and pay rate to zero. The class must have a mutator function to set the pay 
// rate for each employee and hours worked. The class should include accessors for both 
// the hours worked and the rate of pay. The class should lastly have a getGross function 
// that will return a double calculated by multiplying the hours worked by the rate of pay.
// 
// Write a program with an array of seven PayRoll objects. The program should ask the 
// user for the rate of pay for each employee and the number of hours each employee 
// has worked. Be sure to include an employee claiming to work more then 60 hours per week. 
// Print out, the array number of the employee, the hours worked, the rate of pay, and the gross pay, 
// of all the employee's each on their own line. Set the precision for printing the doubles to 
// two decimal places.
// 
// Input Validation: Do not accept values greater than 60 for the number of hours worked, simply have 
// the set function set number of hours worked to 60, the maximum allowed.

#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;


class PayRoll
{
    public:
        // Constructor
        PayRoll();

        // Mutators
        void setPayRoll(double hourlyRate, double hoursWorked);

        // Accessors
        double getHourlyRate();
        double getHoursWorked();

        // Utility
        double getGross();
        
    private:
        double _hourlyRate;
        double _hoursWorked;
};

void inputPayRoll(PayRoll payRoll[], int size);
void printPayRoll(PayRoll payRoll[], int size);

int main()
{
    const int SIZE = 7;
    PayRoll payRoll[SIZE];

    
    inputPayRoll(payRoll, SIZE);

    printPayRoll(payRoll, SIZE);


    return 0;
}

PayRoll::PayRoll()
{
    _hourlyRate = 0;
    _hoursWorked = 0;
}

void PayRoll::setPayRoll(double hourlyRate, double hoursWorked)
{
    _hourlyRate = hourlyRate;

    if (hoursWorked > 60) {
        _hoursWorked = 60;
    } else {
        _hoursWorked = hoursWorked;
    }
}

double PayRoll::getHourlyRate()
{
    return _hourlyRate;
}

double PayRoll::getHoursWorked()
{
    return _hoursWorked;
}

double PayRoll::getGross()
{
    return _hoursWorked * _hourlyRate;
}

void inputPayRoll(PayRoll payRoll[], int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        double hourlyRate;
        double hoursWorked;

        cout << "Employee #" << i << endl;
        cout << "Hourly rate: ";
        cin >> hourlyRate;
        cout << "Hours worked: ";
        cin >> hoursWorked;

        payRoll[i].setPayRoll(hourlyRate, hoursWorked);
    }
}

void printPayRoll(PayRoll payRoll[], int size)
{
    cout << fixed;
    cout << "\nDisplaying payrolls..." << endl;

    for (int i = 0 ; i < size ; i++)
    {
        cout << "Employee #"       << i 
             << ", Hours worked: " << setprecision(2) << payRoll[i].getHoursWorked() 
             << ", Hourly rate: "  << setprecision(2) << payRoll[i].getHourlyRate()
             << ", Gross pay: "    << setprecision(2) << payRoll[i].getGross()
             << endl;
    }
}
