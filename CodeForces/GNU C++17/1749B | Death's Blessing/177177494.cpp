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
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int i = 0, j = n - 1;
        while (i <= j){
            if (b[i] <= b[j]) {
                ans += a[i];
                if (i + 1 <= j) a[i + 1] += b[i];
                ++i;
            }else{
                ans += a[j];
                if (j - 1 >= i) a[j - 1] += b[j];
                --j;
            }
        }
 
        cout << ans << endl;
    }
    return 0;
}