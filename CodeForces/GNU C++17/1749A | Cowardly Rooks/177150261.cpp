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
        cin >> n >> m;
        bool row[n] = {}, col[n] = {};
        vector<pair<int, int>> a(m);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            row[x] = 1;
            col[y] = 1;
            a[i] = {x, y};
        }
        bool ok = 0;
        for (auto& p: a){
            int x = p.first, y = p.second;
            for (int i = 0; i < n; ++i) {
                if (i != y && !col[i]) ok = 1;
                if (i != x && !row[i]) ok = 1;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}