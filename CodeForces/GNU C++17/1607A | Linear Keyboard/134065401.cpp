#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
using vi = vector<int>;
  ///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        string keyboard; cin >> keyboard;
        map<char, int> mp;
        for (int i = 0; i < keyboard.size(); ++i) {
            mp[keyboard[i]] = i;
        }
        string s; cin >> s;
        int n = s.size();
        ll sum = 0;
        for (int i = 1; i < n; ++i) {
            sum += abs(mp[s[i]] - mp[s[i - 1]]);
        }
        cout << sum << endl;
    }
    return 0;
}