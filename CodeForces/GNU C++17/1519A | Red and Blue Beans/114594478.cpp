#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while(t--){
        ll r, b, d; cin >> r >> b >> d;
        if(r > b) swap(r, b);
        ll cnt = b / (d + 1) + !!(b % (d + 1));
        cout << (cnt <= r ? "YES" : "NO") << endl;
    }
    return 0;
}