#include "bits/stdc++.h"
 #pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
  const int N = 1e5 + 2, M = 2e5 + 5;
 int ne, head[N], nxt[M], to[M], cost[M], par[N];
ll dis[N];
 void initGraph(int n){ // reset graph
    memset(head, -1, n * sizeof(head[0]));
    memset(dis, -1, n * sizeof(dis[0]));
    memset(par, -1, n * sizeof(par[0]));
    ne = 0;
}
void addEdge(int f, int t, int c){
    to[ne] = t;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}
 void addBidirectedEdge(int u, int v, int c){
    addEdge(u, v, c);
    addEdge(v, u, c);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n, m; cin >> n >> m;
    initGraph(n);
     while(m--){
        int u, v, c; cin >> u >> v >> c;
        addBidirectedEdge(--u, --v, c);
    }
     dis[0] = 0;
    set<pair<ll, int>> s;
    s.insert({0, 0}); // cost, u
     while(s.size()){
        pair<ll, int> p = *s.begin(); s.erase(s.begin());
        int u = p.second; ll d = p.first;
        if(~dis[u] && dis[u] < d) continue;
        dis[u] = d;
        for(int k = head[u]; ~k; k = nxt[k]){
            int v = to[k];
            if(~dis[v] && dis[v] <= dis[u] + cost[k]) continue;
            s.insert({dis[v] = dis[u] + cost[k], v});
            par[v] = u;
        }
    }
    if(~dis[n - 1]){
        vector<int> path;
        int u = n - 1;
        while(~par[u]) path.push_back(u), u = par[u];
        path.push_back(0);
        reverse(all(path));
        for(auto &i: path) cout << i + 1 << " ";
     }else cout << -1;
    return 0;
}