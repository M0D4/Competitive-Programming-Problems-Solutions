#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 ///Intermediate Overflow!!! (1 << i), x * y, 2 * x
  int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        string s; cin >> s;
        int a = count(all(s), 'A'), b = count(all(s), 'B'), c = count(all(s), 'C');
        int n = s.size();
        int mn = min(a, b);
        n -= 2 * mn, a -= mn, b -= mn;
        mn = min(b, c);
        n -= 2 * mn;
        cout << (n > 0 ? "NO" : "YES") << endl;
    }
    return 0;
}
 