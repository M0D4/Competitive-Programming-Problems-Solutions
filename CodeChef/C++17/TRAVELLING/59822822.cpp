#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 2e5 + 5, M = 4e5 + 5 + 2 * N;

int ne, head[N], nxt[M], to[M], cost[M];

void initGraph(int n){
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

void dfs(vector<bool> &vis, int u, int par, int& mx){
    vis[u] = 1;
    mx = max(mx, u);
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(v != par && !vis[v])
            dfs(vis, v, u, mx);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int n, m; cin >> n >> m;
        initGraph(n);
        vector<bool> hasEdge(n);
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            --u, --v;
            if(abs(u - v) == 1)
                hasEdge[min(u, v)] = 1;
            addBidirectedEdge(u, v, 0);
        }
        for (int i = 0; i < n - 1; ++i) {
            if(!hasEdge[i])
                addBidirectedEdge(i, i + 1, 1);
        }
        priority_queue<pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>> q;
        vector<int> dis(n, -1);
        q.push({0, 0});

        while (!q.empty()){
            int u, d;
            tie(d, u) = q.top();
            q.pop();

            if(~dis[u] && dis[u] <= d) continue;
            dis[u] = d;
            for(int k = head[u]; ~k; k = nxt[k]){
                int v = to[k];
                if(~dis[v] && cost[k] + d >= dis[v]) continue;
                q.push({cost[k] + d, v});
            }
        }
        cout << dis[n - 1] << endl;
    }
    return 0;
}