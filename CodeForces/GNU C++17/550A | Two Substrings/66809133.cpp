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
 //int freq[3];
int main()
{
     fast();
    str s; cin>>s;
    str s1 = "ABBA", s2 = "BAAB";
    int cnt1 = 0, cnt2 =0, si = sz(s);
    fori(0,si-1){
      if(s.substr(i,2)==s1.substr(cnt1,2)) cnt1+=2, i++;
    }
    fori(0,si-1){
     if(s.substr(i,2)==s2.substr(cnt2,2)) cnt2+=2, i++;
    }
        if(cnt1==4 || cnt2 ==4)
      cout<<"YES";
    else cout<<"NO";
    return 0;
}
 ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}