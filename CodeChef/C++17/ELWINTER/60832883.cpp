#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")

using namespace std;

#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))

using ll = long long;

const int N = 1e5 + 5, M = 6e5 + 5;

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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    initGraph(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        addBidirectedEdge(u, v);
    }
    vector<bool> frozen(n);
    vector<int> current;
    while (q--){
        int type, x; cin >> type >> x;
        if(type != 2) --x;
        if(type == 1){
            if(!frozen[x]){
                frozen[x] = 1;
                current.push_back(x);
            }
        }else if(type == 2){
            for (int i = 0; i < x; ++i) {
                vector<int> next;
                for(auto& u: current){
                    for(int k = head[u]; ~k; k = nxt[k]){
                        int v = to[k];
                        if(frozen[v]) continue;
                        frozen[v] = 1;
                        next.push_back(v);
                    }
                }
                current = next;
                if(next.size() == 0) break;
            }
        }else{
            cout << (frozen[x] ? "YES" : "NO") << endl;
        }
    }
    return 0;
}