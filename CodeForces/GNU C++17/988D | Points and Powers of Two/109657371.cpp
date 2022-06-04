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
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> ans = {a[0]};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 31; ++j) {
            int l = a[i] + (1 << j);
            int r = a[i] - (1 << j);
            bool hasL = binary_search(all(a), l);
            bool hasR = binary_search(all(a), r);
            if(ans.size() < 3 && hasL && hasR){
                ans = {a[i], l, r};
            }
            if(ans.size() < 2 && hasL){
                ans = {a[i], l};
            }
            if(ans.size() < 2 && hasR){
                ans = {a[i], r};
            }
        }
    }
    cout << ans.size() << endl;
    for(auto& i: ans)
        cout << i << " ";
    return 0;
}