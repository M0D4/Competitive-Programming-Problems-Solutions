#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
const int N = 2e5 + 5, M = 2e5 + 5;
 
int ne, head[N], nxt[M], to[M], depth[N], parent[N];
bool used[N];
 
void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    memset(parent, -1, n * sizeof(parent[0]));
    memset(depth, 0, n * sizeof(depth[0]));
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
 
void dfs(int u){
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}
 
void mark(int u){
    used[u] = 1;
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if (!used[v])
            mark(v);
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC; cin >> TC;
    while(TC--){
        int n, k;
        cin >> n >> k;
        initGraph(n);
 
        for (int i = 1; i < n; ++i) {
            cin >> parent[i];
            parent[i]--;
            addEdge(parent[i], i);
        }
 
        depth[0] = 0;
        dfs(0);
 
        auto solve = [&] (int mid){
            vector<pair<int, int>> order;
            memset(used, 0, n * sizeof(used[0]));
 
            for (int i = 0; i < n; ++i) {
                if (depth[i] > mid)
                    order.push_back({depth[i], i});
            }
 
            sort(all(order), greater<>());
            int cnt = 0;
            for (auto& p: order){
                int d = p.first, u = p.second;
                if (!used[u]){
                    cnt++;
                    int nodes = 1;
                    while (nodes < mid) u = parent[u], ++nodes;
                    mark(u);
                }
            }
            return cnt;
        };
 
        int l = 1, r = n;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (solve(mid) <= k) r = mid - 1;
            else l = mid + 1;
        }
 
        cout << r + 1 << endl;
    }
    return 0;
}