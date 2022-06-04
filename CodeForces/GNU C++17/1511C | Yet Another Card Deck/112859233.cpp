#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;
  void solve(){
   int n, q; cin >> n >> q;
   int a[n], first[51];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = n - 1; ~i; --i){
        first[a[i]] = i + 1;
    }
    while (q--){
        int x; cin >> x;
        cout << first[x] << " ";
        for (int i = 1; i < 51; ++i) {
            if(first[i] < first[x]) first[i]++;
        }
        first[x] = 1;
    }
}
 int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
      solve();
    return 0;
}