#include <bits/stdc++.h>
using namespace std;

// DSU
int find(vector<int> &parent, int u){
    if(parent[u] == u) return u;
    return parent[u] = find(parent, parent[u]);
}

void unionAB(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return;
    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a] = b;
    }
}

// Kruskal
struct Edge{
    int src;
    int dest;
    int weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int kruskal(vector<Edge> &edges, int n) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    for(int i = 0; i <= n; i++) parent[i] = i;
    vector<Edge> mst;
    for(Edge e : edges) {
        if(find(parent, e.src) != find(parent, e.dest)) {
            mst.push_back(e);
            unionAB(parent, rank, e.src, e.dest);
        }
    }
    int ans = 0;
    for(Edge e : mst) {
        ans += e.weight;
    }
    return ans;
}
// Time Complexity: O(ElogE + ElogV) = O(ElogE) = O(ElogV)

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    cout << kruskal(edges, n) << endl;
    return 0;
}