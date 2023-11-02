#include <iostream>
#include <string>

using namespace std;

int pwr(int num, int pwr);

int main()
{
    cout << "2 to the power of 3: " << pwr(2, 3) << endl;
    cout << "2 to the power of 4: " << pwr(2, 4) << endl;
    cout << "3 to the power of 3: " << pwr(3, 3) << endl;
    cout << "6 to the power of 3: " << pwr(6, 3) << endl;
    cout << "7 to the power of 7: " << pwr(7, 7) << endl;
    cout << "10 to the power of 9: " << pwr(10, 9) << endl;

    return 0;
}

int pwr(int num, int power)
{
    if (power == 0)
        return 1;
    
    if (power == 1)
        return num;

    return (num * pwr(num, power - 1));
}
