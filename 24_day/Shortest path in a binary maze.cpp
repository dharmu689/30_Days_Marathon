#include <bits/stdc++.h>
using namespace std;

// Structure to represent a point in the grid
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}  // Constructor
};

int shortestPath(vector<vector<int>>& mat, int srcR, int srcC, int destR, int destC, int m, int n) {
    if (mat[srcR][srcC] == 0 || mat[destR][destC] == 0) {
        return -1;  // If source or destination is blocked
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<Point, int>> q;  // Queue stores {Point, distance}
    
    // Directions for movement: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    visited[srcR][srcC] = true;
    q.push({Point(srcR, srcC), 0});  // Starting point with distance 0

    while (!q.empty()) {
        auto current = q.front();
        Point point = current.first;
        int distance = current.second;
        q.pop();

        // If we reach the destination, return the shortest distance
        if (point.x == destR && point.y == destC) {
            return distance;
        }

        // Explore all four directions
        for (auto& dir : directions) {
            int x = point.x + dir.first;
            int y = point.y + dir.second;

            // Check boundaries and if the cell is valid
            if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]) {
                visited[x][y] = true;
                q.push({Point(x, y), distance + 1});
            }
        }
    }

    return -1;  // If destination is not reachable
}

// Driver Code
int main() {
    vector<vector<int>> mat = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1}
    };

    int m = mat.size(), n = mat[0].size();
    int srcR = 0, srcC = 0;
    int destR = 3, destC = 3;

    int result = shortestPath(mat, srcR, srcC, destR, destC, m, n);
    cout << "Shortest Path Length: " << result << endl;

    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}  // Constructor
};

int shortestPath(vector<vector<int>>& mat, int srcR, int srcC, int destR, int destC, int m, int n) {
    if (mat[srcR][srcC] == 0 || mat[destR][destC] == 0) {
        return -1;  // If source or destination is blocked
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<Point, int>> q;  // Queue stores {Point, distance}
    
    // Directions for movement: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    visited[srcR][srcC] = true;
    q.push({Point(srcR, srcC), 0});  // Starting point with distance 0

    while (!q.empty()) {
        auto current = q.front();
        Point point = current.first;
        int distance = current.second;
        q.pop();

        // If we reach the destination, return the shortest distance
        if (point.x == destR && point.y == destC) {
            return distance;
        }

        // Explore all four directions
        for (auto& dir : directions) {
            int x = point.x + dir.first;
            int y = point.y + dir.second;

            // Check boundaries and if the cell is valid
            if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] == 1 && !visited[x][y]) {
                visited[x][y] = true;
                q.push({Point(x, y), distance + 1});
            }
        }
    }

    return -1;
}
*/