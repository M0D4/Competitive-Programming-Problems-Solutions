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
bool compare(const char &a, const char &b){
    return a>b;
}
ll fac(ll a){
    ll f = 1;
    fori(2, a+1)
        f *=i;
    return f;
}
ll facs [10]= {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
map<ll, str> mp;
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Drazil and Factorial.txt", "r", stdin);
    mp[2] = "2";
    mp[6] = "3";
    mp[24] = "223"; //2!*2!*3! = 2*2*6
    mp[120]= "5";
    mp[720]= "53";//5!*3! = 120*6
    mp[5040] = "7";
    mp[40320] = "7222";//7!*2!*2!*2! = 5040*2*2*2
    mp[362880] = "7332";//7!*3!*3!*2! = 54040*6*6*2
    ll n, a; cin>>n>>a;
    str ans = "";
    while(a){
        ll b= facs[a%10];
        if(b!=1){
            ans += mp[b];
        }
        a/=10;
    }
    sort(all(ans), compare);
    cout<<ans;
    return 0;
}
ld pow (ll a, ll b){
    ld pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
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
 