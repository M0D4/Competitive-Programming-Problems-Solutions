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
 
int n;
vector<int> a;
bool ok;
 
int solve(int st, int ed, int m){
    if (m == 1) return 0;
 
    int half = m / 2;
 
    int mn1 = 1e9, mx1 = 0, mn2 = 1e9, mx2 = 0;
 
    int mid = (st + ed) >> 1;
 
    for (int i = st; i <= mid; ++i) {
        mn1 = min(mn1, a[i]);
        mx1 = max(mx1, a[i]);
    }
    for (int i = mid + 1; i <= ed; ++i) {
        mn2 = min(mn2, a[i]);
        mx2 = max(mx2, a[i]);
    }
 
    if (mx1 - mn1 >= half || mx2 - mn2 >= half){
        ok = 0;
        return 0;
    }
 
    int cnt = mn1 > mn2;
 
    return cnt + solve(st, mid, m / 2) + solve(mid + 1, ed, m / 2);
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
       cin >> n;
       a = vector<int>(n);
 
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
 
        ok = 1;
 
        int ans = solve(0, n - 1, n);
 
        if (!ok) ans = -1;
 
        cout << ans << endl;
    }
    return 0;
}