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
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int even = a[0] & 1, odd = a[1] & 1;
        bool ok = 1;
        for (int i = 2; i < n; ++i) {
            if (i & 1) ok &= (a[i] & 1) == odd;
            else ok &= (a[i] & 1) == even;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}