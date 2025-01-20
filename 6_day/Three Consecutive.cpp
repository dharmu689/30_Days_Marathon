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
