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
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
typedef vector<int> vecint;
typedef vector<ll> vecll;
void fast(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}
ll pow (ll a, ll b);
ll numOfDigits(ll n);
int BN(ll pre[], int m);
//int freq[101];
 //map<int, int> mp;
int main()
{
    fast();
    int n, t; cin>>n>>t;
    int arr[n+1]; ll pre[n+3];
    fori(1, n+1) cin>>arr[i], pre[i] = pre[i-1] + arr[i];
    int l = 1, r = 1, mx = 0;
    while(r<n+1){
        while(r<n+1 && pre[r] - pre[l-1] <= t) r++;
        mx = max(mx, r - l);
        l++;
    }
    cout<<mx;
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
int BN(ll pre[], int m){
    int low  = 1;
    int up = m;
    int ans = 0;
    while(low<=up){
         ll mid = ((ll)low+up)/2; // to avoid overflow
        if(pre[mid]<=300){
            ans = mid;
           low = mid +1;
        }else  up = mid-1;
    }
    return ans;
}
ll numOfDigits(ll n){
    if(!n) return 1;
    return (ll)(log10(abs(n))+1);
}