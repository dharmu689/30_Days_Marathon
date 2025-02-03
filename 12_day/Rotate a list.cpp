#include <bits/stdc++.h>
// Include headers as needed

using namespace std;

int main()
{
    // Write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n,r;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>r;
        r = r%n;
        vector<int>rotatedArr(n);
        for(int i=0; i<n;i++)
        {
            rotatedArr[i] = arr[(i + r) % n];
        }
        for (int i = 0; i < n; ++i) 
        {
            if (i > 0) cout << " ";
            cout << rotatedArr[i];
        }
        cout << endl;
    }
    

    // Return 0 to indicate normal termination
    return 0;
}
