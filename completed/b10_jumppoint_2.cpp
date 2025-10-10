#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static long long dist2(int x1, int y1, int x2, int y2) {
    long long dx = x1 - x2, dy = y1 - y2;
    return dx*dx + dy*dy;
}

int main() {

    int N, R;
    if (!(cin >> N >> R)) return 0;
    long long R2 = 1LL * R * R;

    vector<pair<int,int>> pts;
    pts.push_back({0, 0});
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        pts.push_back({x, y});
    }
    pts.push_back({100, 100});

    int M = (int)pts.size();

    vector<int> dist(M, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < M; ++v) {
            if (dist[v] == -1 &&
                dist2(pts[u].first, pts[u].second, pts[v].first, pts[v].second) <= R2) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dist[M-1] << "\n";
}