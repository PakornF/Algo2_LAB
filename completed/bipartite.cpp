#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(int N, vector<vector<int>>& adj) {

    vector<int> color(N + 1, 0); 

    // BFS for each component of the graph
    for (int i = 1; i <= N; ++i) {
        if (color[i] == 0) {  // If the node is uncolored, start BFS
            queue<int> q;
            q.push(i);
            color[i] = 1;  // Color the starting node with color 1

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : adj[node]) {
                    if (color[neighbor] == 0) {  // If the neighbor is uncolored, color it with the opposite color
                        color[neighbor] = 3 - color[node];  // If node is color 1, color it 2, else color it 1
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node]) {  // If the neighbor has the same color, it's not bipartite
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int K; // number of test cases
    cin >> K;
    
    while (K--) {
        int N, M;
        cin >> N >> M;

        // Create an adjacency list to represent the graph
        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Check if the graph is bipartite
        if (isBipartite(N, adj)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}