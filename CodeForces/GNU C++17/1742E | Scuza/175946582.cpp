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
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<pair<int, int>> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i].first;
            queries[i].second = i;
        }
        sort(all(queries));
        ll ans[q] = {};
        int p = 0;
        ll sum = 0;
        for (int i = 0; i < q; ++i) {
            int x = queries[i].first;
            while (p < n && a[p] <= x) sum += a[p], ++p;
            ans[queries[i].second] = sum;
        }
        for (int i = 0; i < q; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}