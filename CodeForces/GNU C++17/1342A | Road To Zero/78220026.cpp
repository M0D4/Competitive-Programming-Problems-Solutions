#include <bits/stdc++.h>
#include <ext/numeric>
 using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define var auto
#define MOD 1000000007
  typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
  int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        ll x, y, a, b; cin>>x>>y>>a>>b;
        if(x>y) swap(x, y);
        ll mn = x;
        if(b<=a*2){
            x -= mn, y -= mn;
            cout<<b*mn + a*y<<endl;
        }else{
            ll c1 = b*mn + a * (y-mn);
            ll c2 = (x+y)*a;
            cout<<min(c1, c2)<<endl;
        }
     }
 return 0;
}