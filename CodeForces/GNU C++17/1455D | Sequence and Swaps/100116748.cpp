#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
  using namespace std;
 #define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
 const int N = 505;
 int a[N], n, dp[N][N][N], x;
 int go(int i, int last, int cur_x){
    if(i == n) return 0;
     int &ret = dp[i][last][cur_x];
    if(~ret) return ret;
     ret = 1e9;
    if(a[i] > cur_x && cur_x >= last)
        ret = min(ret, 1 + go(i + 1, cur_x, a[i]));
    if(a[i] >= last)
        ret = min(ret, go(i + 1, a[i], cur_x));
     return ret;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
      int t; cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++)
           for(int j = 0; j <= 500; j++)
              for(int k = 0; k <= 500; k++)
                 dp[i][j][k] = -1;
        int ans = go(0, 0, x);
        if(ans >= 1e9) ans = -1;
        cout << ans << endl;
    }
    return 0;
}