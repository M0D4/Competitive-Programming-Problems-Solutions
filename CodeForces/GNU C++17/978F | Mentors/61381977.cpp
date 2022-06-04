#include <bits/stdc++.h>
using namespace std;
 #define fori( tt,aa)      for(long long i = tt; i<aa; i++)
#define forj( yy,bb)      for(long long j=yy; j<bb; j++)
#define fork( uu,cc)      for(long long k=uu; k<cc; k++)
#define endl "\n";
#define all(v)            v.begin(),v.end()
#define sz(v)             v.size();
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
ll BN (int t, int arr[], int n);
bool isSuperLucky(ll n);
int main()
{
    fast();
    int n, k; cin>>n>>k;
    int arr[n], tmp[n];
    fori(0,n){
        cin>>arr[i];
        tmp[i] = arr[i];
    }
    sort(arr, arr+n);
    int arr2[n]={0};
    fori(0,n){
        int t = BN(tmp[i], arr, n);
        arr2[i] = t+1;
    }
    fori(0,k){
        int p1, p2; cin>>p1>>p2;
        p1--; p2--;
        if(tmp[p1]>tmp[p2]) arr2[p1]--;
        else if(tmp[p2]>tmp[p1]) arr2[p2]--;
    }
    fori(0,n) cout<<arr2[i]<<" ";
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
ll BN (int t,int arr[], int n){
    ll low = 0;
    ll up = n-1;
    ll ans = -1;
    while(low<=up){
        ll mid = (low+up)/2;
        if(arr[mid]>=t){
                up= mid-1;
        }
        else {
                low = mid+1;
        ans = mid;
        }
    }
    return ans;
}
bool isSuperLucky(ll n){
    int seven = 0, four = 0;
    while(n){
        int m = n%10;
        if(m!=7 && m!=4) return 0;
        if(m==7) seven++;
        else four++;
        n/=10;
    }
    return seven==four;
}