#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define sc              scanf
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<ll, ll> a[n + 1] = {};
        ll pfx[n + 3] = {}, suff[n + 3] = {};
        for(auto i = 1; i <= n; i++) cin >> a[i].first;
        for(auto i = 1; i <= n; i++) cin >> a[i].second;
 
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
            pfx[i] = max(a[i].first, pfx[i - 1]);
        }
        for(int i = n; i > 0; i--){
            suff[i] = a[i].second + suff[i + 1];
        }
        ll mn = 1e15;
        for(int i = 1; i < n; i++){
            mn = min(mn, max(pfx[i], suff[i + 1]));
        }
        mn = min({mn, pfx[n], suff[1]});
        cout << mn << endl;
    }
    return 0;
}