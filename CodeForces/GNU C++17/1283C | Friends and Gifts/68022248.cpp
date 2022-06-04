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
ll BN ();
ll BNR ();
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
ll po[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512,
1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072,
 262144, 524288, 1048576, 2097152, 4194304, 8388608,
  16777216, 33554432, 67108864, 134217728, 268435456,
   536870912, 1073741824};
 ll pow (ll a, ll b);
bool isLucky(int n){
    while(n){
        int tmp = n%10;
        if(tmp!=4 && tmp!=7)return 0;
        n/=10;
    }
    return 1;
}
bool usedV[200001];
int main()
{
    //THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\.txt", "r", stdin) ;
    int n; scanf("%d", &n);
    int arr[n];
    fori(0, n){
        scanf("%d", &arr[i]);
        usedV[arr[i]]=1;
    }
    vecint v;
    fori(1, n+1){
        if(!usedV[i]) v.pb(i);
    }
    sort(all(v), compare);
    int cnt = 0;
    fori(0,n){
     if(arr[i]) continue;
      if(v[cnt]==i+1){
        if(cnt+1<v.size()) 
          swap(v[cnt], v[cnt+1]);
         else swap(v[cnt], v[cnt-1]);
      }
      cnt++;
    }
    cnt = 0;
    fori(0, n){
        if(arr[i])
            printf("%d ", arr[i]);
        else printf("%d ", v[cnt++]);
    }
    return 0;
}
  /*
ll BN (){
ll low = 0;
ll up = 1022;
ll ans = 0;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(lucky[mid]==n)return mid;
    if(lucky[mid]<n){
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