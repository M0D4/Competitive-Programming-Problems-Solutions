#include <bits/stdc++.h>
using namespace std;
 #define fori( tt,aa)      for(long long i= tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define sz(v)    v.size()
#define all(v)   (v.begin(), v.end())
#define endl "\n";
#define pb push_back
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
void fast(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}
ll pow (ll a, ll b);
int BN(ll arr[], int n, ll val);
int main()
{
    fast();
    int n, m; cin>>n>>m;
    ll arr[n+1]={0}, b[m+1]={0};
    fori(1,n+1){
        ll t; cin>>t;
        arr[i] = t+ arr[i-1];//prefix sum
    }
    fori(1,m+1)cin>>b[i];
    fori(1,m+1){
        ll val = b[i];
        int index = BN(arr, n, val);//number of the dormitory
        cout<<index<<" "<<val - arr[index-1]<<"\n";
    }
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
  int BN(ll arr[], int n, ll val){//search for first bigger or equal
    int low  = 1;
    int up = n;
    int ans = 1;
    while(low<=up){
         ll mid = ((ll)low+up)/2; // to avoid overflow
        if(arr[mid]<val){
            low = mid+1;
        }else ans = mid, up = mid -1;
    }
    return ans;
}