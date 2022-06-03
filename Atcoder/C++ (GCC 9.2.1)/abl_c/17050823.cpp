#include "bits/stdc++.h"

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

const int N = 1e5 + 2, M = 3e5 + 5;

int ne, head[N], nxt[M], to[M], vis[N];

void initGraph(int n){ // reset graph
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

void dfs(int u){
    vis[u] = 1;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(!vis[v]) dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m; cin >> n >> m;

    initGraph(n);

    while(m--){
        int u, v; cin >> u >> v;
        v--, u--;
        addBidirectedEdge(u, v);
    }
    int comp = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
            comp++;
        }
    }

    cout << comp - 1;
    return 0;
}
