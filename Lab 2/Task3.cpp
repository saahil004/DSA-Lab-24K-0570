/*
Task 3:
A hospital stores the number of medicines given to patients daily. Since each patient may have
different prescriptions, use a jagged array to record the data.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int patients;
    cout << "Enter number of patients: ";
    cin >> patients;
    int* nPrescriptions = new int[patients]; 
    string** prescriptions = new string*[patients];
    for (int i = 0; i < patients; i++)
    {
        cout << "Enter the number of prescriptions for patient #" << i+1 << ": ";
        cin >> nPrescriptions[i];
        nPrescriptions[i]++;
        prescriptions[i] = new string[nPrescriptions[i]];
        
        // name stored in the first column for all records
        cout << "Enter name for this patient: ";
        cin >> prescriptions[i][0];
        for (int j = 1; j < nPrescriptions[i]; j++)
        {
            cout << "Enter prescription number " << j << ": ";
            cin >> prescriptions[i][j];
        }
    }

    cout << "Records\n";
    for (int i = 0; i < patients; i++)
    {
        cout << "\n\nPatient Name: " << prescriptions[i][0] << "\n";
        for (int j = 1; j < nPrescriptions[i]; j++)
        {
            cout << "Prescription " << j << ": " << prescriptions[i][j] << endl;
        }
        cout << "\n";
    }
    for (int i = 0; i < patients; i++)
    {
        delete[] prescriptions[i];
    }
    delete[] prescriptions;
    delete[] nPrescriptions;
    
    
    return 0;
}