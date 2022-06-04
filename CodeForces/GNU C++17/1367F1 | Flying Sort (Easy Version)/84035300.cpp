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
 void solve (vi &x){
    vi y = x;
    sort(all(y));
    for(int i = 0; i<sz(x); i++){
        x[i] = lower_bound(all(y), x[i]) - y.begin();
    }
}
int main()
{
    START
    //freopen("test cases\\in.txt", "r", stdin);
    //freopen("test cases\\in.txt", "w", stdout);
     int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int dp[n + 5] = {}, mx = 0;
        vi v(n);
        for(int i = 0; i<n; i++) cin>>v[i];
        solve(v);
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            dp[i] = 1;
            if(mp.count(v[i] - 1)){
                int in = mp[v[i] - 1];
                dp[i] = dp[in - 1] + 1;
            }
            mp[v[i]] = i + 1;
            mx = max(mx, dp[i]);
        }
        cout<<n - mx<<endl;
    }
    return 0;
}