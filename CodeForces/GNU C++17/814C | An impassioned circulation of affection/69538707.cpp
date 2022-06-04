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
 dd BN (vector<pii> &v, ll n, ll m);
   dd sum(dd mid){
    return ((dd)mid/2)*(mid+1);
}
ll n, l, r, x;
vecll v;
 ll solve(int i, ll sum, ll mx, ll mn){
    if(i>n)  return 0;
    if(i==n){
         if(sum>=l && sum<=r && mx-mn>=x) return 1;
    }
    ll ans = 0;
    ans +=solve(i+1, v[i]+sum, max(mx, v[i]), min(mn, v[i]));
    ans +=solve(i+1, sum, mx, mn);
    return ans;
}
 int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\An impassioned circulation of affection.txt", "r", stdin) ;
    int n; cin>>n;
    str s; cin>>s;
    int q; cin>>q;
    while(q--){
        int m; cin>>m;
        char c; cin>>c;
        int mx = 0, cnt = 0, p1 = 0, p2 = 0;
        while(p1<n){
            while(p2<n && (s[p2]==c || cnt<m)){
                if(s[p2]!=c)cnt++;
                p2++;
            }
            mx = max(mx, p2-p1);
            if(s[p1]!=c) cnt--;
            p1++;
            if(p1>p2) p2 = p1;
        }
        cout<<mx<<endl;
    }
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
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}