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
        vector<int> f(3, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] %= 3;
            f[a[i]]++;
        }
        int mn = min(f[1], f[2]);
        cout << f[0] + mn + (f[1] - mn) / 3 + (f[2] - mn) / 3 << endl;
    }
    return 0;
}