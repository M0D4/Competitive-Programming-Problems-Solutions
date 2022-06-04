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
        string s; cin >> s;
        char c; cin >> c;
        bool ok = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == c) ok |= (i % 2 == 0) || ((s.size() - i - 1) % 2 == 0);
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}