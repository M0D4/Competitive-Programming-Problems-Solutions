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
        int n, q; cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        vector<ll> pre(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            pre[i] = pre[i + 1] + a[i];
        }
        pre.pop_back();
        reverse(all(pre));
        while (q--){
            int x; cin >> x;
            int idx = lower_bound(all(pre), x) - pre.begin();
            if (idx == pre.size()) idx = -2;
            cout << idx + 1 << endl;
        }
    }
    return 0;
}