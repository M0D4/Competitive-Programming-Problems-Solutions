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
//int freq[128];
ll n, k;
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("Burning Midnight Oil .txt", "r", stdin);
    cin>>n>>k;
    cout<<BN()<<endl;
    return 0;
}
ld pow (ll a, ll b){
    ld pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
 
ll BN (){
int low = 1;
int up = n;
ll ans  = n; // new edit 2
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    ll sum = 0, cnt = 0;
    while(1){
        ll val = mid/pow(k, cnt++);
        if(!val) break;
        sum += val;
    }
    if(sum >= n){ //if i have k or more number of mid
        ans = mid;
        up = mid-1;
    }else low = mid+1;
}
return ans;
}
 
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}