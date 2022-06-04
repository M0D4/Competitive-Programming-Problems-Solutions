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
   void solveOne(){
    ll n, m; cin >> m >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, greater<>());
    int cnt = 0;
    ll cat = 0;
    for (int i = 0; i < n; ++i) {
        if(cat >= a[i]) break;
        int want = m - a[i];
        cat += want;
        cnt++;
    }
    cout << cnt << endl;
}
  int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
    int tc; cin >> tc;
    while (tc--){
        solveOne();
    }
    return 0;
}
 