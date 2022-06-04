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
bool sortSecondInRev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.second > b.second);
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
//int freq[101];
 //map<int, int> mp;
int main()
{
    fast();
    int t; cin>>t;
    while(t--){
     ll n, v, l, r; cin>>n>>v>>l>>r;
     cout<<n/v - r/v + (l-1)/v<<endl;
    }
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
 