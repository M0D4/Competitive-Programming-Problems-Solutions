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
    int n, mx = 0; str s, mxS = ""; cin>>n>>s;
    map<str, int> mp;
    fori(0,n-1){
        str tmp = s.substr(i,2);
        mp[tmp]++;
        if(mp[tmp]>mx) mx = mp[tmp], mxS = tmp;
    }
    cout<<mxS;
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}