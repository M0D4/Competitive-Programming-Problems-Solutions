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
#define vector<int> vecint
#define vector<ll> vecll
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
int BN(str s, str t, int si, int ti);
//int freq[1200001];
//map<ll, int> mp;
int main()
{
    fast();
    str s, tmp = "hello"; cin>>s;
    int cnt = 0, si = sz(s);
    fori(0,si){
        if(s[i]==tmp[cnt])cnt++;
    }
    cout<<((cnt==5)?"YES":"NO");
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
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
 