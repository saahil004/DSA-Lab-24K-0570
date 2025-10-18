/*
Simulate a printer job queue using a circular queue to handle continuous print job
requests. Each job contains a job ID and number of pages. Implement functions to
enqueue new print jobs, dequeue completed ones, and show the current print queue.
*/
#include <iostream>
using namespace std;

struct PrintJob {
    int jobID, noOfPages;
     
    PrintJob() {}
    PrintJob(int j, int p) : jobID(j), noOfPages(p) {}
};

ostream& operator<<(ostream& out, const PrintJob& pj) {
       out << "Printjob ID: " << pj.jobID << " | Number of pages: " << pj.noOfPages << "\n";
       return out;
}

class CircularQueue {
   private:
     int front;
     int rear;
     PrintJob* arr;
     int size; // fixed size queue

   public:
     CircularQueue(int s) : front(-1), rear(-1), size(s), arr(new PrintJob[s]) {}
     
     bool enqueue(PrintJob pj) {
        if ((rear + 1) % size == front) {
            return false;
        }
        if (rear == -1 && front == -1)
        {
            rear = front = 0;
            arr[rear] = pj;
            return true;
        }
        rear = (rear + 1) % size;
        arr[rear] = pj;
        return true;
     }

     PrintJob dequeue() {
        if (front == -1 && rear == -1)
        {
            return PrintJob(-1, -1);
        }
        if (front == rear)
        {
            PrintJob val = arr[front];
            front = rear = -1;
            return val;
        }
        PrintJob val = arr[front];
        front = (front + 1) % size;
        return val;
     }

     void display() {
        if (front == -1 && rear == -1) { cout << "Queue empty.\n"; return; }
        if (front == rear && front != -1) { cout << "\n\nQueue\n" << arr[front] << "\n"; return; }
        cout << "\n\nQueue\n";
        for (int i = front; i != rear; i = (i + 1) % size) {
            cout << arr[i] << "\n";
        }
        cout << arr[rear] << "\n";
        cout << endl;
     }

     ~CircularQueue() {
        delete[] arr;
     }
};

int main() {
    int size;
    cout << "How many print jobs can be in the circular queue at a time? Answer: ";
    cin >> size;
    CircularQueue q(size);
    int c = 2;
    while (c > 0 && c < 3) {
        q.display();
        cout << "Enter 1 to add a print job.\nEnter 2 to complete a print job.\nEnter any other number to exit.\nChoice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            {
                int id;
                int pages;
                cout << "Enter new print job ID: ";
                cin >> id;
                cout << "Enter number of pages: ";
                cin >> pages;
                (q.enqueue(PrintJob(id, pages))) ? cout << "Added to queue.\n" : cout << "Queue full.\n";
            }
            break;
        case 2:
            {
                PrintJob pj = q.dequeue();
                if (pj.jobID == -1 && pj.noOfPages == -1)
                {
                    cout << "Queue empty so no dequeue.\n";
                } else {
                    cout << "Dequeued: " << pj;
                }
                
            }
            break;
        
        default:
            break;
        }
    }
    return 0;
}