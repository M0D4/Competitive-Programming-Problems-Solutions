#include <bits/stdc++.h>
#include <ext/numeric>
/**
    HAPPY EID :)
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
        char a[n][n];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                cin>>a[i][j];
         for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(a[i][j]=='0') continue;
                bool r = 1, c = 1;
                if(i+1<n && a[i+1][j]=='0') r = 0;
                if(j+1<n && a[i][j+1]=='0') c = 0;
                if(!r && !c){
                    cout<<"NO\n";
                    goto safeZone;
                }
            }
        }
        cout<<"YES\n";
        safeZone:;
    }
 return 0;
}