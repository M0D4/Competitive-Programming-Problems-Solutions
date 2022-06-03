#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        ll b, c; cin >> b >> c;
        b %= c;
        cout << lcm(b, c) / b << endl;
    }
    return 0;
}