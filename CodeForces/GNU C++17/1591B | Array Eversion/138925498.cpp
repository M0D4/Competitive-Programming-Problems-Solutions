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
    while (tc--){
        int n; cin >> n;
        int a[n], mx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        int steps = 0, mx2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if(a[i] == mx) break;
            if(a[i] > mx2)
                steps++, mx2 = a[i];
        }
        cout << steps << endl;
    }
    return 0;
}