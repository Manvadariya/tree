#include <bits/stdc++.h>

using namespace std;

// // using BFS
// bool detectCycle(int source, vector<int> adj[], vector<bool> &visited){
//     visited[source] = true;
//     queue<pair<int, int>> q; // {node, parent}
//     q.push({source, -1});
//     while(!q.empty()){
//         int current = q.front().first;
//         int parent = q.front().second;
//         q.pop();
//         for(auto neighbour: adj[current]){
//             if(!visited[neighbour]){
//                 visited[neighbour] = true;
//                 q.push({neighbour, current});
//             }else if(neighbour != parent){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// // V = number of vertices
// // adj = adjacency list
// bool isCycle(int V, vector<int> adj[]){
//     vector<bool> visited(V, false);
//     // for multiple components
//     for(int i = 0; i < V; i++){
//         if(!visited[i]){
//             if(detectCycle(i, adj, visited)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// using DFS
bool detectCycle(int source, vector<int> adj[], vector<bool> &visited, int parent){
    visited[source] = true;
    for(auto neighbour: adj[source]){
        if(!visited[neighbour]){
            if(detectCycle(neighbour, adj, visited, source) == true){
                return true;
            }
        }else if(neighbour != parent){
            return true;
        }
    }
    return false;
}
// V = number of vertices
// adj = adjacency list
bool isCycle(int V, vector<int> adj[]){
    vector<bool> visited(V, false);
    // for multiple components
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(detectCycle(i, adj, visited, -1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(V, adj)){
        cout << "Cycle is present" << endl;
    }else{
        cout << "Cycle is not present" << endl;
    }
    return 0;
}