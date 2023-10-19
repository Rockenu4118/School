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
//
// Demonstrate the Class in a Program

#include <iostream>

using std::cout;
using std::endl;

/**************************************
    NumberArray Class Declaration
**************************************/
class NumberArray
{
    public:
        // Constructor and Destructor
        NumberArray(int size);
        ~NumberArray();
    
        // Utility
        void  storeNum(int index, float num);
        float getAnyNum(int index);
        float getHighNum();
        float getLowNum();
        float getAvgNum();
        
    private:
        // Members
        float* _nums;
        int    _size;
};

/**************************************
    Main
**************************************/
int main()
{
    cout << "Creating a Float Class Array Object with a size of 5 using storeNum function with nums (1.4, 2.3, 3.13, 6.66, 7.711) to load array." << endl;
    NumberArray myArray = NumberArray(5);

    myArray.storeNum(0, 1.4);
    myArray.storeNum(1, 2.3);
    myArray.storeNum(2, 3.13);
    myArray.storeNum(3, 6.66);
    myArray.storeNum(4, 7.711);

    cout << "Using getAnyNum with all legitmate index values to print array." << endl;
    cout << "The value of myArray[0]: " << myArray.getAnyNum(0) << endl;
    cout << "The value of myArray[1]: " << myArray.getAnyNum(1) << endl;
    cout << "The value of myArray[2]: " << myArray.getAnyNum(2) << endl;
    cout << "The value of myArray[3]: " << myArray.getAnyNum(3) << endl;
    cout << "The value of myArray[4]: " << myArray.getAnyNum(4) << endl;

    cout << "Highest number: " << myArray.getHighNum() << endl;
    cout << "Lowest number:  " << myArray.getLowNum()  << endl;
    cout << "Average number: " << myArray.getAvgNum()  << endl;

    return 0;
}

/**************************************
    NumberArray Class Definition
**************************************/
NumberArray::NumberArray(int size)
{
    _nums = new float[size];
    _size = size;
}

NumberArray::~NumberArray()
{
    delete[] _nums;
}

void NumberArray::storeNum(int index, float num)
{
    _nums[index] = num;
}

float NumberArray::getAnyNum(int index)
{
    return _nums[index];
}

float NumberArray::getHighNum()
{
    float high = _nums[0];

    for (int i = 0 ; i < _size ; i++)
    {
        if (_nums[i] > high) {
            high = _nums[i];
        }
    }

    return high;
}

float NumberArray::getLowNum()
{
    float low = _nums[0];

    for (int i = 0 ; i < _size ; i++)
    {
        if (_nums[i] < low){
            low = _nums[i]; 
        }
    }

    return low;
}

float NumberArray::getAvgNum()
{
    float sum = 0;

    for (int i = 0 ; i < _size ; i++)
    {
        sum += _nums[i];
    }

    return sum / _size;
}
