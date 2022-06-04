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
    int cnt = 0;
    int a[n];
    iota(a, a + n, 1);
    for (int i = 1; i + 1 < n && cnt < k; ++i) {
        swap(a[i], a[i + 1]);
        i++;
        cnt++;
    }
    if(cnt != k){
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
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