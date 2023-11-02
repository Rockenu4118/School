#ifndef HOSPITAL_EMPLOYEE_H
#define HOSPITAL_EMPLOYEE_H

#include <string>

using namespace std;


class HospitalEmployee
{
    public:
        HospitalEmployee() = default;
        HospitalEmployee(string name, string field);

        void greeting();
        void changeShift();
        bool isOnCall() const;

    protected:
        string _name;
        string _field;
        bool   _onCall;
};


#endif