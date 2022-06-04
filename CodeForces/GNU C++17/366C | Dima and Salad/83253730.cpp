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
  const int N = 100, M = 1e5 + 5, OO = 1e6;
int taste[N], cal[N];
int n, k;
int dp[N][M];
int solve(int i, int sub){
    if(i==n) return (!sub? 0 : -OO);
     int &ret = dp[i][sub];
    if(~ret) return ret;
     ret = solve(i+1, sub);
    ret = max(ret, taste[i] + solve(i+1, sub + taste[i] - cal[i]));
     return ret;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    cin>>n>>k;
    for(int i = 0; i<n; i++) cin>>taste[i];
    for(int i = 0; i<n; i++) cin>>cal[i], cal[i] *= k;
    clr(dp, -1);
    /*
            sumTaste/sumCal = k
            therefore, sumTaste = k * sumCal
            so multiply each cal by k
            and see maximum taste == cal
    */
    ll ans = solve(0, 0);
    cout<<(ans > 0 ? ans : -1);
 return 0;
}