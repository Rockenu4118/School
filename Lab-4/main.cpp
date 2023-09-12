// Assignment 4
	

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void inputData(string names[], double scores[][4], int numStudents);
void printData(string names[], char grades[], double scores[][4], int numStudents);

int main()
{
	cout << "Running program..." << endl;

	const int NUM_STUDENTS = 5;
	const int NUM_SCORES   = 4;  

	string names[NUM_STUDENTS];
	char   grades[NUM_STUDENTS];
	double scores[NUM_STUDENTS][NUM_SCORES];


	inputData(names, scores, NUM_STUDENTS);

	cout << "\nDisplaying gradebook..." << endl;
	printData(names, grades, scores, NUM_STUDENTS);





	return 0;
}

void inputData(string names[], double scores[][4], int numStudents)
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "\nEnter name for student #" << i + 1 << ": ";
		cin >> names[i];

		for (int j = 0; j < 4; j++)
		{
			cout << "Enter their score for test #" << j + 1 << ": ";
			cin >> scores[i][j];
		}
	}
}

void printData(string names[], char grades[], double scores[][4], int numStudents)
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Student #" << i + 1 << " " << names[i] << endl;

		for (int j = 0; j < 4; j++)
		{
			cout << "Test #" << j + 1 << ": " << scores[i][j] << endl;
		}
	}
}
