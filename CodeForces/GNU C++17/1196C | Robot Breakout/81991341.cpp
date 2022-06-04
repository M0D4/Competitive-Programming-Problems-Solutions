#include <bits/stdc++.h>
#include <ext/numeric>
/**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
using namespace std;
using namespace __gnu_cxx;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
  typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef vector<int> vi;
  int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int mnX, mxX, mnY, mxY;
        mnY = mnX = (int)1e5;
        mxX = mxY = (int)-1e5;
        while(n--){
            int x, y, f[4];
            cin>>x>>y;
            for(int i = 0; i<4; i++) cin>>f[i];
            if(!f[0]) mxX = max(mxX, x);
            if(!f[1]) mnY = min(mnY, y);
            if(!f[2]) mnX = min(mnX, x);
            if(!f[3]) mxY = max(mxY, y);
        }
        if(mxX <= mnX && mxY <= mnY) cout<<"1 "<<mnX<<" "<<mnY<<endl;
        else cout<<"0\n";
    }
 return 0;
}