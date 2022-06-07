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
 
ll numOfDigits(ll n);
ll BN (ll arr[], ll j, ll val);
bool compare(int &a, int &b){
    return a>b;
}
 
bool is_prime(ll n){
    for(int i =1; i*i<n; i++)
        if(!(n%i)) return 0;
    return 1;
}
int main()
{
    THINK_TWICE_CODE_ONCE;
    //freopen("test cases\\.txt", "r", stdin);
    int n, m; cin>>n;
    int a[n];
    fori(0, n) cin>>a[i];
    cin>>m;
    int b[m];
    fori(0, m) cin>>b[i];
    sort(a, a+n);
    sort(b, b+m);
    ll cnt = 0;
    map<int , int> mp;
    fori(0, n){
        bool flag = 0;
        forj(0, m){
            if(!mp[j] && abs(a[i]-b[j])<=1){
                    cnt++, mp[j]++;
                    flag = 1;
                    break;
            }
        }
    }
    cout<<cnt;
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