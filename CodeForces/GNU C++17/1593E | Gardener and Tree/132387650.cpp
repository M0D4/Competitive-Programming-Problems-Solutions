#include "bits/stdc++.h"
  #pragma GCC optimize("Ofast")
  using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
  ///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 const int N = 4e5 + 5, M = 8e5 + 5;
 int ne, head[N], nxt[M], to[M], degree[N];
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
 int main() {
     ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while (tc--){
        int n, m; cin >> n >> m;
        initGraph(n);
         for (int i = 0; i < n; ++i) {
            degree[i] = 0;
        }
         for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            --u, --v;
            degree[u]++, degree[v]++;
            addBidirectedEdge(u, v);
        }
         int ans = n;
        vector<int> ready;
        for (int i = 0; i < n; ++i) {
            if(degree[i] == 1) ready.push_back(i);
        }
         while (m && ready.size()) {
            --m;
            vector<int> next;
            for(auto& u: ready){
                --ans;
                for(int k = head[u]; ~k; k = nxt[k]){
                    int v = to[k];
                    degree[v]--;
                    if(degree[v] == 1) next.push_back(v);
                }
            }
            ready = next;
        }
        if(m) ans = 0;
         cout << ans << endl;
    }
    return 0;
}
 