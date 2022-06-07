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
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        string s, t; cin >> s >> t;
        int n = s.size(), m = t.size(), mx = 0;
        for (int len = 1; len <= min(n, m); ++len) {
            for (int i = 0; i + len <= n; ++i) {
                for (int j = 0; j + len <= m; ++j) {
                    if(s.substr(i, len) == t.substr(j, len))
                        mx = max(mx, len);
                }
            }
        }
        cout << n + m - 2 * mx << endl;
    }
    return 0;
}