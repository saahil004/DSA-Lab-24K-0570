/*
Q5. Create a database with Teacher class to store the teacher’s name, the subject they teach,
and their years of experience, with the name and subject stored as dynamic strings. First, write
the class without a copy constructor or assignment operator and observe what happens when
you copy one teacher object into another (shallow copy problem). Then implement the Rule of
Three to fix the issue. Display both teacher objects before and after the fix to demonstrate the
difference.
*/
#include <iostream>
#include <string>
using namespace std;

class Teacher {
    private:
      string* name;
      string* subject;
      int yearsExp;
    
    public:
      Teacher(string n, string s, int y) : name(new string(n)), subject(new string(s)), yearsExp(y) {}
      
      // no copy constructor so shallow copy will be done

      Teacher(const Teacher& other) {
        name = new string(*other.name);
        subject = new string(*other.subject);
        yearsExp = other.yearsExp;
      }

      void display() {
        cout << "\nTeacher Details\n" << "Name: " << *name << "\nSubject: " << *subject << "\nYears of Experience: " << yearsExp << endl;
      }
      
      void changeSubject(string s) {
        *subject = s;
      }

      ~Teacher() {
        delete name;
        delete subject;
      }
};

int main() {
    Teacher t1("Saahil", "cs", 5);
    Teacher t2(t1);
    cout << "Before\n";
    t1.display();
    t2.display();

    cout << "\n\nChanging only teacher one's subject to science.\n\n";
    t1.changeSubject("Science");
    cout << "After\n";
    t1.display();
    t2.display();
    return 0;
}