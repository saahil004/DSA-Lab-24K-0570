/*
Q1. Suppose you’re making a library system. Create a Book class that stores the book’s title, author,
and price. The library system should be able to create a book with default values when details are
unknown, create a book with given details when new books are purchased, and make a copy of an
existing book record for testing purposes. In your program, create three book objects to show the
use of three different constructors:
1. Object one using the default constructor to create an object with default values.
2. Object two with given values input by the user.
3. Object three created using the copy constructor from the second book.
Display all book details to verify correct initialization and copying.
*/
#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
     string title, author;
     double price;

    public:
     // default constructor
     Book() : title(""), author(""), price(0) {}

     // parameterized constructor
      Book(string t, string a, double p) : title(t), author(a), price(p) {}

    // copy constructor
      Book(const Book& other) : title(other.title), author(other.author), price(other.price) {}  

    friend istream& operator>>(istream& in, Book& obj);
    friend ostream& operator<<(ostream& out, const Book& obj);
};

istream& operator>>(istream& in, Book& obj) {
        cout << "Enter title: ";
        in >> obj.title;
        cout << "Enter author: ";
        in >> obj.author;
        cout << "Enter price: ";
        in >> obj.price;
        return in;
    }   

ostream& operator<<(ostream& out, const Book& obj) {
    out << "Title: " << obj.title << "\nAuthor: " << obj.author << "\nPrice: " << obj.price << endl;
    return out;
}    

int main() {
    Book b1;
    Book b2;
    
    cout << "Default\n" << b1 << endl;
    cout << "Input\n";
    cin >> b2; // used operator overloading to make it easy and revise concept
    Book b3(b2);
    cout << "\nCopied object\n" << b3 << endl;

    return 0;
}