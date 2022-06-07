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
        ll a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll g = 0;
        for (int i = 0; i < n; i += 2) {
            g = __gcd(g, a[i]);
        }
        bool ok = 1;
        for (int i = 1; i < n; i += 2) {
            if(a[i] % g == 0){
                ok = 0;
                break;
            }
        }
        if(ok){
            cout << g << endl;
            continue;
        }
        g = 0;
        for (int i = 1; i < n; i += 2) {
            g = __gcd(g, a[i]);
        }
        ok = 1;
        for (int i = 0; i < n; i += 2) {
            if(a[i] % g == 0){
                ok = 0;
                break;
            }
        }
        if(!ok) g = 0;
        cout << g << endl;
    }
    return 0;
}