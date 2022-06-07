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
 
const int N = 1e5 + 1;
int n, a[N], dp[N];
int c;
int solve(int i){
    if(i==n-1) return 0;
 
    int &ret = dp[i];
    if(~ret) return ret;
 
    ret = 0;
    for(int j = i+1; j < n; j++)
        if(__gcd(a[i], a[j]) > 1)
            ret = max(ret, 1 + solve(j));
 
    return ret;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    cin>>n;
    for(int i = 0; i<n; i++) cin >> a[i];
    int f[N] = {};
    int mx = 1; //at least one element (even we can choose 1 only)
    for(int i = 0; i<n; i++){
        dp[a[i]] = 1;
        if(a[i]==1)  continue;
        int mxDp = 0;
        for(ll j = 1; j*j <= a[i]; j++){
            if(a[i]%j==0){
                if(j!=1) mxDp = max(mxDp, dp[j]);
                if(j!=1) mxDp = max(mxDp, dp[a[i]/j]);
            }
        }
        for(ll j = 1; j*j <= a[i]; j++){
            if(a[i]%j==0){
                if(j!=1) dp[j] = mxDp + 1;
                if(j!=1) dp[a[i]/j] = mxDp + 1;
            }
        }
        dp[a[i]] += mxDp;
        mx = max(mx, dp[a[i]]);
    }
 
    cout<<mx;
 return 0;
}