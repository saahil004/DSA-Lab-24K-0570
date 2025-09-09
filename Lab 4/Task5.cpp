/*
5. Write a program to store employee salaries in a linked list. Sort salaries using Selection Sort on the
linked list. Print the unsorted and sorted salary lists.
*/
#include <iostream>
using namespace std;

struct Node {
    double data;
    Node* next;

    Node(double val) : next(nullptr), data(val) {}
};

class Salaries {
    Node* head;

    public:
      Salaries() : head(nullptr) {}

      void addSalary(double sal) {
        Node* n = new Node(sal);
        if (head == nullptr)
        {
            head = n;
            return;
        }
        Node* ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
      }

      void displaySalaries() {
        if (head == nullptr)
        {
            cout << "No salaries to show.\n";
            return;
        }
        Node* ptr = head;
        cout << "Salaries: ";
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "\n";
      }

      void selectionSort() {
        Node* cp = head;
        double min;
        while (cp != nullptr)
        {
            min = cp->data;
            Node* minp = cp;
            Node* mov = cp->next;
            while (mov != nullptr)
            {
                if (mov->data < min)
                {
                    min = mov->data;
                    minp = mov;
                }
                mov = mov->next;
            }
            swap(minp->data, cp->data);
            cp = cp->next;
        }
        
      }

      ~Salaries() {
        Node* prev;
        while (head != nullptr)
        {
            prev = head;
            head = head->next;
            delete prev;
        }
        
      }
};

int main() {
    Salaries s;
    int c = 2;
    double val;
    while (c > 0 && c < 4)
    {
        cout << "Enter 1 to add a salary.\nEnter 2 to sort salaries using selection sort.\nEnter 3 to show salary list.\nChoice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter salary to add: ";
            cin >> val;
            s.addSalary(val);
            cout << "Added.\n\n";
            break;
        case 2:
            s.selectionSort();
            cout << "Sorted.\n\n";
            break;
        case 3:
            s.displaySalaries();
            cout << endl;
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}
