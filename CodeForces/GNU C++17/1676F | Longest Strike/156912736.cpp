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
        int a[n];
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(a, a + n);
        int l = 1, r = 0;
        for (int i = 0; i < n; ++i) {
            if(mp[a[i]] < k) continue;
            int j = i + 1;
            while (j < n && a[j] - a[j - 1] <= 1 && mp[a[j]] >= k)
                ++j;
            if (a[j - 1] - a[i] > r - l)
                l = a[i], r = a[j - 1];
            i = j - 1;
        }
        if (l > r) cout << "-1\n";
        else cout << l << " " << r << endl;
    }
    return 0;
}