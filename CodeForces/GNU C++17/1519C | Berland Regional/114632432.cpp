#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
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
  int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> suff[n + 1];
        int u[n];
        for (int i = 0; i < n; ++i) {
            cin >> u[i];
        }
        for (int i = 0; i < n; ++i) {
            int s; cin >> s;
            suff[u[i]].push_back(s);
        }
         ll sums[n + 1] = {};
        for (int i = 1; i <= n; ++i) {
            if(suff[i].size()){
                sort(all(suff[i]), greater<ll>());
                suff[i].push_back(0);
                for (int j = (int) suff[i].size() - 2; j >= 0; --j) {
                    suff[i][j] += suff[i][j + 1];
                }
                 for (int j = 1; j < suff[i].size(); ++j) {
                    int rem = (suff[i].size() - 1) % j;
                    sums[j] += suff[i][0] - suff[i][(int)suff[i].size() - rem - 1];
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << sums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}