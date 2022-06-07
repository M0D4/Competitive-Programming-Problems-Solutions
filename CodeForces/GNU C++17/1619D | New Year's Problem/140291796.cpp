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
        int m, n; cin >> m >> n;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
 
        auto possible = [&](int x)-> bool {
            vector<int> columns(n, 0);
            bool pigeonHole = 0;
            for (int i = 0; i < m; ++i) {
                int rowCount = 0;
                for (int j = 0; j < n; ++j) {
                    rowCount += (a[i][j] >= x);
                    columns[j] |= a[i][j] >= x;
                }
                pigeonHole |= rowCount >= 2;
            }
            return pigeonHole && all_of(all(columns), [&](bool y){ return y;});
        };
 
        int l = 1, r = 1e9;
        while (l <= r){
            int mid = (l + r) >> 1;
            if(possible(mid)) l = mid + 1;
            else r = mid - 1;
        }
        cout << l - 1 << endl;
    }
    return 0;
}