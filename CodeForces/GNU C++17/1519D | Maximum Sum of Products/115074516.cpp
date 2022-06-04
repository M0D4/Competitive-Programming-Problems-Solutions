#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int n; cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ll pre[n + 1] = {};
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + a[i] * b[i];
    }
    ll ans = pre[n];
    for (int center = 0; center < n; ++center) {
        ll cur = a[center] * b[center];
        for (int l = center - 1, r = center + 1; ~l && r < n; --l, ++r) {
            cur += a[l] * b[r];
            cur += a[r] * b[l];
            ans = max(ans, cur + pre[l] + (pre[n] - pre[r + 1]));
        }
        evenLength:{
            cur = 0;
            for (int l = center, r = center + 1; ~l && r < n; --l, ++r) {
                cur += a[l] * b[r];
                cur += a[r] * b[l];
                ans = max(ans, cur + pre[l] + (pre[n] - pre[r + 1]));
            }
        };
    }
    cout << ans;
    return 0;
}