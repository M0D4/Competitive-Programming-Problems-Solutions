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
     int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        int f[26] = {}, ok = 1;
        string s; cin >> s;
        for (int i = 0; i < n && ok; ++i) {
            if(i) {
                if(s[i] == s[i - 1]) continue;
                ok &= f[s[i] - 'A'] == 0;
            }
            f[s[i] - 'A']++;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}