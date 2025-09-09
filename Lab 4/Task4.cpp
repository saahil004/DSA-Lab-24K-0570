/*
4. A local bookstore wants to organize its books by price in ascending order. Write a program that accepts
the prices of n books and sorts them using Bubble Sort.
*/
#include <iostream>
using namespace std;

void bubbleSort(double* arr, int size) {
    bool s = true;
    for (int i = 0; i < size; i++)
    {
        s = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                s = true;
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (s == false)
        {
            break;
        }
    }
}

int main() {
    int size;
    cout << "Enter number of prices: ";
    cin >> size;

    double* prices = new double[size];

    cout << "Enter " << size << " prices:\n";
    for (int i = 0; i < size; i++) {
        cin >> prices[i];
    }

    cout << "\nPrices array before sorting:\n";
    for (int i = 0; i < size; i++) {
        cout << prices[i] << " ";
    }
    cout << "\n\n";

    bubbleSort(prices, size);

    cout << "Prices array after sorting:\n";
    for (int i = 0; i < size; i++) {
        cout << prices[i] << " ";
    }
    cout << "\n\n";

    delete[] prices;
    return 0;
}


