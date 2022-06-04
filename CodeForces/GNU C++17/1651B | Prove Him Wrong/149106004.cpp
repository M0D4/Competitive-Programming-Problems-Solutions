#include "bits/stdc++.h"
 #pragma GCC optimize("Ofast")
 using namespace std;
 #define endl            "\n"
#define all(v)          v.begin(), v.end()
#define debug(x)        cout << #x << " is " << x << endl
#define pow(n, m)       (int)powl(n, m)
#define clr(x, value)    memset(x, value, sizeof(x))
 using ll = long long;
 /// Check Constraints, please!
 int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
     int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        ll a[n];
        bool ok = 1;
        a[0] = 1;
        for (int i = 1; i < n; ++i) {
            if(3 * a[i - 1] > 1e9){
                ok = 0;
                break;
            }
            a[i] = 3 * a[i - 1];
        }
        if(!ok) cout << "NO\n";
        else{
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}