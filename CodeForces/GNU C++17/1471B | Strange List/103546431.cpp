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
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        ll s = 0;
        vector<int> a(n), b;
        for(auto &i: a) cin >> i, s += i;
        b = a;
        bool ok = 1;
        while(ok){
            for(int i = 0; i < n; i++){
                if(b[i] % x == 0) s += a[i], b[i] /= x;
                else{
                    ok = 0;
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}