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
typedef unsigned long long ull;
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
bool sortSecondInRev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.second > b.second);
}
bool sortSecondInRev2(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.second > b.second || a.first < b.first);
}
bool sortFirstInRev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
bool sortSecond(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.second < b.second);
}
bool compare(ll a, ll b){
    return a>b;
}
 int accuSum2D(vector<vector<int>>&a){
    //accumulate each row
    fori(1, 4)
     forj(1, 4)
        a[i][j] +=a[i][j-1];
     //accumulate each col
    forj(1, 4)
     fori(1, 4)
        a[i][j] +=a[i-1][j];
    return 0;
}
 int sum_range(int i, int j, int k, int l, vector<vector<int>>&s){
    return s[k][l] - s[k][j-1] - s[i-1][l] + s[i-1][j-1];
}
int BN(ll pre[], int m);
int countDigits(ull n);
//int freq[101];
//all powers of 2 up to 2E9
ll powers[32] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048,
4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288,
1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864,
 134217728, 268435456, 536870912, 1073741824, 2147483648};
 int powerOf2(ll tmp);
    map<ll, int> mp;
 int main()
{
    fast();
    int n, q; cin>>n>>q;
    ll arr[n];
    fori(0,n) cin>>arr[i], mp[arr[i]]++;
    fori(0,q){
        ll a; cin>>a;
        cout<<powerOf2(a)<<endl;
    }
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
int powerOf2(ll tmp){
    int cnt = 0;
    for(int i = 31;i>=0; i--){
        ll power = powers[i];
        if(power>tmp) continue;
         ll div = tmp/power, inmap =mp[power] ;
         if(inmap>=div){//the map has enough of this value
            cnt +=div;
            tmp -=div*power;
        }else{//the map doesn't have enough, so we take as more as possible
            cnt +=inmap;
            tmp -=inmap*power;
        }
    }
    if(tmp) return -1;
    return cnt;
 }
int countDigits(ull n){
    if(!n) return 1;
    int digits = 0;
    while(n){
        n /=10;
        digits++;
    }
    return digits;
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
 