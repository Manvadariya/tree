// #include <bits/stdc++.h>

// using namespace std;

// void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited){
//     visited[node] = true;
//     for(auto neighbor : adjList[node]){
//         if(!visited[neighbor]){
//             dfs(neighbor, adjList, visited);
//         }
//     }
// }
// int countComponents(int n, vector<vector<int>>& edges) {
//     vector<vector<int>> adjList(n);
//     for(auto edge : edges){
//         adjList[edge[0]].push_back(edge[1]);
//         adjList[edge[1]].push_back(edge[0]);
//     }
//     vector<bool> visited(n, false);
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         if(!visited[i]){
//             count++;
//             dfs(i, adjList, visited);
//         }
//     }
//     return count;
// }

// int main() {
//     int n = 5;
//     vector<vector<int>> edges = {{0,1}, {0,2}, {0,3}, {1,2}, {1,4}, {2,4}, {3,4}};
//     cout << countComponents(n, edges) << endl;
//     return 0;
// }



// connected components when the graph is given in the form of an adjacency matrix

#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<int>>& adjMatrix, vector<bool>& visited){
    visited[node] = true;
    for(int i = 0; i < adjMatrix.size(); i++){
        if(adjMatrix[node][i] == 1 && !visited[i]){
            dfs(i, adjMatrix, visited);
        }
    }
}
int countComponents(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            count++;
            dfs(i, adj, visited);
        }
    }
    return count;
}
// Time Complexity: O(V^2)
// Space Complexity: O(V)

int main() {
    vector<vector<int>> adj = {{0,1,1,1,0},
                                {1,0,1,0,1},
                                {1,1,0,0,1},
                                {1,0,0,0,1},
                                {0,1,1,1,0}};
    cout << countComponents(adj) << endl;
    return 0;
}

// // connected components when the graph is given in the form of an adjacency list

// #include <bits/stdc++.h>

// using namespace std;

// void dfs(int node, vector<int> adjList[], vector<bool>& visited){
//     visited[node] = true;
//     for(auto neighbor : adjList[node]){
//         if(!visited[neighbor]){
//             dfs(neighbor, adjList, visited);
//         }
//     }
// }
// int countComponents(int n, vector<int> adjList[]) {
//     vector<bool> visited(n, false);
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         if(!visited[i]){
//             count++;
//             dfs(i, adjList, visited);
//         }
//     }
//     return count;
// }
// // Time Complexity: O(V+E)
// // Space Complexity: O(V)

// int main() {
//     int n = 5;
//     vector<int> adj[5] = {{1,2,3},{0,2},{0,1,4},{0,4},{1,2,3}};
//     cout << countComponents(n, adj) << endl;
//     return 0;
// }