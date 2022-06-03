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
        int n, m; cin >> n >> m;
        ll mx = 0;
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < n - 1; ++i) {
            mx = max(mx, a[i] + a[i + 1] + ((a[i] - a[i + 1]) % m + m) % m);
            mx = max(mx, a[i] + a[i + 1] + (a[i + 1] - a[i]) % m);
            mx = max(mx, a[i] + a[i]);
        }
        mx = max(mx, a[n - 1] + a[n - 1]);
        cout << mx << endl;
    }
    return 0;
}