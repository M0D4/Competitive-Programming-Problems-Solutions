#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
 const int N = 2e5 + 5, M = 2e5 + 5;
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
 vector<vector<int>> paths;
vector<int> path;
void dfs(int u){
    path.push_back(u + 1);
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        dfs(v);
        if(path.size()) paths.push_back(path);
        path.clear();
    }
}
 int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        initGraph(n);
        paths.clear();
        int root;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            --x;
            if(x == i) root = x;
            else addEdge(x, i);
        }
        if(n == 1){
            cout << "1\n1\n1\n\n";
            continue;
        }
        path.clear();
        dfs(root);
        cout << paths.size() << endl;
        for(auto& path: paths){
            cout << path.size() << endl;
            for(auto& u: path) cout << u << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}