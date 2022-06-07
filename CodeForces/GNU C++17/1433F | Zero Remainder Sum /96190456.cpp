#include "bits/stdc++.h"
 
#pragma GCC optimize("trapv")
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
 
using namespace std;
 
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define sc              scanf
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
#define numOfDigits(n)  ((n)? (ll)(log10(n))+1 : 1)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
int n, m, k;
 
int dp[70][71][35][70], a[70][71];
 
int go(int i, int j, int cur_k, int rem){
 
    if(i == n) return (rem) * (-1e9);
    if(j == m || !cur_k) return go(i + 1, 0, m >> 1, rem);
 
    int &ret = dp[i][j][cur_k][rem];
    if(~ret) return ret;
 
 
    ret = go(i, j + 1, cur_k, rem);
    ret = max(ret, a[i][j] + go(i, j + 1, cur_k - 1, (rem + a[i][j] % k) % k));
 
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
 
    clr(dp, -1);
 
    cout << max(0, go(0, 0, m >> 1, 0));
    return 0;
}