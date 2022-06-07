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
 
ll numOfDigits(ll n);
ll BN (ll arr[], ll j, ll val);
bool compare(int &a, int &b){
    return a>b;
}
 
bool is_prime(ll n){
    for(int i =1; i*i<n; i++)
        if(!(n%i)) return 0;
    return 1;
}
 
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\DZY Loves Hash.txt", "r", stdin);
    ll p, n; cin>>p>>n;
    int arr[p], indx = -1;
    fori(0, p) arr[i] = -1;
    fori(0, n){
        ll x; cin>>x;
        ll hx = x%p;
        if(arr[hx]!=-1 && indx==-1)indx = i+1;
        else arr[hx] = x;
    }
    cout<<indx;
    return 0;
}
/*
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
}*/
 
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}