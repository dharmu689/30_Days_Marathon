#include <bits/stdc++.h>
using namespace std;

int zeroOneKnapsack(int val[], int weight[], int n, int capacity) {
    // Create a 2D DP table initialized with 0
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Loop through all items
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            // If the current item can be included in the knapsack
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - weight[i - 1]], // Include the item
                    dp[i - 1][w] // Exclude the item
                );
            } else {
                // If item weight is more than current capacity, we can't include it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The final answer is stored in dp[n][capacity]
    return dp[n][capacity];
}

// Driver Code
int main() {
    int val[] = {60, 100, 120};  // Values of the items
    int weight[] = {10, 20, 30}; // Weights of the items
    int capacity = 50;           // Maximum capacity of the knapsack
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum Value: " << zeroOneKnapsack(val, weight, n, capacity) << endl;

    return 0;
}

/*
#include<bits/stdc++.h>
int zeroOneKnapsack(int val[], int weight[], int n, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}*/