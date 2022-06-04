#include <bits/stdc++.h>
#include <ext/numeric>
/**
    HAPPY EID :)
*/
using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef vector<int> vi;
    int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        int n, m, x, y; cin>>n>>m>>x>>y;
        char a[n+2][m+2];
        mem(a, '#');
        ll cost = 0;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=m; j++)
                cin>>a[i][j];
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(a[i][j]=='*') continue;
                if(a[i][j+1]=='.' && y<=2*x){
                    cost += y;
                    j++;
                }else cost += x;
            }
        }
        cout<<cost<<endl;
    }
 return 0;
}