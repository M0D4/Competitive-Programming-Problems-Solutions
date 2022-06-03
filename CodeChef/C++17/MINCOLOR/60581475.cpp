#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

int n, m;
vector<vector<int>> a;

bool valid(int r, int c){
    return ~r && ~c && r < n && c < m;
}

void dfs(int r, int c, int color){
    a[r][c] = color;
    int nextColor = (color == 1 ? 2 : 1);
    for (int i = 0; i < 4; ++i) {
        int x = r + dx[i], y = c + dy[i];
        if(!valid(x, y)) continue;
        if(a[x][y]) continue;
        bool ok = 1;
        for (int j = 0; j < 4; ++j) {
            int xx = x + dx[j], yy = y + dy[j];
            if(!valid(xx, yy)) continue;
            if(a[xx][yy] == nextColor) ok = 0;
        }
        dfs(x, y, nextColor + !ok);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        a = vector<vector<int>>(n, vector<int> (m));
        int x, y; cin >> x >> y;
        --x, --y;
        a[x][y] = 1;
        int r, c; cin >> r >> c;
        --r, --c;
        a[r][c] = 2;
        dfs(x, y, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}