#include "bits/stdc++.h"


#pragma GCC optimize("Ofast")


using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x

const int N = 2e5 + 5, M = 4e5 + 5;

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

int nodes[N];
ll sum[N];

int dfs(int u, int par){
    int cnt = 1;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(v == par) continue;
        cnt += dfs(v, u);
    }
    return nodes[u] = cnt;
}

ll getSum(int u, int par, int d){
    ll s = 0;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(v == par) continue;
        s += getSum(v, u, d + 1);
    }
    return s + d;
}

int n;

void dfs2(int u, int par){
    if(~par){
        sum[u] = sum[par] + (n - nodes[u] - 1) - (nodes[u] - 1);
    }

    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(v == par) continue;
        dfs2(v, u);
    }
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    initGraph(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        addBidirectedEdge(u, v);
    }
    dfs(0, -1);

    sum[0] = getSum(0, -1, 0);

    dfs2(0, -1);

    for (int i = 0; i < n; ++i) {
        cout << sum[i] << endl;
    }
    return 0;
}

