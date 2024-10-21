#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAXSIZE = 10;

class Graph {
private:
    vector<vector<int>> adjList;
    set<int> nodes;
    int numNodes;

public:
    explicit Graph(int n) : numNodes(n) {
        adjList.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            nodes.insert(i);
        }
    }

    void insertEdge(int from, int to) {
        if (from > numNodes || to > numNodes || from <= 0 || to <= 0) {
            throw runtime_error("INVALID SEQUENCE OF COMMANDS");
        }
        if (find(adjList[from].begin(), adjList[from].end(), to) == adjList[from].end()) {
            adjList[from].push_back(to);
        }
    }

    void deleteEdge(int from, int to) {
        if (from > numNodes || to > numNodes || from <= 0 || to <= 0) {
            throw runtime_error("INVALID SEQUENCE OF COMMANDS");
        }
        auto it = find(adjList[from].begin(), adjList[from].end(), to);
        if (it == adjList[from].end()) {
            throw runtime_error("INVALID SEQUENCE OF COMMANDS");
        }
        adjList[from].erase(it);
    }

    void deleteNode(int node) {
        if (node > numNodes || node <= 0 || nodes.find(node) == nodes.end()) {
            throw runtime_error("INVALID SEQUENCE OF COMMANDS");
        }
        adjList[node].clear();
        for (auto& list : adjList) {
            list.erase(remove(list.begin(), list.end(), node), list.end());
        }
        nodes.erase(node);
    }

    void print() {
        if (nodes.empty()) {
            throw runtime_error("Graph is Empty");
        }
        for (int i : nodes) {
            cout << i;
            for (int neighbor : adjList[i]) {
                cout << "->" << neighbor;
            }
            cout << endl;
        }
    }
};
int main() {
    int n;
    cin >> n;

    if (n > MAXSIZE) {
        cout << "C" << endl;
        return 0;
    }

    Graph graph(n);

    while (true) {
        int code;
        cin >> code;

        try {
            switch (code) {
                case 1: {
                    int from, to;
                    cin >> from >> to;
                    graph.insertEdge(from, to);
                    break;
                }
                case 2:
                case 3: {
                    int from, to;
                    cin >> from >> to;
                    graph.deleteEdge(from, to);
                    break;
                }
                case 4: {
                    int node;
                    cin >> node;
                    graph.deleteNode(node);
                    break;
                }
                case 5:
                    graph.print();
                    return 0;
                default:
                    throw runtime_error("INVALID SEQUENCE OF COMMANDS");
            }
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
            return 0;
        }
    }

    return 0;
}