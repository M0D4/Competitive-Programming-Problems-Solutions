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
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
  const int MOD = 1e9 + 7;
  ll power(ll x, int y, int p)
{
    ll res = 1; // Initialize result
     x = x % p; // Update x if it is more than or
    // equal to p
     while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
         // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 // Returns n^(-1) mod p
ll modInverse(ll n, int p)
{
    return power(n, p - 2, p);
}
 const int N = 2e5 + 5;
 ll fac[N + 2];
 ll nCrModP(ll n, int r, int p)
{
    if (r == 0)
        return 1;
     return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
 void init(){
 fac[0] = 1;
 for (int i = 1; i < N; i++)
         fac[i] = (fac[i - 1] * i) % MOD;
}
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
      init();
     int tt; cin >> tt;
    while(tt--){
        int n, m, k; cin >> n >> m >> k;
        int a[n];
        for(auto &i: a) cin >> i;
        sort(a, a + n);
        ll c = 0;
        for(int i = 0; i < n; i++){
            ll idx =  lower_bound(a, a + n, a[i] - k) - a;
            ll len = i - idx;
            if(len >= m - 1) c += nCrModP(len, m - 1, MOD);
            if(c >= MOD) c -= MOD;
        }
        cout << c << endl;
    }
    return 0;
}