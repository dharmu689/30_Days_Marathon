#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int complement = k - arr[i];
        if (freq[complement] > 0) {
            count += freq[complement];
        }
        freq[arr[i]]++;
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << getPairsCount(arr.data(), n, k) << endl;
    }
    return 0;
}


/*
int getPairsCount(int arr[], int n, int k) {
  // Write your code here
  unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int complement = k - arr[i];
        if (freq[complement] > 0) {
            count += freq[complement];
        }
        freq[arr[i]]++;
    }

    return count;
}

*/