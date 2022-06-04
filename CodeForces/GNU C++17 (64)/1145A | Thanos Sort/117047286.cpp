#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
 #define fori( tt,aa)      for(int i= tt; i<aa; i++)
#define forj( yy,bb)      for(int j=yy; j<bb; j++)
#define fork( uu,cc)      for(int k=uu; k<cc; k++)
#define all(v)   v.begin(), v.end()
#define endl "\n";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define EPS 1e-7
#define F first
#define S second
#define JULEE_DO_THE_THING fast()
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
bool compare(int &a, int &b){
    return a>b;
}
 ll pow (ll a, ll b);
 int BN (vector<pii> &x, pii &p);
int n;vecint v;
/*
0  1  2 3 4  5  6 7
11 12 1 2 13 14 3 4
  */
int solve(int i, int j){
    if(is_sorted(v.begin()+i, v.begin()+j)) return j-i;
     return max(solve(i, (i+j)/2), solve((i+j)/2, j));
}
 int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\Thanos Sort.txt", "r", stdin) ;
    cin>>n;
    v.resize(n);
    fori(0, n) cin>>v[i];
    cout<<solve(0, n);
    return 0;
}
   int BN (vector<pii> &x, pii &p){
int low = 0;
int up = x.size()-1;
int ans = -1;
while(low<=up){
    ll mid = ((ll)low+ up)/2;
    if(x[mid].F<=p.F && x[mid].S>=p.S) return mid;
       if(x[mid].F<p.F) {
        low = mid+1;
    }else up = mid-1;
}
return ans;
}
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