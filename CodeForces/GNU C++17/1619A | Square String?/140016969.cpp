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
        if(s.size() & 1){
            cout << "NO\n";
            continue;
        }
        int n = s.size();
        cout << (s.substr(0, n / 2) == s.substr(n / 2) ? "YES" : "NO") << endl;
    }
    return 0;
}