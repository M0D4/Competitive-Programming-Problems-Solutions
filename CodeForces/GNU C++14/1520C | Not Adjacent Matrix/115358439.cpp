#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, last)    memset(x, last, sizeof(x))
 
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
 
 
void solve(){
    int n; cin >> n;
    if(n == 2) return cout << "-1\n", void();
 
    int cur = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << cur << " ";
            cur += 2;
            if(cur > n * n) cur = 2;
        }
        cout << endl;
    }
    cout << endl;
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