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
        int n, m;
        n = m = 8;
        char a[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        bool red = 0;
        for (int i = 0; i < n; ++i) {
            bool same = 1;
            for (int j = 0; j < m; ++j) {
                same &= a[i][j] == 'R';
            }
            red |= same;
        }
        cout << (red ? "R" : "B") << endl;
    }
    return 0;
}