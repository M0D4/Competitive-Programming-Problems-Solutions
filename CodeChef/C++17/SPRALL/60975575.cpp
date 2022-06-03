#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int tc; cin >> tc;
    while (tc--){
        int n, q; cin >> n >> q;
        vector<ll> deg(n, 0);
    
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            --u, --v;
            deg[u]++, deg[v]++;
        }
        
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            ans += deg[i] * (deg[i] + 1) / 2;
            if(i) ans--;
        }
        cout << ans << endl;
        for (int i = 0; i < q; ++i) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            --a, --b, --c, --d;
            ll newAns = ans - deg[a] - deg[b];
            --deg[a], --deg[b];
            cout << newAns + deg[c] + 1 + deg[d] + 1 << endl;
            ++deg[a], ++deg[b];
        }
    }
    return 0;
}