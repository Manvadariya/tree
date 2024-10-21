#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// // adj = adjacency list
// vector<int> BFS(vector<int> adj[]) {
//     int noOfVertex = 5;
//     vector<int> ans;
//     vector<bool> visited(noOfVertex,false);
//     queue<int> q;
//     int start = 0; // or 1
//     q.push(start);
//     visited[start] = true;
//     while(!q.empty()){
//         int curr = q.front();
//         q.pop();
//         ans.push_back(curr);
//         for(int neighbour : adj[curr]){
//             if(!visited[neighbour]){
//                 visited[neighbour] = true;
//                 q.push(neighbour);
//             }
//         }
//     }
//     return ans;
// }
// // Time Complexity: O(V+E)
// // Space Complexity: O(V)

// if adjacency matrix is given
vector<int> BFS(vector<vector<int>> adj) {
    int noOfVertex = 5;
    vector<int> ans;
    vector<bool> visited(noOfVertex,false);
    queue<int> q;
    int start = 0; // or 1
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int i = 0; i < noOfVertex; i++){
            if(adj[curr][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return ans;
}
// Time Complexity: O(V^2)
// Space Complexity: O(V)

int main() {
    int V = 5;
    // vector<int> adj[V] = {{1,2,3},{},{4},{},{}};
    // vector<int> ans = BFS(adj);
    vector<vector<int>> adj = {{0,1,1,1,0},{0,0,0,0,0},{0,0,0,0,1},{0,0,0,0,0},{0,0,0,0,0}};
    vector<int> ans = BFS(adj);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}