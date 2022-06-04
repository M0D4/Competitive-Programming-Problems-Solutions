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
  int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        deque<int> d;
        d.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if(a[i] > d.front()) d.push_back(a[i]);
            else d.push_front(a[i]);
        }
        for (int i = 0; i < n; ++i) {
            cout << d[i] << " " ;
        }
        cout << endl;
    }
    return 0;
}
 