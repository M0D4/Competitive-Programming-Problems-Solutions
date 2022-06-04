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
int BN(ll pre[], int m);
int countDigits(unsigned long long n);
//int freq[101];
 //map<int, int> mp;
int main()
{
    fast();
     map<ll,map<ll,ll>>mp;
    int n,k; cin>>n>>k;
    int arr[n];
    fori(0,n){
        int a; cin>>a;
        arr[i]=a;
        int digits=countDigits(a);
        mp[digits][a%k]++;
    }
    ll solu=0;
    fori(0,n){
         unsigned long long temp = arr[i];
        int digits = countDigits(temp);
        mp[digits][arr[i]%k]--;
            forj(0,10){
                temp*=10;
                int mod = temp%k;
                if(mp[j+1].find((k-mod)%k)!=mp[j+1].end())
                solu+=mp[j+1][(k - mod)%k];
            }
        mp[digits][arr[i]%k]++;
    }
            cout<<solu;
       return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}
int countDigits(unsigned long long n){
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