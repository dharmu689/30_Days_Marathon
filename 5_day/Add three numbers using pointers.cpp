#include<iostream>
using namespace std;

void sum(int *p1, int *p2, int *p3)
{
    
    int total = *p1 + *p2 + *p3;
    cout<<total;
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    sum(&a, &b, &c);
    return 0;
}