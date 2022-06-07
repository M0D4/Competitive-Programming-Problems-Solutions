#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)          v.begin(), v.end()
#define pb              push_back
#define sz(x)          (int) (x.size())
#define endl            "\n"
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int N = 105;
vector<vector<int>> ad(N);
vector<int> vis(N), team(N);
int n, m, del;
void dfs(int u, int parent, int t){
 
    vis[u] = 1;
    team[u] = t;
    for(auto &ch : ad[u]){
        if(ch == parent) continue;
        if(!vis[ch]) dfs(ch, u, !t);
        if(team[ch] == team[u]){
                del++;
                return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m;
    while(m--){
        int u, v; cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1, 0);
        }
    }
    del /= 2;
    int ans = n - del;
    if(isOdd(ans)) del++;
    cout << del;
    return 0;
}