#include <iostream>

using namespace std;

int A(int m, int n);

int main()
{
    cout << "The value of A(0, 0): " << A(0, 0) << endl;
    cout << "The value of A(0, 0): " << A(0, 1) << endl;
    cout << "The value of A(0, 0): " << A(1, 1) << endl;
    cout << "The value of A(0, 0): " << A(1, 2) << endl;
    cout << "The value of A(0, 0): " << A(1, 3) << endl;
    cout << "The value of A(0, 0): " << A(2, 2) << endl;
    cout << "The value of A(0, 0): " << A(3, 2) << endl;

    return 0;
}

int A(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }

    if (n == 0)
    {
        return A(m-1, 1);
    } 
    else 
    {
        return A(m-1, A(m, n-1));
    }
}

int pwr(int num, int pwr);

int pwr(int num, int pwr)
{
    if (pwr == 0)
    {
        return 1;
    }

    return num * pwr(num, pwr - 1);
}
