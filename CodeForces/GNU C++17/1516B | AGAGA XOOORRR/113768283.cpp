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
 
void solve(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll pre[n + 2] = {}, suff[n + 2] = {};
    pre[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] ^ a[i];
    }
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; ~i; --i) {
        suff[i] = suff[i + 1] ^ a[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = n - 1; j > i; --j) {
            if(pre[i] == suff[j]) {
                ll rem = 0, eq = 1, x = pre[i];
                for (int k = i + 1; k < j; ++k) {
                    rem ^= a[k];
                    x = a[k];
                    if(k == i + 1) continue;
                    if(a[k] != a[k - 1]) eq = 0;
                }
                if (rem == pre[i] || (eq && x == pre[i])) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    int tc; cin >> tc;
    while (tc--){
        solve();
    }
    return 0;
}