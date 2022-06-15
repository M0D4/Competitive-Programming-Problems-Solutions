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
        vector<vector<char>> a(8, vector<char>(8));
        int n = 8, m = 8;
        auto valid = [&](int r, int c){
            return ~r && ~c && r < n && c < m;
        };
        auto check = [&](int x, int y){
            int r = x, c = y;
            while (valid(r, c)){
                if(a[r][c] != '#')
                    return 0;
                --r;
                --c;
            }
            r = x, c = y;
            while (valid(r, c)){
                if(a[r][c] != '#')
                    return 0;
                --r;
                ++c;
            }
            r = x, c = y;
            while (valid(r, c)){
                if(a[r][c] != '#')
                    return 0;
                ++r;
                ++c;
            }
            r = x, c = y;
            while (valid(r, c)){
                if(a[r][c] != '#')
                    return 0;
                ++r;
                --c;
            }
            return 1;
        };
        int r = -1, c;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            int cnt = 0, x = -1, y;
            for (int j = 0; j < m; ++j) {
                if(a[i][j] == '#') cnt++, x = i, y = j;
            }
            if(r == -1 && cnt == 1 && x != 0 && x != n - 1 && y != 0 && y != m - 1){
                if(check(x, y))
                    r = x, c = y;
            }
        }
        cout << r + 1 << " " << c + 1 << endl;
    }
    return 0;
}