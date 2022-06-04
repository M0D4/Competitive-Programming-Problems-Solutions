#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
 int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TC; cin >> TC;
    while(TC--){
        int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
        int mn = min(a, x);
        a -= mn;
        x -= mn;
         mn = min(b, y);
        b -= mn;
        y -= mn;
         cout << (c >= (x + y) ? "YES" : "NO") << endl;
    }
    return 0;
}