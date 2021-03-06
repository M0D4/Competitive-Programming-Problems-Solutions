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
#define EPS 1e-7
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout);
    int t; cin>>t;
    while(t--){
        int n, x; cin>>n>>x;
        int o = 0, e = 0, c = 0, sum = 0;
        int f[n+1] = {};
        for(int i = 0; i<n; i++){
            int a; cin>>a;
            f[i] = a;
            if(isOdd(a)) o++;
            else e++;
        }
        bool ok = 0;
        for(int i = 1; i<=o && i<=x; i+=2){
            if(i + min(e, x-i)==x) ok = 1;
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";
    }
 return 0;
}