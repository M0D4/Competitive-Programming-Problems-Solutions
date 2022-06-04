#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cerr << #x << " is " << x << endl;
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 const int N = 1e5 + 5, M = 2e5 + 5;
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
 int m;
bitset<N> hasCat, vis;
int cnt;
 void dfs(int u, int cats){
    vis[u] = 1;
    if(cats > m) return;
    int unvisited = 0;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(vis[v]) continue;
        dfs(v, hasCat[v] ? cats + 1 : 0);
        unvisited++;
    }
    if(!unvisited) cnt++;
}
 int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
     int n; cin >> n >> m;
    initGraph(n);
     for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        hasCat[i] = x;
    }
     for (int i = 0; i + 1 < n; ++i) {
        int u, v; cin >> u >> v;
        addBidirectedEdge(--u, --v);
    }
    dfs(0, hasCat[0]);
    cout << cnt;
    return 0;
}