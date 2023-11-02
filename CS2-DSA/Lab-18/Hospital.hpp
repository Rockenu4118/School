#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "./Doctor.hpp"
#include "./Nurse.hpp"


class Hospital
{
    public:
        Hospital();

    private:
        Doctor _doctor;
        Nurse  _nurse;
};


#endif