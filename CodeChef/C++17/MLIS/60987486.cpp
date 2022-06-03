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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> lis, pre(n), suff(n);
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(all(lis), a[i]) - lis.begin();
            if(j == lis.size()) lis.push_back(0);
            lis[j] = a[i];
            pre[i] = lis.size();
        }

        lis.clear();
        for (int i = n - 1; i >= 0; --i) {
            int j = lower_bound(all(lis), -a[i]) - lis.begin();
            if(j == lis.size()) lis.push_back(0);
            lis[j] = -a[i];
            suff[i] = lis.size();
        }
        int ans = suff[0];
        for (int i = 1; i < n; ++i) {
            ans = max(ans, suff[i] + pre[i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}