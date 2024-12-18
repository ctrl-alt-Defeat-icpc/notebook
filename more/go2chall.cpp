#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 305;
const ll M = 1e9 + 7;
int n, h[N], temp_values[N];
int dp[N][N];

void Main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
        temp_values[i] = h[i];
        dp[i][i] = 1;
    }

// compressing
sort(temp_values, temp_values + n);
int numOfUnique = unique(temp_values, temp_values + n) - temp_values;
for(int i = 0; i < n; i++)
    h[i] = lower_bound(temp_values, temp_values + numOfUnique, h[i]) - temp_values;
    
    for(int i = 1; i < n; i++)
        dp[i - 1][i] = 1 + (h[i - 1] == h[i]);
    
    for(int d = 2; d < n; d++) {
        for(int i = 0; i + d < n; i++) {
            int j = i + d;
            if(h[i] != h[j]) dp[i][j] = dp[i][j - 1];
            else {
                dp[i][j] = dp[i][j - 1] + 1;
                for(int k = i + 1; k < j; k++)
                    if(h[k] >= h[i])
                        dp[i][j] = (dp[i][j] + dp[k][j - 1]) % M;
            }
        }
        
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = (ans + dp[i][n - 1]) % M;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}