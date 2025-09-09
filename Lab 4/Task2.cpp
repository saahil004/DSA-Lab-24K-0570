/*
2. An airline company wants to quickly update its system with flight ticket prices. Use Comb Sort to arrange ticket
prices from lowest to highest. After sorting, display the cheapest 3 flights available.
*/
#include <iostream>
using namespace std;

void combSort(float *arr, int size)
{
    int gap = size;
    bool s = true;

    while (gap > 1 || s)
    {
        s = false;
        gap = (int)gap / 1.3;
        if (gap < 1)
        {
            gap = 1;
        }

        for (int i = 0; i + gap < size; i++)
        {
            if (arr[i] > arr[i + gap])
            {
                float temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                s = true;
            }
        }
    }
}

int main()
{
    int size = 50;
    float *prices = new float[size]{10.5, 20.0, 15.75, 8.99, 30.25, 45.0, 12.49, 25.75, 60.0, 18.99, 22.5, 35.0, 14.25, 19.99, 55.75, 40.0, 9.99, 16.5, 28.0, 33.25, 27.5, 12.75, 50.0, 65.5, 23.99, 11.25, 29.5, 38.0, 42.75, 17.49, 13.5, 26.0, 32.5, 47.0, 21.75, 15.0, 19.5, 36.25, 41.0, 24.99, 52.5, 48.75, 31.0, 20.25, 39.5, 18.25, 44.0, 34.5, 28.75, 59.99};
    cout << "prices array before sorting\n";
    for (int i = 0; i < size; i++)
    {
        cout << prices[i] << " ";
    }
    cout << "\n\n";
    combSort(prices, size);
    cout << "prices array after sorting\n";
    for (int i = 0; i < size; i++)
    {
        cout << prices[i] << " ";
    }
    cout << "\n\n";
    cout << "Cheapest price: " << prices[0] << endl;
    cout << "Second cheapest price: " << prices[1] << endl;
    cout << "Third cheapest price: " << prices[2] << endl;
    delete[] prices;
    return 0;
}