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
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
ll modPow(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
 
int m, d;
vi dig;
ll dp[2001][2001][2];
 
ll solve(int i, int mod, bool smaller){//1-based index
    if(i == sz(dig)) return !mod;
 
    ll &ret = dp[i][mod][smaller];
    if(~ret) return ret;
 
    ll p = modPow(10, sz(dig) - i - 1, m);
    int mxDig = dig[i];
    if(smaller) mxDig = 9;
 
    ll cnt = 0;
    if(!isOdd(i)){
        int cur = d;
        int newMod = mod + cur*p;
        newMod %= m;
        if(smaller || cur<= mxDig) cnt += solve(i+1, newMod, smaller || cur < mxDig);
        cnt %= MOD;
    }else{
        for(int j = 0; j <= mxDig; j++){
            if(j==d) continue;
            int newMod = mod + j*p;
            newMod %= m;
            cnt += solve(i+1, newMod, (smaller || j < mxDig));
            cnt %= MOD;
        }
    }
    return ret = cnt;
}
 
ll pos(string s){
    mem(dp, -1);
    dig.clear();
    dig.pb('0');//fill index 0
    for(int i = 0; i<sz(s); i++)
        dig.pb(s[i] - '0');
 
    return solve(1, 0, 0);
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    cin>>m>>d;
    string s, t; cin>>t>>s;//t = 10, s = 16
    ll x = pos(s) - pos(t);
    int in = 1, val = 0;
 
    for(int i = 0; i<sz(t); i++){//check if the start is d-magic
        val = (t[i] - '0' + val*10)%m;
        if(!isOdd(i) && t[i]-'0'==d){
            in = 0;
            break;
        }
        else if(isOdd(i) && t[i]-'0'!=d){
            in = 0;
            break;
        }
    }
    if(val) in = 0;
    x += in;
    if(x<0) x += MOD;
    cout<<x;
 return 0;
}