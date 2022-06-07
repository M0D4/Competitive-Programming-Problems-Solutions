#include "bits/stdc++.h"
 
using namespace std;
 
#define pb              push_back
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int N = 250;
ll dp[N][N][N];
int rr, gg, bb, r[N], g[N], b[N];
ll solve(int i, int j, int k){
    ll &ret = dp[i][j][k];
    if(~ret) return ret;
 
    ret = 0;
    if(i < rr && j < gg) ret = solve(i + 1, j + 1, k) + r[i] * g[j];
    if(i < rr && k < bb) ret = max(ret, solve(i + 1, j, k + 1) + r[i] * b[k]);
    if(j < gg && k < bb) ret = max(ret, solve(i, j + 1, k + 1) + g[j] * b[k]);
 
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> rr >> gg >> bb;
    for(int i = 0; i < rr; i++) cin >> r[i];
    for(int i = 0; i < gg; i++) cin >> g[i];
    for(int i = 0; i < bb; i++) cin >> b[i];
 
    sort(r, r + rr, greater<>());
    sort(g, g + gg, greater<>());
    sort(b, b + bb, greater<>());
 
    clr(dp, -1);
 
    cout << solve(0, 0, 0);
    return 0;
}