/*
Task 2:
A grocery store tracks the stock quantity of 20 items. Store the quantities in a 1D array and
allow the user to update stock when an item is sold.
*/
#include <iostream>
using namespace std;

bool updateStock(int *arr, int size, int val, int ind)
{
    if (ind >= size || ind < 0)
    {
        cout << "Array index out of bounds.\n";
        return false;
    }
    arr[ind] = val;
    return true;
}

int main()
{
    int n;
    cout << "Enter number of stock items: ";
    cin >> n;
    int *stocks = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter quantity of stock item " << i + 1 << ": ";
        cin >> stocks[i];
    }

    int c = n;
    int s;
    while (c > 0 && c <= n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Stock item " << i + 1 << " has " << stocks[i] << " items.\n";
        }
        cout << "Enter the stock number to update (starting from 1) or enter 0 to exit: ";
        cin >> c;
        if (c > n || c <= 0)
        {
            break;
        }
        cout << "Enter new stock value: ";
        cin >> s;
        updateStock(stocks, n, s, c-1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Stock item " << i + 1 << " has " << stocks[i] << " items.\n";
    }

    delete[] stocks;
    return 0;
}