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

const int N = 400 + 5, M = 400 * 399 + 5;

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

set<pair<int, int>> path;

int bfs(int n, int e){
    int dis[n];
    clr(dis, -1);
    dis[0] = 0;
    queue<int> q;
    q.push(0);

    int par[n];
    par[0] = -1;

    while (!q.empty()){
        int u = q.front();
        q.pop();

        if(u == n - 1) break;

        for(int k = head[u]; ~k; k = nxt[k]){
            int v = to[k];
            if(k == e) continue;
            if(~dis[v] && dis[v] <= dis[u] + 1) continue;
            dis[v] = dis[u] + 1;
            par[v] = u;
            q.push(v);
        }
    }

    if(e == -1 && ~dis[n - 1]){
        int u = n - 1;
        while (~par[u]){
            path.insert({par[u], u});
            u = par[u];
        }
    }

    return dis[n - 1];
}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, m; cin >> n >> m;
    initGraph(n);

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        edges.push_back({u, v});
        addEdge(u, v);
    }

    int d = bfs(n, -1);

    for (int i = 0; i < m; ++i) {
        int u = edges[i].first, v = edges[i].second;
        if(!path.count({u, v})) cout << d << endl;
        else{
            cout << bfs(n, i) << endl;
        }
    }
    return 0;
}

