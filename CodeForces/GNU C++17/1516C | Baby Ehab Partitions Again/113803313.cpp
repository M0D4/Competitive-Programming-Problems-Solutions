#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<ll, int>;
using tii = tuple<int, int, int>;
 
const int N = 100 + 2, M = 2e5 + 5;
 
int dp[N][M], n, total, a[N];
 
int go(int i, int sum, int in){
    if(i == n){
        return total - sum == sum;
    }
 
    int& ret = dp[i][sum];
    if(~ret) return ret;
 
    ret = 0;
    ret = max(ret, go(i + 1, sum, in));
    if(in != i) ret = max(ret, go(i + 1, sum + a[i], in));
 
    return ret;
}
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
 
    clr(dp, -1);
 
    int ans = go(0, 0, -1);
 
    cout << ans << endl;
 
    if(!ans) return 0;
 
    for(int i = 0; i < n; ++i){
       total -= a[i];
       clr(dp, -1);
 
       ans = go(0, 0, i);
 
       if(!ans) return cout << i + 1, 0;
       total += a[i];
    }
    return 0;
}