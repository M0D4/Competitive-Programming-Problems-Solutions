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
//int freq[101];
 //map<int, int> mp;
int main()
{
    int n, r; cin>>n>>r;
    int pre[n+3] = {0};
    vector<pair<int,int>>v;
    fori(1,n+1){
       bool a; cin>>a;
       if(a){
        int left  = max(1, (int)i-r+1);
        int right  = min(n, (int)i+r-1);
        v.pb({left,right});
        pre[left] += 1;
        pre[right+1] -=1;
       }
    }
    fori(1, n+1) pre[i] +=pre[i-1];
    bool hasZero = 0;
    fori(1, n+1) if(!pre[i]){hasZero =1; break;}
    if(hasZero)cout<<-1;
    else {
        int lighten = sz(v), si = lighten;
        fori(0,si){
            int left = v[i].first, right = v[i].second;
            forj(left,right+1) if(pre[j]==1) goto here;
            forj(left,right+1) pre[j]--;
            lighten--;
            here:{
            }
        }
        cout<<lighten;
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
 