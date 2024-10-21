// 1905. Count Sub Islands
// Medium
// Topics
// Companies
// Hint
// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

// Return the number of islands in grid2 that are considered sub-islands.


#include <bits/stdc++.h>

using namespace std;

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid1.size();
    int n = grid1[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid2[i][j] == 1 && visited[i][j] == 0){
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                bool isSubIsland = true;
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    int x = curr.first;
                    int y = curr.second;
                    if(grid1[x][y] == 0){
                        isSubIsland = false;
                    }
                    for(auto dir : directions){
                        int newX = x + dir[0];
                        int newY = y + dir[1];
                        if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid2[newX][newY] == 1 && visited[newX][newY] == 0){
                            visited[newX][newY] = 1;
                            q.push({newX, newY});
                        }
                    }
                }
                if(isSubIsland){
                    count++;
                }
            }
        }
    }
}