#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int, int>;


int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};


int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m; cin >> n >> m;
    int a[n][m], b[n][m];

    auto valid = [&](int r, int c) -> bool{
        return ~r && ~c && r < n && c < m;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    int dis[2][n][m];
    clr(dis, 0x3f);

    priority_queue<tii, vector<tii>, greater<tii>> q;
    q.push({0, 0, 0, 0});

    while (q.size()){
        int cost, op, r, c;
        tie(cost, op, r, c) = q.top();
        q.pop();

        if(dis[op][r][c] <= cost) continue;
        dis[op][r][c] = cost;

        for (int i = 0; i < 3; ++i) {
            int x = r + dx[i], y = c + dy[i];
            if(!valid(x, y)) continue;
            int newCost = cost + (i == 0 ? a[r][c] : i == 1 ? a[x][y] : b[r][c]);
            if(dis[0][x][y] <= newCost) continue;
            q.push({newCost, 0, x, y});
        }

        if(r){
            int newCost = cost + 1 + (1 - op);
            int x = r - 1, y = c;
            if(dis[1][x][y] <= newCost) continue;
            q.push({newCost, 1, x, y});
        }
    }
    cout << min(dis[1][n - 1][m - 1], dis[0][n - 1][m - 1]);
    return 0;
}