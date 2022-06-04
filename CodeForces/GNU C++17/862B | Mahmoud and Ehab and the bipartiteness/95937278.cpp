#include "bits/stdc++.h"
 #pragma GCC optimize("trapv")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
 using namespace std;
 #define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
  const int N = 1e5 + 2, M = 2e5 + 5;
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
 void addBidirectedEdge(int u, int v){
    addEdge(u, v);
    addEdge(v, u);
}
 ll zero, one;
 void dfs(int u, int par, int color){
    (color ? one++ : zero++);
     for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        if(v != par) dfs(v, u, color ^ 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int n; cin >> n;
    initGraph(n);
    int m = n - 1;
    while(m--){
        int u, v; cin >> u >> v;
        addBidirectedEdge(--u, --v);
    }
    dfs(0, -1, 0);
    cout << zero * one - (n - 1);
    return 0;
}