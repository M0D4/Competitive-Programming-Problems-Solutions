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
   int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n; cin >> n;
    int a[n], mx = 0, g = 0;
    ll men = 0;
    for(auto &i: a) cin >> i, mx = max(mx, i);
    for(auto &i: a){
        g = __gcd(g, mx - i);
    }
    for(auto &i: a) men += (mx - i) / g;
    cout << men << " " << g;
    return 0;
}