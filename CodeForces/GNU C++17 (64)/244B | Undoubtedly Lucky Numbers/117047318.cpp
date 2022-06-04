#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
 #define fori( tt,aa)      for(int i= tt; i<aa; i++)
#define forj( yy,bb)      for(int j=yy; j<bb; j++)
#define fork( uu,cc)      for(int k=uu; k<cc; k++)
#define fore(v)           for(auto &it: v)
#define rep(i, v)         for(int i=0; i<v.size(); i++)
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define sc scanf
#define print printf
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
 typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
typedef vector<dd> row;
typedef vector<row> matrix;
 void fast(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
 ll numOfDigits(ll n);
bool compare(int &a, int &b){
    return a>b;
}
 ll pow (ll a, ll b);
 dd BN (vector<pii> &v, ll n, ll m);
 ll gcd(ll a, ll b){
    if(!b) return a;
    if(a%b==0) return b;
    return gcd(b, a%b);
}
ll lcm (ll a, ll b) { return a / gcd(a, b) * b;}
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
int n;
ll ans;
bool lucky(ll num){
    map<int, bool> mp;
    while(num){
        mp[num%10] = 1;
        num/=10;
    }
    return mp.size()<=2;
}
void solve(ll num){
    if(num>0 && num<=n) ans++;
    if(num>=1e9) return;
     fori(0, 10){
        if(num*10+i>0 && lucky(num*10+i)) solve(num*10 + i);
    }
}
int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\Undoubtedly Lucky Numbers.txt", "r", stdin) ;
    cin>>n;
    solve(0);
    cout<<ans;
    return 0;
}
  dd BN (vector<pii> &v, ll n, ll m){
dd low = 0;
dd up = 1e21;
dd ans = 0;
while(low<=up){
    dd mid = trunc((low+ up)/2);
    dd fx = 0;
    fori(0, n){
        fx += max(0.0, mid-v[i].F)*v[i].S;
    }
    if(fx<=m) {
        ans = mid;
        low = mid+1;
    }else up = mid-1;
}
return ans;
}
  ll pow (ll a, ll b){
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n))+1;
}