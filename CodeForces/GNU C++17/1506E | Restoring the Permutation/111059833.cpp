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
 const int N = 2e5 + 5;
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        MN:{
            int f[n + 2] = {}, MEX = 1;
            for (int i = 0; i < n; ++i) {
                if(f[a[i]]){
                    while (f[MEX]) MEX++;
                    cout << MEX << " ";
                    f[MEX]++;
                }else cout << a[i] << " ", f[a[i]]++;
            }
            cout << endl;
        };
         MX:{
            int f[n + 2] = {}, MEX = 1;
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                if(f[a[i]]){
                    while (MEX < a[i]){
                        if(!f[MEX]) v.push_back(MEX);
                        MEX++;
                    }
                    cout << v.back() << " ";
                    f[v.back()]++;
                    v.pop_back();
                }else cout << a[i] << " ", f[a[i]]++;
            }
            cout << endl;
        };
    }
    return 0;
}