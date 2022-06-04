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
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;
 void solve(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0, j = n - 1; i < j && k; ++i) {
        while (a[i] > 0 && k) --a[i], ++a[j], --k;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
 int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        solve();
    }
    return 0;
}