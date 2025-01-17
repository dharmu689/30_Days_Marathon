#include<iostream>
#include<cstdio>
#include<cmath>
#include <iomanip>
using namespace std;
int main()
{
    double x,y,sum;
    cin >>x >>y;
    sum = x + y;
    cout <<fixed<<setprecision(2)<<sum;
   return 0;
}