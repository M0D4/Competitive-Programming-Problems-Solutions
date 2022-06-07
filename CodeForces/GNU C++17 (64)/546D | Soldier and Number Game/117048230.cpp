#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
 
#define fori( tt,aa)      for(int i= tt; i<aa; i++)
#define forj( yy,bb)      for(int j=yy; j<bb; j++)
#define fork( uu,cc)      for(int k=uu; k<cc; k++)
#define fore(v)           for(auto &it: v)
#define rep(i, v)         for(int i=0; i<v.size(); i++)
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
typedef pair<int, int> pii;
 
ll numOfDigits(ll n){if(!n) return 1;  return (ll)(log10(n)+1);}
 
void fast(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
 
bool compare(int &a, int &b){
    return a>b;
}
ll gcd(ll a, ll b){ if(!b) return a; if(a%b==0) return b; return gcd(b, a%b);}
 
ll lcm (ll a, ll b) { return a / gcd(a, b) * b;}
 
 
ll modPow(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
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
bool isPrime(ll q){
    if(q==2) return 1;
    if(q<2 || (q>2 && !(q%2))) return 0;
 
    for(ll i = 2; i*i<q; i++)
        if(!(q%i)) return 0;
 
    return 1;
}
#define MAX 5000005
int sieve[MAX];
int pre[MAX]={0};
int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\Soldier and Number Game.txt", "r", stdin) ;
    for(ll i = 2; i<MAX; i++){
        if(!sieve[i]){
            ll k = i;
            while(k<=MAX-5){
                if(!sieve[k]) sieve[k] = i;
                k+=i;
            }
        }
    }
    fori(2, MAX-4){
        ll n = i, cnt = 0;
        while(sieve[n]>0)cnt++, n /= sieve[n];
        if(n!=1)cnt++;
        pre[i] = cnt;
    }
    fori(1, MAX-3){
        pre[i] += pre[i-1];
    }
    int t; cin>>t;
    while(t--){
        ll a, b; cin>>a>>b;
        cout<<pre[a]-pre[b]<<"\n";
    }
    return 0;
}
 