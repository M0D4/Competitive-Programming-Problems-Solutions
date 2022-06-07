#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
 
 
const int N = 1e5 + 5;
 
int n, p, k, dp[N];
ll x, y;
string s;
 
int go(int i){
    if(i >= n) return 0;
 
    int &ret = dp[i];
    if(~ret) return ret;
 
    ret = (s[i] == '0') * x + go(i + k);
 
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        cin >> n >> p >> k;
        p--;
        cin >> s;
        cin >> x >> y;
 
        memset(dp, -1, n * sizeof dp[0]);
 
        ll mn = 1e9;
        for(int i = 0; i + p < n; i++){
            mn = min(mn, i * y + go(i + p));
        }
        cout << mn << endl;
    }
    return 0;
}