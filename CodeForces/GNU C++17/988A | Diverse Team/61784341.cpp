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
int freq[101];
int main()
{
    fast();
    int n, k, cnt = 0; cin>>n>>k;
    vector<int> v;
    fori(0,n) {
        int t; cin>>t;
        if(!freq[t]) v.pb(i+1), cnt++;
        freq[t]++;
    }
    if(cnt>=k){
        cout<<"YES\n";
        fori(0,k){
            cout<<v[i]<<" ";
        }
    }
    else cout<<"NO";
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
  int BN(ll arr[], int n, ll val){
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