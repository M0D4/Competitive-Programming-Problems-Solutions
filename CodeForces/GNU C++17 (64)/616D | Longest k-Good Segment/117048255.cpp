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
map<int, int> mp;
ll n, k, p1 = 1, p2 = 1, mx =0, cnt, L, R;
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("Longest k-Good Segment.txt", "r", stdin);
    cin>>n>>k;
    int arr[n+1];
    fori(1, n+1) cin>>arr[i];
    n++;
    while(p1<n){
        while(p2<n && cnt <= k){
            if(!mp[arr[p2]])if(cnt+1>k)break; else cnt++;
            mp[arr[p2]]++;
            p2++;
        }
        if(p2-p1>mx) L = p1, R = p2-1, mx = p2-p1;
        mp[arr[p1]]--;
        if(!mp[arr[p1]])cnt--;
        p1++;
    }
    cout<<L<<" "<<R;
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