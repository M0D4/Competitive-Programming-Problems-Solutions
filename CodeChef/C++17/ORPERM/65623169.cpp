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
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        int fa[31] = {};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int bit = 0; bit < 30; ++bit) {
                fa[bit] += ((a[i] >> bit) & 1);
            }
        }
        int bAnd, fb[30] = {};
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            for (int bit = 0; bit < 30; ++bit) {
                fb[bit] += ((b[i] >> bit) & 1);
            }
            if(i) bAnd &= b[i];
            else bAnd = b[i];
        }

        sort(all(b));
        auto check = [&](ll x){
            vector<ll> c;
            for (int i = 0; i < n; ++i) {
                ll bi = a[i] | x;
                c.push_back(bi);
            }
            sort(all(c));
            if(c == b) return true;
            return false;
        };

        ll x = 0;
        for (int bit = 0; bit < 30; ++bit) {
            int bitCountB = fb[bit], bitCountA = fa[bit];
            if(bitCountA == bitCountB) continue;
            if(bitCountB > bitCountA && bitCountB == n)
                x |= (1 << bit);
            else
                break;
        }
        cout << (check(x) ? x : -1) << endl;
    }
    return 0;
}