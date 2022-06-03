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

const int N = 2e5 + 5, M = 2e5 + 5;

int ne, head[N], nxt[M], to[M], out[N];

void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}

void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}


int main() {

    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m; cin >> n >> m;
    initGraph(n);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        out[v]++;
        addEdge(u, v);
    }
    priority_queue<int, vector<int>, greater<int>> ready;
    for (int i = 0; i < n; ++i) {
        if(out[i] == 0) ready.push(i);
    }

    vector<int> ans;
    while (ready.size()){
        while (ready.size()){
            int u = ready.top(); ready.pop();
            ans.push_back(u);
            for(int k = head[u]; ~k; k = nxt[k]){
                int v = to[k];
                out[v]--;
                if(out[v] == 0) ready.push(v);
            }
        }
    }
    if(ans.size() != n) return cout << -1, 0;

    for(auto& i: ans) cout << i + 1 << " ";
    return 0;
}

