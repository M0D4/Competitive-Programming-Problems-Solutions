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
bool isPowerOf2(ll tmp);
int BNA(int arr[], int n,int l, int r, ll val);
int BND(int arr[], int n,int l, int r, ll val);
 //int freq[200000];
int main()
{
    fast();
    int n; cin>>n;
    vector<int> v;
    int cnt = 1, stairways = 1;
    fori(0,n){
        int a; cin>>a;
        if(a==cnt) cnt++;
        else{
            v.pb(cnt-1);
            cnt =2;
            stairways++;
        }
    }
    v.pb(cnt-1);
    cout<<stairways<<"\n";
    fori(0,stairways){
        cout<<v[i]<<" ";
    }
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
bool isPowerOf2(ll tmp){
    fori(0,32){
        ll power = pow(2,i);
            if(power==tmp) return 1;
    }
    return 0;
}
 int BNA(int arr[], int n,int l, int r, ll val){
    int low  = l;
    int up = r;
    int ans = -1;
    while(low<=up){
         ll mid = ((ll)low+up)/2; // to avoid overflow
          if(mid>l)if(arr[mid-1]>arr[mid])return 0;
        if(mid<r)if(arr[mid+1]<arr[mid])return 0;
         if(arr[mid]==val) return mid+1;
        if(arr[mid]<val){
            low = mid+1;
        }else up = mid -1;
    }
    return ans+1;
}
 