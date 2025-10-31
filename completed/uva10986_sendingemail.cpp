#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    int T; 
    if (!(cin >> T)) return 0;

    for (int tc = 1; tc <= T; ++tc) {
        int n, m, S, Target;
        cin >> n >> m >> S >> Target;

        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w}); // bidirectional
        }

        const long long INF = (1LL << 60);
        vector<long long> dist(n, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            if (u == Target) break; // early stop

            for (auto [v, w] : adj[u]) {
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        cout << "Case #" << tc << ": ";
        if (dist[Target] == INF) cout << "unreachable\n";
        else cout << dist[Target] << "\n";
    }
}