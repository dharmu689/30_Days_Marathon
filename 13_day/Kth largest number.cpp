
#include <bits/stdc++.h>
using namespace std;

// Function to find the kth largest element
int kthLargest(int arr[], int size, int k) {
    vector<int> nums(arr, arr + size); // Create a vector from the array

    // Use nth_element to efficiently find the kth largest element
    nth_element(nums.begin(), nums.begin() + (size - 1 - k), nums.end());

    return nums[size - 1 - k];
}

int main() {
    int n, k;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Input the value of k
    cout << "Enter the value of k: ";
    cin >> k;

    // Validate k
    if (k > n || k <= 0) {
        cout << "Invalid value of k!" << endl;
        return 1;
    }

    // Call the function and print the result
    int result = kthLargest(arr, n, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}



/* 

#include<bits/stdc++.h>
int kthLargest(int arr[], int size, int k) {
  // Write your code here
   vector<int> nums(arr, arr + size); // Create a vector from the array

    // Use nth_element to efficiently find the kth largest element
    nth_element(nums.begin(), nums.begin() + (size - 1 - k), nums.end());

    return nums[size - 1 - k];
}

*/