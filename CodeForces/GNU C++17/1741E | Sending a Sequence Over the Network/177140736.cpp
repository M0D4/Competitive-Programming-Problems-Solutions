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
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        bool dp[n + 1] = {};
        int a[n + 1];
        for (int i = 0; i < n; ++i) {
            cin >> a[i + 1];
        }
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] + i <= n) dp[a[i] + i] |= dp[i - 1];
            if (i - a[i] - 1 >= 0) dp[i] |= dp[i - a[i] - 1];
        }
        cout << (dp[n] ? "YES" : "NO") << endl;
    }
    return 0;
}