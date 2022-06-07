#include "bits/stdc++.h"
 
using namespace std;
 
#define endl            "\n"
#define sz(x)          (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)       (n&1)
#define pow(n, m)      (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[n], mx = (ll)-1e18, suff = 0;
        for(auto &i: a) cin >> i;
        for(int i = n - 1; ~i; i--){
            suff += a[i];
            mx = max(mx, suff);
        }
        cout << mx << endl;
    }
    return 0;
}