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
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int n, m;
char a[60][60];
bool vis[60][60];
bool can[60][60];
void solve(int r, int c){
    if(r<=0 || c<=0) return;
    if(vis[r][c] || a[r][c]=='#') return;
    vis[r][c] = 1;
    can[r][c] = 1;
    if(r-1 > 0)  solve(r-1, c);
    if(c-1 > 0)  solve(r, c-1);
    if(r+1 <= n) solve(r+1, c);
    if(c+1 <= m) solve(r, c+1);
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        int cnt = 0;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=m; j++)
                cin>>a[i][j], cnt+= a[i][j]=='G', can[i][j] = 0;
 
        bool ok = 1;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(a[i][j]=='B'){
                    if(i+1<=n && a[i+1][j]=='.')a[i+1][j] = '#';
                    if(j+1<=m && a[i][j+1]=='.')a[i][j+1] = '#';
                    if(i-1>0 && a[i-1][j]=='.')a[i-1][j] = '#';
                    if(j-1>0 && a[i][j-1]=='.')a[i][j-1] = '#';
                }
            }
        }
        mem(vis, 0);
        solve(n, m);
        int good = 0, bad = 0;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=m; j++)
                if(can[i][j] && a[i][j]=='G') good++;
                else if(can[i][j] && a[i][j]=='B') bad++;
 
        if(!bad && good==cnt)cout<<"Yes\n";
        else cout<<"No\n";
    }
 return 0;
}