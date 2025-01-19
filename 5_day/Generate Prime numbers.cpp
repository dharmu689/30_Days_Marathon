//use kam time

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    // Loop through numbers from 2 to n
    for (int i = 2; i <= n; i++) {
        bool isPrime = true; // Assume the number is prime initially
        
        // Check divisors only up to sqrt(i)
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false; // Not a prime number
                break; // Exit the loop early if a divisor is found
            }
        }
        
        if (isPrime) {
            cout << i << endl;
        }
    }

    return 0;
}



/*
use jayda time


#include<iostream>
#include<cstdio>
#include<cmath>
// Include headers as needed

using namespace std;

int main()
{
    // Write your code here
    int n;
    cin>>n;
    
        for(int i=2; i<=n; i++)
        {
            int count = 0;
             for(int j = 1; j<=i; j++)
             {
                 if(i%j == 0)
                 {
                     count++;
                 }
                
             }  
             if(count == 2)
                 {
                    cout<<i<<endl;
                 }
        }

    // Return 0 to indicate normal termination
    return 0;
}





*/