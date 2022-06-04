#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const int N = 205;
 int n, dp[N][501], a[N];
 int go(int i, int st){
    if(i == n) return 0;
    if(st > 500) return 1e9;
     int &ret = dp[i][st];
    if(~ret) return ret;
     ret = 1e9;
    for(int j = st; j <= 500; j++){
        ret = min(ret, abs(a[i] - j) + go(i + 1, j + 1));
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int q; cin >> q;
    while(q--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
         sort(a, a + n);
         memset(dp, -1, n * 501 * sizeof dp[0][0]);
         cout << go(0, 1) << endl;
    }
    return 0;
}