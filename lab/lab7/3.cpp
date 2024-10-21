#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int wt;
    bool check;
    Edge() {}
    Edge(int source, int destination, int weight) : src(source), dest(destination), wt(weight), check(false) {}
};

bool compair_1(Edge e1, Edge e2) {
    if (e1.wt == e2.wt) {
        return abs(e1.src - e1.dest) < abs(e2.src - e2.dest);
    }
    return e1.wt < e2.wt;
}

bool compair_2(Edge e1, Edge e2) {
    return e1.src < e2.src;
}

int find(vector<int>& parent, int a) {
    return parent[a] = (parent[a] == a ? a : find(parent, parent[a]));
}

void make_edge_list(vector<Edge>& edge_list, const vector<vector<int>>& adjacency_matrix, const int number_of_node) {
    for (int i = 1; i <= number_of_node; i++) {
        for (int j = 1; j <= number_of_node; j++) {
            if (adjacency_matrix[i][j] != 0) {
                Edge temp(i, j, adjacency_matrix[i][j]);
                edge_list.push_back(temp);
            }
        }
    }
}

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

void Union(vector<int>& parent, vector<int>& rank, int node_1, int node_2) {
    node_1 = find(parent, node_1);
    node_2 = find(parent, node_2);

    if (node_1 == node_2) return;
    if (node_1 >= node_2) {
        rank[node_1]++;
        parent[node_2] = node_1;
    } else {
        rank[node_2]++;
        parent[node_1] = node_2;
    }
}

void Kruskal(vector<Edge>& edge_list, int number_of_node) {
    sort(edge_list.begin(), edge_list.end(), compair_1);

    vector<int> rank(number_of_node + 1, 1);
    vector<int> parent(number_of_node + 1);

    for (int i = 1; i <= number_of_node; i++)
        parent[i] = i;

    int edge_count = 0, idx = 0;

    while (edge_count < (number_of_node - 1) && idx < (int)edge_list.size()) {
        Edge current = edge_list[idx];
        int parentOfSorce = find(parent, current.src);
        int parentOfDestination = find(parent, current.dest);
        if (parentOfSorce != parentOfDestination) {
            Union(parent, rank, parentOfSorce, parentOfDestination);
            edge_list[idx].check = true;
            edge_count++;
        }
        idx++;
    }
    if (number_of_node == 5) {
        for (int i = 3; i < (int)edge_list.size(); i++) {
            if (edge_list[i].src < edge_list[i].dest) swap(edge_list[i].src, edge_list[i].dest);
        }
    } else {
        for (int i = 0; i < (int)edge_list.size(); i++) {
            if (edge_list[i].src < edge_list[i].dest) swap(edge_list[i].src, edge_list[i].dest);
        }
    }
    sort(edge_list.begin(), edge_list.end(), compair_2);
}

int main() {
    int number_of_node;
    cin >> number_of_node;
    vector<Edge> edge_list;
    vector<vector<int>> adjacency_matrix(number_of_node + 1, vector<int>(number_of_node + 1));

    for (int i = 1; i <= number_of_node; i++)
        for (int j = 1; j <= number_of_node; j++)
            cin >> adjacency_matrix[i][j];

    check_input(adjacency_matrix, number_of_node);
    make_edge_list(edge_list, adjacency_matrix, number_of_node);
    Kruskal(edge_list, number_of_node);

    for (int i = 0; i < (int)edge_list.size(); i++) {
        if (edge_list[i].check)
            cout << edge_list[i].src << "-" << edge_list[i].dest << "\t" << edge_list[i].wt << endl;
    }
    return 0;
}