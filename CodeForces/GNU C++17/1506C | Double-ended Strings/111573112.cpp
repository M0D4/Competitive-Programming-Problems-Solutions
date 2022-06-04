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
  using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 vector<int> computePrefix(string pat) {
    int m = pat.size();
    vector<int> longestPrefix(m);
    for (int i = 1, k = 0; i < m; i++) {
        while (k > 0 && pat[k] != pat[i])
            k = longestPrefix[k - 1];
         if (pat[k] == pat[i]) longestPrefix[i] = ++k;
        else longestPrefix[i] = k;
    }
    return longestPrefix;
}
 bool KMP(string s, string pat) {
    int n = s.size(), m = pat.size();
    vector<int> longestPrefix = computePrefix(pat);
     for (int i = 0, k = 0; i < n; i++) {
        while (k > 0 && pat[k] != s[i])
            k = longestPrefix[k - 1];
         if (pat[k] == s[i]) k++;
         if (k == m) {
            return 1;
            k = longestPrefix[k - 1];
        }
    }
    return 0;
}
 int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
     int tc; cin >> tc;
    while (tc--){
        string s, t; cin >> s >> t;
        int n = s.size(), m = t.size(), mx = 0;
        for (int len = m; len && !mx; --len) {
            for (int i = 0; i + len <= m; ++i) {
                if(KMP(s, t.substr(i, len))){
                    mx = len;
                    break;
                }
            }
        }
        cout << n + m - 2 * mx << endl;
    }
    return 0;
}