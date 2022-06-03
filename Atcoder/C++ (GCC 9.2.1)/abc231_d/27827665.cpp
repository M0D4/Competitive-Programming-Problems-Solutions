#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 1e5 + 5;
vector<vector<int>> adj(N);

bool vis[N];
bool valid;
void dfs(int u, int par){
    vis[u] = 1;
    for(auto& v: adj[u]){
        if(v == par) continue;
        if(vis[v]){
           valid = 0;
            return;
        }
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m; cin >> n >> m;
    int f[n + 3] = {};
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        f[x]++;
        f[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if(f[i] > 2)
            return cout << "No", 0;
    }
    valid = 1;
    for (int i = 1; i <= n; ++i) {
        if(!vis[i])
            dfs(i, -1);
    }
    cout << (valid ? "Yes" : "No");
    return 0;
}