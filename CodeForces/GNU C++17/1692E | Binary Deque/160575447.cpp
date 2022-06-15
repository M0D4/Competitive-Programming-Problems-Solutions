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
        int a[n], s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s += a[i];
        }
        if(s < m){
            cout << "-1\n";
            continue;
        }
        int l = 0, r = 0;
        s = 0;
        int mn = 1e9;
        while (r < n){
            while (r < n && s + a[r] <= m){
                s += a[r];
                ++r;
            }
            if(s == m) mn = min(mn, n - r + l);
            s -= a[l];
            ++l;
            if(l > r)
                r = l;
        }
        cout << mn << endl;
    }
    return 0;
}