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
        int k, n, m; cin >> k >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        int i = 0, j = 0;
        vector<int> ans;
        while ((i < n || j < m) && ans.size() < n + m){
                if(i < n && a[i] <= k) ans.push_back(a[i]), k += (a[i] == 0), ++i;
                else if(j < m && b[j] <= k) ans.push_back(b[j]), k += (b[j] == 0), ++j;
                else break;
        }
        if(ans.size() != n + m){
            cout << "-1\n";
        }else{
            for(auto &i: ans)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}