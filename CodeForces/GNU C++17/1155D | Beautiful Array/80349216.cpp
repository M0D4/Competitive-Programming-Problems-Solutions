#include <bits/stdc++.h>
#include <ext/numeric>
/**
    PROGRESS IS PROGRESS
    NO MATTER HOW SMALL
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
typedef pair<int, int> pii;
typedef vector<int> vi;
 const int N = 3e5;
int n, x;
ll a[N], dp[N][5];
ll solve(int i, int stage){
    if(i==n) return 0;
     ll &ret = dp[i][stage];
    if(~ret) return ret;
     ll c1 = (stage==1 || stage==3)*a[i] + (stage==2)*x*a[i] + solve(i+1, stage);
    ll c2 = (stage+1<4? solve(i, stage+1) : 0);
     return ret = max(c1, c2);
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    cin>>n>>x;
    for(int i = 0; i<n; i++) cin>>a[i];
    mem(dp, -1);
    cout<<solve(0, 0);
 return 0;
}