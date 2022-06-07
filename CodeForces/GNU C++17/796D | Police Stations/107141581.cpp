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
 
const int N = 3e5 + 5, M = 6e5 + 5;
bitset<M> visEdge;
 
int ne, head[N], nxt[M], to[M], id[M];
 
void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}
 
void addEdge(int f, int t, int i){
    to[ne] = t;
    id[ne] = i;
    nxt[ne] = head[f];
    head[f] = ne++;
}
 
void addBidirectedEdge(int u, int v, int i){
    addEdge(u, v, i);
    addEdge(v, u, i);
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int n, p, d; cin >> n >> p >> d;
    initGraph(n);
 
    queue<int> q;
    int dis[n]; clr(dis, -1);
 
    for (int i = 0; i < p; ++i) {
        int x; cin >> x;
        --x;
        q.push(x);
        dis[x] = 0;
    }
 
    for (int i = 0; i + 1 < n; ++i) {
        int u, v; cin >> u >> v;
        addBidirectedEdge(--u, --v, i);
    }
 
    while (q.size()){
        int u = q.front(); q.pop();
        if(dis[u] == d) break;
 
        for(int k = head[u]; ~k; k = nxt[k]){
            int v = to[k];
            if(~dis[v] || visEdge[k]) continue;
            visEdge[k] = visEdge[k ^ 1] = 1;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
 
    vector<int> ans;
    for (int k = 0; k < ne; ++k) {
        if(!visEdge[k]){
            ans.push_back(id[k]);
            visEdge[k] = visEdge[k ^ 1] = 1;
        }
    }
 
    cout << ans.size() << endl;
    for(auto& i: ans) cout << i + 1 << " ";
    return 0;
}