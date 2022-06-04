#include <bits/stdc++.h>
 using namespace std;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
  typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const ll N = 5e3 + 5, inf = 1e15, M = 1e4;
ll pfx[M], dp[N][N];
int a[N];
int n, m, k;
ll solve(int i, int take){
    if(i>=n+1) return take == k? 0 : -inf;
     ll &ret = dp[i][take];
    if(~ret) return ret;
     ret = solve(i+1, take);
    if(i + m <= n+1) ret = max(ret, pfx[i + m - 1] - pfx[i - 1] + solve(i + m, take + 1));
     return ret;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);
    cin>>n>>m>>k;
    for(int i = 1; i<=n; i++) cin>>a[i], pfx[i] = pfx[i - 1] + a[i];
    clr(dp, -1);
    cout<<solve(1, 0);
    return 0;
}