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
 
const int N = 2e5 + 5, M = 4e5 + 5, P = 18;
 
int ne, head[N], nxt[M], to[M];
bool pathY[N], thing[N];
 
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
 
void dfs(int u, int par){
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if (v == par) continue;
        dfs(v, u);
        if (thing[v]) thing[u] = 1;
        if (pathY[v]) pathY[u] = 1;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
 
    int TC; cin >> TC;
    while(TC--){
 
        int n, k;
        cin >> n >> k;
 
        int x, y;
        cin >> x >> y;
        --x, --y;
 
        for (int i = 0; i < n; ++i) thing[i] = pathY[i] = 0;
 
        for (int i = 0; i < k; ++i) {
            int idx;
            cin >> idx;
            thing[idx - 1] = 1;
        }
 
        pathY[y] = 1;
 
        initGraph(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            addBidirectedEdge(u, v);
        }
 
        dfs(x, -1);
 
        ll ans = 0;
        for (int u = 0; u < n; ++u) {
            if (u == x) continue;
            if (pathY[u]) ans++;
            else if (thing[u]) ans += 2;
        }
        cout << ans << endl;
    }
    return 0;
}