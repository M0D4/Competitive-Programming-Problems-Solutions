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
 
bool isAP(ll a, ll b, ll c){
    return (a - b == b - c) || (c - b == b - a);
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while(tc--){
        ll a, b, c; cin >> a >> b >> c;
        bool ok = isAP(a, b, c);
 
        ok |= (2 * b - a > 0) && ((2 * b - a) % c == 0) && (isAP(a, b, 2 * b - a));
 
        ll x = c - (c - a) / 2;
        ok |= (x > 0) && ((c - a) & 1 ^ 1) && (x % b == 0) && isAP(a, x, c);
        x = a - (a - c) / 2;
        ok |= (x > 0) && ((a - c) & 1 ^ 1) && (x % b == 0) && isAP(a, x, c);
 
        ok |= (2 * b - c > 0) && ((2 * b - c) % a == 0) && isAP(2 * b - c, b, c);
 
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}