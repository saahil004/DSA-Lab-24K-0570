/*
An e-commerce website needs to quickly sort product prices to display deals efficiently. Since speed is
a priority, quick sort is used. Write a C++ program to sort an array of product prices in ascending order
using the Quick Sort algorithm. Implement a partition () function using a pivot. Display array before
and after sorting.
*/
#include <iostream>
using namespace std;


int partition(int* arr, int l, int h) {
      int p = arr[l];
      int i = l + 1;
      int j = h;

      while (1)
      {
        while (i <= h && arr[i] < p)
        {
            i++;
        }
        while (j > l && arr[j] >= p)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swap(arr[i], arr[j]);
      }
      swap(arr[l], arr[j]);
      return j;
}

void quickSort(int* arr, int l, int h) {
      int pi;
      if (l < h) {
        pi = partition(arr, l, h);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
      }
}

int main() {
    int size;
    cout << "Enter size of the price array: ";
    cin >> size;
    int* prices = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter price " << i + 1 << ": ";
        cin >> prices[i];
    }
    cout << "\n\nPrices before sorting: ";
    for (int i = 0; i < size; i++) {
        cout << prices[i] << " ";
    }
    cout << "\n";
    quickSort(prices, 0, size - 1);
    cout << "Prices after sorting: ";
    for (int i = 0; i < size; i++) {
        cout << prices[i] << " ";
    }
    cout << "\n";

    return 0;
}