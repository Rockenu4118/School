#ifndef PERSON_DATA_H
#define PERSON_DATA_H

#include <string>

using namespace std;


class PersonData
{
    public:
        PersonData() = default;

        string getLastName();
        string getFirstName();
        string getAddress();
        string getCity();
        string getState();
        int    getZip();
        string getPhone();

        void setLastName(string lastName);
        void setFirstName(string firstName);
        void setAddress(string address);
        void setCity(string city);
        void setState(string state);
        void setZip(int zip);
        void setPhone(string phone);

    private:
        string _lastName;
        string _firstName;
        string _address;
        string _city;
        string _state;
        int    _zip;
        string _phone;

};

#endif