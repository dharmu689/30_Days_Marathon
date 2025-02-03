#include <iostream>
using namespace std;

int gcd(int i, int j) {
    if (j == 0) {
        return i;
    } else {
        return gcd(j, i % j);
    }
}

int main() {
    // Test cases
    cout << gcd(30, 18) << endl; // Output: 6
    cout << gcd(11, 17) << endl; // Output: 1

    return 0;
}

/*
int gcd(int i, int j)
{
   if(j==0)
   {
       return i;
   }
    else
    {
        return gcd(j,i%j);   
    }
}

*/