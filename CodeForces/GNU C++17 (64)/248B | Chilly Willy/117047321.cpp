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
    //freopen("test cases\\Chilly Willy.txt", "r", stdin);
    int n; cin>>n;
    if(n<=2) return cout<<-1, 0;
    if(n==3) return cout<<210, 0; //2 * 3 * 5 * 7 = 210 the minimum number divisible by 2,3,5,7
    ll num = 1;
    /*
        9 % 5 = 4
        to make 9 divisible by 5
        we add to it (5-(9%5))
        therefore 9 + (5-(4)) = 9 + 1 = 10
        10 is divisible by 5.
    */
    fori(1, n) num *=10, num %=210; //to generate minimum number of n digits divisible by 210
    int m =  numOfDigits(210-num)+1;
    cout<<1;
    while(m<n)cout<<0, m++;
    cout<<210-num;
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