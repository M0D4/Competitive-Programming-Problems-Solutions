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
  int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while (t--){
        int a, b, c; cin >> a >> b >> c;
        ll g = 1, x = 1, y = 1;
        while (numOfDigits(g) < c){
            g <<= 1;
            x <<= 1;
            y <<= 1;
        }
        while (numOfDigits(x) < a){
            x *= 3;
        }
        while (numOfDigits(y) < b){
            y *= 5;
        }
        cout << x << " " << y  << endl;
    }
    return 0;
}