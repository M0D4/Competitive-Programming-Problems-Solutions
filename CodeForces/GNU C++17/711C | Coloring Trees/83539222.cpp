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
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const ll N = 101, OO = 1e15;
int n, m, k;
ll dp[N][N][N];
int color[N];
int cost[N][N];
ll solve(int i, int beauty, int lastCol){
    if(i==n) return beauty==k? 0 : OO;
     ll &ret = dp[i][beauty][lastCol];
    if(~ret) return ret;
     ret = OO;
    if(color[i]) ret = min(ret, solve(i+1, beauty + (color[i]!=lastCol), color[i]));
    else{
        for(int j = 1; j<=m; j++){
            ret = min(ret, cost[i][j-1] + solve(i+1, beauty + (j != lastCol), j));
        }
    }
     return ret;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    cin>>n>>m>>k;
    for(int i = 0; i<n; i++) cin>>color[i];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin>>cost[i][j];
     clr(dp, -1);
    ll mn = solve(0, 0, 0);
    if(mn >= OO) mn = -1;
    cout<<mn;
 return 0;
}