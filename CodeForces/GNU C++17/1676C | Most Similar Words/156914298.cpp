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
        int n, m; cin >> n >> m;
        string a[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
         auto calcDifference = [&](string& a, string& b){
            ll diff = 0;
            for (int i = 0; i < m; ++i) {
                diff += abs(a[i] - b[i]);
            }
            return diff;
        };
         ll mn = 1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mn = min(mn, calcDifference(a[i], a[j]));
            }
        }
        cout << mn << endl;
    }
    return 0;
}