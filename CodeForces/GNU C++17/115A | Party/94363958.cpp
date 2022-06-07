#include "bits/stdc++.h"
 
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
 
using namespace std;
 
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define EPS             1e-10
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
const int N = 2e3 + 5, M = 1e5 + 5;
 
int ne, head[N], nxt[M], to[M];
 
void initGraph(int n){ // reset graph
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
 
int mx;
void dfs(int u, int len){
    mx = max(mx, len);
    for(int k = head[u]; ~k; k = nxt[k]){
        int v = to[k];
        dfs(v, len + 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n; cin >> n;
    initGraph(n);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        if(~v) addEdge(i, --v);
    }
    for(int i = 0; i < n; i++)
        dfs(i, 0);
 
    cout << mx + 1;
    return 0;
}