#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,count=0;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(k==arr[i])
            {
                count++;
            }
           
        } cout<<count<<endl;
    }
   return 0;
}