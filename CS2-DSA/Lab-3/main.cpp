// Sorting Orders
//
// Write a program that uses two identical arrays of just eight integers. It should display the contents of the first array, then call a function to sort the array
// using an ascending order bubble sort modified to print out the array contents after each pass of the sort. Next, the program should display the contents of the
// second array, then call a function to sort the array using an ascending order selection sort modified to print out the array contents after each pass of the sort.

#include <iostream>

using std::cout;
using std::endl;

void displayArrayContents(int nums[], int size);
void bubbleSort(int nums[], int size);
void selectionSort(int nums[], int size);
void swap(int& a, int& b);


int main()
{
    cout << "Program running..." << endl;
    
    const int SIZE = 8;
    
    int nums1[SIZE] = { 10, 2, 7, 12, 8, 15, 5, 11 };
    int nums2[SIZE] = { 10, 2, 7, 12, 8, 15, 5, 11 };

    cout << "\nDisplaying nums1 pre-sorted..." << endl;
    displayArrayContents(nums1, SIZE);
    
    cout << "\nDisplaying nums1 sorting process..." << endl;
    bubbleSort(nums1, SIZE);
    
    cout << "\nDisplaying nums2 pre-sorted..." << endl;
    displayArrayContents(nums2, SIZE);
    
    cout << "\nDisplaying nums2 sorting process..." << endl;
    selectionSort(nums2, SIZE);
    
    return 0;
}

void displayArrayContents(int nums[], int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        cout << nums[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    
    cout << endl;
}

void bubbleSort(int nums[], int size)
{
    int maxElement;
    int index;
    
    for (maxElement = size - 1 ; maxElement > 0 ; maxElement--)
    {
        for (index = 0 ; index < maxElement ; index++)
        {
            if (nums[index] > nums[index + 1]) {
                swap(nums[index], nums[index + 1]);
            }
        }
        
        displayArrayContents(nums, size);
    }
}

void selectionSort(int nums[], int size)
{
    int minIndex;

    for (int i = 0; i < size - 1 ; i++)
    {
        minIndex = i;
        for (int j = i + 1 ; j < size ; j++)
        {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(nums[minIndex], nums[i]);
        }

        displayArrayContents(nums, size);
    }
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
