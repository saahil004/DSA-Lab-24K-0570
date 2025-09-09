/*
1. A list of students’ exam score is given. First, arrange the scores in ascending order using Insertion Sort. Then,
allow the teacher to search for a particular student’s score using Binary Search. If the score exists, display the
student’s rank. Otherwise, show "Score not found".
*/
#include <iostream>
using namespace std;

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i;
        while (j > 0 && key < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

int binarySearch(int *arr, int size, int t)
{
    int mid;
    int l = 0;
    int h = size - 1;
    while (l <= h)
    {
        mid = l + (h - l) / 2;

        if (arr[mid] == t)
        {
            return mid;
        }
        else if (arr[mid] > t)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    // random values for marks array
    int *marks = new int[50]{85, 90, 76, 88, 92, 67, 74, 81, 95, 100, 66, 79, 83, 91, 72, 89, 94, 87, 77, 69, 81, 73, 85, 68, 90, 76, 82, 88, 70, 93, 80, 84, 97, 65, 92, 71, 75, 86, 99, 78, 82, 89, 60, 91, 77, 85, 69, 96, 88, 73};
    int size = 50;
    cout << "Marks array before sorting\n";
    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << " ";
    }
    cout << "\n\n";
    insertionSort(marks, size);
    cout << "Marks array after sorting\n";
    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << " ";
    }
    cout << "\n\n";
    int m;
    cout << "Enter marks to search in this array: ";
    cin >> m;
    int ind = binarySearch(marks, size, m);
    (ind == -1) ? cout << "Marks not found.\n" : cout << "Found at index: " << ind << "\nStudent rank: " << size - ind << endl;
    delete[] marks;
    return 0;
}