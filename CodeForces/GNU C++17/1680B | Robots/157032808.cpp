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
        int n, m; cin >> n >> m;
        char a[n][m];
        int x = -1, y = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                if(a[i][j] == 'R' && x == -1)
                    x = i, y = j;
            }
        }
        bool ok = 1;
        for (int i = x; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(i == x && j == y) continue;
                if(a[i][j] == 'R' && i > x && j < y){
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}