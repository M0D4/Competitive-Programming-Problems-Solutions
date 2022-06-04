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
 const int N = 4002;
 int n, a, b, c;
 int dp[N];
 int go(int rem){
     int &ret = dp[rem];
    if(~ret) return ret;
     if(rem >= a) ret = 1 + go(rem - a);
    if(rem >= b) ret = max(ret, 1 + go(rem - b));
    if(rem >= c) ret = max(ret, 1 + go(rem - c));
     if(ret < 0) return ret = (rem != 0) * -1e7;
     return ret;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     cin >> n >> a >> b >> c;
     clr(dp, -1);
     cout << go(n);
    return 0;
}