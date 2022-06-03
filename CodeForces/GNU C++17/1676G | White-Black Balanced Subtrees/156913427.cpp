#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
 const int N = 4000 + 5, M = 4000 + 5;
 int ne, head[N], nxt[M], to[M], color[N];
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
 vector<int> dfs(int u){
    vector<int> f(3);
    f[color[u]] = 1;
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        auto curr = dfs(v);
        for (int i = 0; i < 3; ++i) {
            f[i] += curr[i];
        }
    }
    if(f[0] == f[1]) f[2]++;
    return f;
}
 int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        initGraph(n);
         for (int i = 1; i < n; ++i) {
            int v; cin >> v;
            --v;
            addEdge(v, i);
        }
        for (int i = 0; i < n; ++i) {
            char c; cin >> c;
            color[i] = (c == 'W');
        }
         auto ans = dfs(0);
        cout << ans[2] << endl;
    }
    return 0;
}