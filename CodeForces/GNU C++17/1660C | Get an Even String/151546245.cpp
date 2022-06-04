#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
 const int N = 2e5 + 5;
string s;
int n;
int dp[N], nxt[N];
 int go(int i){
    if(i >= n) return 0;
     int& ret = dp[i];
    if(~ret) return ret;
     ret = 1 + go(i + 1);
    ret = min(ret, nxt[i] - i - 1 + go(nxt[i] + 1));
     return ret;
}
 int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while(tc--){
        cin >> s;
        n = s.size();
        for (int i = 0; i <= n; ++i) {
            dp[i] = -1;
        }
        vector<int> f(26, n + 1);
        for (int i = n - 1; i >= 0; --i) {
            nxt[i] = f[s[i] - 'a'];
            f[s[i] - 'a'] = i;
        }
         cout << go(0) << endl;
    }
    return 0;
}