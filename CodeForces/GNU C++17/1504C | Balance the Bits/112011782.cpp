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
  void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ones = 0;
    for (int i = 0; i < n; ++i) {
        ones += (s[i] == '1');
    }
    if(isOdd(ones) || s[0] == '0' || s.back() == '0'){
        cout << "NO\n";
        return;
    }
    string a, b;
    a = b = "";
    bool flip = 0;
    for (int i = 0, k = 0; i < n; ++i) {
        if(s[i] == '1'){
            a.push_back(2 * k >= ones? ')' : '(');
            b.push_back(a.back());
            ++k;
        }else{
            a.push_back(flip ? '(' : ')');
            b.push_back(flip ? ')' : '(');
            flip ^= 1;
        }
    }
    cout << "YES\n" << a << endl << b << endl;
}
 int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
     int tc; cin >> tc;
    while (tc--){
        solve();
    }
    return 0;
}