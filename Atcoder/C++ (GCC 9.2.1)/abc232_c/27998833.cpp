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

    int n, m; cin >> n >> m;
    set<pair<int, int>> tak, ako;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        if(u > v) swap(u, v);
        tak.insert({u, v});
    }
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        if(u > v) swap(u, v);
        ako.insert({u, v});
    }
    vector<int> a(n);
    iota(all(a), 0);
    bool yes = 0;
    do {
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x = a[i], y = a[j];
                if(x > y) swap(x, y);
                ok &= (tak.count({i, j}) == ako.count({x, y}));
            }
        }
        if(ok){
            yes = 1;
            break;
        }
    } while (next_permutation(all(a)));

    cout << (yes ? "Yes" : "No");
    return 0;
}