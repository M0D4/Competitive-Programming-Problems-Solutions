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
        int n, m; cin >> n >> m;
        vector<vector<int>> a(m);
        for (int i = 0; i < m; ++i) {
            int x, w; cin >> x >> w;
            a[i] = {w, x, i + 1};
        }
        sort(all(a));
        ll sum = 0;
        vector<vector<int>> ans;
        for (int i = 0, j = 0; j < n; i += 2, ++j) {
            sum += a[i][0] + a[i + 1][0];
            ans.push_back({a[i][1], a[i][2]});
            ans.push_back({a[i + 1][1], a[i + 1][2]});
        }
        sort(all(ans));
        cout << sum << endl;
        for (int i = 0, j = ans.size() - 1; i < ans.size() / 2; ++i, --j) {
            cout << ans[i][1] << " " << ans[j][1] << endl;
        }
        cout << endl;
    }
    return 0;
}