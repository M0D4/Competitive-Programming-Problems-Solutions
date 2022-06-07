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
    //freopen("test cases\\.txt", "r", stdin) ;
    int n; cin>>n;
    map<int , int> mp;
    map<int, int> index;
    for(int i = 0; i<n; i++){
     int a; cin>>a;
     mp[a]++;
     index[a] = i+1;
    }
    int mn = index.begin()->F;
    if(mp[mn]>1)cout<<"Still Rozdil";
    else cout<<index[mn];
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