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
#define numOfDigits(x)  (x ? (ll)(log10(x)) + 1 : 1)
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
const int N = 100 + 5, M = 1e5;
int dp[N][M], t, v1, v2, d;
 
int go(int sec, int last){
    if(sec + 1 == t){
        if(abs(last - v2) <= d) return 0;
        return -1e8;
    }
 
    int& ret = dp[sec][last];
    if(~ret) return ret;
 
    ret = -1e8;
    for (int i = 0; i <= d; ++i) {
        ret = max(ret, i + last + go(sec + 1, i + last));
        if(last - i >= 1) ret = max(ret, last - i + go(sec + 1, last - i));
    }
    return ret;
}
 
void solve(){
    cin >> v1 >> v2;
    cin >> t >> d;
    clr(dp, -1);
    cout << go(1, v1) + v1 + v2;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
    solve();
    return 0;
}
                               