#ifndef EMPLOYEE_INFO_H
#define EMPLOYEE_INFO_H

#include <iostream>
#include <string>

using namespace std;

class EmployeeInfo
{
    friend bool operator<(const EmployeeInfo& lhs, const EmployeeInfo& rhs);
    friend bool operator<(const EmployeeInfo& lhs, const int& id);
    friend bool operator==(const EmployeeInfo& employee, const int& id);
    friend ostream& operator<<(ostream& out, EmployeeInfo& data);

    public:
        EmployeeInfo() = default;
        EmployeeInfo(int employeeID, string employeeName);

        int    getEmployeeID();
        string getEmployeeName();

        void setEmployeeID(int employeeID);
        void setEmployeeName(string employeeName);

    private:
        int    _employeeID;
        string _employeeName;
};

#endif