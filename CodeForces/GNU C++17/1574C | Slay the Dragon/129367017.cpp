#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
 
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n; cin >> n;
    vector<ll> a(n);
    ll heroes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        heroes += a[i];
    }
    sort(all(a));
    int m; cin >> m;
    while (m--){
        ll x, y; cin >> x >> y;
        auto it = lower_bound(all(a), x);
 
        if(it == a.end()) --it;
 
        ll mn = max(0LL, x - *it) + max(0LL, y - (heroes - *it));
 
        ++it;
        if(it != a.end()){
            mn = min(mn, max(0LL, x - *it) + max(0LL, y - (heroes - *it)));
        }
        --it;
 
        if(it != a.begin()) --it;
 
        mn = min(mn, max(0LL, x - *it) + max(0LL, y - (heroes - *it)));
 
        cout << mn << endl;
    }
    return 0;
}
 