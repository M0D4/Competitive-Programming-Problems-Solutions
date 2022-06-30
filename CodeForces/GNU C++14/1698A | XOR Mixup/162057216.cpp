#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
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
        int n; cin >> n;
        int a[n];
        int x = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            x ^= a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if((x ^ a[i]) == a[i]){
                ans = a[i];
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}