#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adja;
vector<bool> visited;

void dfs(int n) {
    visited[n] = true;
    for (int v : adja[n]) {
        if (!visited[v]) dfs(v);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    adja.assign(n + 1, {});
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adja[u].push_back(v);
        adja[v].push_back(u); 
    }

    int count = 0;  
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    cout << count << "\n";


}