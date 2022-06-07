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
#define to_str to_string
 
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
ll BN (ll val, ll x);
bool compare(int &a, int &b){
    return a>b;
}
bool isPrime(ll a){
    //if(a<2 || (a>2 && !(a%2))) return 0;
    ll sq = sqrt(a);
    fori(2, sq+1){
        if(!(a%i)) return 0;
    }
    return 1;
}
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\k-th divisor.txt", "r", stdin);
    ll n, k; cin>>n>>k;
    ll sq = sqrt(n);
   // if(k>2*sq)   return cout<<-1, 0;
    vecll d;
    fori(1, sq+1){
        if(!(n%i)){
            d.pb(i);
            if(n/i!=i)d.pb(n/i);
        }
    }
    if(d.size()<k) return cout<<-1, 0;
    sort(all(d));
    cout<<d[k-1];
    return 0;
}
/*
ll BN (ll val, ll x){
int low = 0;
int up = val;
ll ans = 0;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(mid*x>=val){
        ans = mid;
        up = mid-1;
    }else low = mid+1;
}
return ans;
}*/
 
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}