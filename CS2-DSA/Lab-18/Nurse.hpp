#ifndef NURSE_H
#define NURSE_H

#include <string>

#include "./HospitalEmployee.hpp"

using namespace std;


class Nurse : public HospitalEmployee
{
    public: 
        Nurse() = default;
        Nurse(string name);

        void takeVitals();
        
};


#endif