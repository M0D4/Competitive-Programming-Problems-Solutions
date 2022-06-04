#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
 #define fori( tt,aa)      for(int i= tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define EPS 1e-7
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE fast()
#define to_str to_string
#define isOdd(n)    (n&1)
#define sc scanf
#define print printf
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
 ll pow (ll a, ll b);
bool isLucky(int n){
    while(n){
        int tmp = n%10;
        if(tmp!=4 && tmp!=7)return 0;
        n/=10;
    }
    return 1;
}
 int main()
{
    //THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; sc("%d", &t);
    while(t--){
        int n; sc("%d", &n);
        ll arr[n], yasser=0;
        fori(0, n){
            sc("%lld", &arr[i]);
            yasser +=arr[i];
        }
        ll mx_cr=arr[0], mx_gl=arr[0];
        fori(1,n-1){
            mx_cr = max(arr[i], mx_cr+arr[i]);
            if(mx_cr>mx_gl)
                mx_gl = mx_cr;
        }
        ll mx_cr2=arr[1], mx_gl2=arr[1];
        fori(2,n){
            mx_cr2 = max(arr[i], mx_cr2+arr[i]);
            if(mx_cr2>mx_gl2)
                mx_gl2 = mx_cr2;
        }
        if(yasser>max(mx_gl, mx_gl2)) print("YES\n");
        else print("NO\n");
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