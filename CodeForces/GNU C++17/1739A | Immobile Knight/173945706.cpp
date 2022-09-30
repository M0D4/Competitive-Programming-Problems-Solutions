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
 
int dx[] = {1, 1,  -1, -1, -2, -2, 2, 2};
int dy[] = {2, -2,  2, -2, 1, -1, 1, -1};
 
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n, m;
        cin >> n >> m;
 
        auto valid = [&](int r, int c){
            return r >= 0 && c >= 0 && r < n && c < m;
        };
 
        auto freeToMove = [&](int r, int c){
            for (int i = 0; i < 8; ++i) {
                int x = r + dx[i], y = c + dy[i];
                if (valid(x, y)) return true;
            }
            return false;
        };
 
        int r = 1, c = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!freeToMove(i, j)){
                    r = i + 1, c = j + 1;
                }
            }
        }
        cout << r << " " << c << endl;
    }
    return 0;
}