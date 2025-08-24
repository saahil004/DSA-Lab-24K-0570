#include <iostream>
using namespace std;

int main() {
    double* temps = new double[7];
    
    for (int i = 0; i < 7; i++) {
        cout << "Enter temperature of day " << i+1 << ": ";
        cin >> *(temps + i);
    }
    cout << "\n\nResults:\n";
    double total = 0;
    for (int i = 0; i < 7; i++) {
        cout << i+1 << ") " << *(temps + i) << endl;
        total += *(temps + i);
    }
    cout << "Average: " << total/7 << endl;
    delete[] temps;
return 0;
}
