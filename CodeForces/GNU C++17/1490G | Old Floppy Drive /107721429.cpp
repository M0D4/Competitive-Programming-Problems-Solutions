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
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
   int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        ll a[n], sum = 0, in = 0;
        vector<ll> pre;
        vector<int> ind;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if(pre.empty() || pre.back() < sum){
                pre.push_back(sum);
                ind.push_back(in);
            }
            in++;
        }
         while (m--){
            int x; cin >> x;
            if(pre.back() < x && sum <= 0){
                cout << "-1 ";
                continue;
            }
            ll cnt = 0;
            if(x > pre.back()){
                cnt += (x - pre.back()) / sum + !!((x - pre.back()) % sum);
            }
            x -= cnt * sum;
            cout << cnt * n + ind[lower_bound(all(pre), x) - pre.begin()] << " ";
        }
        cout << endl;
    }
    return 0;
}