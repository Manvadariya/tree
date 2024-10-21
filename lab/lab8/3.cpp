#include <bits/stdc++.h>
using namespace std;

void check_input(const vector<vector<int>>& adjacency_matrix, const int number_of_node) {
    for (int i = 1; i <= number_of_node; i++) {
        if (adjacency_matrix[i][i] != 0) {
            cout << "Weight of the edge " << i << " - " << i << " must be 0";
            exit(0);
        }
    }

    for (int i = 1; i <= number_of_node; i++) {
        for (int j = 1; j <= number_of_node; j++) {
            if (adjacency_matrix[i][j] < 0) {
                cout << "Weight of the edge " << i << " - " << j << " can not be negative";
                exit(0);
            }
            if (adjacency_matrix[i][j] != adjacency_matrix[j][i]) {
                cout << "Weight of the edge " << j << " - " << i << " must be same as edge " << i << " - " << j;
                exit(0);
            }
        }
    }
}

void primMST(const vector<vector<int>>& graph, int startNode) {
    int n = graph.size() - 1; // Adjust for 1-based indexing
    vector<int> key(n + 1, INT_MAX);
    vector<bool> inMST(n + 1, false);
    vector<int> parent(n + 1, -1);

    key[startNode] = 0;

    for (int count = 0; count < n; ++count) {
        int minKey = INT_MAX, u = 0;

        for (int v = 1; v <= n; ++v) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 1; v <= n; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (parent[i] != -1) {
            cout << i << "-" << parent[i] << "\t" << graph[i][parent[i]] << endl;
        }
    }
}

int main() {
    int number_of_node;
    cin >> number_of_node;
    vector<vector<int>> adjacency_matrix(number_of_node + 1, vector<int>(number_of_node + 1));

    for (int i = 1; i <= number_of_node; i++)
        for (int j = 1; j <= number_of_node; j++)
            cin >> adjacency_matrix[i][j];

    check_input(adjacency_matrix, number_of_node);

    int startNode;
    cin >> startNode;

    primMST(adjacency_matrix, startNode);

    return 0;
}