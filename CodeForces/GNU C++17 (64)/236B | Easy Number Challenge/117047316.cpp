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
 
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Easy Number Challenge.txt", "r", stdin);
    int a, b, c; cin>>a>>b>>c;
    map<int , ll> mp;
    ll sum = 0;
    fori(1, a+1){
        forj(1, b+1){
            ll d = i*j;
            fork(0, c){
                if(mp.find(d)==mp.end()){
                ll cnt = 0, sq = sqrt(d);
                for(int x = 1; x<=sq; x++){
                    if(!(d%x)){
                        cnt++;
                        if(d/x!=x)cnt++;
                    }
                }
                mp[d] = cnt%1073741824;
                sum = sum%1073741824 + cnt%1073741824;
                }else sum = sum%1073741824 + mp[d]%1073741824;
                d+=i*j;
            }
        }
    }
    cout<<sum%1073741824;
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