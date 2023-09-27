// Number Array Class
//
// Design a class that has an array of floating-point numbers. The constructor should accept an integer
// argument and dynamically allocate the array to hold that many numbers. The private data members of
// the class should include the inter argument in a variable to hold the size of the array and a
// pointer to float type to hold the address of the first element in the array.
// The destructor should free the memory held by the array.
// In addition, there should be member functions to perform the following operations:
// • Store a number in any element of the array.
// • Retrieve a number from any element of the array.
// • Return the highest value store in the array.
// • Return the lowest value stored in the array
// • Return the average of all the numbers stored in the array

#include <iostream>

using std::cout;
using std::endl;


class NumberArray
{
    public:
        // Constructor and Destructor
        NumberArray(int size);
        ~NumberArray();
        

    private:
        float* _nums;
        int    _size;

};

int main()
{
    cout << "Program running..." << endl;



    return 0;
}

NumberArray::NumberArray(int size)
{
    _nums = new float[size];
    _size = size;
}

NumberArray::~NumberArray()
{
    delete[] _nums;
}
