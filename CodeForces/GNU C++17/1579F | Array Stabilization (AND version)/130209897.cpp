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
 const int N = 1e6 + 5;
 int dp[N], a[N], d, n;
 int dfs(int i){
    if(a[i] == 0) return 0;
     int& ret = dp[i];
    if(ret == 0) return 1e7; //cycle
    if(ret > 0) return ret;
     ret = 0;
    ret = 1 + dfs((i + n - d) % n);
    return ret;
}
 int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        cin >> n >> d;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            dp[i] = -1;
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if(a[i] == 1) mx = max(mx, dfs(i));
        }
        if(mx >= 1e7) mx = -1;
        cout << mx << endl;
    }
    return 0;
}
 