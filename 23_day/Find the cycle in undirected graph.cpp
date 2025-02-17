#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool dfs(int node, int parent, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
    visited.insert(node);

    for (int neighbor : graph[node]) {
        // If the neighbor is not visited, continue DFS
        if (visited.find(neighbor) == visited.end()) {
            if (dfs(neighbor, node, graph, visited)) {
                return true;
            }
        }
        // If the neighbor is visited and not the parent, we found a cycle
        else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

bool hasCycle(int vertices, vector<pair<int, int>>& edges) {
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;

    // Build the graph
    for (auto edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    // Check for a cycle in each component of the graph
    for (int i = 0; i < vertices; i++) {
        if (visited.find(i) == visited.end()) {
            if (dfs(i, -1, graph, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int vertices, edgesCount;
    cin >> vertices >> edgesCount;

    vector<pair<int, int>> edges(edgesCount);
    for (int i = 0; i < edgesCount; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    if (hasCycle(vertices, edges)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}