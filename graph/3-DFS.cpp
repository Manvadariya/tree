#include <iostream>
#include <vector>

using namespace std;

void DFS(int curr, vector<int> adj[], vector<bool>& visited, vector<int>& ans){
    visited[curr] = true;
    ans.push_back(curr);
    for(int neighbour: adj[curr]){
        if(!visited[neighbour])
            DFS(neighbour, adj, visited, ans);
    }
}
// Time Complexity: O(V+E)
// Space Complexity: O(V)

// // if adjacency matrix is given
// void DFS(int curr, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans){
//     visited[curr] = true;
//     ans.push_back(curr);
//     for(int i = 0; i < adj.size(); i++){
//         if(adj[curr][i] == 1 && !visited[i])
//             DFS(i, adj, visited, ans);
//     }
// }
// // Time Complexity: O(V^2)
// // Space Complexity: O(V)
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    int start=0;
    vector<int> ans;
    DFS(start, adj, visited, ans);
    return ans;
}
// Time Complexity: O(V+E)
// Space Complexity: O(V)

int main() {
    int V = 5;
    vector<int> adj[V] = {{1,2,3},{0,2},{0,1,4},{0,4},{1,2,3}};
    vector<int> ans = dfsOfGraph(V, adj);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}