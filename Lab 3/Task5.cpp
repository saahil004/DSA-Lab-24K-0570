#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;

    Node(string val) : data(val), next(nullptr) {}
};

class LinkedList {
    private: 
      Node* head;
      Node* tail;

    public:
      LinkedList() : head(nullptr), tail(nullptr) {}
      
      void addAtBeginning(string val) {
        Node* n = new Node(val);
        if (head == nullptr)
        {
            head = n;
            tail = n;
            return;
        }
        n->next = head;
        head = n;
      }

      void addAtEnd(string val) {
        Node* n = new Node(val);
        if (tail == nullptr && head == nullptr)
         {
            tail = n;
            head = n;
            return;
         }
         tail->next = n;
         tail = n;
      }

      bool addAtIndex(int ind, string val) {
        Node* ptr = head;
        Node* n = new Node(val);
        int c = 0;
        if (ind == 0)
        {
            addAtBeginning(val);
            return true;
        }
        
        while (ind > 0 && c != ind - 1 && ptr != nullptr)
        {
            ptr = ptr->next;
            c++;
        }
        if (ptr == nullptr) {return false;}
        n->next = ptr->next;
        ptr->next = n;
        return true;
      }

      void Traversal() {
        Node* ptr = head;
        while (ptr != nullptr)
        {
            cout << ptr->data << " " << endl;
            ptr = ptr->next;
        }
      }

      bool deleteFromBeginning() {
        if (head == nullptr)
        {
            return false;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
      }

      bool deleteFromEnd() {
        if (tail == nullptr)
        {
            return false;
        }
        Node* n = head;
        while (n->next != tail)
        {
            n = n->next;
        }
        delete tail;
        tail = n;
        tail->next = nullptr;
        return true;
      }

      bool deleteAtIndex(int ind) {
        if (ind < 0)
        {
            return false;
        }
        if (ind == 0)
        {
            this->deleteFromBeginning();
            return false;
        }
        Node* ptr = head;
        Node* prev;
        int c = 0;
        while (c != ind) {
            prev = ptr;
            ptr = ptr->next;
            c++;
        }
        prev->next = ptr->next;
        delete ptr;
        return true;
      }

      ~LinkedList() {
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
    LinkedList ll;
    int c = 2;
    while (c > 0 && c < 8)
    {
        cout << "Enter 1 to add a VIP buyer.\n"
                "Enter 2 to add a new customer.\n"
                "Enter 3 to remove any customer who bought tickets.\n"
                "Enter 4 to show list.\n"
                "Enter any other number to exit.\n"
                "Choice: ";
        cin >> c;
        switch (c)
        {
            case 1: {
                string val;
                cout << "Enter name of VIP: ";
                cin >> val;
                ll.addAtBeginning(val);
                break;
            }
            case 2: {
                string val;
                cout << "Enter name of customer: ";
                cin >> val;
                ll.addAtEnd(val);
                break;
            }
            
            case 3:
            {
                int tn;
                cout << "Enter customer number (starting from 1) to be deleted: ";
                cin >> tn;
                tn--;
                ll.deleteAtIndex(tn);
            }

            case 4: {
                cout << "Current list:\n";
                ll.Traversal();
                break;
            }
            default:
                cout << "Exiting...\n";
                c = 0;  // Exit condition
                break;
        }
    }

    return 0;
}
