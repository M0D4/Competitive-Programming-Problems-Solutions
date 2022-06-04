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
 ll BN ();
 ll cb, cs, cc;
ll nb, ns, nc;
ll pB, ps, pc;
ll r;
ll f(ll x){
    return max(0LL, cb*x - nb)*pB
         + max(0LL, cs*x - ns)*ps
         + max(0LL, cc*x - nc)*pc;
}
int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\Hamburgers.txt", "r", stdin) ;
    str s; cin>>s;
    int n = s.size();
    fori(0, n)
        if(s[i]=='B')cb++;
        else if(s[i]=='S')cs++;
        else cc++;
     cin>>nb>>ns>>nc;
    cin>>pB>>ps>>pc;
    cin>>r;
    cout<<BN();
    return 0;
}
  ll BN (){
ll low = 0;
ll up = (ll)1e15;
ll ans = 0;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(f(mid)<=r) {
        ans = mid;
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