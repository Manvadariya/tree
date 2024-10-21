using namespace std;

void bfs(int start,const vector<list<int>>& adglist, vector<int>& result, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        result.push_back(current);
        for(int neighbor : adglist[current]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

void dfs(int start,const vector<list<int>>& adglist, vector<int>& result, vector<bool>& visited) {
    visited[start] = true;
    result.push_back(start);
    for(int neighbor : adglist[start]){
        if(!visited[neighbor]){
            dfs(neighbor, adglist, result, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<list<int> > adglist(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adglist[u].push_back(v);
        adglist[v].push_back(u);
    }
    vector<int> BFSresult;
    vector<int> DFSresult;
    vector<bool> visited(n+1, false);
    int startNode;
    cin >> startNode;
    bfs(startNode, adglist, BFSresult, visited);
    fill(visited.begin(), visited.end(), false);
    dfs(startNode, adglist, DFSresult, visited);
    for(int node : BFSresult) cout << node << " ";
    cout << "\n";
    for(int node : DFSresult) cout << node << " ";
    return 0;
}