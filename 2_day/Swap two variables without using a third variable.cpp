#include<iostream>
#include<cstdio>
#include<cmath>
// Include headers as needed
using namespace std;
int main()
{
    // Write your code here
    int a,b;
    cin>>a>>b;
    a = a+b;
    b = a-b;
    a = a-b;
    cout<<a<<endl<<b;
    // Return 0 to indicate normal termination
    return 0;
}