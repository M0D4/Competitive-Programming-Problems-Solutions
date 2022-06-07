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
#define pow(n, m) power(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
#define MAX (ll) 1e18
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    int t; cin>>t;
    const int N = 1024;
    while(t--){
        int n; cin>>n;
        int a[n];
       bool f[N + 1] = {};
       for(int i  = 0; i<n; i++){
            int b; cin>>b;
            a[i] = b;
            f[b] = 1;
       }
        int ans = -1;
       for(int i = 1; i<=16384; i++){
            bool v[N + 1] = {};
            int c = 0;
            for(int j = 0; j<n; j++){
                if((a[j]^i) <= 1024 && !v[a[j]^i] && f[a[j]^i]) v[a[j]^i] = 1, c++;
            }
            if(c==n){
                ans = i;
                break;
            }
       }
       cout<<ans<<endl;
    }
 return 0;
}