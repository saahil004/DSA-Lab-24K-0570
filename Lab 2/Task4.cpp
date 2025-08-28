/*
Task 4:
Create two 3×3 matrices to represent image pixel values. Add them element by element using
a 2D array and display the result.
*/
#include <iostream>
using namespace std;

int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{11, 21, 31}, {24, 25, 36}, {27, 18, 29}};
    int res[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "Matrix 1\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matrix 2\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Result\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}