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
     ll blX, blY, trX, trY; cin >> blX >> blY >> trX >> trY;
    ll BlX, BlY, TrX, TrY; cin >> BlX >> BlY >> TrX >> TrY;
    ll BlX2, BlY2, TrX2, TrY2; cin >> BlX2 >> BlY2 >> TrX2 >> TrY2;
     ll area = (trY - blY) * (trX - blX);
     ll x1 = min(trX, TrX), y1 = min(TrY, trY);
    ll x2 = max(blX, BlX), y2 = max(BlY, blY);
     area -= max(0LL, x1 - x2) * max(0LL, y1 - y2);
     ll x3 = min(trX, TrX2), y3 = min(TrY2, trY);
    ll x4 = max(blX, BlX2), y4 = max(BlY2, blY);
     area -= max(0LL, x3 - x4) * max(0LL, y3 - y4);
     x3 = min({trX, TrX, TrX2}), y3 = min({trY, TrY, TrY2});
    x4 = max({blX, BlX, BlX2}), y4 = max({blY, BlY, BlY2});
     area += max(0LL, x3 - x4) * max(0LL, y3 - y4);
     cout << (area <= 0 ? "NO" : "YES");
     return 0;
}