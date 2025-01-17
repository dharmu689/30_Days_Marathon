#include<bits/stdc++.h>
using namespace std;
int main()
{
     int bill;
    double net;
    cin>>bill;
    if(bill<1000)
    {
        net = bill;
    }
    else if(bill>=1001 && bill<=5000 )
    {
        net = bill - ((bill*5)/100);
    }
    else if(bill>=5001 && bill<=10000 )
    {
        net = bill - ((bill*10)/100);
    }
    else if(bill>10000)
    {
        if(bill>30000)
        {
            net = bill - ((bill*17)/100); 
        }
        else
        {
            net = bill - ((bill*15)/100);
        }
    }
    cout<<fixed << setprecision(2)<<net;
   return 0;
}