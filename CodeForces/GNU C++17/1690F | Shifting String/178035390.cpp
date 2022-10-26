#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 
using namespace std;
using ll = long long;
 
int calc(string s) {
    int cnt = 1;
    string t = s;
    while (true) {
        t.push_back(t[0]);
        t = t.substr(1);
        if (t == s) break;
        cnt++;
    }
    return cnt;
}
 
 
ll lcm(ll x, ll y) {
    return x / __gcd(x, y) * y;
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        string s;
        cin >> n >> s;
        int p[n];
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            --p[i];
        }
        vector<bool> vis(n);
        ll ans = 1;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            string x = "";
            int nxt = i;
            while (vis[nxt] == 0) {
                vis[nxt] = 1;
                x.push_back(s[nxt]);
                nxt = p[nxt];
            }
            ans = lcm(ans, calc(x));
        }
        cout << ans << endl;
    }
    return 0;
}