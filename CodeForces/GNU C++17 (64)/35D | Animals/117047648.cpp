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
 const int N = 101, M = 1e4 + 1;
int a[N], n, x;
int dp[N][M];
int solve(int i, int rem){
    if(i==n) return 0;
     int &ret = dp[i][rem];
    if(~ret) return ret;
     ret = solve(i+1, rem);
    if(a[i] * (n-i) <= rem) ret = max(ret, 1 + solve(i+1, rem - a[i] * (n-i)));
     return ret;
}
int main()
{
    START
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout);
    cin>>n>>x;
    for(int i = 0; i<n; i++) cin>>a[i];
    clr(dp, -1);
    cout<<solve(0, x);
 return 0;
}