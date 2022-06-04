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
int freq[101];
 map<int, int> mp;
int main()
{
    fast();
    int a, b ,x; cin>>a>>b>>x;
    if(a<=b){
        fori(0,x)
            if(!(i%2))b--, cout<<1;
            else a--, cout<<0;
        if(!(x%2)){
            while(a) a--, cout<<0;
            while(b) b--, cout<<1;
        }else{
            while(b) b--, cout<<1;
            while(a) a--, cout<<0;
        }
    }else{
         fori(0,x)
            if(!(i%2))a--, cout<<0;
            else b--, cout<<1;
        if(!(x%2)){
            while(b) b--, cout<<1;
            while(a) a--, cout<<0;
        }else{
            while(a) a--, cout<<0;
            while(b) b--, cout<<1;
        }
    }
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
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