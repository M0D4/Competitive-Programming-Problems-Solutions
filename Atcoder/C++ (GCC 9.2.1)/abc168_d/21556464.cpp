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
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;


const int N = 1e5 + 5, M = 4e5 + 5;

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

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m; cin >> n >> m;
    initGraph(n);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        addBidirectedEdge(u, v);
    }

    int ans[n];
    clr(ans, -1);

    queue<int> q;
    q.push(0);

    while (q.size()){
        int u = q.front(); q.pop();
        for(int k = head[u]; ~k; k = nxt[k]){
            int v = to[k];
            if(~ans[v]) continue;
            ans[v] = u;
            q.push(v);
        }
    }

    for (int i = 1; i < n; ++i) {
        if(~ans[i]) continue;
        return cout << "No", 0;
    }

    cout << "Yes\n";
    for (int i = 1; i < n; ++i) {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}