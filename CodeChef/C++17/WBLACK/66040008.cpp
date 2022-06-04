#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 3e5 + 5, M = 6e5 + 5;

int ne, head[N], nxt[M], to[M], sub[N], color[N], wantColor[N];

void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}

void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

void addBidirectedEdge(int u, int v){
    addEdge(u, v);
    addEdge(v, u);
}

ll dp[N][2][2];

ll go(int u, int par, bool changed, bool flyColor){


    ll& ret = dp[u][changed][flyColor];
    if(~ret) return ret;

    int cnt = 0;
    ret = 0;

    if(changed && flyColor != wantColor[u]) cnt = 1;
    else if(!changed && color[u] != wantColor[u]) cnt = 1;

    ll noChange = 0, withChange = 0;
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if(v == par) continue;
        noChange += go(v, u, changed, flyColor);
        withChange += go(v, u, 1, wantColor[u]);
    }

    if(cnt) noChange = 1e9;
    return ret = min(withChange + 1, noChange + cnt);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        initGraph(n);
        for (int i = 0; i < n; ++i) {
            cin >> color[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> wantColor[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            --u, --v;
            addBidirectedEdge(u, v);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        auto v = go(0, -1, 0, 0);
        cout << v << endl;
    }
    return 0;
}