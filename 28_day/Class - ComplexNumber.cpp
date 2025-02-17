#include<bits/stdc++.h>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(int r, int i) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Overloading the - operator
    Complex operator-(const Complex& obj) {
        return Complex(real - obj.real, imag - obj.imag);
    }

    // Function to display the complex number in required format
    void display() {
        cout << real;
        if (imag >= 0) cout << "+";  // Ensure '+' sign for positive imaginary parts
        cout << imag << "i"; // Removed extra endl here to match your output format
    }

};

int main()
{
  int r,i;
  cin>>r>>i;
  Complex D1(r,i);
  cin>>r>>i;
  Complex D2(r,i);
  Complex D3,D4;
  D3=D1+D2;
  D4=D1-D2;
  D3.display();
  cout<<endl;
  D4.display();
  return 0;
}