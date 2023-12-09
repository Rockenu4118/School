#include <string>

#include "./CustomerData.hpp"


int CustomerData::getCustomerNumber()
{
    return _customerNumber;
}

bool CustomerData::getMailingList()
{
    return _mailingList;
}

void CustomerData::setCustomerNumber(int customerNumber)
{
    _customerNumber = customerNumber;
}

void CustomerData::setMailingList(bool mailingList)
{
    _mailingList = mailingList;
}