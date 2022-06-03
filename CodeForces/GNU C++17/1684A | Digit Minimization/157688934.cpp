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
        string s; cin >> s;
        if(s.size() == 2) cout << s[1] << endl;
        else cout << *min_element(all(s)) << endl;
    }
    return 0;
}