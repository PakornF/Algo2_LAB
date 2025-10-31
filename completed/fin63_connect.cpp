#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int L, N, T;
    if (!(cin >> L >> N >> T)) return 0;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) cin >> words[i];

    // Map exact word -> list of indices (handle duplicates robustly)
    unordered_map<string, vector<int>> wordIdx;
    wordIdx.reserve(N * 2);

    // Map prefix (length L-1) -> list of word indices starting with that prefix
    unordered_map<string, vector<int>> startWith;
    startWith.reserve(N * 2);

    const int K = max(0, L - 1);
    for (int i = 0; i < N; ++i) {
        wordIdx[words[i]].push_back(i);
        string pref = words[i].substr(0, K);
        startWith[pref].push_back(i);
    }

    // Build adjacency: edge i -> j if suffix(L-1) of wi == prefix(L-1) of wj
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; ++i) {
        string suf = words[i].substr(L > 0 ? 1 : 0, K); // when L=1, K=0 -> empty
        auto it = startWith.find(suf);
        if (it != startWith.end()) adj[i] = it->second; // copy neighbors
    }

    // Answer queries with BFS (multi-source if duplicates)
    for (int qi = 0; qi < T; ++qi) {
        string s, t;
        cin >> s >> t;

        const auto &srcs = wordIdx[s];
        const auto &tgts = wordIdx[t];

        vector<char> isTarget(N, 0);
        for (int v : tgts) isTarget[v] = 1;

        vector<char> vis(N, 0);
        queue<int> q;

        for (int sidx : srcs) {
            vis[sidx] = 1;
            q.push(sidx);
        }

        bool ok = false;
        while (!q.empty() && !ok) {
            int u = q.front(); q.pop();
            if (isTarget[u]) { ok = true; break; }
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        cout << (ok ? "yes" : "no") << '\n';
    }
}