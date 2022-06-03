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

    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        ll a[n], b[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<ll, ll> f;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            f[a[i] ^ b[i]]++;
        }
        ll cnt = 0;
        for(auto& p: f){
            ll c = p.second;
            cnt += c * (c - 1) / 2;
        }
        cout << cnt << endl;
    }
    return 0;
}