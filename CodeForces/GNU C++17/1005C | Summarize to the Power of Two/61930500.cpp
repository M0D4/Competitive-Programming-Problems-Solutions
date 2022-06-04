#include <bits/stdc++.h>
using namespace std;
 #define fori( tt,aa)      for(long long i= tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define sz(v)    v.size()
#define all(v)   v.begin(), v.end()
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
bool hasPowerOf2(ll tmp);
int BN(str s, str t, int si, int ti);
//int freq[1200001];
map<ll, int> mp;
int main()
{
    fast();
    int n; cin>>n;
    int arr[n], cnt = 0;
    fori(0,n) cin>>arr[i], mp[arr[i]]++;
    fori(0,n){
        if(!hasPowerOf2(arr[i])) cnt++;
    }
    cout<<cnt;
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
bool hasPowerOf2(ll tmp){
    fori(1,32){
        ll power = pow(2,i);
        mp[tmp]--;
        if(power>tmp && mp[power-tmp]){
            mp[tmp]++;
            return 1;
        }
        mp[tmp]++;
    }
    return 0;
}
 int BN(str s, str t, int si, int ti){
    int low  = 0;
    int up = min(si, ti)-1;
    int ans = si + ti;
    while(low<=up){
         ll mid = ((ll)low+up)/2; // to avoid overflow
        if(s.substr(0,mid+1)==t.substr(0,mid+1)){
           low = mid+1;
            ans = si-mid-1 + ti - mid-1;
        }else  up = mid -1;
    }
    return ans;
}
 