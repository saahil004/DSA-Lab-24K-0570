/*
A university wants to arrange student records based on their GPA for generating merit lists. Since
accuracy and stability are important, merge sort is chosen. Write a C++ program to sort an array of
student GPAs (floating-point numbers) in ascending order using the Merge Sort algorithm. Implement
mergeSort() and merge() functions. Input: list of GPAs. Output: sorted list of GPAs in ascending order.
Example:
Input: 3.2, 3.9, 2.8, 3.5, 3.0
Output: 2.8, 3.0, 3.2, 3.5, 3.9
*/
#include <iostream>
using namespace std;

void merge(float* arr, int l, int mid, int h) {
    float B[h - l + 1];
    int i, j, k;
    i = l;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= h) {
        if (arr[i] <= arr[j]) {
            B[k] = arr[i];
            k++; i++;
        } else {
            B[k] = arr[j];
            j++; k++;
        }
    }
    while (i <= mid) {
        B[k] = arr[i];
        k++; i++;
    }
    while (j <= h) {
        B[k] = arr[j];
        k++; j++;
    }
    for (int i = 0; i < h - l + 1; i++) {
        arr[i + l] = B[i];
    }
}

void mergeSort(float* arr, int l, int h) {
    int mid;
    if (l < h) {
        mid = l + (h - 1) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
} 

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    float* gpas = new float[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter gpa of student " << i+1 << ": ";
        cin >> gpas[i];
    }
    mergeSort(gpas, 0, n-1);
    cout << "\n\nSorted\n";
    for (int i = 0; i < n; i++) {
        cout << gpas[i] << " ";
    }
    delete[] gpas;
    return 0;
}