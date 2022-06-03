#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 2e5 + 5, M = 4e5 + 5;

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

vector<int> subtree;

void dfs(int u, int p){
    subtree[u] = 1;
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if(v == p) continue;
        dfs(v, u);
        subtree[u] += subtree[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        int n, m; cin >> n >> m;
        initGraph(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, x; cin >> u >> v >> x;
            --u, --v;
            addBidirectedEdge(u, v, x);
        }
        subtree = vector<int>(n);
        dfs(0, -1);

        ll sum = subtree[0];

        priority_queue<vector<ll>> q;
        q.push({subtree[0], 0, 0, -1});

        int ans = 0;
        while (q.size()){
            auto v = q.top(); q.pop();
            ll sub = v[0], type = v[1], u = v[2], parent = v[3];
            if(type == 1) sum -= sub, ans++;
            if(sum <= m) break;
            if(type == 1) continue;
            for (int k = head[u]; ~k; k = nxt[k]) {
                int v = to[k];
                if(v == parent) continue;
                q.push({subtree[v], cost[k], v, u});
            }
        }

        if (sum > m) cout << "-1\n";
        else cout << ans << endl;
    }
    return 0;
}