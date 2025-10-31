#include <iostream>
#include <vector>

using namespace std;

vector<int> bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size() - 1;
    vector<int> visited(n + 1, 1000000000);
    queue<int> q;
    visited[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (visited[v] == 1000000000) {
                visited[v] = visited[u] + 1;
                q.push(v);
            }
        }
    }
    return visited;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> P(n+1);

    for (int i = 1; i <= n; i++){
        cin >> P[i];
    }

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // bfs from node 1 and N
    vector<int> distFrom1 = bfs(1, adj);
    vector<int> distFromN = bfs(n, adj);
    
    int best = 0;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) continue;
            int option1 = distFrom1[i] + distFromN[j] + P[i] + P[j];
            int option2 = distFrom1[j] + distFromN[i] + P[i] + P[j];
            best = max({best, option1, option2});
        }
    }
    cout << best << "\n";
}
