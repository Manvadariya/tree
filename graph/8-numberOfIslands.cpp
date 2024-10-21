#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void BFS(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x > 0 && grid[x-1][y] == '1') {
                q.push({x-1, y});
                grid[x-1][y] = '0';
            }
            if(x < grid.size()-1 && grid[x+1][y] == '1') {
                q.push({x+1, y});
                grid[x+1][y] = '0';
            }
            if(y > 0 && grid[x][y-1] == '1') {
                q.push({x, y-1});
                grid[x][y-1] = '0';
            }
            if(y < grid[0].size()-1 && grid[x][y+1] == '1') {
                q.push({x, y+1});
                grid[x][y+1] = '0';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    BFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution obj;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << obj.numIslands(grid) << endl;
    return 0;
}

// class Solution {
// public:
//     void BFS(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid){
//         visited[row][col] = true;
//         queue<pair<int, int>> q;
//         q.push({row, col});
//         while (!q.empty()){
//             int x = q.front().first;
//             int y = q.front().second;
//             q.pop();
//             // traverse all 8 directions
//             for (int deltaX = -1; deltaX <= 1; deltaX++){
//                 for (int deltaY = -1; deltaY <= 1; deltaY++){
//                     int newX = x + deltaX;
//                     int newY = y + deltaY;
//                     if (newX >= 0 && newX < grid.size() && newY >= 0 &&
//                         newY < grid[0].size() && grid[newX][newY] == '1' && !visited[newX][newY])
//                     {
//                         visited[newX][newY] = true;
//                         q.push({newX, newY});
//                     }
//                 }
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         int count = 0;
//         for(int row = 0; row < n; row++) {
//             for(int col = 0; col < m; col++) {
//                 if(grid[row][col] == '1' && !visited[row][col]) {
//                     BFS(row, col, visited, grid);
//                     count++;
//                 }
//             }
//         }
//     }
// };