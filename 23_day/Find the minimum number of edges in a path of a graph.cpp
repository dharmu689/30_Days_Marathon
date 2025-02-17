/*
#include<bits/stdc++.h>

int number_of_edges(int n) {
  // write code here 
    if (n == 1) return 0; // If the start and end are the same, no edges are required.

    // BFS queue: stores pairs (current node, distance from the start)
    queue<pair<int, int>> q;
    q.push({1, 0}); // Start from node 1 with distance 0

    // Visited set to avoid revisiting nodes
    unordered_set<int> visited;
    visited.insert(1);

    while (!q.empty()) {
        pair<int, int> front = q.front();
        int current = front.first;
        int distance = front.second;
        q.pop();

        // Generate possible next nodes
        vector<int> next_nodes = {current + 1, current * 3};
        for (int next : next_nodes) {
            if (next == n) {
                return distance + 1; // Reached the target node
            }
            if (next <= n && visited.find(next) == visited.end()) {
                q.push({next, distance + 1});
                visited.insert(next);
            }
        }
    }

    return -1;
}*/