#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> convert(int V, vector<pair<int,int>>edges) {
    vector<vector<int>> adjList(V);
    // we also can use vector<int> adjList[V];
    // we can also use vector<list<int>> adjList(V);
    for(auto edge : edges){
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }
    return adjList;
}

int main() {
    int V = 5;
    vector<pair<int,int>> edges = {{0,1}, {0,2}, {0,3}, {1,2}, {1,4}, {2,4}, {3,4}};
    vector<vector<int>> adjList = convert(V, edges);
    for(int i = 0; i < V; i++){
        cout << i << " -> ";
        for(int j = 0; j < adjList[i].size(); j++){
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}