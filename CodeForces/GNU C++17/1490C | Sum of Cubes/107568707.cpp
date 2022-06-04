#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 const int N = 1e4 + 2;
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        bool ok = 0;
        for (ll i = 1; i <= N; ++i) {
            ll rem = n - i * i * i;
            if(rem <= 0) continue;
            ll c = cbrt(rem);
            if(c * c * c + i * i * i == n){
                ok = 1;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}