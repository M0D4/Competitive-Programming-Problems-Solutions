#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
 #define fori( tt,aa)      for(int i= tt; i<aa; i++)
#define forj( yy,bb)      for(int j=yy; j<bb; j++)
#define fork( uu,cc)      for(int k=uu; k<cc; k++)
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define EPS 1e-7
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
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
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
 dd BN ();
  ll n, x;
 dd sum(dd mid){
    return ((dd)mid/2)*(mid+1);
}
 int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\.txt", "r", stdin) ;
    int n; cin>>n;
    if(n<=10 || n>21) return cout<<0, 0;
    n -= 10;
    if(n==10) return cout<<15, 0;
    cout<<4;
    return 0;
}
  dd BN (){
dd low = n;
dd up = 9.5e18;
dd ans = -1;
while(low<=up){
    dd mid = trunc(((low+ up)/2));
    dd s = sum(mid) - sum(mid-n);
    if(s==x) return mid - n+1;
    if(s<x) {
        low = mid+1;
    }else up = mid-1;
}
return ans;
}
 ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}