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
        auto getMax = [](ll x, ll g){
            ll mx = 0;
            for(ll i = 1; i * i <= x; ++i){
                if(x % i == 0){
                    if (i % g == 0)
                        mx = max(i, mx);
                    if (i != 1 && (x / i) % g == 0)
                        mx = max(x / i, mx);
                }
            }

            return mx;
        };
        while (q--){
            int u, v; cin >> u >> v;
            int g = __gcd(u, v);

            ll ans = 0;
            while (u != g) {
                ll newU = getMax(u, g);
                cout << flush;
                ans += u / newU;
                u = newU;
            }
            while (v != g) {
                ll newV = getMax(v, g);
                ans += v / newV;
                v = newV;
            }
            cout << ans << endl;
        }
    }
    return 0;
}