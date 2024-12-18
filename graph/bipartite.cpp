#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 10;
vector <int> adj[maxN];
bool mark[maxN];
int color[maxN];
bool bipartite = true;

void DFS(int v, int parent) {
    mark[v] = true;

    if(parent != -1) color[v] = 1 - color[parent];
    else color[v] = 1;

    for (auto u : adj[v]) {
        if(!mark[u])
            DFS(u, v);
        else if(color[u] == color[v])
            bipartite = false;
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
    if(bipartite) cout << "Graph Is Bipartite\n";
    else cout << "Graph Is Not Bipartite\n";
}

