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
typedef double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
 
const int N = 2e5 + 5;
 
int a[N], n;
ll dp[N];
 
ll go(int i){
    if(i >= n) return 0;
 
    ll &ret = dp[i];
    if(~ret) return ret;
 
    ret = a[i] + go(i + a[i]);
 
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i], dp[i] = -1;
        ll mx = 0;
 
        for(int i = 0; i < n; i++)
            mx = max(mx, go(i));
        cout << mx << endl;
    }
    return 0;
}