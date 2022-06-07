#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
 
 
 
const int N = 1e2 + 5, M = 1e3 + 5;
 
int ne, head[N], to[M], nxt[M];
 
void initGraph(int n){
    memset(head, -1, n * sizeof(head[0]));
    ne = 0;
}
 
void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}
 
int n;
vector<ll> v;
 
void dfs(int u){
    v.push_back(u);
    for(int k = head[u]; ~k; k = nxt[k]){
        dfs(to[k]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    cin >> n;
    ll a[n];
    for(auto &i: a) cin >> i;
 
    initGraph(n);
 
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] == 2 * a[j])
                addEdge(i, j);
            else if(2 * a[i] == a[j])
                addEdge(j, i);
            else if(a[i] == 3 * a[j])
                addEdge(j, i);
            else if(3 * a[i] == a[j])
                addEdge(i, j);
        }
    }
    for(int i = 0; i < n; i++){
        dfs(i);
        if(v.size() == n) break;
        v.clear();
    }
 
    reverse(all(v));
    for(auto &i: v) cout << a[i] << " ";
    return 0;
}