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
     int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<bool> f(n + 2, 0);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(all(a));
        for (int i = 0; i < n; ++i) {
            while (a[i] > 0){
                if(a[i] <= n && f[a[i]] == 0){
                    f[a[i]] = 1;
                    break;
                }
                a[i] /= 2;
            }
        }
        cout << (all_of(f.begin() + 1, f.begin() + n + 1,
                        [](bool x){return x;}) ? "YES" : "NO") << endl;
    }
    return 0;
}