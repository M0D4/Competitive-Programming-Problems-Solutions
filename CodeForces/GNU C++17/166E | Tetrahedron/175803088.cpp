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
 
const int mod = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n;
    cin >> n;
 
    ll a, b, c, d = 0;
    a = b = c = 1;
 
 
    for (int i = 2; i <= n; ++i) {
        ll newA = (b + c + d) % mod;
        ll newB = (a + c + d) % mod;
        ll newC = (a + b + d) % mod;
        ll newD = (a + b + c) % mod;
 
        a = newA;
        b = newB;
        c = newC;
        d = newD;
    }
 
    cout << d;
    return 0;
}