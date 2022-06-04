#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
  using namespace std;
 #define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
 int lcm(int a, int b){
    return  a / __gcd(a, b) * b;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int tt; cin >> tt;
    while (tt--){
        string s, t; cin >> s >> t;
        if(s.size() > t.size()) swap(s, t);
        int n = s.size(), m = t.size(), lc = lcm(n, m);
        string x = "";
        for(int i = 0; i < lc / n; i++)
            x += s;
         bool ok = 1;
        for(int i = 0; i + n <= lc; i += n){
            if(x.substr(i, n) != s){
                ok = 0;
                break;
            }
        }
        for(int i = 0; i + m <= lc; i += m){
            if(x.substr(i, m) != t){
                ok = 0;
                break;
            }
        }
         cout << (ok ? x : "-1") << endl;
    }
    return 0;
}