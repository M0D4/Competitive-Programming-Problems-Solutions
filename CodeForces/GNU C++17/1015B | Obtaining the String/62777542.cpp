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
int find1(str a,int n, char c){
    fori(0,n) if(a[i]==c) return i;
    return -1;
}
//int freq[101];
 //map<int, int> mp;
int main()
{
    fast();
    int n, k = 0; cin>>n;
    str s, t; cin>>s>>t;
    str stmp = s, ttmp = t;
    sort(all(stmp));
    sort(all(ttmp));
    if(stmp!=ttmp) return cout<<-1, 0;
    vecint v;
    fori(0,n){//outer loop
        char c = t[i];
        if(c==s[i]){
            s[i]=' ';
            continue;
        }
        int index = find1(s,n,c), index2 = index;
        k +=index - i;
        index++;
        while(index-1>i){
            v.pb(--index);
            str b = s.substr(index-1, 2);
            reverse(all(b));
            s.replace(index-1, 2, b);
        }
        s[i]=' ';
    }
    cout<<k<<"\n";
    fori(0,k) cout<<v[i]<<" ";
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
         ll mid = ((ll)low+up)/2; /// to avoid overflow
        if(pre[mid]<=300){
            ans = mid;
           low = mid +1;
        }else  up = mid-1;
    }
    return ans;
}