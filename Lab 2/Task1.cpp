/*
Task 1:
A weather station records the temperature of a city for 7 days, with 3 readings per day
(morning, afternoon, night). Store this data in a dynamic 2D array and find the hottest and
coldest reading of the week.
*/
#include <iostream>
using namespace std;

int main() {
    float hottest = -1000.00;
    float coldest = 1000.00; 
    float** temps = new float*[7];
    for (int i = 0; i < 7; i++)
    {
        temps[i] = new float[3];
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter temperature number " << j+1 << " of day number " << i+1 << ": ";
            cin >> temps[i][j];
            if (temps[i][j] > hottest) { hottest = temps[i][j]; }
            if (temps[i][j] < coldest) { coldest = temps[i][j]; }
        }
    }

    cout << "Hottest temperature: " << hottest << endl;
    cout << "Coldest temperature: " << coldest << endl;
    
    for (int i = 0; i < 7; i++)
    {
        delete[] temps[i];
    }
    delete[] temps;

    return 0;
}