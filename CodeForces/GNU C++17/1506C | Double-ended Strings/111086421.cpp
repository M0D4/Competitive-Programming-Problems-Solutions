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
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
    int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
     int tc; cin >> tc;
    while (tc--){
        string s, t; cin >> s >> t;
        int n = s.size(), m = t.size();
        int dp[n + 1][m + 1], mx = 0;
        clr(dp, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = 0;
                mx = max(mx, dp[i][j]);
            }
        }
        cout << n + m - 2 * mx << endl;
    }
    return 0;
}