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
using pii = pair<ll, int>;
using tii = tuple<ll, int, int>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
const int N = 1e5 + 5, M = 8e5 + 5;
 
int ne, head[N], nxt[M], to[M], cost[M], type[M];
 
void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}
 
void addEdge(int f, int t, int c, int ty){
    to[ne] = t;
    type[ne] = ty;
    cost[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}
 
void addBidirectedEdge(int u, int v, int c, int t){
    addEdge(u, v, c, t);
    addEdge(v, u, c, t);
}
 
 
 
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
 
 
    int n, m, t; cin >> n >> m >> t;
    initGraph(n);
 
    for (int i = 0; i < m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        --u, --v;
        addBidirectedEdge(u, v, c, 0);
    }
 
    for (int i = 0; i < t; ++i) {
        int u, c; cin >> u >> c;
        --u;
        addBidirectedEdge(0, u, c, 1);
    }
 
    ll dis[n];
    clr(dis, 0x3f);
 
    priority_queue<tii, vector<tii>, greater<tii>> q;
    q.push({0, 0, 0});
 
    int cnt = t;
 
    while (!q.empty()){
        ll u, c, t;
        tie(c, t, u) = q.top();
        q.pop();
 
        if(dis[u] <= c) continue;
        dis[u] = c;
        if(t == 1) cnt--;
 
        for(int k = head[u]; ~k; k = nxt[k]){
            int v = to[k];
            if(dis[v] <= dis[u] + cost[k]) continue;
            q.push({dis[u] + cost[k], type[k], v});
        }
    }
 
    cout << cnt;
    return 0;
}
 