#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
#define Unique(x)       x.erase(unique(all(x)), x.end())

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TC; cin >> TC;
    while(TC--){
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(all(a));
        Unique(a);
        ll mx = 2 * a.back();
        if (a.size() > 1){
            ll x = a.back(), y = a[a.size() - 2];
            mx = max({mx, x + y + (x - y) % m, x + y + ((y - x) % m + m) % m});
        }
        cout << mx << endl;
    }
    return 0;
}