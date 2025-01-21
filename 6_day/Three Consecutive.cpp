#include <iostream>
#include <algorithm> // For sort
using namespace std;

// Function to check if three numbers are consecutive
int threeConsecutive(int a, int b, int c) {
    // Put the numbers into an array and sort them
    int arr[3] = {a, b, c};
    sort(arr, arr + 3);

    // Check if they are consecutive
    if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1) {
        return 1; // They are consecutive
    } else {
        return 0; // Not consecutive
    }
}

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << threeConsecutive(a, b, c) << endl;
    }

    return 0;
}


/*
 * Complete the function 'threeConsecutive' below
 * @params
 *   a,b,c -> integers which are to be checked
 * @return
 * An integer, 1 if the numbers are consecutive else 0
 
#include<bits/stdc++.h>
int threeConsecutive(int a, int b, int c){
  // Write your code here
    int arr[3] = {a,b,c};
    sort(arr,arr+3);
    if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
*/