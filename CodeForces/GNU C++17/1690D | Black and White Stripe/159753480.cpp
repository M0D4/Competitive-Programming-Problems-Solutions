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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int white[n + 2] = {};
        for (int i = 0; i < n; ++i) {
            white[i + 1] = white[i] + (s[i] == 'W');
        }
        int mn = 1e9;
        for (int i = 0; i + k <= n; ++i) {
            int whiteCnt = white[i + k] - white[i];
            mn = min(mn, whiteCnt);
        }
        cout << mn << endl;
    }
    return 0;
}