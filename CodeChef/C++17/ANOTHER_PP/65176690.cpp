#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 2e5 + 5, M = 4e5 + 5, P = 18; //P = log2(N)

int dp[N][P + 2], depth[N], n;

int ne, head[N], nxt[M], to[M], lg[N];
string s;

void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    //clr(dp, -1);
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

vector<vector<int>> f;
void dfs(int u, int parent){
    dp[u][0] = parent;
    if(parent == -1){
        f[u][s[u] - 'a']++;
    }else{
        auto p = f[parent];
        p[s[u] - 'a']++;
        f[u] = p;
    }
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if(v == parent) continue;
        depth[v] = depth[u]+ 1;
        dfs(v, u);
    }
}

vector<int> getFrequency(int u, int lc){
    auto p = f[u];
    for (int i = 0; i < 26; ++i) {
        p[i] -= f[lc][i];
    }
    return p;
}

int lca(int u, int v){
    if(depth[u] < depth[v])
        swap(u, v);

    for (int k = lg[n]; k >= 0; --k) {
        if(depth[u] - (1 << k) >= depth[v]){
            u = dp[u][k];
        }
    }
    if(u == v) return v;

    for (int k = lg[n]; k >= 0; --k) {
        if(dp[u][k] != dp[v][k]){
            u = dp[u][k];
            v = dp[v][k];
        }
    }
    return dp[u][0];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    lg[1] = 0, lg[2] = 1;
    for (int i = 3; i < N; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    int TC; cin >> TC;
    while(TC--){
        cin >> n;
        initGraph(n);
        cin >> s;
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            --u, --v;
            addBidirectedEdge(u, v);
        }
        for (int k = 1; k <= lg[n]; ++k) {
            for (int u = 0; u < n; ++u) {
                dp[u][k] = -1;
            }
        }
        f = vector<vector<int>> (n, vector<int> (26));
        dfs(0, -1);
        for (int k = 1; k <= lg[n]; ++k) {
            for (int u = 0; u < n; ++u) {
                if(dp[u][k - 1] == -1) continue;
                dp[u][k] = dp[dp[u][k - 1]][k - 1];
            }
        }
        int q; cin >> q;
        while (q--){
            int u, v; cin >> u >> v;
            --u, --v;
            bool ok = 0;
            int lc = lca(u, v);
            for (int j = 0; j < 26 && !ok; ++j) {
                if(f[u][j] - f[lc][j] && f[v][j] - f[lc][j])
                    ok = 1;
            }
            cout << (ok ? "YES" : "NO") << endl;
        }
    }
    return 0;
}