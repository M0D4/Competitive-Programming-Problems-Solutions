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
 
const int N = 2e5 + 5, M = 2e5 + 5;
 
int ne, head[N], nxt[M], to[M], last[N], index[N];
 
 
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
 
vector<int> order;
void dfs(int u){
    order.push_back(u);
    last[u] = u;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        q.push(v);
    }
    while(q.size()){
        int v = q.top(); q.pop();
        dfs(v);
        last[u] = last[v];
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n, q; cin >> n >> q;
    initGraph(n + 1);
 
    for(int v = 2; v <= n; v++){
        int u; cin >> u;
        addEdge(u, v);
    }
    dfs(1);
    for(int i = 0; i < n; i++){
        int u = order[i];
        index[u] = i + 1;
    }
    while(q--){
        int u, k; cin >> u >> k;
        int len = index[last[u]] - index[u] + 1;
        if(k > len) cout << "-1\n";
        else{
            cout << order[index[u] + k - 2] << endl;
        }
    }
    return 0;
}