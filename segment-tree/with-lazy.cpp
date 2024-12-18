#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int seg[2 * N], lazy[2 * N], a[N];
int segSize;

void build(int u = 1, int ul = 0, int ur = n) {
    if(ur - ul < 2){
        seg[u] = a[ul];
        return;
    }
    int mid = (ul + ur) / 2;
    build(u * 2, ul, mid);
    build(u * 2 + 1, mid, ur);
    seg[u] = seg[u * 2] + seg[u * 2 + 1];
}

void upd(int u, int ul, int ur, int x){
    lazy[u] += x;
    seg[u] += (ur - ul) * x;
}
void shift(int u, int ul, int ur){
    int mid = (ul + ur) / 2;
    upd(u * 2, ul, mid, lazy[u]);
    upd(u * 2 + 1, mid, ur, lazy[u]);
    lazy[u] = 0;
}
void increase(int l, int r, int x, int u = 1, int ul = 0, int ur = n){
    if(l >= ur || ul >= r)return;
    if(l <= ul && ur <= r){
        upd(u, ul, ur, x);
        return;
    }
    shift(u, ul, ur);
    int mid = (ul + ur) / 2;
    increase(l, r, x, u * 2, ul, mid);
    increase(l, r, x, u * 2 + 1, mid, ur);
    seg[u] = seg[u * 2] + seg[u * 2 + 1];
}
int sum(int l, int r, int u = 1, int ul = 0, int ur = n){
    if(l >= ur || ul >= r)return 0;
    if(l <= ul && ur <= r)return seg[u];
    shift(u, ul, ur);
    int mid = (ul + ur) / 2;
    return sum(l, r, u * 2, ul, mid) + sum(l, r, u * 2 + 1, mid, ur);
}

void showSegments() {
    for(int i = 0; i < segSize; i++)
        cout << seg[i] << ' ';
    cout << endl;
}

void Main() {
    cin >> n;
    segSize = 2;
    while(segSize / 2 <= n) segSize *= 2;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build();

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}