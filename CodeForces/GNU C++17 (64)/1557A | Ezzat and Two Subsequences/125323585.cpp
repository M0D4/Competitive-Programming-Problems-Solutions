#include "bits/stdc++.h"
 
 
#pragma GCC optimize("Ofast")
 
 
using namespace std;
 
#define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (ll)powl(n, m)
#define Unique(x)       x.erase(unique(all(x)), x.end())
#define clr(x, last)    memset(x, last, sizeof(x))
 
using ll = long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
 
///Intermediate Overflow!!! (1 << i), x * y, 2 * x
 
 
int main()
{
 
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cout << fixed << setprecision(8);
 
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        double b = 0;
        for (int i = 0; i + 1 < n; ++i) {
            b += a[i];
        }
        if(n - 1 > 0) b /= (n - 1);
        cout << b + a[n - 1] << endl;
    }
    return 0;
}