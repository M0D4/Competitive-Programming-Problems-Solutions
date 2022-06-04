#include "bits/stdc++.h"
  #pragma GCC optimize("-Ofast")
#pragma GCC optimize("-O2")
  using namespace std;
 #define endl            "\n"
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(x.begin(), x.end()), x.end())
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
  using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        char next = 'b';
        int i = s.find('a'), j = i;
        if(i == -1){
          cout << "NO\n";
          continue;
        }
        bool ok = 1;
        while (i > 0 || j + 1 < n){
            if(i - 1 >= 0 && s[i - 1] == next) --i, next++;
            else if(j + 1 < n && s[j + 1] == next) ++j, next++;
            else{
                ok = 0;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}