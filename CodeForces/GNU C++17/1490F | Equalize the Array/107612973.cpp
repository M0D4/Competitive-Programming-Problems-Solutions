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
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n], id = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            if(mp.count(a[i])) continue;
            mp[a[i]] = id++;
        }
        int f[n + 5] = {};
        for(auto& i: a)
            i = mp[i], f[i]++;
         sort(f + 1, f + n + 1);
        ll pre[n + 2] = {};
        for(int i = 1; i <= n; i++)
            pre[i] += pre[i - 1] + f[i];
         ll mn = 1e15;
        for(int i = 1; i <= n; i++){
            int r = upper_bound(f + 1, f + n + 1, i) - f;
            int l = lower_bound(f + 1, f + n + 1, i) - f - 1;
            mn = min(mn, (pre[n] - pre[r - 1]) - (1LL * i * (n - r + 1)) + pre[l]);
        }
        cout << mn << endl;
    }
    return 0;
}