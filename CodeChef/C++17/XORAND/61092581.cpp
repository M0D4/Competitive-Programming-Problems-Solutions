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
        vector<int> a(n);
        int f[33] = {};
        int clz[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            int c = __builtin_clz(a[i]);
            f[c]++;
            clz[i] = c;
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            f[clz[i]]--;
            ans += f[clz[i]];
        }
        cout << ans << endl;
    }
    return 0;
}