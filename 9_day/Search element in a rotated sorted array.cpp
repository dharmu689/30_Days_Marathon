#include <iostream>
using namespace std;

// Function to search for the target in the rotated sorted array
int searchRotatedSortedArray(int arr[], int n, int k) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if mid is the target
        if (arr[mid] == k) {
            return mid;
        }
        
        // Determine the sorted half
        if (arr[low] <= arr[mid]) { // Left half is sorted
            if (k >= arr[low] && k < arr[mid]) {
                high = mid - 1; // Search in the left half
            } else {
                low = mid + 1; // Search in the right half
            }
        } else { // Right half is sorted
            if (k > arr[mid] && k <= arr[high]) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
    }
    
    return -1; // Target not found
}

int main() {
    int T; // Number of test cases
    cin >> T;
    
    while (T--) {
        int n, k; // Size of the array and the target value
        cin >> n;
        
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cin >> k;
        cout << searchRotatedSortedArray(arr, n, k) << endl;
    }
    
    return 0;
}


/*
int searchRotatedSortedArray(int arr[], int n, int k) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if mid is the target
        if (arr[mid] == k) {
            return mid;
        }
        
        // Determine the sorted half
        if (arr[low] <= arr[mid]) { // Left half is sorted
            if (k >= arr[low] && k < arr[mid]) {
                high = mid - 1; // Search in the left half
            } else {
                low = mid + 1; // Search in the right half
            }
        } else { // Right half is sorted
            if (k > arr[mid] && k <= arr[high]) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
    }
    
    return -1; // Target not found
}

*/