/*
3. An HR manager has a list of employee salaries. Use Selection Sort to sort them in descending order. Then search
for a specific salary using Linear Search. If multiple employees earn the same salary, return the first and last
occurrence.
*/
#include <iostream>
using namespace std;

void selectionSort(double* sal, int size) {
    double max;
    int shftind;
    for (int i = 0; i < size; i++)
    {
        max = sal[i];
        shftind = i;
        for (int j = i + 1; j < size; j++)
        {
            if (max < sal[j]) {
                shftind = j;
                max = sal[j];
            }
        }
        double temp = sal[i];
        sal[i] = sal[shftind];
        sal[shftind] = temp;
    }
    
}

void linearSearch(double* sal, int size) {
    int occ = 0;
    int focc = -1;
    int locc = -1;  
    double t;
    cout << "Enter target value to find: ";
    cin >> t;
    for (int i = 0; i < size; i++)
      {
        if (t == sal[i] && occ == 0)
        {
            focc = i;
            locc = i;
            occ++;
        } else if (t == sal[i])
        {
            occ++;
            locc = i;
        }
      }
      (occ == 0) ? cout << "Not found.\n" : cout << "Occurred " << occ << " Times | First at index: " << focc << " | Last at index: " << locc << endl;
}

int main() {
    double* salaries = new double[10] {55000.5, 72000.0, 60000.75, 45000.0, 72000.0, 50000.25, 88000.0, 47000.0, 66000.0, 39000.5};
    int size = 10;
    cout << "salaries array before sorting\n";
    for (int i = 0; i < size; i++)
    {
        cout << salaries[i] << " ";
    }
    cout << "\n\n";
    selectionSort(salaries, size);
    cout << "Salaries array after sorting\n";
    for (int i = 0; i < size; i++)
    {
        cout << salaries[i] << " ";
    }
    cout << "\n\n";
    linearSearch(salaries, size);
    delete[] salaries;
    return 0;
}