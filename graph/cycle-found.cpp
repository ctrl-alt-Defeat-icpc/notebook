#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
bool mark[maxN];
bool cycle_found = false;

void DFS(int v, int parent) {
    mark[v] = true;

    for (auto u : adj[v]) {
        if(!mark[u]) DFS(u, v); //u's parent is v.
        else if(u != parent) cycle_found = true;
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        if(mark[i]) continue ;
        DFS(i, -1); //root does not have parent.
    }
    if(cycle_found) cout << "Graph has Cycle\n";
    else cout << "Graph does not have Cycle\n";
}
