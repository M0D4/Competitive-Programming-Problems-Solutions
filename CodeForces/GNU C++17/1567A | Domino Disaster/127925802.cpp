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
  int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < n; ++i) {
            if(s[i] == 'L' || s[i] == 'R') cout << s[i];
            else cout << (s[i] == 'U' ? 'D' : 'U');
        }
        cout << endl;
    }
    return 0;
}