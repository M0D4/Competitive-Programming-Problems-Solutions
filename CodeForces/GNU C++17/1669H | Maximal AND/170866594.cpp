#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n, k;
        cin >> n >> k;
        int a[n];
        int f[32] = {};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for (int bit = 0; bit < 31; ++bit) {
                f[bit] += ((1 << bit) & a[i]) != 0;
            }
        }
 
        ll ans = 0;
        for (int bit = 30; bit >= 0; --bit) {
            ll need = n - f[bit];
            if (k >= need){
                k -= need;
                ans |= (1LL << bit);
            }
        }
        cout << ans << endl;
    }
    return 0;
}