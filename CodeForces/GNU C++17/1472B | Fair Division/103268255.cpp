#include "bits/stdc++.h"
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define sc              scanf
#define endl            "\n"
#define sz(x)           (int) (x.size())
#define all(v)          v.begin(), v.end()
#define isOdd(n)        (n&1)
#define pow(n, m)       (ll)powl(n, m)
#define clr(x, val)     memset(x, val, sizeof(x))
 
 
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;
typedef tuple<int, int, int> tii;
 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int f[3] = {};
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            f[a]++;
        }
 
        bool ok = (f[1] && !isOdd(f[1])) || (f[2] && !isOdd(f[2]));
        ok = ok && !isOdd(f[1] + 2 * f[2]);
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}