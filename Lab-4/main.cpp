// Assignment 4
//
// A teacher has five students who have taken four tests. The teacher uses the following grading
// scale to assign a letter grade to a student, based on the average of his or her four test scores.
//
// Write a program that uses an array of string objects to hold the five students' names, an array of
// five characters to hold the five students' letter grades, and five arrays of four doubles to hold
// each student's set of test scores. The program should allow the user to enter each student's name
// and his or her four test scores. It should then calculate and display each student's average test
// score, and a letter grade based on the average.
//
// Input validation: Do not accept test scores less than 0 or greater than 100.
    

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::string;

void inputData(string names[], double scores[][4], int numStudents);
void calcData(double scores[][4], double avgScores[], char grades[], int numStudents);
char gradeThreshold(double score);
void printData(string names[], double avgScores[], char grades[], int numStudents);

int main()
{
    cout << "Running program..." << endl;

    const int NUM_STUDENTS = 5;
    const int NUM_SCORES   = 4;

    string names[NUM_STUDENTS];
    char   grades[NUM_STUDENTS];
    double scores[NUM_STUDENTS][NUM_SCORES];
    double avgScores[NUM_STUDENTS];

    
    inputData(names, scores, NUM_STUDENTS);
    
    calcData(scores, avgScores, grades, NUM_STUDENTS);

    cout << "\nDisplaying gradebook..." << endl;
    printData(names, avgScores, grades, NUM_STUDENTS);

    
    return 0;
}

void inputData(string names[], double scores[][4], int numStudents)
{
    for (int i = 0; i < numStudents; i++)
    {
        cout << "\nEnter name for student #" << i + 1 << ": ";
        getline(cin, names[i]);
        
        for (int j = 0; j < 4; j++)
        {
            cout << "Enter their score for test #" << j + 1 << ": ";
            cin >> scores[i][j];
            cin.ignore();
            while (scores[i][j] < 0 || scores[i][j] > 100)
            {
                cout << "Invalid test score! Please try again..." << endl;
                cout << "Enter their score for test #" << j + 1 << ": ";
                cin >> scores[i][j];
                cin.ignore();
            }
        }
    }
}

void calcData(double scores[][4], double avgScores[], char grades[], int numStudents)
{
    double sums[numStudents];
    
    for (int i = 0 ; i < numStudents ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            sums[i] = sums[i] + scores[i][j];
        }
        avgScores[i] = sums[i] / 4;
        grades[i] = gradeThreshold(avgScores[i]);
    }
}

char gradeThreshold(double score)
{
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void printData(string names[], double avgScores[], char grades[], int numStudents)
{
    cout << left
         << setw(20) << "Name"
         << setw(12) << "Avg Score"
         << setw(12) << "Letter Grade" << endl;
    
    for (int i = 0; i < numStudents; i++)
    {
        cout << setw(20) << names[i]
             << setw(12) << avgScores[i]
             << setw(12) << grades[i] << endl;
    }
}
