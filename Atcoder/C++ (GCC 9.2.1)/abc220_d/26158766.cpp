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

const ll MOD = 998244353;


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


const int N = 1e5 + 5;
ll a[N], dp[N][10][10], n;

ll go(int i, int last, int k){
    if(i >= n){
        return last == k;
    }
    ll& ret = dp[i][last][k];
    if(~ret) return ret;

    ret = go(i + 1, (last + a[i]) % 10, k) % MOD;
    ret += go(i + 1, (last * a[i]) % 10, k) % MOD;
    ret %= MOD;

    return ret;
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    clr(dp, -1);

    for (int i = 0; i < 10; ++i) {
        cout << (go(2, (a[0] + a[1]) % 10, i)
                + go(2, (a[0] * a[1]) % 10, i)) % MOD << endl;
    }
    return 0;
}

