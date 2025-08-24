/*
Q3. Create a C++ classInventory that stores a list of item prices using DMA. The size of the
inventory will be provided during object creation. Implement a deep copy constructor so that if
one inventory object is copied to another, changes in one will not affect the other. In your
program, create one inventory with some prices, copy it to another inventory, update a price in
the copied version, and display both to verify they are separate.
*/
#include <iostream>
using namespace std;

class Inventory {
    private:
      int size;
      double* prices;
       
      // method to initialize random values
      void initialize() {
        for (int i = 0; i < size; i++)
        {
            prices[i] = i * 2 + 1;
        }        
      }


    public:
      Inventory(int s) : size(s), prices(new double[s]) {
        this->initialize();
      }
      

      // deep copy constructor
      Inventory(const Inventory& other) {
        size = other.size;
        prices = new double[size];
        for (int i = 0; i < size; i++)
        {
            prices[i] = other.prices[i];
        }
        
      }


      bool change(int ind, double p) {
        if (ind < 0 || ind >= size)
        {
            // index out of bounds
            return false;
        }
        prices[ind] = p;
        return true;
      }

      void display() {
        for (int i = 0; i < size; i++)
        {
            cout << prices[i] << " ";
        }
        cout << endl;
      }

      ~Inventory() {
        delete[] prices;
      }
};


int main() {
    Inventory i1(5), i2(i1);
    cout << "First inventory before: ";
    i1.display();
    cout << "Second inventory before: ";
    i2.display();

    cout << "\n\nValue on 2nd index changed to 22222 in first inventory.\n\n";
    i1.change(2, 22222); //updated the third value or value on 2nd index

    cout << "First inventory after change: ";
    i1.display();
    cout << "Second inventory after change in first inventory: ";
    i2.display();
    return 0;
}