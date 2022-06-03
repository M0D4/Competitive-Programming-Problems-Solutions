#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;



int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, r, c; cin >> n >> m >> r >> c;
    --r, --c;
    char a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    int x = r - 1, y = c;
    while (x >= 0 && a[x][y] != '#') cnt++, x--;
    x = r + 1, y = c;
    while (x < n && a[x][y] != '#') cnt++, x++;
    x = r, y = c - 1;
    while (y >= 0 && a[x][y] != '#') cnt++, y--;
    x = r, y = c + 1;
    while (y < m && a[x][y] != '#') cnt++, y++;
    cnt += a[r][c] != '#';
    cout << cnt;
    return 0;
}