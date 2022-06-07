#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v)   v.begin(), v.end()
#define sz(x)    (int) (x.size())
#define Unique(x) x.erase(unique(all(x)), x.end())
#define endl "\n"
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
 
 
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);
 
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi a(n);
        for(auto &i: a) cin>>i;
        vi x = a;
        sort(all(x));
        for(int i = 0; i<n; i++)
            a[i] = lower_bound(all(x), a[i]) - x.begin();
        int dp[n + 5] = {}, mx = 0;
        for(int i =0 ; i<n; i++){
            dp[i] = 1;
            for(int j = 0; j<i; j++)
                if(a[j]+1==a[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            mx = max(mx, dp[i]);
        }
        cout<<n - mx<<endl;
    }
    return 0;
}