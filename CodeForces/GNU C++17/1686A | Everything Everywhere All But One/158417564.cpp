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
        int n; cin >> n;
        int a[n];
        ll sum = 0;
        int same = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            same += (i > 0 && a[i] == a[0]);
        }
        int f[102] = {};
        bool ok = (same == n);
        for (int i = 0; i < n && !ok; ++i) {
            sum -= a[i];
            if(sum % (n - 1) == 0 && sum / (n - 1) == a[i]){
                ok = 1;
            }
            sum += a[i];
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}