#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
  using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  struct DSU{
     const static int N = 2e3 + 5; //nodes
     int parent[N], groupSize[N];
    int groupCnt;
     DSU(int n){
        groupCnt = n;
        for(int i = 0; i < n; i++){
            parent[i] = i;
            groupSize[i] = 1;
        }
    }
     int findLeader(int i){
        if(parent[i] == i) return i;
         return parent[i] = findLeader(parent[i]);
    }
     bool sameGroup(int x, int y){
        return findLeader(x) == findLeader(y);
    }
     void mergeGroups(int x, int y){//merge to one component
        int leaderX = findLeader(x);
        int leaderY = findLeader(y);
         if(leaderX == leaderY) return;
         groupCnt--;
         if(groupSize[leaderX] > groupSize[leaderY]){
            parent[leaderY] = leaderX;
            groupSize[leaderX] += groupSize[leaderY];
        }else{
            parent[leaderX] = leaderY;
            groupSize[leaderY] += groupSize[leaderX];
        }
    }
     int getSize(int x){//size of group
        return groupSize[findLeader(x)];
    }
};
 const int N = 2e3 + 5, M = 8e6 + 5, P = 12;
 int ne, head[N], nxt[M], to[M], a[N][N],
dp[N][P + 2], depth[N], cost[M];
ll  dis[N][P + 2];
 void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    clr(dp, -1);
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
 void dfs(int u, int parent){
    dp[u][0] = parent;
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(v == parent) continue;
        dis[v][0] = cost[k];
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}
 ll calcDis(int u, int v){
    if(depth[u] < depth[v])
        swap(u, v);
     ll ans = 0;
    for (int k = P; k >= 0; --k) {
        if(depth[u] - (1 << k) >= depth[v]){
            ans += dis[u][k];
            u = dp[u][k];
        }
    }
     if(u == v) return ans;
     for (int k = P; k >= 0; --k) {
        if(dp[u][k] != dp[v][k]){
            ans += dis[u][k];
            ans += dis[v][k];
            u = dp[u][k];
            v = dp[v][k];
        }
    }
     return ans + dis[u][0] + dis[v][0];
}
  int n, m;
void Kruskal(){
    vector<tuple<int, int, int>> edgeList;
    DSU dsu(n);
    for(int i = 0; i < n; i++){
        for (int j = i + 1; j < n; ++j) {
            edgeList.push_back({a[i][j], i, j});
            edgeList.push_back({a[i][j], j, i});
        }
    }
    m = edgeList.size();
    sort(all(edgeList));//sort by w
     for(int i = 0; i < m; i++){
        int w, u, v; tie(w, u, v) = edgeList[i];
        if(!dsu.sameGroup(u, v)){//will not cause a cycle
            addBidirectedEdge(u, v, w);
            dsu.mergeGroups(u, v);
        }
    }
}
  int main()
{
    //ios_base::sync_with_stdio(false), cin.tie(nullptr);
     scanf("%d", &n);
    initGraph(n);
     for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            if(i == j && a[i][j] != 0)
                return puts("NO"), 0;
        }
    }
     for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(a[i][j] != a[j][i] || a[i][j] == 0)
                return puts("NO"), 0;
        }
    }
     Kruskal();
     dfs(0, -1);
     dis[0][0] = -1;
    for (int k = 1; k <= P; ++k) {
        for (int u = 0; u < n; ++u) {
            if(dp[u][k - 1] == -1){
                continue;
            }
            dp[u][k] = dp[dp[u][k - 1]][k - 1];
            dis[u][k] = dis[u][k - 1] + dis[dp[u][k - 1]][k - 1];
        }
    }
     for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(calcDis(i, j) != a[i][j]) {
                return puts("NO"), 0;
            }
        }
    }
     puts("YES");
    return 0;
}