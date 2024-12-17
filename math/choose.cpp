#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e3 + 5;
const ll M = 1e9 + 7;
ll fact[N], inv[N];
int r, n, q;

ll exp(ll b, ll p, ll m) {
    b %= m;
    ll result = 1;
    while(p) {
        if(p % 2)
            result = result * b % m;
        b = b * b % m;
        p /= 2;
    }
    return result;
}

void preProcess() {
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % M;
    inv[N - 1] = exp(fact[N - 1], M - 2, M);
    for(int i = N - 1; i > 0; i--)
        inv[i - 1] = inv[i] * i % M;    
}

ll choose(int n, int r) {
    if(r > n) return 0;
    return fact[n] * inv[r] % M * inv[n - r] % M; 
}

void Main() {
    cin >> q;
    while(q--) {
        cin >> n >> r;
        cout << choose(n, r) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    preProcess();
    Main();
    return 0;
}