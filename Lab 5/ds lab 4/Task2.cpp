/*
2. Given a singly linked list, write a recursive function to print the elements of the list in reverse order
without modifying the list.
*/
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
      friend void printReverse(LinkedList ll);
    public:
      LinkedList() : head(nullptr) {}
      
      void addNode(int val) {
        Node* n = new Node(val);
        if (head == nullptr)
        {
            head = n;
            return;
        }
        Node* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = n;
        return;
      }

      Node* getHead() {return head;}
};

void printReverse(Node* head) {
    if (head != nullptr)
    {
        printReverse(head->next);
        cout << head->data << " ";
    }
}

int main() {
    LinkedList ll;
    ll.addNode(1);
    ll.addNode(2);
    ll.addNode(3);
    printReverse(ll.getHead());
    return 0;
}
