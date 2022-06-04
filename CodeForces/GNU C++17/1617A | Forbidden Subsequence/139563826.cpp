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
        string s, t; cin >> s >> t;
        int n = s.size();
        int f[26] = {};
        for (int i = 0; i < n; ++i) {
            f[s[i] - 'a']++;
        }
        if(t != "abc" || f[0] == 0 || f[2] == 0 || f[1] == 0){
            sort(all(s));
            cout << s << endl;
            continue;
        }
         cout << string(f[0], 'a');
        cout << string (f[2], 'c');
        cout << string (f[1], 'b');
         for (int i = 3; i < 26; ++i) {
            cout << string(f[i], char(i + 'a'));
        }
        cout << endl;
    }
    return 0;
}