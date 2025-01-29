 #include <iostream>
#include <climits>
using namespace std;

// Function to calculate minimum, maximum, and sum of an array
void calculate(int *arr, int size, int *min, int *max, int *sum) {
    *min = INT_MAX;  // Initialize min to the maximum possible value
    *max = INT_MIN;  // Initialize max to the minimum possible value
    *sum = 0;        // Initialize sum to 0

    for (int i = 0; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
        *sum += arr[i];
    }
}

int main() {
    int t;
    cout << "Enter the number of elements: ";
    cin >> t;

    int arr[t];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }

    int min, max, sum;
    calculate(arr, t, &min, &max, &sum);

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}


/*
#include<bits/stdc++.h>
void multiReturnArray(int *a, int size, int *min, int *max, int *sum)
{
   *min = a[0];
    *max = a[0];
    *sum = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] < *min) {
            *min = a[i];
        }
        if (a[i] > *max) {
            *max = a[i];
        }
        *sum += a[i];
    }
    
} 
*/