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
    if(a<2 || (a>2 && !(a%2))) return 0;
    ll sq = sqrt(a);
    fori(2, sq+1){
        if(!(a%i)) return 0;
    }
    return 1;
}
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Make Them Odd.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
       int n ;cin>>n;
       vecll arr(n);
       fori(0, n) cin>>arr[i];
       unique(all(arr));
       n = arr.size();
       map<int, int> mp;
       for(int i = n-1; i>=0; i--){
            if(!(arr[i]%2)){
                ll m = arr[i], x = m, sq = sqrt(m);
                while(!(m%2))m/=2, mp[m]++;
            }
       }
       cout<<mp.size()<<endl;
    }
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