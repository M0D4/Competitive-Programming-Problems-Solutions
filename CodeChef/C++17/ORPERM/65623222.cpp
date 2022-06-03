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
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        ll o1 = 0, o2 = 0, a1 = (1LL << 30) - 1, a2 = (1LL << 30) - 1;
        ll x1 = 0, x2 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            o1 |= a[i];
            a1 &= a[i];
            x1 ^= a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            o2 |= b[i];
            a2 &= b[i];
            x2 ^= b[i];
        }
        sort(all(b));
        auto check = [&](ll mid){
            vector<ll> c;
            for (int i = 0; i < n; ++i) {
                ll x = a[i] | mid;
                c.push_back(x);
            }
            sort(all(c));
            if(c == b) return cout << mid << endl, true;
            return false;
        };

        vector<ll> c = {a1, a2, o1, o2, x1, x2};
        bool ok = 0;
        for (int i = 0; i < c.size() && !ok; ++i) {
            if(check(c[i])) ok = 1;
            for (int j = i + 1; j < c.size() && !ok; ++j) {
                ok = check(c[i] ^ c[j]) || check(c[i] & c[j]) || check(c[i] | c[j]);
            }
        }
        if(!ok) cout << "-1\n";
    }
    return 0;
}