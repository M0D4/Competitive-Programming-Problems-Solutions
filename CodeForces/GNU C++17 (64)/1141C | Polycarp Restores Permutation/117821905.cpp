#include "bits/stdc++.h"
  #pragma GCC optimize("-Ofast")
#pragma GCC optimize("-O2")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, val)    memset(x, val, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
  using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int n; cin >> n;
    vector<int> q(n - 1);
    ll mn = 0, sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> q[i];
        sum += q[i];
        mn = min(mn, sum);
    }
    vector<int> p(n);
    p[0] = 1 - mn;
    for (int i = 0; i < n - 1; ++i) {
        p[i + 1] = p[i] + q[i];
    }
    bool ok = (set<int> (all(p)).size() == n);
    for (int i = 0; i < n; ++i) {
        ok &= (p[i] >= 1 && p[i] <= n);
    }
    if(ok == 0) cout << -1;
    else{
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
    }
    return 0;
}