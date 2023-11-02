#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>

#include "./HospitalEmployee.hpp"

using namespace std;


class Doctor : public HospitalEmployee
{
    public:
        Doctor() = default;
        Doctor(string name, string field);

        void checkCharts();
};

#endif