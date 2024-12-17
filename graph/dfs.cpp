#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
bool mark[maxN];
vector <int> component;

void DFS(int v) {
    mark[v] = true;
    component.push_back(v);

    for (auto u : adj[v])
        if(!mark[u]) DFS(u);

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
        component.clear();

        DFS(i);

        for (auto v : component)
            cout << v << ' ';
        cout << '\n';

    }

}
