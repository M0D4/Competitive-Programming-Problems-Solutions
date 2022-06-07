#include <bits/stdc++.h>
#include <ext/numeric>
/**
    PROGRESS IS PROGRESS
    NO MATTER HOW SMALL
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
#define LLMAX LLONG_MAX
#define LLMIN LLONG_MIN
#define IMN INT_MIN
#define IMX INT_MAX
#define pow(n, m) power((ll)n, (ll)m)
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
#define mem(x, val)    memset(x, val, sizeof(x)) //be careful
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
typedef double dd;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int N = 1e6;
int n, k;
string s;
int dp[N + 5][3], one[N + 5];
int solve(int i, int stage){
    if(i>=n || stage>2) return 0;
 
    int &ret = dp[i][stage];
    if(~ret) return ret;
 
    int c1 = (stage==0 || stage==2)*(s[i]=='1') + (stage==1)*(s[i]=='0') + solve(i+k, stage);
    int c2 = (stage+1<3? solve(i, stage+1) : n);
 
    return ret = min(c1, c2);
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin) ;
    //freopen("test cases\\out.txt", "w", stdout) ;
 
    int t; cin>>t;
    while(t--){
       cin>>n>>k>>s;
       memset(dp, -1, 3* n * sizeof dp[0][0]);
       memset(one, 0, k * sizeof one[0]);
       int total = count(all(s), '1');
       for(int i = 0; i<n; i++) one[i%k] += (s[i]=='1');
        int mn = n;
        for(int i = 0; i<k; i++){
            int cost = solve(i, 0) + total - one[i];
            mn = min(mn, cost);
        }
       cout<<mn<<endl;
    }
 return 0;
}