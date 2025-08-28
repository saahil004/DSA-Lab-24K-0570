/*
Task 5:
A customer performs N transactionsin a day. Store them in a dynamic array and calculate the
total balance at the end of the day.
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of transactions for today: ";
    cin >> n;
    double* transactions = new double[n];
    double bal = 0;
    cout << "Enter positive amount to deposit or negative amount for withdrawal.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Transaction " << i + 1 << ": ";
        cin >> transactions[i];
        bal += transactions[i];
    }
    
    cout << "\n\nTransactions for today\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Transaction " << i + 1 << ((transactions[i] >= 0) ? " deposit of $" : " withdrawal of $") << static_cast<unsigned int>(abs(transactions[i])) << endl;
    }
    cout << "Final balance: " << bal << endl;

    delete[] transactions;
    return 0;
}