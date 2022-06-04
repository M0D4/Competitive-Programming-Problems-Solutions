#include "bits/stdc++.h"
 using namespace std;
 #define pb              push_back
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
        int r, g, b, w; cin >> r >> g >> b >> w;
        int o = isOdd(r) + isOdd(g) + isOdd(b) + isOdd(w);
        if (o == 3 && (!r || !g || !b)) cout << "No" << endl;
        else cout << (o == 2 ? "No\n" : "Yes\n");
    }
    return 0;
}