#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
 int n;
string x;
map<pair<int, string>, ll> dp;
 ll go(int d, string s){
    if(s.size() > n) return 1e9;
    if(s.size() == n) return 0;
     if(dp.count({d, s}))
        return dp[{d, s}];
      ll& ret = dp[{d, s}];
    ret = 1e15;
     int f[10] = {};
    for (int i = 0; i < s.size(); ++i) {
        f[s[i] - '0']++;
    }
    ll num = stoll(s);
    for (int i = 1; i < 10; ++i) {
        if(f[i]){
            ret = min(ret, 1 + go(i, to_string(num * i)));
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