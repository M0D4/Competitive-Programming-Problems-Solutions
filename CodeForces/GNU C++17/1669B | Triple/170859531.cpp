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
        int n;
        cin >> n;
        int f[n + 1] = {};
        int v = -1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            f[x]++;
            if (f[x] >= 3)
                v = x;
        }
        cout << v << endl;
    }
    return 0;
}