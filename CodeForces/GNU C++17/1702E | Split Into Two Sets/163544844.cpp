#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
 
const int N = 2e5 + 5, M = 4e5 + 5;
 
int ne, head[N], nxt[M], to[M];
 
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
 
vector<int> color;
bool cycle;
bool dfs(int u, int par, int dep){
    color[u] = 1;
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if (v == par) continue;
        if (color[v] == 0){
            if (dfs(v, u, dep + 1)){
                return 1;
            }
        }else if(color[v] == 1){
            if (dep & 1) cycle = 1;
            return 1;
        }
    }
    color[u] = 2;
    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        initGraph(n);
        set<pair<int, int>> s;
        bool ok = 1;
        int deg[n] = {};
        for (int i = 0; i < n; ++i) {
            int u, v; cin >> u >> v;
            ok &= (u != v);
            if (s.count({u, v})){
                swap(u, v);
                ok &= (!s.count({u, v}));
            }
            --u, --v;
            deg[u]++;
            deg[v]++;
            ok &= (deg[u] <= 2 && deg[v] <= 2);
            addBidirectedEdge(u, v);
        }
        if (!ok){
            cout << "NO\n";
            continue;
        }
        color = vector<int> (n);
        for (int i = 0; i < n && ok; ++i) {
            if (!color[i]){
                cycle = 0;
                dfs(i, -1, 1);
                ok &= (!cycle);
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}