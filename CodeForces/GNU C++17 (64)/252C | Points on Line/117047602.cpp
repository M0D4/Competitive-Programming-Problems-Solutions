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
ll BN (ll arr[], ll j, ll val);
ll n, d, p1, p2, p3, cnt;
int main()
{
 
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Points on Line.txt", "r", stdin);
    cin>>n>>d;
    ll arr[n];//strictly increase
    fori(0, n) cin>>arr[i];
    fori(0, n-2){
        p1 = i, p2 = i+1;
        p3 = BN(arr, i+2, arr[p1]);
        if(p3!=-1){
            ll val = p3 - p2;
            cnt += val*(val+1)/2;
        }
    }
    cout<<cnt;
    return 0;
}
ld pow (ll a, ll b){
    ld pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
 
ll BN (ll arr[], ll j, ll val){
int low = j;
int up = n-1;
ll ans = -1;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(abs(arr[mid]-val)<=d){
        ans = mid;
        low = mid+1;
    }else up = mid-1;
}
return ans;
}
 
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}