#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
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
#define isOdd(n)    (n&1)
 
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
ll BNL ();
ll BNR ();
bool compare(char &a, char &b){
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
ll po[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512,
1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072,
 262144, 524288, 1048576, 2097152, 4194304, 8388608,
  16777216, 33554432, 67108864, 134217728, 268435456,
   536870912, 1073741824};
ll pow (ll a, ll b);
 
int main()
{
    //THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Fedor and New Game.txt", "r", stdin) ;
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    ll arr[m+1], cnt = 0;
    fori(0, m+1) scanf("%lld", &arr[i]);
    fori(0, m){
        bitset<20> b((arr[i]^arr[m]));
        /*
         assume Fedor  10001
               player ^00101
                      ______
                       10100
                    number of 1's  = 2
                    so they are different in 2 bits
        */
        if(b.count()<=k)cnt++;
    }
    cout<<cnt;
    return 0;
}
 
 
/*
ll BNL (){
ll low = L;
ll up = R;
ll ans = 0;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(mid3>=L && mid3<=R){
        ans = mid;
        low = mid+1;
    }else up = mid-1;
}
return ans;
}*/
 
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