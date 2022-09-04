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
        int alice = 0, bob = 0, ans = 0;
        int l = 0, r = n - 1;
        while (l <= r){
            while (l <= r && alice <= bob) {
                if (alice == bob) ans = l + (n - r - 1);
                alice += a[l++];
            }
            if (alice == bob) ans = l + (n - r - 1);
            while (l <= r && bob < alice) bob += a[r--];
            if (alice == bob) ans = l + (n - r - 1);
        }
        cout << ans << endl;
    }
    return 0;
}