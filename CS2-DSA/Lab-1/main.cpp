#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void getScore(double& score);
void calcAverage(double sc1, double sc2, double sc3, double sc4, double sc5);
double findLowest(double sc1, double sc2, double sc3, double sc4, double sc5);

int main()
{
    cout << "Running program..." << endl;

    double sc1, sc2, sc3, sc4, sc5;

    cout << "Please enter the first score..." << endl;
    getScore(sc1);
    cout << "Please enter the second score..." << endl;
    getScore(sc2);
    cout << "Please enter the third score..." << endl;
    getScore(sc3);
    cout << "Please enter the fourth score..." << endl;
    getScore(sc4);
    cout << "Please enter the fifth score..." << endl;
    getScore(sc5);

    calcAverage(sc1, sc2, sc3, sc4, sc5);

    return 0;
}

void getScore(double& score)
{
    cin >> score;

    if (score < 0 || score > 100) {
        cout << "Invalid test score! Please try again..." << endl;
        getScore(score);
    }
}

void calcAverage(double sc1, double sc2, double sc3, double sc4, double sc5)
{
    double sum = sc1 + sc2 + sc3 + sc4 + sc5;
    double lowest = findLowest(sc1, sc2, sc3, sc4, sc5);
    double avg = (sum - lowest) / 4;

    cout << "Average test score: " << avg << endl;
}

double findLowest(double sc1, double sc2, double sc3, double sc4, double sc5)
{
    double scores[5] = { sc1, sc2, sc3, sc4, sc5 };
    double currLowest = sc1;

    for (int i = 0 ; i < 5 ; i++) {
        if (scores[i] < currLowest) {
            currLowest = scores[i];
        }
    }

    return currLowest;
}
