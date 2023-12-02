// Assignment 22
//
// Employee Tree
// Design an EmployeeInfo class that holds the following employee information:
// Employee ID Number : int
// Employee Name : string
// 
// Next, use the template you designed in Programming Challenge 1 (Binary Tree Template) to implement
// a binary tree whose nodes hold an instance of the EmployeeInfo class. The nodes should be sorted
// on the Employee ID number.

#include <iostream>

#include "./BinaryTree.hpp"
#include "./EmployeeInfo.hpp"

using namespace std;

int main()
{
	BinaryTree<EmployeeInfo> tree;

	EmployeeInfo employee1(1021, "John Williams");
	EmployeeInfo employee2(1057, "Bill Witherspoon");
	EmployeeInfo employee3(2487, "Jennifer Twain");
	EmployeeInfo employee4(3769, "Sophia Lancaster");
	EmployeeInfo employee5(1017, "Debbie Reece");
	EmployeeInfo employee6(1275, "George McMullen");
	EmployeeInfo employee7(1899, "Ashley Smith");
	EmployeeInfo employee8(4218, "Johh Plemmons");

	tree.insertNode(employee1);
	tree.insertNode(employee2);
	tree.insertNode(employee3);
	tree.insertNode(employee4);
	tree.insertNode(employee5);
	tree.insertNode(employee6);
	tree.insertNode(employee7);
	tree.insertNode(employee8);

	int input;

	while (input != 0)
	{
		cout << "Employee ID: ";
		cin >> input;

		tree.searchNode(input);
	}

    return 0;
}
