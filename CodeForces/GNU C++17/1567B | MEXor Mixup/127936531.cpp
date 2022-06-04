#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 using ll = long long;
using pii = pair<int, int>;
using tii = tuple<ll, int, int>;
 ///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 ll calc(ll l, ll r){
    if(l & 1){
        if(r & 1){
            ll one = (r - l) >> 1;
            one &= 1;
            return one ^ l;
        }
        ll one = (r - l - 1) >> 1;
        one &= 1;
        return one ^ l ^ r;
    }else{
        if(r & 1){
            ll one = (r - l + 1) >> 1;
            return one & 1;
        }
        ll one = (r - l) >> 1;
        one &= 1;
        return one ^ r;
    }
}
 int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while (t--){
        ll a, b; cin >> a >> b;
        ll needForMex = a;
        ll x = calc(0, a - 1);
        if(x == b) cout << needForMex << endl;
        else{
            cout << needForMex + 1 + ((x ^ b) == a) << endl;
        }
    }
    return 0;
}