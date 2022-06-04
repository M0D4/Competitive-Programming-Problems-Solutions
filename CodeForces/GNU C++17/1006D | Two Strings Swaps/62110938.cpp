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
    int n; cin>>n;
    str a, b; cin>>a>>b;
    int prepro = 0;
     for(int i=0, cnt2=n-1; i<=cnt2; i++, cnt2--){
        map<char, int> mp;
        if(i<cnt2){
            mp[a[i]]++; mp[a[cnt2]]++; mp[b[i]]++; mp[b[cnt2]]++;
             int si = sz(mp);
            if(si==4) prepro+=2;
            else if(si==3) prepro += 1 + (a[i]==a[cnt2]);
            else if(si==2 && mp[a[i]]!=2) prepro++;
            }else prepro += a[i]!=b[i];
            mp.clear();
    }
        cout<<prepro<<" ";
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
 