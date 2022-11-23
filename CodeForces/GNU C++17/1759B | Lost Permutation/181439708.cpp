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
    int TC;
    cin >> TC;
    while(TC--){
        int m, s;
        cin >> m >> s;
        int f[150] = {};
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            f[x] = 1;
        }
        bool ok = 1;
        int x = 1, cnt = m;
        while (s > 0){
            while (x < 150 && f[x]) ++x;
            if (s >= x){
                s -= x;
                f[x] = 1;
                ++x;
                cnt++;
            }else{
                ok = 0;
                break;
            }
        }
        for (int i = 1; i <= cnt; ++i) {
            ok &= f[i];
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}