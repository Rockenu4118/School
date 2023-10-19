// Test Scores #1
// 
// Write a program that dynamically allocates an array large enough to hold a user
// defined number of test scores. Once all the scores are entered, the array should 
// be passed to a function that sorts them in ascending order. Another function should
// be called that calculates the average score. The program should display the sorted
// list of scores and averages with appropriate headings. Use pointer notation rather
// than array notation whenever possible.
//
// Input Validation: Do not accept negative numbers for test scores.

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::left;

void inputScores(double scores[], int numScores);
void sortScores(double scores[], int size);
void swap(double& a, double& b);
void calcAverage(double scores[], int size, double& avgScore);
void printData(double scores[], int numScores, double avgScore);

int main()
{
    double* scores;
    int     numScores;
    double  avgScore;

    cout << "Number of scores: ";
    cin >> numScores;

    scores = new double[numScores];

    inputScores(scores, numScores);

    sortScores(scores, numScores);

    calcAverage(scores, numScores, avgScore);

    printData(scores, numScores, avgScore);

    return 0;
}

void inputScores(double scores[], int numScores)
{
    for (int i = 0 ; i < numScores ; i++)
    {
        cout << "Score #" << i + 1 << ": ";
        cin >> *(scores + i);

        while (*(scores + i) < 0) {
            cout << "Invalid input! Please try again..." << endl;
            cin >> *(scores + i);
        }
    }
}

void sortScores(double scores[], int size)
{
    int maxElement;
    int index;

    for (maxElement = size - 1 ; maxElement > 0 ; maxElement--)
    {
        for (index = 0 ; index < maxElement ; index++)
        {
            if (*(scores + index) > *(scores + (index + 1))) {
                swap(*(scores + index), *(scores + (index + 1)));
            }
        }
    }
}

void swap(double& a, double& b)
{
    double temp = a;
    a = b;
    b = temp;
}

void calcAverage(double scores[], int size, double& avgScore)
{
    double sum = 0;

    for (int i = 0 ; i < size ; i++)
    {
        sum = sum += *(scores + i);
    }

    avgScore = sum / size;
}

void printData(double scores[], int numScores, double avgScore)
{
    cout << setw(15) << "Scores sorted: ";
    for (int i = 0 ; i < numScores ; i++)
    {
        cout << *(scores + i);
        if (i != numScores - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << left << setw(15) << "Avg Score: " << avgScore << endl;
}
