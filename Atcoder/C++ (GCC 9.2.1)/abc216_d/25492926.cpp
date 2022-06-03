#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"

#define all(v)          v.begin(), v.end()

#define debug(x)        cout << #x << " is " << x << endl

#define pow(n, m)       (ll)powl(n, m)

#define Unique(x)       x.erase(unique(all(x)), x.end())

#define clr(x, last)    memset(x, last, sizeof(x))

using ll = long long;

using pii = pair<int, int>;

using pic = pair<int, char>;

using tii = tuple<int, int, int>;

///Intermediate Overflow!!! (1 << i), x * y, 2 * x

const int N = 4e5 + 5, M = 1e6 + 5;

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

int color[N];

bool dfs(int u){

    color[u] = 1;

    for(int k = head[u]; ~k; k = nxt[k]){

        int v = to[k];

        if(color[v] == 1) return 0;

        if(color[v] == 0) if(!dfs(v)) return 0;

    }

    color[u] = 2;

    return 1;

}

int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m; cin >> n >> m;

    initGraph(2 * n);

    for (int i = 0; i < m; ++i) {

        int k; cin >> k;

        int u;

        for (int j = 0; j < k; ++j) {

            int v; cin >> v;

            if(j) addEdge(u, v);

            u = v;

        }

    }

    bool ok = 1;

    for (int i = 1; i <= n; ++i) {

        if(color[i] == 0) ok &= dfs(i);

    }

    cout << (ok ? "Yes" : "No");

    return 0;

}