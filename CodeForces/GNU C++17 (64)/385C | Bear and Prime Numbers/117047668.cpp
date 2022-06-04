#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
 #define fori( tt,aa)      for(int i= tt; i<aa; i++)
#define forj( yy,bb)      for(int j=yy; j<bb; j++)
#define fork( uu,cc)      for(int k=uu; k<cc; k++)
#define rep(i, v)         for(int i=0; i<v.size(); i++)
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define EPS 1e-7
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define sc scanf
#define print printf
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
typedef vector<ll> row;
typedef vector<row> matrix;
  void fast(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
 ll numOfDigits(ll n);
bool compare(int &a, int &b){
    return a>b;
}
 ll pow (ll a, ll b);
 dd BN ();
  int n;
vector<bool> sieve(1e7+1, 1);
int freq[(ll)1e7+5];
ll pre[(ll)1e7+1]={0};
int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\Bear and Prime Numbers.txt", "r", stdin) ;
     //fori(1, 6)cout<<primes[i]<<" "; return 0;
     cin>>n;
    fori(0, n) {
        int a; cin>>a;
        freq[a]++;
    }
    sieve[0] = sieve[1] = 0;
    for(ll i = 2; i<=1e7; i++){
        if(sieve[i]){
            ll k= i;
            while(k<=1e7) sieve[k] = 0, pre[i]+=freq[k], k+=i ;
        }
    }
    fori(1, 1e7+1) pre[i] += pre[i-1];
    int m; cin>>m;
    while(m--){
        ll l, r; cin>>l>>r;
       l = min(l, (ll)1e7);
       r = min(r, (ll)1e7);
        cout<<max(0LL, pre[r]-pre[l-1]) <<endl;
    }
    return 0;
}
  ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}