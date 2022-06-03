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
        char c = 0;
        for (int i = 0; i < 2 * n + 1; ++i) {
            string s; cin >> s;
            for(auto& si: s)
                c ^= si;
        }
        cout << c << endl;
    }
    return 0;
}