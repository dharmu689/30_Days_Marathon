#include <bits/stdc++.h>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element (last element)
    int i = low - 1;  // Pointer for the smaller element
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Swap if element is smaller than pivot
        }
    }
    swap(arr[i + 1], arr[high]);  // Swap pivot with the correct position
    return i + 1;  // Return partition index
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);  // Sort left partition
        quickSort(arr, pi + 1, high); // Sort right partition
    }
}

// Driver Code
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate array size
    
    quickSort(arr, 0, n - 1);  // Call QuickSort

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}


/*
int partition(int array[], int low, int high) {
    int pivot = array[high]; 
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}
*/