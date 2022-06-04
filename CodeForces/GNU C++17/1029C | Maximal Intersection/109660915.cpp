#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
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
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
//    sort(all(a));
    vector<pii> suff(n), pre(n);
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; ~i; --i) {
        int x = max(a[i].first, suff[i + 1].first);
        int y = min(a[i].second, suff[i + 1].second);
        suff[i] = {x, y};
    }
    pre[0] = a[0];
    for (int i = 1; i < n; ++i) {
        int x = max(a[i].first, pre[i - 1].first);
        int y = min(a[i].second, pre[i - 1].second);
        pre[i] = {x, y};
    }
    int mx = 0;
    for (int i = 1; i + 1 < n; ++i) {
        int x = max(pre[i - 1].first, suff[i + 1].first);
        int y = min(pre[i - 1].second, suff[i + 1].second);
        if(x <= y)
            mx = max(mx, y - x);
    }
    if(suff[1].first <= suff[1].second)
        mx = max(mx, suff[1].second - suff[1].first);
     if(pre[n - 2].first <= pre[n - 2].second)
        mx = max(mx, pre[n - 2].second - pre[n - 2].first);
     cout << mx;
    return 0;
}