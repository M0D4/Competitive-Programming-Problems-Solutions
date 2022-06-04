#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
#define Unique(x)       x.erase(unique(all(x)), x.end())
 using ll = long long;
 int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
           cin >> a[i];
        }
        int mx = *max_element(all(a)), mn = *min_element(all(a));
        cout << mx - mn << endl;
    }
    return 0;
}