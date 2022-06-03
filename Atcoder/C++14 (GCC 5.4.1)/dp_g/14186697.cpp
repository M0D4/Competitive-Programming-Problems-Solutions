#include <bits/stdc++.h>

/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/

using namespace std;

#define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
#define LSOne(x)  (x & (-x))   //least significant 1
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 1;
vector<vi> adj(N);
bool vis[N];
int dp[N];
void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i<sz(adj[u]); i++){
        int v = adj[u][i];
        if(!vis[v])
            dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    int n, m; cin>>n>>m;

    for(int i = 0; i<m; i++){
        int u, v; cin>>u>>v;
        adj[u].pb(v);
    }
    int mx = 0;
    for(int i = 1; i<=n; i++)
        if(!vis[i] && sz(adj[i]))
            dfs(i);

    cout<<*max_element(dp, dp+N);
	return 0;
}
