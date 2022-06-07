#include <bits/stdc++.h>
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 
 
void fast(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
 
bool compare(int &a, int &b){
    return a>b;
}
 
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n))+1;
}
 
ull pow (ll a, ll b);
 
 
 
 
/*
 
*/
 
ll BN ();
int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\WinOrFreeze.txt", "r", stdin) ;
    ll q; cin>>q;
    vecll primes;
    for(ll i=2; i*i<=q && primes.size()<=3; i++){
     while(!(q%i))primes.pb(i), q/=i;
    }
    if(q>1)primes.pb(q);//6/2 = 3
 
    if(primes.size()<=1) return cout<<"1\n0", 0;
    if(primes.size()==2) cout<<2; // 10: 10 5 2 1, 2*5 = 10, forbidden!
    else cout<<"1\n"<<primes[0]*primes[2];
    return 0;
}
 
 
ll BN (){
    ll low = 0;
    ll up = 0;
    ll ans = 0;
    while(low<=up){
        ll mid = ((low+ up)/2);
        if(mid) {
            ans = mid;
            low = mid+1;
        }else up = mid-1;
    }
    return ans;
}
 
 
ull pow (ll a, ll b){
    ull res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}