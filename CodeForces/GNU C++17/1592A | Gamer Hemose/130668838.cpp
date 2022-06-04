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
  int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        ll n, h; cin >> n >> h;
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        ll x = a[n - 1], y = a[n - 2];
        ll l = 1, r = 1e9;
        while (l <= r){
            ll mid = (l + r) >> 1;
            ll big = (mid + 1) / 2, small = mid - big;
            if(x * big + y * small >= h) r = mid - 1;
            else l = mid + 1;
        }
        cout << r + 1 << endl;
    }
    return 0;
}
 