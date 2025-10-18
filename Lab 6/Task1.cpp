/*
Write a program to check for balanced parentheses { [ ( ) ] } using a stack
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
      
      char pop() {
          if (pointer == 0) { return '!'; } // exclamation mark to indicate stack underflow
          pointer--;
          return arr[pointer];
      }
      
      ~Stack() {
          delete[] arr;
      }
};

char parenthesis(char p) {
    if (p == '(') { return ')'; }
    if (p == '[') { return ']'; }
    if (p == '{') { return '}'; }
    return ' ';
}

bool matchParentheses(string exp) {
    Stack s(exp.size());
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            s.push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            char res = s.pop();
            if (res == '!' || exp[i] != parenthesis(res)) {
                return false;
            }
        }
    }
    if (s.pop() != '!') { return false; }
    return true;
    
}

int main() {
    string exp;
    cout << "Enter string to check if parentheses are balanced or not(dont enter spaces): ";
    cin >> exp;
    (matchParentheses(exp)) ? cout << "Parantheses balanced.\n" : cout << "Not balanced.\n";
    return 0;
}