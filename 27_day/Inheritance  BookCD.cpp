#include<iostream>
#include<cstdio>
#include<string>
#include<iomanip>
using namespace std;
class Publication
{
      protected:
      string title;
      int price;
      public:
};
// Derived class Book from Publication
class Book : public Publication {
private:
    int pages;
    string author;

public:
    // Constructor for Book (Manually assigning title and price)
    Book(string t, int p, int pg, string w) {
        title = t;  // Assigning directly
        price = p;  // Assigning directly
        pages = pg;
        author = w;
    }

    // Function to display Book data
    void putdata() {
        cout << "Book Title \"" << title << "\", written by \"" << author 
             << "\" has " << pages << " pages and of " << price << " rupees." << endl;
    }
};

// Derived class CD from Publication
class CD : public Publication {
private:
    int length; // Playing time in minutes

public:
    // Constructor for CD (Manually assigning title and price)
    CD(string t, int p, int l) {
        title = t;  // Assigning directly
        price = p;  // Assigning directly
        length = l;
    }

    // Function to display CD data
    void putdata() {
        cout << "CD Title \"" << title << "\", is of " << length 
             << " minutes length and of " << price << " rupees." << endl;
    }
};

// Function to execute user-defined logic (since main() is auto-generated)
void userMain() {
    // Taking user input
    string bookTitle, writer, cdTitle;
    int bookPrice, bookPages, cdPrice, cdLength;

    getline(cin, bookTitle);
    cin >> bookPrice;
    cin >> bookPages;
    cin.ignore();  // Ignore newline character
    getline(cin, writer);

    getline(cin, cdTitle);
    cin >> cdPrice;
    cin >> cdLength;

    // Creating objects
    Book b(bookTitle, bookPrice, bookPages, writer);
    CD c(cdTitle, cdPrice, cdLength);

    // Displaying details
    b.putdata();
    c.putdata();
}

int main()
{
  string t,w;
  int p,pa,ti;
  cin>>t>>p>>pa>>w;
  Book b(t,p,pa,w);
  cin>>t>>p>>ti;
  CD c(t,p,ti);
  b.putdata();
  c.putdata();
  return 0;
}