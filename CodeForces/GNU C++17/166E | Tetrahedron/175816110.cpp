#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
const int mod = 1e9 + 7, N = 1e7 + 2;
int dp[4][N];
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n;
    cin >> n;
 
    for (int i = 0; i < 4; ++i) {
        dp[i][0] = 0;
    }
 
    dp[0][1] = dp[1][1] = dp[2][1] = 1;
 
    for (int i = 2; i <= n; ++i) {
        dp[0][i] = (0LL + dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1]) % mod;
        dp[1][i] = (0LL + dp[0][i - 1] + dp[2][i - 1] + dp[3][i - 1]) % mod;
        dp[2][i] = (0LL + dp[0][i - 1] + dp[1][i - 1] + dp[3][i - 1]) % mod;
        dp[3][i] = (0LL + dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % mod;
    }
 
    cout << dp[3][n];
    return 0;
}