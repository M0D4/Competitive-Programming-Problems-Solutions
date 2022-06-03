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
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) power(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi dig;
int k;
string s;
ll dp[20002][100][2];
/*
dp[i][modOfDigits][f1];
index of digit, sum of digits mod k,
 state that we are smaller than b.
 */

ll solve(int i, int modDig, int smaller){
    if(i==sz(dig))  return !modDig;

    ll &ret = dp[i][modDig][smaller];
    if(~ret) return ret;

    ll cnt = 0, mxDig = 0;
    if(smaller) mxDig = 9;
    else mxDig = dig[i];

    for(int j = 0; j<=mxDig; j++){
        int sum = modDig + j;
        sum %= k;
        int sm = (j < mxDig || smaller);
        cnt += solve(i+1, sum, sm)%MOD;
        cnt %= MOD;
    }
    return ret = cnt%MOD;
}
ll pos(string s){
    dig.clear();
    for(int i = 0; i<sz(s); i++){
        dig.pb(s[i]-'0');
    }
    mem(dp, -1);

    return solve(0, 0, 0);
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    cin>>s>>k;
    ll ans = pos(s) - 1;
    cout<<(ans>=0? ans: ans + MOD);
	return 0;
}
