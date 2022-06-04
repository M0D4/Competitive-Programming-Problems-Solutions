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
        int n, m; cin >> n >> m;
        int a[n], b[m];
        for(int &i: a) cin >> i, i--;
        for(int &i: b) cin >> i;
         ll sum = 0;
         sort(a, a + n, greater<>());
        for(int i = 0, j = 0; i < n; i++){
            ll y = a[i];
            if(y <= j) sum += b[y];
            else sum += b[j++];
        }
        cout << sum << endl;
    }
    return 0;
}