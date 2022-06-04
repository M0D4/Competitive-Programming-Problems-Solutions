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
  ///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 int go(string& s, string t){
    int mn = 1000, n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        if(s[i] == t[1]){
            for (int j = i - 1; j >= 0; --j) {
                if(s[j] == t[0]){
                    mn = min(mn, i - j - 1 + (n - i - 1));
                    break;
                }
            }
        }
    }
    return mn;
}
 void solveOne(){
    string s; cin >> s;
    int n = s.size();
    string mul[] = {"00", "25", "50", "75"};
    int mn = 1e3;
    for (int i = 0; i < 4; ++i) {
        mn = min(mn, go(s, mul[i]));
    }
    cout << mn << endl;
}
  int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
    int tc; cin >> tc;
    while (tc--){
        solveOne();
    }
    return 0;
}
 