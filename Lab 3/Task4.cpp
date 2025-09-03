/*
Q4. Write a C++ program to keep track of a customer’s transactions. The program should allow the
user to traverse forward and backward to view transaction history.
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev; // to go backwards

    Node(string dat) : data(dat), next(nullptr), prev(nullptr) {}
};

class Transactions {
    Node* head;
    Node* currentTrans;

    public:
      Transactions() : head(nullptr) {}
       
      bool fwd() {
        if (currentTrans->next == nullptr)
        {
          return false;
        }
        currentTrans = currentTrans->next;
        return true;
        
      }
      bool bwd() {
        if (currentTrans->prev == nullptr)
        {
          return false;
        }
        currentTrans = currentTrans->prev;
        return true;
        
      }

      void addTransaction(string trans) {
        Node* n = new Node(trans);
        if (head == nullptr)
        {
           head = n;
           currentTrans = head;
           return;
        }
        head->prev = n;
        n->next = head;
        head = n;
        currentTrans = head;
      }

      void displayHistory() {
        Node* n = head;
        if (head == nullptr)
        {
          cout << "List empty.\n";
          return;
        }
        int i = 1;
        cout << "\nList:\n";
        while (n != nullptr)
        {
          cout << i << ": " << n->data << "\n";
          n = n->next;
          i++;
        }
        cout << "Current transaction: " << currentTrans->data << endl;
        cout << "\n";
        return;
      }

      ~Transactions() {
        Node* curr = head;
        while (curr != nullptr)
        {
            Node* n = curr->next;
            delete curr;
            curr = n;
        }
        
      }
};

int main() {
    Transactions t;

    t.addTransaction("Deposit $100");
    t.addTransaction("Withdraw $50");
    t.addTransaction("Deposit $200");
    t.addTransaction("Withdraw $30");

    int choice;
    do {
        cout << "\n==============================";
        t.displayHistory();
        cout << "==============================\n";

        cout << "Options:\n";
        cout << "1. Move forward\n";
        cout << "2. Move backward\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        cout << "\n----------------------------------\n";

        switch (choice) {
            case 1:
                if (t.fwd())
                    cout << "Moved forward.\n";
                else
                    cout << "No next transaction.\n";
                break;
            case 2:
                if (t.bwd())
                    cout << "Moved backward.\n";
                else
                    cout << "No previous transaction.\n";
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

        cout << "----------------------------------\n";

    } while (choice != 3);

    return 0;
}
