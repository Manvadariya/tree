#include <bits/stdc++.h>

using namespace std;

int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) {
            q.push({i, 0});
            visited[i][0] = 1;
        }
        if (grid[i][m - 1] == 1) {
            q.push({i, m - 1});
            visited[i][m - 1] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        if (grid[0][i] == 1) {
            q.push({0, i});
            visited[0][i] = 1;
        }
        if (grid[n - 1][i] == 1) {
            q.push({n - 1, i});
            visited[n - 1][i] = 1;
        }
    }
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                q.push({newRow, newCol});
                visited[newRow][newCol] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += grid[i][j] && !visited[i][j];
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << numEnclaves(grid) << endl;
    return 0;
}