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

const int N  = 3e5 + 5, MOD = 998244353;

class FenwickTree {
private:
    vector<ll> ft;
public:
    ll LSOne(ll x){ // least significant bit (1)
        return (x & (-x));
    }
    FenwickTree(int n) {
        ft.assign(n + 2, 0);
    }
    int rsq(int b) {
        ll sum = 0;//overflow?
        for( ; b; b -= LSOne(b)) (sum += ft[b]) %= MOD;
        return sum;
    }
    void update(int k, ll v) {
        for (; k < (int)ft.size(); k += LSOne(k)) (ft[k] += v) %= MOD;
    }
};

ll modPow(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]];
    }
    int idx = 1;
    for(auto& it: mp) it.second = idx++;

    for (int i = 0; i < n; ++i) {
        a[i] = mp[a[i]];
    }

    FenwickTree ft(n + 3);
    ll ans = 0;
    ll modInv = modPow(2, MOD - 2, MOD);
    ll modInvPower = 1;
    for (int i = 0; i < n; ++i) {
        ll cnt = ft.rsq(a[i]);
        ans += ((i ? modPow(2, i - 1, MOD) : 1) * cnt) % MOD;
        ans %= MOD;
        ft.update(a[i], modInvPower);
        (modInvPower *= modInv) %= MOD;
    }

    cout << ans;
    return 0;
}

