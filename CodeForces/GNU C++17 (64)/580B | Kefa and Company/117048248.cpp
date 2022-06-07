#include <bits/stdc++.h>
using namespace std;
 
#define fori( tt,aa)      for(long long i= tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define sz(v)    v.size()
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define EPS 1e-7
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE; fast();
 
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
 
ld pow (ll a, ll b);
ll numOfDigits(ll n);
ll BN ();
//map<int, int> freq;
ll n, d, p1 = 1, p2 = 1;
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("Kefa and Company.txt", "r", stdin);
    cin>>n>>d;
    vector<pair<ll, ll>> v(n+1);
    fori(1, n+1) cin>>v[i].F>>v[i].S;
    sort(all(v));
    ll pre[n+3]={0}, mx = 0;//for factors
    fori(1, n+1) pre[i] = pre[i-1] + v[i].S;
    n++;
    while(p1<n){
        while(p2<n && abs(v[p1].F-v[p2].F)< d){
            p2++;
        }
        mx = max(mx, pre[p2-1]-pre[p1-1]);
        p1++;
    }
    cout<<mx;
    return 0;
}
ld pow (ll a, ll b){
    ld pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
/*
ll BN (){
int low = 0;
int up = k;
ll cnt  = 0;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(((mid +k )*(k-mid+1))/2 >= n){
        low = mid+1;
    }else up = mid-1;
}
return k - low + 2;
}*/
 
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}