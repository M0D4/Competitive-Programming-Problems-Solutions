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
        int n, k; cin >> n >> k;
        vector<ll> a(n);
        ll ans = 0;
        for (int i = 0; i < n; ++i){
            cin >> a[i];
            ans += a[i] / k;
            a[i] %= k;
        }
        sort(all(a));
        for (int i = 0, j = n - 1; i < j; ++i, --j){
            while (i < j && a[i] + a[j] < k) ++i;
            if (i == j) break;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}