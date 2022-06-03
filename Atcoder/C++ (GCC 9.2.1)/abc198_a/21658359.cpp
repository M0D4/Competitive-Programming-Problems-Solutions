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
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;

const int N = 1e5 + 5, M = 2e5 + 5;

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

int f[N];
vector<int> ans;

void dfs(int u, int par){
    if(!f[color[u]]) ans.push_back(u + 1);
    f[color[u]]++;
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if(v == par) continue;
        dfs(v, u);
    }
    f[color[u]]--;
}

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n; cin >> n;
    initGraph(n);

    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        addBidirectedEdge(u, v);
    }

    dfs(0, -1);
    sort(all(ans));
    for(auto &i: ans)
        cout << i << endl;
    return 0;
}