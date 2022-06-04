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
#define to_str to_string
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
ll BN (ll arr[], ll j, ll val);
bool compare(int &a, int &b){
    return a>b;
}
 int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Remove One Element.txt", "r", stdin);
    int n, cnt = 1; cin>>n;
    vecll arr(n+1, 0), pre(n+3, 0) ,pre2(n+3, 0);
    fori(1, n+1){
        cin>>arr[i];
        if(arr[i]<=arr[i-1])cnt =1;
        pre[i] = cnt++;
    }
    cnt = 1;
    for(int i = n; i>0; i--){
        if(arr[i]>=arr[i+1])cnt = 1;
        pre2[i] = cnt++;
    }
    ll mx = 1;
    fori(1, n+1){
        if(arr[i]>arr[i-1])
            mx = max(mx, pre[i]);
        else{
            if(arr[i]>arr[i-2])//1 2 (5) #4
                mx = max(mx, pre[i-2]+pre2[i]);//1 2 4
            if(arr[i+1]>arr[i-1])//3 4 5 #(2) 6 7
                mx = max(mx, pre[i-1]+pre2[i+1]);//3 4 5 6 7
        }
    }
    cout<<mx;
    return 0;
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