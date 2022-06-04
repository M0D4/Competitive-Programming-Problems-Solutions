#include "bits/stdc++.h"
 using namespace std;
 #define pb              push_back
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const int N = 105, M = 205;
 int n, ne, head[N], nxt[M], to[M], color[M], vis[M], vid, m;
 void initGraph(){
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}
void addEdge(int f, int t, int c){
    to[ne] = t;
    color[ne] = c;
    nxt[ne] = head[f];
    head[f] = ne++;
}
 int dist;
unordered_map<int, bool> mp;
 void dfs(int u, int c){
    if(u == dist) return mp[c], void();
     for(int k = head[u]; ~k; k = nxt[k]){
        if(vis[k] == vid) continue;
         int v = to[k];
        int edgeColor = color[k];
        if(c == -1 || edgeColor == c){
            vis[k] = vis[k ^ 1] = vid;
            dfs(v, edgeColor);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n >> m;
     initGraph();
     while(m--){
        int u, v, c; cin >> u >> v >> c;
        u--, v--;
        addEdge(u, v, c);
        addEdge(v, u, c);
    }
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        u--, v--;
        dist = v;
        vid++;
        dfs(u, -1);
        cout << mp.size() << endl;
        mp.clear();
    }
    return 0;
}