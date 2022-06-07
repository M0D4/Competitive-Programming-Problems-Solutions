#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
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
 
const int N = 1e5 + 2, M = 2e5 + 5;
 
int ne, head[N], nxt[M], to[M], color[N];
bool reachable[N];
 
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
 
int root;
vector<int> nodes;
void dfs(int u, int par){
    color[u] = 1;
    if(u != root) reachable[u] = 1;
    nodes.push_back(u);
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(v == par) continue;
        if(!color[v]) dfs(v, u);
        else if(color[v] == 1){
            reachable[v] = 1;
            for(auto &i: nodes) reachable[i] = 1;
            return;
        }
    }
    nodes.pop_back();
    color[u] = 2;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n, m; cin >> n >> m;
    initGraph(n);
 
    while(m--){
        int u, v; cin >> u >> v;
        addBidirectedEdge(--u, --v);
    }
    for(int i = 0; i < n; i++){
        if(!reachable[i]){
            root = i;
            dfs(i, -1);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += (!reachable[i]);
    }
    cout << ans;
    return 0;
}