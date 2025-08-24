// Q2. Create a MovieTicket class to manage bookings. The class should store the movie name (use
// DMA) and the seat number. Implement the Rule of Three by writing a destructor, a copy
// constructor, and a copy assignment operator to ensure deep copying of data. In your program,
// create one ticket, make a copy of it, and also assign it to another ticket object. Then change the
// movie name in one of the copies and confirm that the original booking remains unaffected.

#include <iostream>
#include <string>
using namespace std;

class MovieTicket {
  private:
    int seatNumber;
    string* movieName;
  
  public:
   MovieTicket(int s, string n) : seatNumber(s), movieName(new string(n)) {}
   
   //deep copy
   MovieTicket(const MovieTicket& other) {
     seatNumber = other.seatNumber;   
     movieName = new string(*(other.movieName));   
   }
   
   void display() {
       cout << "Seat Number: " << seatNumber << endl;
       cout << "Movie Name: " << *movieName << endl;
   }
   
   void setMovieName(string n) {
       *movieName = n;
   }
   
   ~MovieTicket() {
       delete movieName;
   }
   
};

int main() {
    MovieTicket m1(1, "movie1");
    MovieTicket m2(m1); //copy constructor
    
    //before
    cout << "Before:\n";
    m1.display();
    m2.display();
    
    m2.setMovieName("movie2");
    
    //after
    cout << "\n\nAfter:\n";
    m1.display();
    m2.display();
    
    return 0;
}
