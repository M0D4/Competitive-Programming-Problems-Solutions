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
 
const int N = 1e5 + 5;
 
ll dp[N][31], a[N], n, k;
 
ll go(int i, int bad){
    bad = min(bad, 30);
    if (i == n) return 0;
 
    ll& ret = dp[i][bad];
    if (~ret) return ret;
 
    int mn = min(bad + 1, 30);
 
    ///with good
    ret = a[i] / (1 << bad) - k + go(i + 1, bad);
    ///with bad
    ret = max(ret, a[i] / (1 << mn) + go(i + 1, bad + 1));
 
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < 31; ++j) {
                dp[i][j] = -1;
            }
        }
        cout << go(0, 0) << endl;
    }
    return 0;
}