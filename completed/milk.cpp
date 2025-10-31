#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>

using namespace std;

// -------- Fast I/O (fread-based) ----------
struct FastScanner {
    static const int BUFSIZE = 1 << 20;
    int idx = 0, size = 0;
    char buf[BUFSIZE];

    inline char gc() {
        if (idx >= size) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }
    template<typename T>
    inline bool readInt(T &out) {
        char c; T sign = 1; T val = 0;
        c = gc(); if (!c) return false;
        while (c != '-' && (c < '0' || c > '9')) { c = gc(); if (!c) return false; }
        if (c == '-') { sign = -1; c = gc(); }
        for (; c >= '0' && c <= '9'; c = gc()) val = val * 10 + (c - '0');
        out = val * sign;
        return true;
    }
    inline bool readOp(char &op) {
        char c = gc(); if (!c) return false;
        while (c != 'c' && c != 'q') { c = gc(); if (!c) return false; }
        op = c; 
        return true;
    }
} in;

// -------- DSU with iterative path halving + union by rank ----------
struct DSU {
    int n;
    vector<int> parent;
    vector<uint16_t> rnk; // small, fast

    explicit DSU(int n): n(n), parent(n+1), rnk(n+1, 0) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    // Iterative find with path halving
    inline int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]]; // halve
            x = parent[x];
        }
        return x;
    }

    inline void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) ++rnk[a];
    }

    inline bool same(int a, int b) { return find(a) == find(b); }
};

int main() {
    // Use FastScanner for input, manual buffer for output
    int N, Q;
    if (!in.readInt(N)) return 0;
    in.readInt(Q);

    DSU dsu(N);
    string out; out.reserve(Q * 4); // rough

    for (int i = 0; i < Q; ++i) {
        char op; in.readOp(op);
        int x, y; in.readInt(x); in.readInt(y);
        if (op == 'c') {
            dsu.unite(x, y);
        } else { // 'q'
            out += (dsu.same(x, y) ? "yes\n" : "no\n");
        }
    }
    cout << out;
}