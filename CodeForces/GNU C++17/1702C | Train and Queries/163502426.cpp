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
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n, q; cin >> n >> q;
        map<int, pair<int, int>> mp;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if(mp.count(x)) mp[x].first = min(mp[x].first, i);
            else mp[x].first = i;
            mp[x].second = max(mp[x].second, i);
        }
        while(q--){
            int u, v; cin >> u >> v;
            if (!mp.count(u) || !mp.count(v)) {
                cout << "NO\n";
                continue;
            }
            int mn = mp[u].first, mx = mp[v].second;
            cout << (mn <= mx ? "YES" : "NO") << endl;
        }
    }
    return 0;
}