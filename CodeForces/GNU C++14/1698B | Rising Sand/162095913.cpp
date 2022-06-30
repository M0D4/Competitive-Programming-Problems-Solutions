#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
const int N = 2e5 + 5;
int a[N], n, k, dp[N][2];
 
int go(int i, bool b){
    if(i >= n - 1){
        return 0;
    }
    int& ret = dp[i][b];
    if(~ret) return ret;
 
    ll sum = a[i - 1] + a[i + 1];
    ret = go(i + 2, 0) + (a[i] > sum);
    ret = max(ret, go(i + 2, 1) + 1);
 
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = -1;
            }
        }
        int cnt = 0;
        for (int i = 1; i < n - 1; ++i) {
            ll sum = a[i - 1] + a[i + 1];
            cnt += (a[i] > sum);
        }
        if(k == 1){
            cnt = max(cnt, go(1, 0));
        }
        cout << cnt << endl;
    }
    return 0;
}