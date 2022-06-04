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
ll BN ();
//map<char, int> mp;
ll n, p1 = 1, p2 = 1, mx =0;
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("Three Parts of the Array.txt", "r", stdin);
    cin>>n;
    ll arr[n+1], pre1[n+3]={0}, pre2[n+3]={0};
    fori(1, n+1) cin>>arr[i], pre1[i] = pre1[i-1] + arr[i];
     for(int i = n; i>=1 ;i--)//reversed prefix sum
        pre2[i] = pre2[i+1] + arr[i];
     reverse(pre2+1, pre2+n+1);//reverse order
     while(p1<n){
        while(p2<=n-p1 && pre2[p2]<pre1[p1]) p2++;
        if(p2<=n-p1 &&pre1[p1]==pre2[p2])
            mx = max(mx, pre1[p1]);
        p1++;
    }
    cout<<mx;
    return 0;
}
ld pow (ll a, ll b){
    ld pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
/*
ll BN (){
int low = 0;
int up = k;
ll cnt  = 0;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(((mid +k )*(k-mid+1))/2 >= n){
        low = mid+1;
    }else up = mid-1;
}
return k - low + 2;
}*/
 ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(n)+1);
}