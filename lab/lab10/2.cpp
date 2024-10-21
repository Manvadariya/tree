// A Bipartite or BiGraph is graph whose vertices can be devided into two disjoint sets U and V such that every edge in the garph connects a vertex in U to one in V.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int adj[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>adj[i][j];
        }
    }
    int color[n];
    for(int i=0; i<n; i++){
        color[i] = -1;
    }
    color[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0; v<n; v++){
            if(adj[u][v] && color[v]==-1){
                color[v] = 1-color[u];
                q.push(v);
            }else if(adj[u][v] && color[v]==color[u]){
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
    return 0;
}

// A graph is bipatide if and only if there is no odd cycle in the graph