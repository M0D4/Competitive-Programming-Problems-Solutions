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
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << "0 ";
        for (int i = 0; i + 1 < n; ++i) {
            int x = 0;
            for (int j = 31; ~j; --j) {
                if(((a[i] >> j) & 1) && !((a[i + 1] >> j) & 1)){
                    x |= (1 << j);
                }
            }
            cout << x << " ";
            a[i + 1] ^= x;
        }
        cout << endl;
    }
    return 0;
}