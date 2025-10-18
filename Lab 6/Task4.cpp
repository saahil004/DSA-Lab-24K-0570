/*
Implement a function copyStack(Stack *S1, Stack *S2) that copies one stack into another
using a linked list representation.
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int dat) : data(dat), next(nullptr) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    bool push(int c)
    {
        Node *n = new Node(c);
        if (n == nullptr)
        {
            return false;
        } // stack overflow as no new nodes can be made
        if (top == nullptr)
        {
            top = n;
            return true;
        }
        n->next = top;
        top = n;
        return true;
    }

    int pop()
    {
        if (top == nullptr)
        {
            return INT_MIN; // stack underflow
        }
        int ans = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return ans;
    }

    void display()
    {
        cout << "\nCurrent Stack\nTop: " << top->data << endl;
        for (Node *temp = top->next; temp != nullptr; temp = temp->next)
        {
            cout << "     " << temp->data << "\n";
        }
        cout << "\n";
    }
};

void copyStack(Stack* s1, Stack* s2) {
    Stack temp;
    while (1) {
        int val = s2->pop();
        if (val == INT_MIN) { break; } // emptied s2 first
    }
    while (1) {
        int val = s1->pop();
        if (val == INT_MIN) { break; } // means all elements are popped and pushed
        temp.push(val);
    }
    while (1) {
        int val = temp.pop();
        if (val == INT_MIN) { break; } // means all elements are popped and pushed
        s2->push(val);
    }
    
}

int main() {
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "Stack 1\n";
    s1.display();
    Stack s2;
    copyStack(&s1, &s2);
    cout << "Stack 2\n";
    s2.display();
    return 0;
}