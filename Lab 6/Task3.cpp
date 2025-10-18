/*
Using a stack implemented via linked list, check whether a given string is a palindrome.
*/
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *next;

    Node(char dat) : data(dat), next(nullptr) {}
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    bool push(char c)
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

    char pop()
    {
        if (top == nullptr)
        {
            return '\0'; // null terminator to show stack underflow
        }
        char ans = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return ans;
    }

    void display()
    {
        cout << "\nCurrent Stack\nTop: ";
        for (Node *temp = top; temp != nullptr; temp = temp->next)
        {
            cout << temp->data << "\n";
        }
        cout << "\n";
    }
};

bool palindrome(string str)
{
    Stack s;
    int len = str.size();
    int mid = len / 2;

    for (int i = 0; i < mid; i++)
    {
        s.push(str[i]);
    }
    if (len % 2 == 1)
    {
        mid++;
    }

    for (int i = mid; i < len; i++)
    {
        if (s.pop() != str[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    cout << " Enter a string: ";
    cin >> str;
    (palindrome(str)) ? cout << "Is a palindrome.\n" : cout << "is not a palindrome.\n";
    return 0;
}
