/*
Create a program that evaluates a postfix arithmetic expression using a stack — like how
compilers compute mathematical operations. Given a postfix expression (e.g.
"23*54*+9-"), evaluate and output the result
*/
#include <iostream>
#include <string>
using namespace std;

class Stack {
    private:
      int size;
      char* arr;
      int pointer; // points to next empty space
      
    public:
      Stack(int s) : size(s), arr(new char[size]), pointer(0) {}
      
      bool push(char c) {
          if (pointer == size) { return false; }
          arr[pointer] = c;
          pointer++;
          return true;
      }
      
      bool empty() {
          if (pointer == 0) { return true; }
          return false;
      }
      
      char top() {
          if (pointer == 0) { return '!'; }
          return arr[pointer-1];
      }
      
      char pop() {
          if (pointer == 0) { return '!'; } // exclamation mark to indicate stack underflow
          pointer--;
          return arr[pointer];
      }
      
      ~Stack() {
          delete[] arr;
      }
};

int precedence(char p) {
    if (p == '+' || p == '-') { return 1; }
    if (p == '*' || p == '/') { return 2; }
    return -1;
}

string infixToPostfix(string exp) {
    string postfix;
    Stack s(exp.size());
    for (int i = 0; i < exp.size(); i++) {
        if (precedence(exp[i]) == -1) {
            postfix.push_back(exp[i]);
            continue;
        }
        if (s.empty() && precedence(exp[i]) > 0 || precedence(exp[i]) > precedence(s.top())) {
            s.push(exp[i]);
            continue;
        }
        if (precedence(exp[i]) <= precedence(s.top())) {
            postfix.push_back(s.pop());
            i--;
        }
    }
    while (!s.empty()) {
        postfix.push_back(s.pop());
    }
    return postfix;
}

int evaluatePostfix(const string& exp) {
    Stack s(exp.size());

    for (int i = 0; i < exp.size(); i++) {
        char ch = exp[i];

        // If character is an operand (0–9)
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0'); // convert char to int
        }
        // Otherwise it's an operator
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
        }
    }

    return s.pop(); // final result
}


int main() {
    string exp;
    cout << "Enter string to convert to postfix(dont enter spaces): ";
    cin >> exp;
    cout << "Postfix: " << infixToPostfix(exp) << "\nResult: " << evaluatePostfix(infixToPostfix(exp)) << endl;
    return 0;
}