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
 
 
void solve(){
    string s; cin >> s;
    int n = s.size();
    int f[3] = {}, mex = 0;
    for (int i = 0; i < n; ++i) {
        f[s[i] - '0']++;
        while (mex < 3 && f[mex]) mex++;
    }
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '0'){
            zeros++;
            while (i + 1 < n && s[i + 1] == '0') ++i;
        }
    }
    cout << min(zeros, mex) << endl;
}
 
int main() {
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
 
    int TC; cin >> TC;
    for (int i = 1; i <= TC; ++i) {
        solve();
    }
    return 0;
}
 