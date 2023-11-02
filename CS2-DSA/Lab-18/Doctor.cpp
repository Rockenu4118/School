#include <iostream>
#include <string>

#include "./Doctor.hpp"

using namespace std;


Doctor::Doctor(string name, string field) : HospitalEmployee(name, field)
{}

void Doctor::checkCharts()
{
    if (_onCall)
        cout << "Charts have been checked." << endl;
    else 
        cout << "Sorry, it's not my shift." << endl;
}