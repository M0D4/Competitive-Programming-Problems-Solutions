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
#define flip(c)         (c == '0' ? '1' : '0')
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  void solve(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int zero = 0, one = 0, x = '0';
    for (int i = 0; i < n; ++i) {
        if(s[i] == '0') zero++;
        else one++;
    }
    bool ok = 1;
    for (int i = n - 1; ~i; --i) {
        bool notEqual = (x == '0' && s[i] != t[i]);
        notEqual |= (x == '1' && flip(s[i]) != t[i]);
        if(notEqual) {
            if (one == zero) {
                x = flip(x);
            }else{
                ok = 0;
                break;
            }
        }
        char y = s[i];
        if(x == '1') y = flip(y);
        if(y == '0') zero--;
        else one--;
    }
    cout << (ok ? "YES" : "NO") << endl;
}
 int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
     int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}