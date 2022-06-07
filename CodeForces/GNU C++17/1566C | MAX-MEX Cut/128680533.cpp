#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, value)    memset(x, value, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<ll, ll, ll>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
const int N = 1e5 + 5, M = 2;
string a[2];
int n, dp[N][1 << M];
 
int getMex(int mex){
    for (int j = 0; j <= M; ++j) {
        if((mex >> j) & 1 ^ 1) return j;
    }
}
 
int go(int i, int mex){
    if(i == n){
        return getMex(mex);
    }
 
    int& ret = dp[i][mex];
    if(~ret) return ret;
 
    int t1 = a[0][i] - '0';
    int d1 = a[1][i] - '0';
 
    bool hasZero = 0, hasOne = 0;
    if(!t1 || !d1) hasZero = 1;
    if(t1 || d1) hasOne = 1;
 
    int newMex = mex;
    if(hasZero) newMex |= (1 << 0);
    if(hasOne) newMex |= (1 << 1);
 
    ret = getMex(newMex) + go(i + 1, 0);
    ret = max(ret, go(i + 1, newMex));
 
    return ret;
}
 
void solve(){
    cin >> n;
    for (int i = 0; i < 2; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << M); ++j) {
            dp[i][j] = -1;
        }
    }
 
    cout << go(0, 0) << endl;
}
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
 
    int TC; cin >> TC;
    for (int i = 1; i <= TC; ++i) {
        solve();
    }
    return 0;
}
 