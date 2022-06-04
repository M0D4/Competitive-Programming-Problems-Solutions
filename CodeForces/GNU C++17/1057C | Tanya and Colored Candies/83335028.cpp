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
 const int N = 51, M = 2501, inf = 1e7;
int dp[N][M];
int a[N], n, s, k;
int c[N];
int solve(int i, int val){
    if (val >= k) return 0;
     int &ret = dp[i][val];
    if(~ret) return ret;
     ret = inf;
    for(int j = 0; j < n; j++)
        if(a[j] > a[i] && c[j] != c[i])//bigger than current element
            ret = min(ret, solve(j, val + a[j]) + abs(i - j));
     return ret;
}
int main()
{
    START
    //freopen("test cases\\input.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    cin>>n>>s>>k;
    s--;
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++){
        char cc; cin>>cc;
        if(cc=='R') c[i] = 0;
        else if(cc=='G') c[i] = 1;
        else c[i] = 2;
    }
    clr(dp, -1);
    int mn = inf;
    for(int i = 0; i<n; i++)//try to start taking candies from each position
        mn = min(mn, solve(i, a[i]) + abs(s - i));
     if(mn == inf) mn = -1;
    cout<<mn;
 return 0;
}