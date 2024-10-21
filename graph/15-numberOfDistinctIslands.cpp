#include <bits/stdc++.h>

using namespace std;

// using DFS
void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int, int>>& island, int baseI, int baseJ){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j] == 0){
        return;
    }
    visited[i][j] = 1;
    island.push_back({i-baseI, j-baseJ});
    dfs(i+1, j, grid, visited, island, baseI, baseJ);
    dfs(i-1, j, grid, visited, island, baseI, baseJ);
    dfs(i, j+1, grid, visited, island, baseI, baseJ);
    dfs(i, j-1, grid, visited, island, baseI, baseJ);
}
int countDistinctIslands(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>> islands;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                vector<pair<int, int>> island;
                dfs(i, j, grid, visited, island, i, j);
                islands.insert(island);
            }
        }
    }
    return islands.size();
}