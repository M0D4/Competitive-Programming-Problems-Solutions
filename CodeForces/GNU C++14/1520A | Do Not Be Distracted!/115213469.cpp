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
        string s; cin >> s;
        string t(1, s[0]);
        for (int i = 1; i < n; ++i) {
            if(s[i] == t.back()) continue;
            t.push_back(s[i]);
        }
        int f[26] = {}, ok = 1;
        for (int i = 0; i < t.size(); ++i) {
            ok &= f[t[i] - 'A'] == 0;
            f[t[i] - 'A']++;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}