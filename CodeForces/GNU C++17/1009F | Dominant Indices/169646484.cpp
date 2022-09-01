#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
const int N = 1e6 + 5, M = 2e6 + 5;
 
int ne, head[N], nxt[M], to[M], ans[N];
 
void initGraph(int n) {
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}
 
void addEdge(int f, int t) {
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}
 
void addBidirectedEdge(int u, int v) {
    addEdge(u, v);
    addEdge(v, u);
}
 
 
pair<int, vector<int>> dfs(int u, int par) {
    pair<int, vector<int>>  sequence = {0, vector<int>()};
    for (int k = head[u]; ~k; k = nxt[k]) {
        int v = to[k];
        if (v == par) continue;
 
        pair<int, vector<int>> childSequence = dfs(v, u);
 
        if (childSequence.second.size() > sequence.second.size())
            swap(childSequence, sequence);
 
        for (int i = (int)childSequence.second.size() - 1,
                 j = (int)sequence.second.size() - 1; i >= 0; --j, --i) {
            sequence.second[j] += childSequence.second[i];
            if (sequence.second[j] == sequence.second[sequence.first]){
                sequence.first = max(sequence.first, j);
            }
            else if(sequence.second[j] > sequence.second[sequence.first]){
                sequence.first = j;
            }
        }
    }
    sequence.second.push_back(1);
 
    if (sequence.second[sequence.first] == 1) sequence.first = sequence.second.size() - 1;
 
    ans[u] = sequence.second.size() - sequence.first - 1;
 
    return sequence;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
 
    int n;
    cin >> n;
    initGraph(n);
 
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        addBidirectedEdge(u, v);
    }
 
    dfs(0, -1);
 
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}