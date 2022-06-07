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
int x[N], h[N], n;
map<pii , int> dp;
int solve(int i, int right){
    if(i>=n) return 0;
 
    if(dp.count({i, right})) return dp[{i, right}];
 
    int &ret = dp[{i, right}];
    ret = solve(i+1, x[i]);
 
    if(x[i] + h[i] < x[i+1]) ret =  max(ret,  1 + solve(i+1, x[i] + h[i]));
    if(x[i] - h[i] > right) ret =  max(ret,  1 + solve(i+1, x[i]));
 
    return ret;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    cin>>n;
    for(int i = 0; i<n; i++) cin>>x[i]>>h[i];
    x[n] = INT_MAX, h[n] = 0;
    cout<< 1 + solve(1, x[0]);//first one can always be down to left
 return 0;
}