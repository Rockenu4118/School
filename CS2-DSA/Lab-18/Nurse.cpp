#include <iostream>
#include <string>

#include "./Nurse.hpp"

using namespace std;


Nurse::Nurse(string name) : HospitalEmployee(name, "nursing")
{}

void Nurse::takeVitals()
{
    if (_onCall)
        cout << "Vitals have been taken." << endl;
    else 
        cout << "Sorry, it's not my shift." << endl;
}