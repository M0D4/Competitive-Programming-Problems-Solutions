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
        ll a2;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if(i) a2 &= b[i];
            else a2 = b[i];
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


        if(check(a2));
        else cout << "-1\n";
    }
    return 0;
}