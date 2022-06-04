#include <bits/stdc++.h>
 /**
       return NO_PAIN ? NO_GAIN : GAIN;
*/
 using namespace std;
 #define all(v)   v.begin(), v.end()
#define sz(x)    (int) x.size()
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define START cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define isOdd(n)    (n&1)
#define pow(n, m) (ll)powl(n, m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define clr(x, val)    memset(x, val, sizeof(x)) //be careful of value and TLE
#define MOD 1000000007
#define EPS 1e-7
 typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 const int N = 30005, M = N/2, OO = 1e8;
int n, d;
int dp[N][500], f[N];
int solve(int i, int prev){
    if(i >= N) return 0;
     int x = prev - (d - 250);
    int &ret = dp[i][x];
    if(~ret) return ret;
     ret = 0;
    ret = max(ret, f[i] + solve(i + prev, prev));
    ret = max(ret, f[i] + solve(i + prev + 1, prev + 1));
    if(prev - 1 > 0) ret = max(ret, f[i] + solve(i + prev - 1, prev - 1));
     return ret;
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\in.txt", "w", stdout);
    cin>>n>>d;
    for(int i = 0; i<n; i++){
        int a; cin>>a;
        f[a]++;
    }
    clr(dp, -1);
    cout<<solve(d, d);
 return 0;
}