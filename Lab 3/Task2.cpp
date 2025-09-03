/*
Q2. Write a C++ program using a doubly linked list to manage a web browser’s history. The
program should insert new websites visited, move backward to go to the previous page and move
forward to revisit a page. Add function to search for a website in history.
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;

    Node(string dat) : data(dat), next(nullptr), prev(nullptr) {}
};

class LinkedList {
    private:
      Node* head;
      Node* currentPage;

    public:
      LinkedList() : head(nullptr), currentPage(nullptr) {}
      
      bool fwd() {
        if (currentPage->next == nullptr)
        {
          return false;
        }
        currentPage = currentPage->next;
        return true;
        
      }
      bool bwd() {
        if (currentPage->prev == nullptr)
        {
          return false;
        }
        currentPage = currentPage->prev;
        return true;
        
      }

      void addHistory(string domain) {
        Node* n = new Node(domain);
        if (head == nullptr)
        {
           head = n;
           currentPage = head;
           return;
        }
        head->prev = n;
        n->next = head;
        head = n;
        currentPage = head;
      }

      bool deleteHistory(int ind) {
        Node* n = head;
        int c = 0;
        if (ind < 0 || head == nullptr)
        {
          return false;
        }
        
        if (ind == 0) {
          head = head->next;
          head->prev = nullptr;
          delete n;
          return true;
        }
        while (c!= ind && n != nullptr) {
           n = n->next;
           c++;
        }
        if (n == nullptr) { return false; }
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
        return true;
      }

      int searchPage(string dat) {
        Node* n = head;
        int i = 0;
        while (n->data != dat && n != nullptr) {
            n = n->next;
            i++;
        }
        if (n == nullptr)
        {
            return -1;
        }
        return i;
      }

      void displayHistory() {
        Node* n = head;
        if (head == nullptr)
        {
          cout << "List empty.\n";
          return;
        }
        int i = 1;
        cout << "\nList:\n";
        while (n != nullptr)
        {
          cout << i << ": " << n->data << "\n";
          n = n->next;
          i++;
        }
        cout << "Current page: " << currentPage->data << endl;
        cout << "\n";
        return;
      }

      ~LinkedList() {
        Node* curr = head;
        while (curr != nullptr)
        {
            Node* n = curr->next;
            delete curr;
            curr = n;
        }
        
      }
};

int main() {
    LinkedList history;
    int c = 2;
    while (c > 0 && c < 6)
    {
       history.displayHistory();
       cout << "Enter 1 to add a website to history.\nEnter 2 to delete a history.\nEnter 3 to search a webpage in the list.\nEnter 4 to move forward or 5 to move backward.\nChoice: ";
       cin >> c;
       switch (c)
       {
       case 1:
        {
          string website;
          cout << "Enter website domain visited to be added to history: ";
          cin >> website;
          history.addHistory(website);
        }
        break;
       case 2:
        {
          int idx;
          cout << "Enter number to be deleted from the history(starting from 1): ";
          cin >> idx;
          idx--;
          (history.deleteHistory(idx)) ? cout << "Deleted.\n" : cout << "Not deleted.\n";

        }
        break;
       case 3:
        {
          string website;
          cout << "Enter website domain to search in history: ";
          cin >> website;
          int idx = history.searchPage(website);
          (idx == -1) ? cout << "Page not visited.\n" : cout << "Found at " << idx + 1 << endl;
        }
        break;
         case 4: 
         {
           history.fwd();
         }
         break;
         case 5: 
         {
           history.bwd();
         }
         break;
       default:
        break;
       }
    }
    
    return 0;
}