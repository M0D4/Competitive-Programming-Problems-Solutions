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
typedef double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t; cin >> t;
    while(t--){
        ll w, h, n; cin >> w >> h >> n;
        ll sheets = 1 , add = 1;
        while(!isOdd(w)) sheets += add, add <<= 1, w /= 2;
        while(!isOdd(h)) sheets += add, add <<= 1, h /= 2;
        cout << (sheets >= n ? "YES" : "NO") << endl;
    }
    return 0;
}