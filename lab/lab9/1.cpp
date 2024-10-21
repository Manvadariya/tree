#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void path(vector<int>& parent, int n) {
    if (parent[n] == n) {
        cout << n;
        return;
    }
    path(parent, parent[n]);
    cout << "->" << n;
}

void dijkstra_algo(int n, const vector<vector<long int>> adj[], int src) {
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    vector<int> dist(n + 1, 10000);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {src, -1}});
    dist[src] = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second.first;
        for (const auto& i : adj[node]) { // Use const reference here
            int edge_node = i[0];
            int weight = i[1];
            if (dist[edge_node] > dist[node] + weight) {
                dist[edge_node] = dist[node] + weight;
                parent[edge_node] = node;
                pq.push({weight, {edge_node, node}});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << "\t" << dist[i] << "\t";
        path(parent, i);
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    long int matrix[n + 1][n + 1];
    vector<vector<long int>> adj[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long int temp;
            cin >> temp;

            matrix[i][j] = temp;
            if (temp < -1) {
                cout << "Weight of the edge " << i << " - " << j << " can not be negative";
                return 0;
            }
            if (i == j && temp != 0) {
                cout << "Weight of the edge " << i << " - " << j << " must be 0";
                return 0;
            }
            if (i != j && temp == 0) {
                cout << "Weight of the edge " << i << " - " << j << " can not be 0";
                return 0;
            }
            if (matrix[i][j] != 0 && matrix[i][j] != -1) {
                vector<long int> t1;
                t1.push_back(j);
                t1.push_back(matrix[i][j]);
                adj[i].push_back(t1);
            }
        }
    }

    int src;
    cin >> src;
    dijkstra_algo(n, adj, src);
    return 0;
}
