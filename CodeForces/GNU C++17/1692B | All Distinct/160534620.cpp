#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
const int N = 1e4 + 5;
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        int a[n], f[N] = {};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]]++;
        }
        int cc = 0;
        for (int i = 0; i < N; ++i) {
            cc += max(0, f[i] - 1);
        }
        if(cc & 1) cc++;
        cout << n - cc << endl;
    }
    return 0;
}