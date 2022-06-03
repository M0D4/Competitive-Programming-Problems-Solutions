#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
using vi = vector<int>;


///Intermediate Overflow!!! (1 << i), x * y, 2 * x


int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m; cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    bool ok = 1;
    for (int i1 = 0; i1 < n; ++i1) {
        for (int i2 = i1 + 1; i2 < n; ++i2) {
            for (int j1 = 0; j1 < m; ++j1) {
                for (int j2 = j1 + 1; j2 < m; ++j2) {
                    ok &= a[i1][j1] + a[i2][j2] <= a[i2][j1] + a[i1][j2];
                }
            }
        }
    }
    cout << (ok ? "Yes" : "No");
    return 0;
}