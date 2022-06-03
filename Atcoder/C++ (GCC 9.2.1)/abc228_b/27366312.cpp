#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 1e5 + 5, M = 2e5 + 5;

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

bool vis[N];

void dfs(int u){
    vis[u] = 1;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(vis[v]) continue;
        dfs(v);
    }
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, x; cin >> n >> x;

    initGraph(n);

    for (int i = 0; i < n; ++i) {
        int y; cin >> y;
        addEdge(i, y - 1);
    }
    dfs(x - 1);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += vis[i];
    }
    cout << cnt;
    return 0;
}