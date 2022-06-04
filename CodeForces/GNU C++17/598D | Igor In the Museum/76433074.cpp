#include <bits/stdc++.h>
#include <ext/numeric>
 using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define MOD 1000000007
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;
 const int N = 1000;
char arr[N][N];
bool vis[N][N];
bool vis2[N][N];
ll dp[N][N];
ll res[N][N];
int n, m, k;
bool valid(int r, int c){
    return r>=0 && r<n && c>=0 && c<m;
}
ll solve(int r, int c){
     if(!valid(r, c) || vis[r][c]|| arr[r][c]=='*') return 0;
     vis[r][c] = 1;
    ll &ret = dp[r][c];
    if(~ret) return ret;
     ll cnt = 0;
    if(valid(r+1, c) && arr[r+1][c]=='*')cnt++;//down
    if(valid(r, c+1) && arr[r][c+1]=='*')cnt++;//right
    if(valid(r-1, c) && arr[r-1][c]=='*')cnt++;//up
    if(valid(r, c-1) && arr[r][c-1]=='*')cnt++;//left
     cnt += solve(r+1, c) + solve(r, c+1) + solve(r-1, c) + solve(r, c-1);
     return ret = cnt;
}
ll toSet;
void countReachable(int r, int c){
    if(!valid(r, c) || vis2[r][c] || arr[r][c]=='*') return;
     vis2[r][c] = 1;
    ll cnt = 1;
    res[r][c] = toSet;
    countReachable(r+1, c);
    countReachable(r, c+1);
    countReachable(r-1, c);
    countReachable(r, c-1);
}
int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    cin>>n>>m>>k;
    for(int i =0; i<n; i++)
        for(int j  =0; j<m; j++)
            cin>>arr[i][j];
    mem(dp, -1);
    mem(res, -1);
    while(k--){
        int r, c; cin>>r>>c;
        r--, c--;
        if(~res[r][c])cout<<res[r][c]<<endl;
        else{
            toSet = solve(r, c);
            cout<<toSet<<endl;
            countReachable(r, c);
        }
     }
 return 0;
}