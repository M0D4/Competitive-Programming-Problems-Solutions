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

int dp[N][P + 2], depth[N], freq[N][P + 2][26];

int ne, head[N], nxt[M], to[M];
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



void dfs(int u, int parent){
    dp[u][0] = parent;
    freq[u][0][s[u] - 'a'] = 1;
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if(v == parent) continue;
        depth[v] = depth[u]+ 1;
        dfs(v, u);
    }
}

int calculateDis(int u, int v, char c){
    if(depth[u] < depth[v])
        swap(u, v);

    int ans = 0;
    for (int k = P; k >= 0; --k) {
        if(depth[u] - (1 << k) >= depth[v]){
            ans += freq[u][k][c - 'a'];
            u = dp[u][k];
        }
    }
    if(u == v) return ans;

    for (int k = P; k >= 0; --k) {
        if(dp[u][k] != dp[v][k]){
            ans += freq[u][k][c - 'a'];
            ans += freq[v][k][c - 'a'];
            u = dp[u][k];
            v = dp[v][k];
        }
    }

    return ans + freq[u][0][c - 'a'] + freq[v][0][c - 'a'];
}

int lca(int u, int v){
    if(depth[u] < depth[v])
        swap(u, v);

    for (int k = P; k >= 0; --k) {
        if(depth[u] - (1 << k) >= depth[v]){
            u = dp[u][k];
        }
    }
    if(u == v) return v;

    for (int k = P; k >= 0; --k) {
        if(dp[u][k] != dp[v][k]){
            u = dp[u][k];
            v = dp[v][k];
        }
    }
    return dp[u][0];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        initGraph(n);
        cin >> s;
        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            --u, --v;
            addBidirectedEdge(u, v);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < P + 2; ++j) {
                for (int k = 0; k < 26; ++k) {
                    freq[i][j][k] = 0;
                }
            }
        }
        for (int k = 1; k <= P; ++k) {
            for (int u = 0; u < n; ++u) {
                dp[u][k] = -1;
            }
        }
        dfs(0, -1);
        for (int k = 1; k <= P; ++k) {
            for (int u = 0; u < n; ++u) {
                if(dp[u][k - 1] == -1) continue;
                dp[u][k] = dp[dp[u][k - 1]][k - 1];
                for (int i = 0; i < 26; ++i) {
                    freq[u][k][i] = freq[u][k - 1][i] + freq[dp[u][k - 1]][k - 1][i];
                }
            }
        }
        int q; cin >> q;
        while (q--){
            int u, v; cin >> u >> v;
            --u, --v;
            bool ok = 0;
            int lc = lca(u, v);
            for (int i = 0; i < 26 && !ok; ++i) {
                int l = calculateDis(u, lc, i + 'a');
                int r = calculateDis(v, lc, i + 'a');
                if(l && r)
                    ok = 1;
            }
            cout << (ok ? "YES" : "NO") << endl;
        }
    }
    return 0;
}