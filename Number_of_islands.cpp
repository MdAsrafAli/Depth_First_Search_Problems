#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1}; // for 8 directions

void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    int n = grid.size(), m = grid[0].size();
    vis[i][j] = 1;
    for (int k = 0; k < 8; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
            !vis[ni][nj] && grid[ni][nj] == 1)
            dfs(ni, nj, grid, vis);
    }
}

int numIslands(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                dfs(i, j, grid, vis);
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    cout << numIslands(grid); // Output: 2
}
