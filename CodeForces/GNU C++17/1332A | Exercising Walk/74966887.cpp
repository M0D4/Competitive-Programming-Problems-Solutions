#include <bits/stdc++.h>
#include <ext/numeric>
 using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define THINK_TWICE_CODE_ONCE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n)+1) : 1)
#define mem(x, val)    memset(x, val, sizeof(x))
 typedef long long ll;
typedef long double ld;
typedef double dd;
typedef string str;
typedef pair<int, int> pii;
 int main()
{
    THINK_TWICE_CODE_ONCE
    //freopen("test cases\\.txt", "r", stdin) ;
    int t; cin>>t;
    while(t--){
        int a, b, c, d; cin>>a>>b>>c>>d;
        int x,y, x1,y1, x2, y2; cin>>x>>y>>x1>>y1>>x2>>y2;
        x += 1e8, y += 1e8, x1 += 1e8, x2 += 1e8, y1 += 1e8, y2 += 1e8;
        if(x1==x2 && (a||b)){
            cout<<"No\n";
            continue;
        }
        if(y1==y2 && (c||d)){
            cout<<"No\n";
            continue;
        }
        int mnRL = min(a, b); a -=mnRL, b -= mnRL;
        int mnUD = min(c, d); c -= mnUD, d -= mnUD;
         if(x1==x2 && y1==y2)cout<<"No\n";
        else if(-a + x >= x1 && b + x <= x2 && -c + y >= y1 && d + y<=y2)
            cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
    