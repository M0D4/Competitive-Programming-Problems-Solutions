#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
const int N = 3e5 + 5;
vector<bool> sieve(N);
const int mod = 998244353;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    for (ll i = 2; i < N; ++i) {
        if (sieve[i] == 0) {
            for (ll j = i * i; j < N; j += i)
                sieve[j] = 1;
        }
    }
 
    ll n, m;
    cin >> n >> m;
 
    ll all = m % mod, p = m % mod;
    ll factors = 1;
    for (int i = 2; i <= n; ++i) {
        all += p * (m % mod) % mod;
        all %= mod;
        p *= m % mod;
        p %= mod;
    }
 
    ll non_valid = m % mod;
    p = m % mod;
    for (int i = 2; i <= n; ++i) {
        if (sieve[i] == 0)
            factors *= i;
 
        if (factors > m)
            break;
 
        p *= ((m / factors) % mod);
        p %= mod;
        non_valid += p;
        non_valid %= mod;
    }
 
    cout << (all - non_valid + mod) % mod;
    return 0;
}