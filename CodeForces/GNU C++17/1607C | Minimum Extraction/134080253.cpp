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
        int n; cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i = 0; i < n; ++i) {
            ll x; cin >> x;
            q.push(x);
        }
        ll sum = 0, mx = q.top();
        while (q.size()){
            ll x = q.top() - sum;
            q.pop();
            mx = max(mx, x);
            sum += x;
        }
        cout << mx << endl;
    }
    return 0;
}