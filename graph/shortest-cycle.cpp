//this code works for simple graphs.
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010, oo = 1e9;

vector <int> adj[maxN];

int deleted, distances[maxN];
queue<int> q;

void BFS(int n, int r) {

    for (int i=1; i<=n; i++) distances[i] = oo;
    distances[r] = 0;

    q.push(r);

    while(q.size()) {
        int v = q.front();
        q.pop();

        for (auto u : adj[v]) {
            if(v == r && u == deleted) continue; //ignore deleted edge.
            if(distances[u] > distances[v] + 1) {
                distances[u] = distances[v] + 1;
                q.push(u);
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    int length = oo;

    for (int i=1; i<=n; i++) {
        for (auto u : adj[i]) {
            deleted = u;
            BFS(n, i);
            length = min(length, distances[u] + 1);
        }
    }

    if(length == oo) cout << "Graph Does Not Have Cycle\n";
    else cout << "Minimum Cycle Length is : " << length << '\n';

}