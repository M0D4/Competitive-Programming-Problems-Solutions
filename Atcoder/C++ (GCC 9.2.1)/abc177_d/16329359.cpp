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


const int N = 2e5 + 5, M = 4e5 + 5;

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

int c = 0;
void dfs(int u){
    vis[u] = 1;
    c++;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(!vis[v]) dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, mx = 0; cin >> n >> m;
    initGraph(n);
    while(m--){
        int u, v; cin >> u >> v;
        u--, v--;
        addEdge(u, v);
        addEdge(v, u);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            c = 0;
            dfs(i);
            mx = max(mx, c);
        }
    }
    cout << mx;
    return 0;
}
