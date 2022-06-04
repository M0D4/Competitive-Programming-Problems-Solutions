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
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
  int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 3] = {};
        for(int i = 1; i <= n; i++)
            a[i] = n - i + 1;
        for(int i = 2; i <= n; i++){
            if(a[i] == i) swap(a[i], a[i - 1]);
        }
        for(auto i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}