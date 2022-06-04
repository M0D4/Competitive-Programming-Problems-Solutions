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
int BNMax(int arr[], int n, int k, int val);
int BN(int arr[], int n, int k);
//int freq[3];
int main()
{
    fast();
    int n, k; cin>>n>>k;
    int arr[n];
    fori(0,n) cin>>arr[i];
    sort(arr, arr+n);
    cout<<BN(arr, n, k);
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
int BN(int arr[], int n, int k){
    int low  = 1;
    int up = 1000000000;
    int ans = -1;
    while(low<=up){
         ll mid = ((ll)low+up)/2; // to avoid overflow
         int nums = BNMax(arr, n, k, mid);
         if(nums==k) return mid;
         else if(nums>k) up = mid-1;
         else low = mid+1;
    }
    return ans;
}
 int BNMax(int arr[], int n, int k, int val){
    int low  = 0;
    int up = n-1;
    int ans = -1;
    while(low<=up){
         ll mid = ((ll)low+up)/2; // to avoid overflow
        if(arr[mid]<=val){
            ans = mid;
            low = mid+1;
        }else up = mid -1;
    }
    return ans+1;
}