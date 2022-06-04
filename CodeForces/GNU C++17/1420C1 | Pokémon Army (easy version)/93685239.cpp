#include "bits/stdc++.h"
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const ll N = 3e5 + 5, M = -1e17;
int a[N], n, q;
ll dp[N][2];
ll go(int i, int ch){
    if(i == n) return 0;
     ll &ret = dp[i][ch];
    if(~ret) return ret;
     int add = (!ch ? 1 : -1);
     ret = go(i + 1, ch);
    ret = max(ret, add * a[i] + go(i + 1, !ch));
     return ret;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t; cin >> t;
    while(t--){
        cin >> n >> q;
        for(int i = 0; i < n; i++) cin >> a[i];
        memset(dp, -1, n * 2 * sizeof(dp[0][0]));
        cout << go(0, 0) << endl;
    }
    return 0;
}