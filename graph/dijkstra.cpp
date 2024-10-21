#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> Edge; // (weight, vertex)

void dijkstra(const vector<vector<Edge>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : graph[u]) {
            int v = edge.second;
            int weight = edge.first;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        cout << "Vertex: " << i << " Distance: " << dist[i] << " Path: ";
        int j = i;
        while (j != -1) {
            cout << j << " ";
            j = parent[j];
        }
        cout << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back({10, 1});
    graph[0].push_back({3, 4});
    graph[1].push_back({2, 2});
    graph[1].push_back({4, 4});
    graph[2].push_back({9, 3});
    graph[3].push_back({7, 2});
    graph[4].push_back({1, 1});
    graph[4].push_back({8, 2});
    graph[4].push_back({2, 3});

    dijkstra(graph, 0);

    return 0;
}