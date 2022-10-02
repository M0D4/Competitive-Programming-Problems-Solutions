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
 
map<int, ll> mp;
ll mn, l, r;
 
ll go(int ai){
    if (2 * mn > ai) return 0;
    if (mp.count(ai)) return mp[ai];
    ll& ret = mp[ai];
 
    ll x = ai - mn;
    if (x <= r)
        return ret = 1 + go(x);
 
    return ret = 1 + (ai - 2 * mn) / r;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        mn = a[0];
        l = mn, r = 2 * mn - 1;
        mp.clear();
 
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += go(a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}