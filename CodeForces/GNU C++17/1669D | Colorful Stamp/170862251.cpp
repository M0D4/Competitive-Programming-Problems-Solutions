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
        string s;
        cin >> n >> s;
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') continue;
            int red = (s[i] == 'R'), black = (s[i] == 'B');
            while (i + 1 < n && s[i + 1] != 'W'){
                ++i;
                if (s[i] == 'R') red++;
                else black++;
            }
            ok &= (red && black);
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}