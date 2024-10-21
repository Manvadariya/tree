#include <bits/stdc++.h>
using namespace std;

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
class Solution {
public:
    // Function to calculate the minimum number of minutes until no cell has a fresh orange
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        int fresh = 0;
        // Push all the rotten oranges into the queue and mark them as visited
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visited[i][j] = true;
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        // If there are no fresh oranges, return 0
        if(fresh == 0) return 0;
        int minutes = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // Perform BFS to rot the adjacent fresh oranges
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> curr = q.front();
                q.pop();
                for(auto dir : directions){
                    int x = curr.first + dir.first;
                    int y = curr.second + dir.second;
                    if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1 && !visited[x][y]){
                        q.push({x, y});
                        visited[x][y] = true;
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        // If there are still fresh oranges remaining, return -1
        return fresh == 0 ? minutes - 1 : -1;
    }
};