#include <iostream>
using namespace std;

// Function to reverse the array using pointers
void reverseArray(int *a, int size) {
    int *start = a;             // Pointer to the beginning of the array
    int *end = a + size - 1;    // Pointer to the end of the array

    while (start < end) {
        // Swap the elements pointed by start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers closer
        start++;
        end--;
    }
}

int main() {
    int t; // Number of elements in the array
    cin >> t;

    int arr[t];
    for (int i = 0; i < t; i++) {
        cin >> arr[i]; // Input array elements
    }

    // Reverse the array
    reverseArray(arr, t);

    // Print the reversed array
    for (int i = 0; i < t; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


/*
void reverseArray(int *a, int size)
{
    int *start = a;             
    int *end = a + size - 1;    

    while (start < end) {
        
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    
}
*/