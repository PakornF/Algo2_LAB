#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        adj[A].push_back({B, W});
        adj[B].push_back({A, W}); // undirected
    }

    const long long INF = 1e15;
    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue; // outdated entry
        if (u == N) break; // early stop once reaching destination

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[N] << "\n";
}