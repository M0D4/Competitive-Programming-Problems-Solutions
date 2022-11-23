#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
ll calc(ll x, ll a){
    return x / a + x % a;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while(tc--){
        ll l, r, a; cin >> l >> r >> a;
        ll x;
        if (l == r) x = l;
        else{
            ll tmp = r / a;
            x = max(tmp * a - 1, l);
        }
        cout << max({calc(x, a), calc(r, a), calc(l, a)}) << endl;
    }
    return 0;
}