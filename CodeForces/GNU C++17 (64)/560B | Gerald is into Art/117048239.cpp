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
int solve(int n){
    if(n<=1)  return 0;
 
    return 1 + min({((n%3==0)?solve(n/3):IMAX) ,
      ((n%2==0)?solve(n/2):IMAX),
        solve(n-1)});
 
}
int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\.txt", "r", stdin) ;
    int a1, b1, a2, b2, a3, b3;
    cin>>a1>>b1>>a2>>b2>>a3>>b3;
    if(a2+b3<=b1 && max(b2, a3)<=a1){
        cout<<"YES"; return 0;
    }
    if(b2+a3<=a1 && max(a2, b3)<=b1){
         cout<<"YES"; return 0;
    }
    if(a2+a3<=b1 && max(b2, b3)<=a1){
        cout<<"YES"; return 0;
    }
    if(b2+b3<=a1 && max(a2, a3)<=b1){
        cout<<"YES"; return 0;
    }
    swap(a1, b1);
    if(a2+b3<=b1 && max(b2, a3)<=a1){
        cout<<"YES"; return 0;
    }
    if(b2+a3<=a1 && max(a2, b3)<=b1){
         cout<<"YES"; return 0;
    }
    if(a2+a3<=b1 && max(b2, b3)<=a1){
        cout<<"YES"; return 0;
    }
    if(b2+b3<=a1 && max(a2, a3)<=b1){
        cout<<"YES"; return 0;
    }
    cout<<"NO";
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