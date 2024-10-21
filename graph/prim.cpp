#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> Edge; // (weight, vertex)

void primMST(vector<vector<Edge>>& graph, int V) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    int src = 0;
    pq.push({0, src});
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for (auto& edge : graph[u]) {
            int weight = edge.first;
            int v = edge.second;
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back({2, 1});
    graph[0].push_back({3, 3});
    graph[1].push_back({2, 0});
    graph[1].push_back({3, 2});
    graph[1].push_back({4, 3});
    graph[2].push_back({3, 1});
    graph[2].push_back({5, 4});
    graph[3].push_back({3, 0});
    graph[3].push_back({4, 1});
    graph[3].push_back({1, 4});
    graph[4].push_back({5, 2});
    graph[4].push_back({1, 3});

    primMST(graph, V);

    return 0;
}