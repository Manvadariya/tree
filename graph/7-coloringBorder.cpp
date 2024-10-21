#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> internals;
void DFS(vector<vector<int>>& grid, int row, int col, int inColor, int newColor){
    int tRow = grid.size();
    int tCol = grid[0].size();
    if(row<0 || col < 0 || row >= tRow || col >= tCol) return;
    if(grid[row][col] != inColor) return;
    grid[row][col] = -newColor;
    DFS(grid, row, col+1, inColor, newColor);
    DFS(grid, row, col-1, inColor, newColor);
    DFS(grid, row+1, col, inColor, newColor);
    DFS(grid, row-1, col, inColor, newColor);
    // fatching internals
    if (!(row == 0 || col == 0 || row == tRow-1 || col == tCol-1 || 
    grid[row+1][col] != -newColor || grid[row-1][col] != -newColor || grid[row][col+1] != -newColor || grid[row][col-1] != -newColor))
        internals.push_back({row,col});
}
vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    if(grid[r0][c0] == color) return grid;
    int orgColor = grid[r0][c0];
    DFS(grid, r0, c0,grid[r0][c0], color);
    for(auto p: internals){
        grid[p.first][p.second] = orgColor;
    }
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j] < 0) grid[i][j]*=-1;
        }
    }
    return grid;
}

int main(){
    vector<vector<int>> grid = {{1,2,2},{2,3,2}};
    int r0 = 0, c0 = 1, color = 3;
    vector<vector<int>> res = colorBorder(grid, r0, c0, color);
    for(auto x : res){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}