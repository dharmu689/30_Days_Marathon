#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int num, div = 1, divsum = 0;
    cin >> num;
    if (num > 0)
    {
        while (div < num)
        {
            if (num % div == 0)
            {
                divsum = divsum + div;
            }
            div++;
        }
        if (divsum == num)
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
    }
    else
    {
        cout << "no";
    }
    return 0;
}