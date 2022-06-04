#include <bits/stdc++.h>
#include <ext/numeric>
/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) power(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
  const int N = 1e5 + 5;
string a[N], b[N];
int cost[N], n;
ll dp[N][2];
ll solve(int i, bool lastRev){
    if(i==n) return 0;
     ll &ret = dp[i][lastRev];
    if(~ret) return ret;
     ret = (ll)1e15;
    if(lastRev){
        if(a[i] >= b[i-1]) ret = min(ret, solve(i+1, 0));
        if(b[i] >= b[i-1]) ret = min(ret, cost[i] + solve(i+1, 1));
    }else{
        if(a[i] >= a[i-1]) ret = min(ret, solve(i+1, 0));
        if(b[i] >= a[i-1]) ret = min(ret, cost[i] + solve(i+1, 1));
    }
     return ret;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    cin>>n;
    for(int i = 0; i<n; i++) cin>>cost[i];
    for(int i = 0; i<n; i++){
        string s; cin>>s;
        a[i] = s;
        reverse(all(s));
        b[i] = s;
    }
    clr(dp, -1);
    ll ans = solve(1, 0);
    clr(dp, -1);
    ans = min(ans, cost[0] + solve(1, 1));
    if(ans == (ll)1e15) ans = -1;
    cout<<ans;
 return 0;
}