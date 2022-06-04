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
    ll m = 1;
    vector<int> ans;
    for (int i = 1; i + 1 < n; ++i) {
        if(__gcd(i, n) == 1){
            m *= i;
            m %= n;
            ans.push_back(i);
        }
    }
    if((m * (n - 1) % n) == 1)
        ans.push_back(n - 1);
     cout << ans.size() << endl;
    for(auto&i : ans)
        cout << i << " ";
    return 0;
}