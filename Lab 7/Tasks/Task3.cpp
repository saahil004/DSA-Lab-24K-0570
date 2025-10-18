/*
A company stores employee ID numbers (integers) and wants to sort them efficiently for payroll
processing. Implement Radix Sort in C++ to sort employee IDs in ascending order. Use counting sort as
a subroutine for each digit place. Input: list of integer IDs. Output: sorted IDs.
 */
#include <iostream>
using namespace std;

int extractDigit(int num, int exp) {
    return (num / exp) % 10;
}

void countSort(int* arr, int n, int exp) {
    int* outputArr = new int[n];
    int* count = new int[10];
    for (int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        count[extractDigit(arr[i], exp)]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        outputArr[count[extractDigit(arr[i], exp)] - 1] = arr[i];
        count[extractDigit(arr[i], exp)]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = outputArr[i];
    }
    delete[] outputArr;
    delete[] count;
    
}

int max(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}



void radixSort(int* arr, int n) {
    int maxnum = max(arr, n);
    int exp;
    for (exp = 1; (maxnum / exp) > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}


int main() {
    int size;
    cout << "Enter number of employees: ";
    cin >> size;
    int* IDs = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter ID for employee " << i + 1 << ": ";
        cin >> IDs[i];
    }
    cout << "\n\nBefore sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << IDs[i] << " ";
    }
    // countSort(IDs, size);
    radixSort(IDs, size);
    cout << "\nAfter Sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << IDs[i] << " ";
    }
    cout << "\n";

    delete[] IDs;
    return 0;
}