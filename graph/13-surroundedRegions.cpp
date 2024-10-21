#include <bits/stdc++.h>

using namespace std;
// using DFS
void dfs(vector<vector<char>>& board, int i, int j){
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O'){
        return;
    }
    board[i][j] = '1';
    dfs(board, i+1, j);
    dfs(board, i-1, j);
    dfs(board, i, j+1);
    dfs(board, i, j-1);
}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    if(n == 0){
        return;
    }
    int m = board[0].size();
    for(int i=0; i<n; i++){
        dfs(board, i, 0);
        dfs(board, i, m-1);
    }
    for(int i=0; i<m; i++){
        dfs(board, 0, i);
        dfs(board, n-1, i);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            if(board[i][j] == '1'){
                board[i][j] = 'O';
            }
        }
    }
}

int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    solve(board);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}