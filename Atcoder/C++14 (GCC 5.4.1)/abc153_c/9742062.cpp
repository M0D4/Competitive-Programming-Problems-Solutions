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
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMIN INT_MIN
#define IMAX INT_MAX

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

dd BN (vector<pii> &v, ll n, ll m);



dd sum(dd mid){
    return ((dd)mid/2)*(mid+1);
}
int  N, M, NUM, mn = IMAX;
#define MAX 1000000
bool visited[15][102];
bool arr[15][102];

bool valid(int r, int c){//if not out of the bounds
    if(r>=N || r<0) return 0;
    if(c>=M || c<0) return 0;
    return 1;
}
void countReachable(int r, int c, int cnt, int i){
    //if out of bounds || visited before
    if(!valid(r, c) || visited[r][c])
        return;

    visited[r][c] = 1; //mark as visited

    if(i==NUM) {mn = min(mn, cnt); return;}
    //try 4 moves
    countReachable(r,c+1, cnt+1, i+arr[r][c]);//right

    countReachable(r,c-1, cnt+1, i+arr[r][c]);//left

    countReachable(r+1,c, cnt+1, i+arr[r][c]);//up
    visited[r][c] = 0;
    countReachable(r-1,c, cnt+1, i+arr[r][c]);//down
    visited[r][c] = 0;

}

int main()
{
    JULEE_DO_THE_THING;
    //freopen("test cases\\.txt", "r", stdin) ;
    int n, k; cin>>n>>k;
    ll arr[n];
    fori(0, n) cin>>arr[i];
    sort(arr, arr+n);
    ll sum = 0;
    for(int i=n-1; i>=0; i--){
        if(k){
            k--;
            continue;
        }
        sum+=arr[i];
    }
    cout<<sum;
    return 0;
}


dd BN (vector<pii> &v, ll n, ll m){
dd low = 0;
dd up = 1e21;
dd ans = 0;
while(low<=up){
    dd mid = trunc((low+ up)/2);
    dd fx = 0;
    fori(0, n){
        fx += max(0.0, mid-v[i].F)*v[i].S;
    }
    if(fx<=m) {
        ans = mid;
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
