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
        ll w, h; cin >> w >> h;
        ll mx = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int k; cin >> k;
                vector<int> a(k);
                for (auto &item : a) cin >> item;
                mx = max(mx, (a.back() - a[0]) * (i == 0 ? h : w));
            }
        }
        cout << mx << endl;
    }
    return 0;
}