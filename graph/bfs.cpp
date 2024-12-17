#include<bits/stdc++.h>
#define distance d

using namespace std;

const int maxN = 1e5 + 10, oo = 1e9;

vector <int> adj[maxN];
int distance[maxN];

queue<int> q;

void BFS(int n, int r) {

    for (int i=1; i<=n; i++) distance[i] = oo;
    distance[r] = 0;
    q.push(r);

    while(q.size()) {
        int v = q.front();
        q.pop();

        for (auto u : adj[v])
            if(distance[u] > distance[v] + 1) {
                distance[u] = distance[v] + 1;
                q.push(u);
            }
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

    BFS(n, 1);

    for (int i=1; i<=n; i++)
        cout << i << ':' << distance[i] << '\n';

}
