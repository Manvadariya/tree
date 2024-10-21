#include <bits/stdc++.h>

using namespace std;

// using BFS
vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    // push all 0s in queue
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        ans[row][col] = dist;
        for(int i=0; i<4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol]){
                visited[nrow][ncol] = true;
                q.push({{nrow, ncol}, dist + 1});
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> ans = updateMatrix(mat);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}