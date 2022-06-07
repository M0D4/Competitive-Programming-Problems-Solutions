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
    map<int, int> mp;
    ll cnt = 0;
    int a[n];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i - 1];
        mp[a[i - 1] - i]++;
    }
    for (int i = 1; i <= n; ++i) {
        ll m = mp[a[i - 1] - i];
        cnt += m * (m - 1) >> 1;
        mp[a[i - 1] - i] = 0;
    }
    cout << cnt << endl;
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