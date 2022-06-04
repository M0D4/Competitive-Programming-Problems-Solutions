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
        int n; cin >> n;
        vector<ll> a(n);
        multiset<ll> mins;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mins.insert(a[i]);
        }
        auto b = a;
         int l = 0, r = 1e9;
        while (l <= r){
            int mid = (l + r) >> 1;
            a = b;
            for (int i = n - 1; i >= 2; --i) {
                ll diff = min(a[i] - mid, b[i]);
                ll x = max(0LL, diff / 3);
                 a[i] -= 3 * x;
                a[i - 1] += x;
                a[i - 2] += 2 * x;
            }
             if(*min_element(all(a)) >= mid) l = mid + 1;
            else r = mid - 1;
        }
        cout << l - 1 << endl;
    }
    return 0;
}