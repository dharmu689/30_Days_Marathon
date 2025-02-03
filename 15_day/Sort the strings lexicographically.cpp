
#include <bits/stdc++.h>
using namespace std;

void sortStrings(int n, string arr[]) {
    vector<string> words(arr, arr + n); // Convert array to vector
    sort(words.begin(), words.end()); // Sort strings lexicographically

    for (int i = 0; i < n; ++i) {
        cout << words[i];
        if (i < n - 1) {
            cout << " "; // Add space except for the last word
        }
    }
    cout << endl; // Newline for better formatting
}

// Driver Code
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // To handle newline after input
    
    string arr[n]; // Create array of strings
    cout << "Enter strings: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input strings
    }

    sortStrings(n, arr); // Call the sorting function

    return 0;
}


/*
#include<bits/stdc++.h>
void sortStrings(int n, string str[]) {
   vector<string> words(str, str + n); 
    sort(words.begin(), words.end()); 
    for (int i = 0; i < n; ++i) {
        cout << words[i];
        if (i < n - 1) { // Add space except after the last string
            cout << " ";
        }
    }
}
*/