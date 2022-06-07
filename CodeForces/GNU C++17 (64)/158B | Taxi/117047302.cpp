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
ll BN (ll arr[], ll j, ll val);
bool compare(int &a, int &b){
    return a>b;
}
int main()
{
 
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\Taxi.txt", "r", stdin);
    int n , taxi = 0;cin>>n;
    int arr[n], freq[5]={0};
    fori(0,n) cin>>arr[i], freq[arr[i]]++;
    sort(arr, arr+n, compare);
    fori(0, n){
        if(freq[arr[i]]){
            freq[arr[i]]--;
            int emptyy = 4 - arr[i];
            while(emptyy>=3 && freq[3]) emptyy-=3, freq[3]--;
            while(emptyy>=2 && freq[2]) emptyy-=2, freq[2]--;
            while(emptyy>=1 && freq[1]) emptyy-=1, freq[1]--;
            taxi++;
        }
    }
    cout<<taxi;
    return 0;
}
ld pow (ll a, ll b){
    ld pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
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