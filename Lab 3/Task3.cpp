/*
Q3. Write a C++ program using a circular linked list to manage reserved seats in a train coach. The
program should traverse the list circularly to check seat availability.
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int dat) : data(dat), next(nullptr) {}
};

class CircularLinkedList {
    Node* head;

    public:
      CircularLinkedList() : head(nullptr) {}

      void addSeat(int a) {
        Node* ptr = head;
        Node* n = new Node(a); 
        if (head == nullptr)
         {
            head = n;
            head->next = head;
            return;
         }
         while (ptr->next != head)
         {
            ptr = ptr->next;
         }
         ptr->next = n;
         n->next = head;
      }

      void showAvailableSeats() {
        if (head == nullptr)
        {
            cout << "No seats.\n";
            return;
        }
        Node* ptr = head;
        int i = 1;
        cout << "Seats: \n";
        while (ptr->next != head)
        {
            cout << i << ": " << ((ptr->data == 1) ? "Available.\n" : "Not available.\n");
            i++;
            ptr = ptr->next;
        }
        cout << i << ": " << ((ptr->data == 1) ? "Available.\n" : "Not available.\n");
      }

      
};

int main() {
    CircularLinkedList ll;

    // using 0 for booked seats and 1 for available seats
    ll.addSeat(0);
    ll.addSeat(1);
    ll.addSeat(1);
    ll.addSeat(0);
    ll.addSeat(1);
    ll.addSeat(0);
    ll.showAvailableSeats();
    return 0;
}