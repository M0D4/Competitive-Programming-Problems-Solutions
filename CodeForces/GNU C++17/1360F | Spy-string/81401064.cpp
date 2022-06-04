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
        int n, m; cin>>n>>m;
        string a[n], ans;
        for(int i = 0; i<n; i++){
            string s; cin>>s;
            a[i] = s;
        }
        string s = a[0];
        bool okk = 0;
        for(int i = 0; i<m; i++){
            s = a[0];
            for(char c = 'a'; c<='z'; c++){
                s[i] = c;
                bool ok = 1;
                for(int j = 1; j<n; j++){
                    int cnt = 0;
                    for(int k = 0; k<m; k++)
                        cnt += (s[k]!=a[j][k]);
                    if(cnt>1) ok = 0;
                }
                if(ok){
                    ans = s;
                    okk = 1;
                    break;
                }
            }
            if(okk) break;
        }
        if(!okk)cout<<"-1\n";
        else cout<<ans<<endl;
    }
 return 0;
}