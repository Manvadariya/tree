#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& image, int row, int col, int inColor, int newColor){
    int tRow = image.size();
    int tCol = image[0].size();
    if(row<0 || col < 0 || row >= tRow || col >= tCol) return;
    if(image[row][col] != inColor) return;
    image[row][col] = newColor;
    DFS(image, row, col+1, inColor, newColor);
    DFS(image, row, col-1, inColor, newColor);
    DFS(image, row+1, col, inColor, newColor);
    DFS(image, row-1, col, inColor, newColor);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color) return image;
    DFS(image, sr, sc,image[sr][sc], color);
    return image;
}

int main(){
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> res = floodFill(image, sr, sc, newColor);
    for(auto x : res){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}