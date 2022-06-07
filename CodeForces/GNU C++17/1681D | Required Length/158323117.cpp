#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
#define numOfDigits(x)  log(x) / log(10) + 1
 
using ll = long long;
 
int n;
ll x;
map<pair<int, ll>, ll> dp;
 
ll go(int d, ll s){
    int digits = numOfDigits(s);
    if(digits > n) return 1e9;
    if(digits == n) return 0;
 
    if(dp.count({d, s}))
        return dp[{d, s}];
 
 
    ll& ret = dp[{d, s}];
    ret = 1e15;
 
    int f[10] = {};
    ll tmp = s;
    while (tmp){
        f[tmp % 10]++;
        tmp /= 10;
    }
 
    for (int i = 1; i < 10; ++i) {
        if(f[i]){
            ret = min(ret, 1 + go(i, s * i));
        }
    }
 
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> n >> x;
 
    ll ans = go(0, x);
 
    if(ans >= 1e15)
        ans = -1;
 
    cout << ans;
    return 0;
}