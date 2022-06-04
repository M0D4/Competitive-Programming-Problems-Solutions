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
 bool compare(pii &a, pii &b){
    if(a.F==b.F) return a.S>b.S;
    return a.F>b.F;
}
 ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n))+1;
}
 dd pow (ll a, ll b);
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
bool isPrime(ll q){
    if(q==2) return 1;
    if(q<2 || (q>2 && !(q%2))) return 0;
     for(ll i = 2; i*i<q; i++)
        if(!(q%i)) return 0;
     return 1;
}
/*
  */
int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\.txt", "r", stdin) ;
    int n; cin>>n;
    while(n){
        if(n%1000==144 || n%1000==111){
            n/=1000;
        }else if(n%100==14 || n%100==11){
            n/=100;
        }else if(n%10==1){
            n/=10;
        }else return cout<<"NO", 0;
    }
    cout<<"YES";
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
  dd pow (ll a, ll b){
    dd res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * log(a);
        a = a * log(a);
        b >>= 1;
    }
    return res;
}