/*
6. Calculate the factorial of a number using direct recursion. The factorial of a number n
(denoted as n!) is the product of all positive integers less than or equal to n. Example: 5!
= 5 × 4 × 3 × 2 × 1 = 120. Write a recursive function to calculate the factorial of a given
number.
*/
#include <iostream>
#include <string>
using namespace std;

int factorial(int n) {
    
    if (n > 0) {
        return n *= factorial(n-1);
    }
    return 1;
}

int main() {
    int fac = factorial(6);
    cout << fac;
    return 0;
}
