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
     int tc; cin >> tc;
    while(tc--){
        int n, b, x, y; cin >> n >> b >> x >> y;
        ll sum = 0;
        ll a[n + 1] = {0};
        for (int i = 1; i <= n; ++i) {
            ll add = a[i - 1] + x;
            if(add > b) a[i] = a[i - 1] - y;
            else a[i] = add;
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}