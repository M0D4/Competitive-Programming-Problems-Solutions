#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
const int N = 5e3 + 5;
 
ll dp[N][N], a[N], b[N], n;
 
ll go(int i, int j){
    if(i > j) return 0;
 
    ll& ret = dp[i][j];
    if(~ret) return ret;
 
    if(i == j) return a[i] * b[i];
 
    ret = go(i + 1, j - 1) + a[i] * b[j] + a[j] * b[i];
 
    return ret;
}
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
 
    ll pre[n + 1] = {};
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + a[i] * b[i];
    }
 
    ll ans = pre[n];
 
    clr(dp, -1);
 
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans = max(ans, go(i, j) + pre[i] + (pre[n] - pre[j + 1]));
        }
    }
    cout << ans;
    return 0;
}