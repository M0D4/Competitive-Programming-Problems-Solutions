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
     int tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        ll cnt = 0;
        set<ll> s;
        for (ll i = 1; i * i <= n; ++i) {
            s.insert(i * i);
            if(i * i * i <= n) s.insert(i * i * i);
        }
        cout << s.size() << endl;
    }
    return 0;
}