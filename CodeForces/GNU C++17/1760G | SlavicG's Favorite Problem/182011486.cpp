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
 
const int N = 1e5 + 5, M = 2e5 + 5;
 
int ne, head[N], nxt[M], to[M], cost[M];
 
void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}
 
void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}
 
void addBiDirectedEdge(int u, int v, int c){
    addEdge(u, v, c);
    addEdge(v, u, c);
}
 
map<ll, bool> mp;
void calculateXor(int u, int par, int xxor, int b){
    if(u != b) mp[xxor] = 1;
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if (v == par) continue;
        calculateXor(v, u, xxor ^ cost[k], b);
    }
}
 
bool dfs(int u, int par, int xxor, int b){
    if (mp.count(xxor)) {
        return 1;
    }
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if (v == par || v == b) continue;
        if (dfs(v, u, xxor ^ cost[k], b))
            return 1;
    }
    return 0;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while(TC--){
        int n, a, b;
        cin >> n >> a >> b;
        --a, --b;
        initGraph(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            addBiDirectedEdge(u, v, w);
        }
        mp.clear();
        calculateXor(b, -1, 0, b);
 
        cout << (dfs(a, -1, 0, b) ? "YES" : "NO") << endl;
    }
    return 0;
}