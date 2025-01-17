#include<bits/stdc++.h>
using namespace std;
int main()
{
    char op;
    double num1,num2,result;
    cin>> num1 >> op >> num2;
    switch(op) 
    {
      case '+':
      result = num1 + num2;
      cout<<fixed << setprecision(2)<<result;
      break;
     case '-':
      result = num1 - num2;
      cout<<fixed << setprecision(2)<<result;
      break;
      case '*':
      result = num1 * num2;
      cout<<fixed << setprecision(2)<<result;
      break;
      case '/':
      result = num1 / num2;
      cout<<fixed << setprecision(2)<<result;
      break;
    }       
   return 0;
}