/*
1. Write a recursive function that counts how many times a specific character appears in a given string.
*/
#include <iostream>
using namespace std;

int charCount(string str, int i, char c, int count) {
     if (i < str.size())
     {
        if (str[i] == c) {
            i++;
            return charCount(str, i, c, count+1);
        }
        else {
            i++;
            return charCount(str, i, c, count);
        }
     }
     return count;
}

int main() {
    string name = "saahil";
    char c = 'a';
    cout << "Number of a's in saahil: " << charCount(name, 0, c, 0);
    return 0;
}