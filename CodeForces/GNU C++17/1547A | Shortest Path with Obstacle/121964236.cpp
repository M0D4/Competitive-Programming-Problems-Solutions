#include "bits/stdc++.h"
  #pragma GCC optimize("-Ofast")
#pragma GCC optimize("-O2")
  using namespace std;
 #define endl            "\n"
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(x.begin(), x.end()), x.end())
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
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
      int xa, ya, xb, yb, xf, yf;
      cin >> ya >> xa >> yb >> xb >> yf >> xf;
      ll path = abs(xa - xb) + abs(ya - yb);
      path += ((xa == xb && xa == xf && yf > min(ya, yb) && yf < max(ya, yb))
              || (ya == yb && ya == yf && xf > min(xa, xb) && xf < max(xa, xb))) * 2;
      cout << path << endl;
    }
    return 0;
}