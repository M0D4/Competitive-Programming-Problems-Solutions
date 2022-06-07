#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<ll, ll, ll>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
const int N = 2e5 + 5, M = 4e5 + 5;
 
int ne, head[N], nxt[M], to[M];
bool bud[N], leaf[N];
 
void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    memset(bud, 0, n * sizeof(bud[0]));
    memset(leaf, 0, n * sizeof(bud[0]));
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
    bool hasLeaves = 0;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(v == par) continue;
        dfs(v, u);
        if(leaf[v]) hasLeaves = 1;
    }
    if(u){
        if(hasLeaves) bud[u] = 1;
        else leaf[u] = 1;
    }
}
 
void solve(){
    int n; cin >> n;
    initGraph(n);
 
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        addBidirectedEdge(u, v);
    }
 
    dfs(0, -1);
 
    bool hasLeaf = 0;
    for(int k = head[0]; ~k; k = nxt[k]){
        int v = to[k];
        if(leaf[v]) hasLeaf = 1;
    }
 
    int k = 0;
    for (int i = 0; i < n; ++i) {
        k += bud[i];
    }
    cout << n - 2 * k - hasLeaf << endl;
}
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
 
    int TC; cin >> TC;
    for (int i = 1; i <= TC; ++i) {
        solve();
    }
    return 0;
}
 