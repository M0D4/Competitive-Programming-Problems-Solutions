#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<ll> vi;
 
 
const int N = 101;
int n, k, d;
ll dp[N][2];
ll solve(int sum, bool hasDPlus){
    if(sum > n) return 0;
    if(sum == n) return hasDPlus;
 
    ll &ret = dp[sum][hasDPlus];
    if(~ret) return ret;
 
    ret = 0;
    for(int i = 1; i<=k; i++){
        ret += solve(sum + i, hasDPlus || i >= d);
        if(ret >= MOD) ret -= MOD;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test cases\\in.txt", "r", stdin);
 
    cin >> n >> k >> d;
    clr(dp, -1);
    cout<<solve(0, 0);
    return 0;
}