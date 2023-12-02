#include <string>

#include "./EmployeeInfo.hpp"


EmployeeInfo::EmployeeInfo(int employeeID, string employeeName)
{
    _employeeID   = employeeID;
    _employeeName = employeeName;
}

int EmployeeInfo::getEmployeeID()
{
    return _employeeID;
}

string EmployeeInfo::getEmployeeName()
{
    return _employeeName;
}

void EmployeeInfo::setEmployeeID(int employeeID)
{
    _employeeID = employeeID;
}

void EmployeeInfo::setEmployeeName(string employeeName)
{
    _employeeName = employeeName;
}

bool operator<(const EmployeeInfo& lhs, const EmployeeInfo& rhs)
{
    return lhs._employeeID < rhs._employeeID;
}

bool operator<(const EmployeeInfo& employee, const int& id)
{
    return employee._employeeID < id;
}

bool operator==(const EmployeeInfo& employee, const int& id)
{
    return employee._employeeID == id;
}

ostream& operator<<(ostream& out, EmployeeInfo& data)
{
    out << "Employee name: " << data.getEmployeeName() << endl;

    return out;
}