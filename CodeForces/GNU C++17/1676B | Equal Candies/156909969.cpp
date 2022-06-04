#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
 int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        int a[n], mn = 1e9;
        for (int i = 0; i < n; ++i) {
           cin >> a[i];
           mn = min(mn, a[i]);
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += a[i] - mn;
        }
        cout << ans << endl;
    }
    return 0;
}