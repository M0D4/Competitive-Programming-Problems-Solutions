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
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const int N = 1e3 + 2, M = 1e5 + 5;
 int ne, head[N], nxt[M], to[M], cost[M], f[M], dis[N][N];
bool vis[N];
void initGraph(int n){ // reset graph
    memset(head, -1, n * sizeof(head[0]));
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
int n;
void Dijkstra(int s){
    if(vis[s]) return;
    vis[s] = 1;
     priority_queue<pii, vector<pii>, greater<pii>> q;
     q.push({0, s});//cost, node
     for(int i = 0; i < n; i++)
        dis[s][i] = 1e9;
     dis[s][s] = 0;
    while(q.size()){
        int u = q.top().second, d = q.top().first; q.pop();
         if(dis[s][u] < d) continue;
         dis[s][u] = d;
         for(int k = head[u]; ~k; k = nxt[k]){
            int v = to[k];
            if(dis[s][v] <= dis[s][u] + cost[k]) continue;
            q.push({dis[s][u] + cost[k], v});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int m, kk; cin >> n >> m >> kk;
     initGraph(n);
     while(m--){
        int u, v, c; cin >> u >> v >> c;
        addBidirectedEdge(--u, --v, c);
    }
     vector<pii> query;
    for(int i = 0; i < kk; i++){
        int s, e; cin >> s >> e;
        --s, --e;
        query.push_back({s, e});
        Dijkstra(s);
        Dijkstra(e);
    }
    ll mn = INT_MAX;
    for(int node = 0; node < n; node++){
       for(int k = head[node]; ~k; k = nxt[k]){ //delete edge(node, child)
            int child = to[k];
            ll sum = 0;
            for(int i = 0; i < kk; i++){
                int s, e; tie(s, e) = query[i];
                sum += min({dis[s][e], dis[s][node] + dis[e][child]
                                     , dis[s][child] + dis[e][node]});
            }
            mn = min(mn, sum);
       }
    }
    cout << mn;
    return 0;
}