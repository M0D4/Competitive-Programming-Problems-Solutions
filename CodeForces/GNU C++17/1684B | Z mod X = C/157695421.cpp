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
    while(TC--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll x, y, z;
        z = c;
        y = z + b;
        x = y + a;
        assert(x % y == a);
        assert(y % z == b);
        assert(z % x == c);
        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}