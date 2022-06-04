#include <bits/stdc++.h>
using namespace std;
 #define fori( t,a)      for(long long i = t; i<a; i++)
#define forj( y,b)      for(long long j=y; j<b; j++)
#define fork( u,c)      for(long long k=u; k<c; k++)
#define endl "\n";
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string String;
typedef string str;
 ll pow (ll a, ll b);
const dd PI = 3.141592;
//int freq[1000001];
ll pre[109];//1-indexed, more size for prefix-sum
 int main()
{
     cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    fori(1,n+1){
      int l, r;
      cin>>l>>r;
        pre[l]+=1;
        pre[r+1]-=1;
    }
    int cnt = 0;
    fori(1,m+1){
      pre[i] +=pre[i-1];
      if(!pre[i]) cnt++;
    }
    cout<<cnt<<"\n";
    if(cnt)
    fori(1, m+1){
        if(!pre[i])
            cout<<i<<" ";
    }
    return 0;
}
ll pow (ll a, ll b){
    ll pow = 1;
    fori(0,b)
        pow *=a;
    return pow;
}