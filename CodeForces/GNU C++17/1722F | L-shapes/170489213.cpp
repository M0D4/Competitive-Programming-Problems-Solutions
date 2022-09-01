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
 
enum dir    {RIGHT, LEFT, DOWN, UP, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT};
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char> (m));
 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
 
        auto valid = [&](int r, int c){
            return ~r && ~c && r < n && c < m;
        };
 
        vector<vector<bool>> vis(n, vector<bool> (m));
 
        vector<pair<int, int>> sequence;
 
        function<void(int, int)> dfs = [&](int r, int c) -> void{
            vis[r][c] = 1;
            sequence.push_back({r, c});
            for (int i = 0; i < 8; ++i) {
                int x = r + dx[i];
                int y = c + dy[i];
                if (valid(x, y) && a[x][y] == '*' && !vis[x][y]){
                    dfs(x, y);
                }
            }
        };
 
        auto sameRow = [](pair<int, int>& a, pair<int, int>& b){
            return a.first == b.first;
        };
        auto sameColumn = [](pair<int, int>& a, pair<int, int>& b){
            return a.second == b.second;
        };
 
        bool ok = 1;
        for (int i = 0; i < n && ok; ++i) {
            for (int j = 0; j < m && ok; ++j) {
                if (!vis[i][j] && a[i][j] == '*'){
                    sequence.clear();
                    dfs(i, j);
                    if (sequence.size() != 3) ok = 0;
                    else{
                        auto& x = sequence[0];
                        auto& y = sequence[1];
                        auto& z = sequence[2];
 
                        bool checkPoint = 0;
                        checkPoint |= (sameRow(x, y) && sameColumn(x, z))
                                || (sameRow(x, z) && sameColumn(x, y));
 
                        checkPoint |= (sameRow(y, x) && sameColumn(y, z))
                                || (sameRow(y, z) && sameColumn(y, x));
 
                        checkPoint |= (sameRow(z, x) && sameColumn(z, y))
                                || (sameRow(z, y) && sameColumn(z, x));
 
                        ok &= checkPoint;
                    }
                }
            }
        }
 
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}