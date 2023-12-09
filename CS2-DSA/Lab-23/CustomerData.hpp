#ifndef CUSTOMER_DATA_H
#define CUSTOMER_DATA_H

#include <string>

#include "./PersonData.hpp"

using namespace std;


class CustomerData : public PersonData
{
    public:
        CustomerData() = default;

        int  getCustomerNumber();
        bool getMailingList();

        void setCustomerNumber(int customerNumber);
        void setMailingList(bool mailingList);

    private:
        int  _customerNumber;
        bool _mailingList;

};

#endif