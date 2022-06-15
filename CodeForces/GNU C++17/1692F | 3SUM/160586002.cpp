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
        int n; cin >> n;
        vector<int> a(n);
        int f[11] = {};
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] %= 10;
            f[a[i]]++;
        }
        bool ok = 0;
        for (int i = 0; i <= 9; ++i) {
            if(f[i] == 0) continue;
            f[i]--;
            for (int j = 0; j <= 9; ++j) {
                if(f[j] == 0) continue;
                f[j]--;
                for (int k = 0; k <= 9; ++k) {
                    if(f[k] == 0) continue;
                    if((i + j + k) % 10 == 3){
                        ok = 1;
                        goto EmergencyGate;
                    }
                }
                f[j]++;
            }
            f[i]++;
        }
        EmergencyGate:;
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}