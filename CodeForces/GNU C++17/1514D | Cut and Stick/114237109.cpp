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
 const int N = 3e5 + 5;
int a[N];
vector<int> pos[N];
 int cnt(int l, int r, int x){
    return upper_bound(all(pos[x]), r) - lower_bound(all(pos[x]), l);
}
 int main()
{
     ios_base::sync_with_stdio(false), cin.tie(nullptr);
     int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (q--){
        int l, r; cin >> l >> r;
        --l, --r;
        int len = r - l + 1, mx = 0;
        for (int i = 0; i < 30; ++i) {
            int x = uniform_int_distribution<int>(l,  r)(rng);
            mx = max(mx, cnt(l, r, a[x]));
        }
        cout << max(1, 2 * mx - len) << endl;
    }
    return 0;
}