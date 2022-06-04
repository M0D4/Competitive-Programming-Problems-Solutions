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
        bool ok = 1;
        for(int i = 0; i<n && ok; i++){
            for(int j = 0; j<n; j++){
                if(a[i][j]=='0') continue;
                bool r = 1, c = 1;
                for(int row = i+1; row<n; row++)
                    if(a[row][j]=='1') break;
                    else if(a[row][j]=='0') r = 0;
                for(int col = j+1; col<n; col++)
                    if(a[i][col]=='1') break;
                    else if(a[i][col]=='0') c = 0;
                if(!r && !c){
                    ok = 0;
                    break;
                }
            }
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
 return 0;
}