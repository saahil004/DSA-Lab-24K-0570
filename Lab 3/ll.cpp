#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    private: 
      Node* head;
      Node* tail;

    public:
      LinkedList() : head(nullptr), tail(nullptr) {}
      
      void addAtBeginning(int val) {
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

      void addAtEnd(int val) {
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

      bool addAtIndex(int ind, int val) {
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
    while (c > 0 && c < 7)
    {
        cout << "Enter 1 to add at beginning.\n"
                "Enter 2 to add at end.\n"
                "Enter 3 to add at index.\n"
                "Enter 4 to delete from beginning.\n"
                "Enter 5 to delete from end.\n"
                "Enter 6 to show list.\n"
                "Enter any other number to exit.\n"
                "Choice: ";
        cin >> c;
        switch (c)
        {
            case 1: {
                int val;
                cout << "Enter value to add at beginning: ";
                cin >> val;
                ll.addAtBeginning(val);
                break;
            }
            case 2: {
                int val;
                cout << "Enter value to add at end: ";
                cin >> val;
                ll.addAtEnd(val);
                break;
            }
            case 3: {
                int val, ind;
                cout << "Enter index to add at: ";
                cin >> ind;
                cout << "Enter value to add at index " << ind << ": ";
                cin >> val;
                if (!ll.addAtIndex(ind, val)) {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 4: {
                if (!ll.deleteFromBeginning()) {
                    cout << "List is empty. Nothing to delete.\n";
                }
                break;
            }
            case 5: {
                if (!ll.deleteFromEnd()) {
                    cout << "List is empty or has only one element.\n";
                }
                break;
            }
            case 6: {
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
