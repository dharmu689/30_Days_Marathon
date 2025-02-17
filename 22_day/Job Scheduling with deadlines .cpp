#include <bits/stdc++.h>
using namespace std;

int jobScheduling(vector<int> deadlines, vector<int> profits) {
    int n = deadlines.size();
    vector<pair<int, int>> jobs;  

    // Step 1: Store {profit, deadline} pairs and sort by profit (descending)
    for (int i = 0; i < n; i++) {
        jobs.push_back({profits[i], deadlines[i]});
    }
    sort(jobs.rbegin(), jobs.rend());  // Sorting in decreasing order of profit

    // Step 2: Find the maximum deadline
    int maxDeadline = *max_element(deadlines.begin(), deadlines.end());

    // Step 3: Use an array to keep track of available slots
    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0, countJobs = 0;

    // Step 4: Assign jobs greedily
    for (auto job : jobs) {
        int profit = job.first, deadline = job.second;
        
        // Find a free slot from deadline to earlier times
        for (int i = deadline; i > 0; i--) {
            if (slot[i] == -1) { // If the slot is free
                slot[i] = profit;
                totalProfit += profit;
                countJobs++;
                break;
            }
        }
    }

    return totalProfit;
}

// Driver Code
int main() {
    vector<int> deadlines = {2, 1, 2, 1, 3};  
    vector<int> profits = {100, 50, 200, 30, 150}; 

    cout << "Maximum Profit: " << jobScheduling(deadlines, profits) << endl;
    return 0;
}

/* 
#include <bits/stdc++.h>
using namespace std;

int jobScheduling(vector<int> deadlines, vector<int> profits) {
    int n = deadlines.size();
    vector<pair<int, int>> jobs;  

    // Step 1: Store {profit, deadline} pairs and sort by profit (descending)
    for (int i = 0; i < n; i++) {
        jobs.push_back({profits[i], deadlines[i]});
    }
    sort(jobs.rbegin(), jobs.rend());  // Sorting in decreasing order of profit

    // Step 2: Find the maximum deadline
    int maxDeadline = *max_element(deadlines.begin(), deadlines.end());

    // Step 3: Use an array to keep track of available slots
    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0, countJobs = 0;

    // Step 4: Assign jobs greedily
    for (auto job : jobs) {
        int profit = job.first, deadline = job.second;
        
        // Find a free slot from deadline to earlier times
        for (int i = deadline; i > 0; i--) {
            if (slot[i] == -1) { // If the slot is free
                slot[i] = profit;
                totalProfit += profit;
                countJobs++;
                break;
            }
        }
    }

    return totalProfit;
}*/