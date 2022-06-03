#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

ll phi(ll n){
    ll pK, coPrime = 1;
    for(ll i = 2, d = 1; i * i <= n; i += d, d = 2){
        if(!(n % i)){
            pK = 1;
            while(!(n % i))
                pK *= i, n /= i;
            coPrime *= (pK / i)*(i - 1);
        }
    }

    if(n != 1) coPrime *= (n - 1);

    return coPrime;
}


ll power(ll x, ll y, int MOD)
{
    ll res = 1;

    x = x % MOD;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

const int mod = 998244353;

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    ll n, k, m; cin >> n >> k >> m;

    if (m % mod == 0) return cout << 0, 0;

    cout << power(m, power(k, n, mod - 1), mod);
    return 0;
}