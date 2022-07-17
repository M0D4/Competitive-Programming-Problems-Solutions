//testing
 
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e3 + 5, M = 1e5 + 5, mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
double eps = 1e-8;
int head[N], nxt[M], to[M], ne;
bool vis[N];
int n, m;
void init() {
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    ne = 0;
}
void addEdge(int f, int t) {
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}
void addBiEdge(int u, int v) {
    addEdge(u, v);
    addEdge(v, u);
}
void dfs(int u) {
    vis[u] = 1;
    for (int e = head[u]; ~e; e = nxt[e]) {
        int v = to[e];
        if (!vis[v])
            dfs(v);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> m;
    int ans = 0;
    set<int>st ;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            ans++;
            continue;
        }
        for (int j = 0; j < x; ++j) {
            int v;
            cin >> v;
            st.insert(i);
            addBiEdge(i, v + 100);
        }
    }
 
    for (int i = 0; i < n; ++i) {
        if (!vis[i] and st.find(i) != st.end())
            dfs(i), ++ans;
    }
    cout << ans - 1 + st.empty() << endl;
}