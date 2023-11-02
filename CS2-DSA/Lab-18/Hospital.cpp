#include "./Hospital.hpp"
#include "./Doctor.hpp"
#include "./Nurse.hpp"


Hospital::Hospital()
{
    _doctor = Doctor("Jennifer Jaskson", "pediatrics");
    _nurse  = Nurse("Bobby Blake");

    _nurse.changeShift();

    _doctor.greeting();
    _doctor.checkCharts();

    _nurse.greeting();
    _nurse.takeVitals();
}