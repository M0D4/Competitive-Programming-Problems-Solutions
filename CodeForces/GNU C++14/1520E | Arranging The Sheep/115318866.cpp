#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 //#define endl            "\n"
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
 void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int stars = count(all(s), '*'), pos = 0;
    if(stars & 1) stars++;
    for (int i = 0, j = 0; i < n && j != stars / 2; ++i) {
        if(s[i] == '*') j++;
        if(j == stars / 2){
            pos = i;
            break;
        }
    }
    int cnt = 0;
    ll ans = 0;
    for (int i = pos - 1; i >= 0; --i) {
        if(s[i] == '*'){
            ans += cnt;
            continue;
        }
        cnt++;
    }
    cnt = 0;
    for (int i = pos + 1; i < n; ++i) {
        if(s[i] == '*'){
            ans += cnt;
            continue;
        }
        cnt++;
    }
    cout << ans << endl;
}
 int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}