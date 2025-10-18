/*
Simulate a real-world ticket counter system where people line up in a queue to buy
tickets and are served one by one. Implement enqueue and dequeue operations to add
customers to the queue and serve them in order (FIFO).
*/
#include <iostream>
#include <string>
using namespace std;

class Queue {
   private:
     int front;
     int rear;
     string* arr;
     int size; // fixed size queue

   public:
     Queue(int s) : front(-1), rear(-1), size(s), arr(new string[s]) {}
     
     bool enqueue(string name) {
        if (rear == size - 1) {
            return false;
        }
        if (rear == -1 && front == -1)
        {
            rear = front = 0;
            arr[rear] = name;
            return true;
        }
        rear++;
        arr[rear] = name;
        return true;
     }

     string dequeue() {
        if (front == -1 && rear == -1)
        {
            return "Queue empty.\n";
        }
        if (front == rear)
        {
            string val = arr[front];
            front = rear = -1;
            return val + " was served.\n";
        }
        string val = arr[front];
        front++;
        return val + " was served.\n";
     }

     void display() {
        if (front == -1 && rear == -1) { cout << "Queue empty.\n"; return; }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
     }

     ~Queue() {
        delete[] arr;
     }
};

int main() {
    int size;
    cout << "How many buyers can be in the linear queue at a time? Answer: ";
    cin >> size;
    Queue q(size);
    int c = 2;
    while (c > 0 && c < 3) {
        q.display();
        cout << "Enter 1 to add a customer.\nEnter 2 to serve.\nChoice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            {
                string name;
                cout << "Enter name of the customer to add in queue: ";
                cin >> name;
                (q.enqueue(name)) ? cout << "Added to queue.\n" : cout << "Queue full, must serve all first.\n";
            }
            break;
        case 2:
            {
                cout << q.dequeue();
            }
            break;
        
        default:
            break;
        }
    }
    return 0;
}