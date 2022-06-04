#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
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
        int n; cin >> n;
        string s; cin >> s;
        int l = -2, r = -2;
        for (int i = 0; i < n && l == -2; ++i) {
            int a = s[i] == 'a', b = !a;
            for (int j = i + 1; j < n; ++j) {
                if(s[j] == 'a') a++;
                else b++;
                if(a == b){
                    l = i, r = j;
                    break;
                }
            }
        }
        cout << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}
 