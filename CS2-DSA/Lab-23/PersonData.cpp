#include <string>

#include "./PersonData.hpp"
#include "PersonData.hpp"

using namespace std;


string PersonData::getLastName()
{
    return _lastName;
}

string PersonData::getFirstName()
{
    return _firstName;
}

string PersonData::getAddress()
{
    return _address;
}

string PersonData::getCity()
{
    return _city;
}

string PersonData::getState()
{
    return _state;
}

int PersonData::getZip()
{
    return _zip;
}

string PersonData::getPhone()
{
    return _phone;
}

void PersonData::setLastName(string lastName)
{
    _lastName = lastName;
}

void PersonData::setFirstName(string firstName)
{
    _firstName = firstName;
}

void PersonData::setAddress(string address)
{
    _address = address;
}

void PersonData::setCity(string city)
{
    _city = city;
}

void PersonData::setState(string state)
{
    _state = state;
}

void PersonData::setZip(int zip)
{
    _zip = zip;
}

void PersonData::setPhone(string phone)
{
    _phone = phone;
}
