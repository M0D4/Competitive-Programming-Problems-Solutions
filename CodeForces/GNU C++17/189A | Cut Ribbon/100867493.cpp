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
  int n, a, b, c;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     cin >> n >> a >> b >> c;
    int mx = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i * a + j * b > n) continue;
            int zc = n - (i * a + j * b);
            if(zc % c == 0)
                mx = max(mx, i + j + zc / c);
        }
    }
    cout << mx;
    return 0;
}