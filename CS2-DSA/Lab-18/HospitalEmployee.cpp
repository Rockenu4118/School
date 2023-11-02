#include <iostream>
#include <string>

#include "./HospitalEmployee.hpp"

using namespace std;


HospitalEmployee::HospitalEmployee(string name, string field)
{
    _name   = name;
    _field  = field;
    _onCall = false;
}

void HospitalEmployee::greeting()
{
    cout << "Hello, my name is " + _name + ". I work in " + _field + ". How can I help you?" << endl;
}

void HospitalEmployee::changeShift()
{
    _onCall = _onCall == false ? true : false;
}

bool HospitalEmployee::isOnCall() const
{
    return _onCall;
}