#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)     memset(x, last, sizeof(x))
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
const int N = 1e3 + 5, M = 2e3 + 5;
 
int ne, head[N], nxt[M], to[M], color[M];
bitset<M> vis;
 
void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}
void addEdge(int f, int t, int c){
    to[ne] = t;
    color[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}
 
void addBidirectedEdge(int u, int v, int c){
    addEdge(u, v, c);
    addEdge(v, u, c);
}
 
int v;
set<int> s;
 
void dfs(int u, int curColor){
    if(u == v) return s.insert(curColor), void ();
 
    for(int k = head[u]; ~k; k = nxt[k]){
        if(vis[k]) continue;
        int vv = to[k];
        if(curColor == -1 || curColor == color[k]) {
            vis[k] = vis[k ^ 1] = 1;
            dfs(vv, color[k]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n, m; cin >> n >> m;
    initGraph(n);
 
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        addBidirectedEdge(--u, --v, c);
    }
    int q; cin >> q;
    while (q--){
        int u; cin >> u >> v;
        --u, --v;
        dfs(u, -1);
        cout << s.size() << endl;
        s.clear();
        vis = bitset<M>(0);
    }
    return 0;
}