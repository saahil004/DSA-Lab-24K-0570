/*
University registration numbers are long integers. Implement radix sort to sort a large list of student
registration numbers efficiently. Numbers are stored in a linked list and use any search technique to
search for the user defined value in the list.
*/
#include <iostream>
using namespace std;

struct Node {
    long long regNo;
    Node* next;
    Node(long long r) : regNo(r), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(long long regNo) {
        Node* newNode = new Node(regNo);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->regNo << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void bubbleSort() {
        if (!head || !head->next) return;

        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->regNo > ptr1->next->regNo) {
                    swap(ptr1->regNo, ptr1->next->regNo);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    bool search(long long target) {
        Node* temp = head;
        while (temp) {
            if (temp->regNo == target)
                return true;
            temp = temp->next;
        }
        return false;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    int n;
    long long regNo;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter " << n << " registration numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> regNo;
        list.insert(regNo);
    }

    cout << "\nOriginal list:\n";
    list.display();

    list.bubbleSort();
    cout << "\nSorted list:\n";
    list.display();

    cout << "\nEnter a registration number to search: ";
    cin >> regNo;

    if (list.search(regNo))
        cout << "Registration number " << regNo << " found in the list.\n";
    else
        cout << "Registration number " << regNo << " not found.\n";

    return 0;
}
