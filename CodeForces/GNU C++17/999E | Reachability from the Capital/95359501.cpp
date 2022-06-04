#include "bits/stdc++.h"
 #pragma GCC optimize("trapv")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const int N = 5e3 + 2, M = 1e5 + 5;
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
 bool reachable[N], vis[N];
 void dfs1(int u){
    reachable[u] = 1;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(!reachable[v])
            dfs1(v);
    }
}
 int c;
 void dfs2(int u){
    vis[u] = 1;
    c++;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(!vis[v] && !reachable[v])
            dfs2(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n, m, s; cin >> n >> m >> s;
    initGraph(n);
     --s;
    while(m--){
        int u, v; cin >> u >> v;
        addEdge(--u, --v);
    }
      dfs1(s);
     priority_queue<pii> pq; //mxNodes, u
    for(int i = 0; i < n; i++){
        if(!reachable[i]){
            c = 0;
            fill(vis, vis + n, 0);
            dfs2(i);
            pq.push({c, i});
        }
    }
     int extraEdges = 0;
    while(pq.size()){
        int u = pq.top().second; pq.pop();
        if(reachable[u]) continue;
        extraEdges++;
        dfs1(u);
    }
    cout << extraEdges;
    return 0;
}