#include <iostream>
#include <vector>
using namespace std;

// DFS function to mark all connected lands as visited
void dfs(int **matrix, vector<vector<bool>>& visited, int i, int j, int m, int n) {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    visited[i][j] = true;

    for (auto& dir : directions) {
        int x = i + dir.first;
        int y = j + dir.second;
        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == 1 && !visited[x][y]) {
            dfs(matrix, visited, x, y, m, n);
        }
    }
}

// Function to count the number of islands
int countIslands(int **matrix, int m, int n) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int islands = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                dfs(matrix, visited, i, j, m, n);
                ++islands;
            }
        }
    }

    return islands;
}

int main() {
    int m, n;
    cin >> m >> n;

    int **matrix = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << countIslands(matrix, m, n) << endl;

    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

/*

#include <bits/stdc++.h>
using namespace std;

void dfs(int **matrix, vector<vector<bool>>& visited, int i, int j, int m, int n) {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    visited[i][j] = true;
    
    for (auto& dir : directions) {
        int x = i + dir.first;
        int y = j + dir.second;
        if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == 1 && !visited[x][y]) {
            dfs(matrix, visited, x, y, m, n);
        }
    }
}

int countIslands(int **matrix, int m, int n){
  // Write your code here
vector<vector<bool>> visited(m, vector<bool>(n, false));
    int islands = 0;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                dfs(matrix, visited, i, j, m, n);
                ++islands;
            }
        }
    }
    
    return islands;

}
*/